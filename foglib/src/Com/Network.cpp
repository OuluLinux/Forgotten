#include "Com.h"
#include <plugin/enet/enet.h>
#include <plugin/websocketpp/config/asio_no_tls.hpp>
#include <plugin/websocketpp/server.hpp>

#include <plugin/websocketpp/config/asio_no_tls_client.hpp>
#include <plugin/websocketpp/client.hpp>

namespace Network::Native {
using namespace Com;


const char* GetIpStringFromDword(dword d) {
	static thread_local char addr[4*3+3+1];
	
	if (!d)
		return "0.0.0.0";
	
	int cur = 0;
	bool is_invalid = false;
	for (size_t i = 0; i < 4; i++) {
		if (i) addr[cur++] = '.';
		int shift = (4-1-i) * 8;
		byte b = (d >> shift) & 0xFF;
		bool empty = true;
		for(int j = 0; j < 3; j++) {
			byte mul;
			switch (j) {
				case 0: mul = 100; break;
				case 1: mul = 10; break;
				case 2: mul = 1; break;
			}
			int v = (b / mul) % 10;
			if (empty && !v) continue;
			empty = false;
			addr[cur++] = '0' + v;
		}
	}
	addr[cur++] = 0;

	return addr;
}

struct StdTcpSocket {
	#ifdef flagWIN32
	static WSADATA wsaData;
	static bool is_initialized;
	SOCKET sock = 0;
	
	struct Uninitializer {
		~Uninitializer() {WSACleanup();}
	};
	static Uninitializer uninit;
	
	#elif defined flagPOSIX
	int sock;
	
	#endif
	const char* last_error = 0;
	
	StdTcpSocket();
	~StdTcpSocket();
	bool Listen(int port, int max_conn, bool ip6, const char* addr);
	bool Accept(StdTcpSocket& sock);
	bool IsOpen();
	void Close();
	int Put(const void* data, int size);
	int Get(void* data, int size);
	bool Connect(const char* addr, int port);
	void Timeout(int ms);
	void GetPeerAddr(char* buf, int bufsize);
	const char* GetLastError();
	static StdTcpSocket* Create();
};

const char* StdTcpSocket::GetLastError() {return last_error;}



class StdWebSocketServer {
	struct connection_data {
	    int sessionid;
	};
	typedef websocketpp::connection_hdl connection_hdl;
	typedef websocketpp::server<websocketpp::config::asio> Server;
	typedef Server::message_ptr MessagePtr;
	typedef std::map<connection_hdl,connection_data,std::owner_less<connection_hdl>> con_list;
	
	Server server;
	con_list connections;
	int next_sessionid = 0;
	bool verbose = false;
	void (*fn)(void*, int, const char*, int);
	void *fn_arg;
	
	void on_open(websocketpp::connection_hdl conn);
	void on_close(websocketpp::connection_hdl conn);
	void on_message(websocketpp::connection_hdl conn, MessagePtr msg);
	connection_data& get_data_from_hdl(connection_hdl hdl);
	
public:
	StdWebSocketServer();
	
	void SetVerbose(bool b);
	void Run(int port);
	void StopListening();
	void Close();
	void SetMessageCallback(void (*fn)(void*, int, const char*, int), void* arg);
	
	static StdWebSocketServer* Create();
};

class StdWebSocketClient {
	typedef websocketpp::client<websocketpp::config::asio_client> Client;
	typedef websocketpp::config::asio_client::message_type::ptr MessagePtr;
	
	Client c;
	bool verbose = false;
	void (*fn)(void*, const char*, int);
	void *fn_arg;
	Client::connection_ptr con;
	
	void on_message(websocketpp::connection_hdl conn, MessagePtr msg);
	
public:
	StdWebSocketClient();
	
	void SetVerbose(bool b);
	void Run(const char* ws_url);
	void SetMessageCallback(void (*fn)(void*, const char*, int), void* arg);
	void Put(void* data, int data_len);
	void Close();
	
	static StdWebSocketClient* Create();
	
};



struct NetAddress {
	uint32	host;
	uint16	port;
};

#define THISPACKET		((ENetPacket*)this)
#define THISPEER		((ENetPeer*)this)
#define THISEVENT		((ENetEvent*)this)
#define THISHOST		((ENetHost*)this)


struct NetPacket {
	void Clear();
	void Append(void* data, int len);
	
