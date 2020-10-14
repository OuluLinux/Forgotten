#include "Com.h"
#include <plugin/enet/enet.h>
#include <plugin/websocketpp/config/asio_no_tls.hpp>
#include <plugin/websocketpp/server.hpp>

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


/*using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;*/

struct StdWebSocketServer {
	typedef websocketpp::server<websocketpp::config::asio>::message_ptr message_ptr;
	
	websocketpp::server<websocketpp::config::asio> server;
	
	
	StdWebSocketServer();
	void Clear();
	void Close();
	bool Listen(int port);
	bool IsOpen() const;
	int Put(const void* data, int size);
	int Get(void* data, int size);
	const char* GetPeerAddr() const;
	void Timeout(int ms);
	
};

struct StdWebSocketClient {
	
	void Clear();
	void Close();
	bool Accept(StdWebSocketServer& server);
	bool IsOpen() const;
	int Put(const void* data, int size);
	int Get(void* data, int size);
	const char* GetPeerAddr() const;
	bool Connect(const char* addr, int port);
	void Timeout(int ms);
	
};

struct StdWebSocket {
	StdWebSocketServer server;
	StdWebSocketClient client;
	bool is_server = false;
	
	bool IsServer() const {return is_server;}
	void SwitchServer() {if (!is_server) {client.Clear(); is_server = true;}}
	void SwitchClient() {if (is_server) {server.Clear(); is_server = false;}}
	
	
	bool Listen(int port);
	bool Accept(StdWebSocket& sock);
	bool IsOpen();
	void Close();
	const char* GetLine(int max_len);
	const char* GetPeerAddr() const;
	int Put(const void* data, int size);
	int Get(void* data, int size);
	const char* Get(int size);
	bool Connect(const char* addr, int port);
	void Timeout(int ms);
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














bool StdWebSocket::Listen(int port) {
	SwitchServer();
	return server.Listen(port);
}

bool StdWebSocket::Accept(StdWebSocket& sock) {
	SwitchClient();
	ASSERT(sock.IsServer());
	return client.Accept(sock.server);
}

bool StdWebSocket::IsOpen() {
	if (is_server)
		return server.IsOpen();
	else
		return client.IsOpen();
}

void StdWebSocket::Close() {
	if (is_server)
		server.Close();
	else
		client.Close();
}

const char* StdWebSocket::GetLine(int max_len) {
	static thread_local std::string s;
	s.clear();
	if (is_server) {
		for(int i = 0; i < max_len; i++) {
			char c;
			if (!server.Get(&c, 1)) break;
			s.append(1, c);
		}
	}
	else {
		for(int i = 0; i < max_len; i++) {
			char c;
			if (!client.Get(&c, 1)) break;
			s.append(1, c);
		}
	}
	return s.c_str();
}

const char* StdWebSocket::GetPeerAddr() const {
	if (is_server)
		return server.GetPeerAddr();
	else
		return client.GetPeerAddr();
}

int StdWebSocket::Put(const void* data, int size) {
	if (is_server)
		return server.Put(data, size);
	else
		return client.Put(data, size);
}

int StdWebSocket::Get(void* data, int size) {
	if (is_server)
		return server.Get(data, size);
	else
		return client.Get(data, size);
}

const char* StdWebSocket::Get(int size) {
	if (size <= 0) return 0;
	if (size > UINT16_MAX) size = UINT16_MAX;
	
	static thread_local std::vector<char> v;
	v.resize(size);
	Get(v.data(), size);
	return v.data();
}

bool StdWebSocket::Connect(const char* addr, int port) {
	SwitchClient();
	return client.Connect(addr, port);
}

void StdWebSocket::Timeout(int ms) {
	if (is_server)
		server.Timeout(ms);
	else
		client.Timeout(ms);
}











StdWebSocketServer::StdWebSocketServer() {
	
    // Set logging settings
    server.set_access_channels(websocketpp::log::alevel::all);
    server.clear_access_channels(websocketpp::log::alevel::frame_payload);

    // Initialize Asio
    server.init_asio();
	
}

void StdWebSocketServer::Clear() {
	
}

void StdWebSocketServer::Close() {
	
}

bool StdWebSocketServer::Listen(int port) {
	server.listen(port);
}

bool StdWebSocketServer::IsOpen() const {
	
}

int StdWebSocketServer::Put(const void* data, int size) {
	
}

int StdWebSocketServer::Get(void* data, int size) {
	
}

const char* StdWebSocketServer::GetPeerAddr() const {
	
}

void StdWebSocketServer::Timeout(int ms) {
	
}









void StdWebSocketClient::Clear() {
	
}

void StdWebSocketClient::Close() {
	
}

bool StdWebSocketClient::Accept(StdWebSocketServer& server) {
	
}

bool StdWebSocketClient::IsOpen() const {
	
}

int StdWebSocketClient::Put(const void* data, int size) {
	
}

int StdWebSocketClient::Get(void* data, int size) {
	
}

const char* StdWebSocketClient::GetPeerAddr() const {
	
}

bool StdWebSocketClient::Connect(const char* addr, int port) {
	
}

void StdWebSocketClient::Timeout(int ms) {
	
}














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
