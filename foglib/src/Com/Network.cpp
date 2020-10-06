#include "Com.h"

namespace Network::Native {


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

}