	static NetPacket* Create(void* data, int len, bool is_reliable);
};


struct NetPeer {
	void Disconnect();
	void Reset();
	void*& GetDataRef();
	void SetData(dword d);
	void Send(int channel, NetPacket* packet);
	
	bool IsConnecting() const;
	bool IsConnected() const;
	bool IsDisconnected() const;
	dword GetData() const;
	int GetState() const;
	const char* GetAddr() const;
	int GetPort() const;
	
};


struct NetEvent {
	bool		IsConnected() const;
	bool		IsData() const;
	bool		IsDisconnected() const;
	int			GetEventType() const;
	const char*	GetPeerAddr() const;
	int			GetPeerPort() const;
	int			GetDataSize() const;
	const char*	GetData() const;
	const char*	GetDataString() const;
	int			GetChannel() const;
	NetPeer*	GetPeer() const;
};

struct NetHost {
	void Flush();
	void DisconnectPeers();
	void ResetPeers();
	void Destroy();
	NetPeer* Connect(const char* addr, int port, int channels, int timeout);
	int Poll(NetEvent* event, int timeout);
	void Broadcast(int channel, NetPacket* p);
	int GetPeerCount() const;
	NetPeer* Begin();
	NetPeer* End();
	
	static NetHost* Create(
		NetAddress* addr,
		int max_clients,
		int channels,
		int incoming_bandwidth,
		int outgoing_bandwidth);
	
};














#ifdef flagWIN32
WSADATA TcpSocket::wsaData;
bool TcpSocket::is_initialized;
TcpSocket::Uninitializer TcpSocket::uninit;


StdTcpSocket::StdTcpSocket() {
	if (!is_initialized) {
		int res = WSAStartup(MAKEWORD(2,2), &wsaData);
		if (res == 0)
			is_initialized = true;
	}
}

StdTcpSocket::~StdTcpSocket() {
	Close();
}

StdTcpSocket* StdTcpSocket::Create() {
	return new StdTcpSocket();
}

bool StdTcpSocket::Listen(int port, int max_conn, bool ip6, const char* addr) {
	Close();
	
	struct addrinfo hints;
	MemorySet(&hints, 0, sizeof(struct addrinfo));
	
	if (ip6) PANIC("TODO");
	hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    
    // Resolve the server address and port
    String portstr = IntStr(port);
	struct addrinfo *result = NULL;
    int iResult = getaddrinfo(NULL, portstr.Begin(), &hints, &result);
    if ( iResult != 0 ) {
        last_error = "Couldn't resolve the address";
        return false;
    }
    
    int addr_len = 0;
    if (addr) {
        addr_len = strlen(addr);
    }
    else {
        addr = result->ai_addr;
        addr_len = result->ai_addrlen;
    }
	
	// Create a SOCKET for connecting to server
    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == INVALID_SOCKET) {
        last_error = WSAGetLastError();
        freeaddrinfo(result);
        return false;
    }
    
	// Setup the TCP listening socket
    iResult = bind(sock, addr, addr_len);
    if (iResult == SOCKET_ERROR) {
        last_error = WSAGetLastError();
        freeaddrinfo(result);
        closesocket(sock);
        result = 0;
        return false;
    }
    
    freeaddrinfo(result);

    iResult = listen(sock, max_conn);
    if (iResult == SOCKET_ERROR) {
        last_error = WSAGetLastError();
        closesocket(sock);
        return false;
    }
    
    is_open = true;
    return true;
}

bool StdTcpSocket::Accept(StdTcpSocket& sock) {
	Close();
	
	this->sock = accept(sock.sock, NULL, NULL);
    if (this->sock == INVALID_SOCKET) {
        last_error = WSAGetLastError();
        return false;
    }
    
    is_open = true;
    return true;
}

bool StdTcpSocket::IsOpen() {
	return sock != 0 && is_open;
}

void StdTcpSocket::Close() {
	if (sock){
		shutdown(sock, SD_SEND);
		closesocket(sock);
		sock = 0;
		is_open = false;
	}
}

int StdTcpSocket::Put(const void* data, int size) {
	if (!IsOpen()) return 0;
	int sent = send(sock, (const char*)data, size, 0);
	if (sent != size) {
		Close();
	}
	return sent;
}

int StdTcpSocket::Get(void* data, int size) {
	if (!IsOpen()) return 0;
	int got = recv(sock, (char*)data, size, 0);
	if (got != size) {
		Close();
	}
	return got;
}

bool StdTcpSocket::Connect(const char* addr, int port) {
	Close();
	
	// Initialize Winsock
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

	struct addrinfo hints;
	MemorySet(&hints, 0, sizeof(struct addrinfo));
	
    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    String portstr = IntStr(port);
	struct addrinfo *result = NULL;
    iResult = getaddrinfo(addr.Begin(), portstr.Begin(), &hints, &result);
    if ( iResult != 0 ) {
        //printf("getaddrinfo failed with error: %d\n", iResult);
        return false;
    }
    for(struct addrinfo *ptr=result; ptr != NULL ;ptr=ptr->ai_next) {
	
	    sock = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
	    if (sock == INVALID_SOCKET) {
	        //printf("socket failed with error: %ld\n", WSAGetLastError());
	        continue;
	    }
	
	    // Connect to server.
	    iResult = connect(sock, ptr->ai_addr, (int)ptr->ai_addrlen);
	    if (iResult == SOCKET_ERROR) {
	        closesocket(sock);
	        sock = 0;
	        continue;
	    }
		
		is_open = true;
		freeaddrinfo(result);
		return true;
    }
    
    Close();
    freeaddrinfo(result);
    return false;
}

void StdTcpSocket::Timeout(int ms) {
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&ms, sizeof(int))
}

void StdTcpSocket::GetPeerAddr(char* buf, int bufsize) {
	if (!buf || bufsize <= 0) return;
	buf[0] = 0;
	if (!IsOpen()) return;
	sockaddr_in client_info = {0};
	int len = sizeof(client_info);
	getpeername(sock, (struct sockaddr*)&client_info, &len);
	inet_ntop(client_info.sin_family, (const void*)&client_info.sin_addr, buf, bufsize);
}

#elif defined flagPOSIX

StdTcpSocket::StdTcpSocket() {
	sock = -1;
}

StdTcpSocket::~StdTcpSocket() {
	Close();
}

bool StdTcpSocket::Listen(int port, int max_conn, bool ip6, const char* addr) {
	Close();
	
	if (ip6) PANIC("TODO");
	
    int addr_len = 0;
    if (addr) {
        addr_len = strlen(addr);
    }
    else {
        addr = "127.0.0.1";
        addr_len = 9;
    }
    
	sockaddr_in a;
	a.sin_family = AF_INET;
	a.sin_port = port;
	if (inet_aton(addr, &a.sin_addr) != 1) {
		last_error = "Address was not in valid IPv4 address format";
		return false;
	}
	
	sock = socket (a.sin_family, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1) {
	    last_error = "Socket creation error";
	    return false;
	}
	
	
	if (bind(sock, (const sockaddr*)&a, sizeof(a)) == -1) {
	    last_error = "Bind error";
	    close(sock);
	    return false;
	}
	
	if (listen(sock, 1/*length of connections queue*/) == -1) {
	    last_error = "Listen error";
	    close(sock);
	    return false;
	}
	
	return true;
}

bool StdTcpSocket::Accept(StdTcpSocket& s) {
	Close();
	if (s.sock < 0)
		return false;
	sock = accept(s.sock, 0, 0);
	if (sock == -1) {
	    last_error = "Accept error";
	    return false;
	}
	return true;
}

bool StdTcpSocket::IsOpen() {
	return sock != -1;
}

void StdTcpSocket::Close() {
	if (sock >= 0) {
		shutdown(sock, SHUT_RDWR);
		close(sock);
		sock = -1;
	}
}

int StdTcpSocket::Put(const void* data, int size) {
	if (sock == -1 || size <= 0)
		return 0;
	int sent = send(sock, data, size, 0);
	if (sent == -1) {
		last_error = "Send error";
		Close();
		return 0;
	}
	return sent;
}

int StdTcpSocket::Get(void* data, int size) {
	if (sock == -1 || size <= 0)
		return 0;
	int readlen = recv(sock, data, size, 0);
	if (readlen < 0) {
		last_error = "Receive error";
		Close();
		return 0;
	}
	return readlen;
}

bool StdTcpSocket::Connect(const char* addr, int port) {
	Close();
	
	if (!addr) return false;
	int addr_len = strlen(addr);
    if (!addr_len) return false;
    
	sock = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1) {
		last_error = "Socket creation error";
		return false;
	}
	
	if (connect(sock, (struct sockaddr*) addr, addr_len) == -1) {
		last_error = "Connection error";
		Close();
		return false;
	}
	
	return true;
}

void StdTcpSocket::Timeout(int ms) {
	if (sock != -1)
		setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&ms, sizeof(int));
}

void StdTcpSocket::GetPeerAddr(char* buf, int bufsize) {
	if (!buf || bufsize <= 0) return;
	buf[0] = 0;
	if (!IsOpen()) return;
	sockaddr_in client_info = {0};
	socklen_t len = sizeof(client_info);
	getpeername(sock, (struct sockaddr*)&client_info, &len);
	inet_ntop(client_info.sin_family, (const void*)&client_info.sin_addr, buf, bufsize);
}


#else

StdTcpSocket::StdTcpSocket() {
	
}

StdTcpSocket::~StdTcpSocket() {
	
}

bool StdTcpSocket::Listen(int port, int max_conn) {
	
}

bool StdTcpSocket::Accept(StdTcpSocket& sock) {
	
}

bool StdTcpSocket::IsOpen() {
	
}

void StdTcpSocket::Close() {
	
}

int StdTcpSocket::Put(const void* data, int size) {
	
}

int StdTcpSocket::Get(void* data, int size) {
	
}

bool StdTcpSocket::Connect(const char* addr, int port) {
	
}

void StdTcpSocket::Timeout(int ms) {
	
}

#endif





















using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;


StdWebSocketServer::StdWebSocketServer() {
	
    // Set logging settings
    server.set_access_channels(websocketpp::log::alevel::all);
    server.clear_access_channels(websocketpp::log::alevel::frame_payload);

    // Initialize Asio
    server.init_asio();
	
    server.set_open_handler(bind(&StdWebSocketServer::on_open, this, _1));
    server.set_close_handler(bind(&StdWebSocketServer::on_close, this, _1));
    server.set_message_handler(bind(&StdWebSocketServer::on_message, this, _1, _2));
}

void StdWebSocketServer::on_open(websocketpp::connection_hdl hdl) {
	connection_data data;
    data.sessionid = next_sessionid++;

	if (verbose)	std::cout	<< "Opening connection with sessionid " << data.sessionid << endl;
	
    connections[hdl] = data;
}

void StdWebSocketServer::on_close(websocketpp::connection_hdl hdl) {
	connection_data& data = get_data_from_hdl(hdl);
	
	if (verbose)	std::cout	<< "Closing connection with sessionid " << data.sessionid << endl;
	
	connections.erase(hdl);
}

void StdWebSocketServer::on_message(websocketpp::connection_hdl hdl, MessagePtr msg) {
	connection_data& data = get_data_from_hdl(hdl);
	
	std::string s = msg->get_payload();
	if (verbose)	std::cout	<< "Got a message from connection with sessionid " << data.sessionid << endl;
	
	if (fn)
		fn(fn_arg, data.sessionid, s.c_str(), s.size());
}

StdWebSocketServer::connection_data& StdWebSocketServer::get_data_from_hdl(connection_hdl hdl) {
	auto it = connections.find(hdl);
	
	if (it == connections.end()) {
		// this connection is not in the list. This really shouldn't happen
		// and probably means something else is wrong.
		throw std::invalid_argument("No data available for session");
	}
	
	return it->second;
}

void StdWebSocketServer::SetVerbose(bool b) {verbose = b;}

void StdWebSocketServer::Run(int port) {
	server.listen(port);
	server.start_accept();
	server.run();
}

void StdWebSocketServer::StopListening() {
	websocketpp::lib::error_code ec;
	server.stop_listening(ec);
}

void StdWebSocketServer::Close() {
	server.stop();
}

void StdWebSocketServer::SetMessageCallback(void (*fn)(void*, int, const char*, int), void* arg) {
	this->fn = fn;
	fn_arg = arg;
}

StdWebSocketServer* StdWebSocketServer::Create() {return new StdWebSocketServer();}









StdWebSocketClient::StdWebSocketClient() {
	// Set logging to be pretty verbose (everything except message payloads)
    c.set_access_channels(websocketpp::log::alevel::all);
    c.clear_access_channels(websocketpp::log::alevel::frame_payload);

    // Initialize ASIO
    c.init_asio();

    // Register our message handler
    c.set_message_handler(bind(&StdWebSocketClient::on_message, this, _1, _2));
}

void StdWebSocketClient::SetVerbose(bool b) {verbose = b;}

void StdWebSocketClient::Run(const char* ws_url) {
	if (!ws_url) return;
	try {
		std::string url = ws_url;
		websocketpp::lib::error_code ec;
		con = c.get_connection(url, ec);
		if (ec) {
			if (verbose)
				std::cout << "could not create connection because: " << ec.message() << endl;
			return;
		}
		
		// Note that connect here only requests a connection. No network messages are
        // exchanged until the event loop starts running in the next line.
        c.connect(con);

        // Start the ASIO io_service run loop
        // this will cause a single connection to be made to the server. c.run()
        // will exit when this connection is closed.
        c.run();
	}
	catch (websocketpp::exception const & e) {
		if (verbose)
			std::cout << e.what() << endl;
    }
}

void StdWebSocketClient::SetMessageCallback(void (*fn)(void*, const char*, int), void* arg) {
	this->fn = fn;
	fn_arg = arg;
}

void StdWebSocketClient::StdWebSocketClient::on_message(websocketpp::connection_hdl hdl, MessagePtr msg) {
	std::string s = msg->get_payload();
	if (verbose)
		std::cout	<< "Got a message (size " << s.size() << ")" << endl;
	
	if (fn) {
		fn(fn_arg, s.c_str(), s.size());
	}
}


void StdWebSocketClient::Put(void* data, int data_len) {
	c.send(con->get_handle(), data, data_len, websocketpp::frame::opcode::binary);
}

void StdWebSocketClient::Close() {
	c.stop();
}


StdWebSocketClient* StdWebSocketClient::Create() {return new StdWebSocketClient();}















void NetInitialize() {
	enet_initialize();
}

void NetDeinitialize() {
	enet_deinitialize();
}








void NetPacket::Clear() {
	enet_packet_destroy(THISPACKET);
}

NetPacket* NetPacket::Create(void* data, int len, bool is_reliable) {
	return (NetPacket*)enet_packet_create(data, len, is_reliable);
}

void NetPacket::Append(void* data, int len) {
	int begin = THISPACKET->dataLength;
	int new_len = begin + len;
	enet_packet_resize(THISPACKET, new_len);
	memcpy(&THISPACKET->data[begin], data, len);
}









inline dword& GetDwordRef(void*& ptr) {return *((dword*)&ptr);}

void NetPeer::Disconnect() {
	enet_peer_disconnect(THISPEER, 0);
}

void NetPeer::Reset() {
	enet_peer_reset(THISPEER);
}

void*& NetPeer::GetDataRef() {
	return THISPEER->data;
}

void NetPeer::SetData(dword d) {
	GetDwordRef(THISPEER->data) = d;
}

void NetPeer::Send(int channel, NetPacket* packet) {
	enet_peer_send(THISPEER, 0, (ENetPacket*)packet);
}


bool NetPeer::IsConnecting() const {
	return THISPEER->state == ENET_PEER_STATE_CONNECTING;
}

bool NetPeer::IsConnected() const {
	return	THISPEER->state == ENET_PEER_STATE_CONNECTION_SUCCEEDED ||
			THISPEER->state == ENET_PEER_STATE_CONNECTED;
}

bool NetPeer::IsDisconnected() const {
	return THISPEER->state == ENET_PEER_STATE_DISCONNECTED;
}

dword NetPeer::GetData() const {
	return GetDwordRef(THISPEER->data);
}

int NetPeer::GetState() const {
	return THISPEER->state;
}

const char* NetPeer::GetAddr() const {
	return GetIpStringFromDword(THISPEER->address.host);
}

int NetPeer::GetPort() const {
	return THISPEER->address.port;
}

















bool NetEvent::IsConnected() const {
	return THISEVENT->type == ENET_EVENT_TYPE_CONNECT;
}

bool NetEvent::IsData() const {
	return THISEVENT->type == ENET_EVENT_TYPE_RECEIVE;
}

bool NetEvent::IsDisconnected() const {
	return THISEVENT->type == ENET_EVENT_TYPE_DISCONNECT;
}

int NetEvent::GetEventType() const {
	return THISEVENT->type;
}

const char* NetEvent::GetPeerAddr() const {
	return GetIpStringFromDword(THISEVENT->peer -> address.host);
}

int NetEvent::GetPeerPort() const {
	return THISEVENT->peer -> address.port;
}

int NetEvent::GetDataSize() const {
	return (int)THISEVENT->packet -> dataLength;
}

const char* NetEvent::GetData() const {
	return (const char*)THISEVENT->packet->data;
}

const char* NetEvent::GetDataString() const {
	return (const char*)THISEVENT->packet->data;
}

int NetEvent::GetChannel() const {
	return THISEVENT->channelID;
}

NetPeer* NetEvent::GetPeer() const {
	return (NetPeer*)THISEVENT->peer;
}


















void NetHost::Flush() {
	enet_host_flush(THISHOST);
}

void NetHost::DisconnectPeers() {
	ENetPeer* it = THISHOST->peers;
	ENetPeer* end = THISHOST->peers + THISHOST->peerCount;
	while (it != end) {
		if (it->state == ENET_PEER_STATE_CONNECTED)
			enet_peer_disconnect(it, 0);
		it++;
	}
}

void NetHost::ResetPeers() {
	ENetPeer* it = THISHOST->peers;
	ENetPeer* end = THISHOST->peers + THISHOST->peerCount;
	while (it != end) {
		if (it->state != ENET_PEER_STATE_DISCONNECTED)
			enet_peer_reset(it);
		it++;
	}
}

void NetHost::Destroy() {
	enet_host_destroy(THISHOST);
}

NetPeer* NetHost::Connect(const char* addr, int port, int channels, int timeout) {
	if (!addr || !port || channels <= 0)
		return 0;
	int addrlen = strnlen(addr, 512);
	if (!addrlen || addrlen >= 512)
		return 0;
	
	ENetAddress address;
	enet_address_set_host(&address, addr);
	address.port = port;
	
	ENetPeer* peer = enet_host_connect(THISHOST, &address, channels, 0);
	if (!peer)
		return 0;
	
	ENetPacket* packet = enet_packet_create("", 0, 1);
	ASSERT(packet);
	enet_peer_send(peer, 0, packet);
	
	::Native::HighResTimePoint ts;
	while (ts.Elapsed() < timeout) {
		if (peer->state == ENET_PEER_STATE_CONNECTION_SUCCEEDED ||
			peer->state == ENET_PEER_STATE_CONNECTED)
			break;
		Concurrency::Native::Sleep(1);
	}
	return (NetPeer*)peer;
}

int NetHost::Poll(NetEvent* event, int timeout) {
	return enet_host_service(THISHOST, (ENetEvent*)event, timeout);
}

void NetHost::Broadcast(int channel, NetPacket* p) {
	enet_host_broadcast(THISHOST, channel, (ENetPacket*)p);
}

int NetHost::GetPeerCount() const {
	return THISHOST->connectedPeers;
}

NetPeer* NetHost::Begin() {
	return (NetPeer*)THISHOST->peers;
}

NetPeer* NetHost::End() {
	return (NetPeer*)THISHOST->peers + THISHOST->peerCount;
}


NetHost* NetHost::Create(
	NetAddress* addr,
	int max_clients,
	int channels,
	int incoming_bandwidth,
	int outgoing_bandwidth) {
	return (NetHost*)enet_host_create(
		(ENetAddress*)addr,
		max_clients,
		channels,
		incoming_bandwidth,
		outgoing_bandwidth);
}




}
