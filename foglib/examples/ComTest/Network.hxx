#ifndef NETWORK_HXX
#define NETWORK_HXX

#include <new>

#ifndef CONCURRENCY_HXX
#include <Concurrency.hxx>
#endif

namespace Network
{
    namespace Native
    {
        struct StdTcpSocket
        {
#line 7 "../../src/Com/Network.fog"
            StdTcpSocket();
            ~StdTcpSocket();
#line 11
            bool Accept(StdTcpSocket& sock);
#line 13
            void Close();
#line 16
            bool Connect(const char *addr, int port);
#line 15
            int Get(void *data, int size);
#line 19
            const char *GetLastError();
#line 18
            void GetPeerAddr(char *buf, int bufsize);
#line 12
            bool IsOpen();
#line 9
            bool Listen(int port, int max_conn, bool ip6, const char *addr);
#line 14
            int Put(const void *data, int size);
#line 17
            void Timeout(int ms);
            
#line 20
            static StdTcpSocket *Create();
        };
    };
    
    class TcpSocket
    {
#line 27
        typedef Native::StdTcpSocket Std;
        
#line 28
        Container::One < Std > s;
        
    public:
        inline TcpSocket();
        inline ~TcpSocket();
#line 35
        inline bool Accept(TcpSocket& sock);
#line 37
        inline void Close();
#line 44
        bool Connect(Text::String addr, int port);
#line 48
        Text::String Get(int size);
#line 42
        inline int Get(void *data, int size);
#line 38
        Text::String GetLine(int max_len = 65535);
        Text::String GetPeerAddr();
#line 36
        inline bool IsOpen();
#line 34
        inline bool Listen(int port, int max_conn, bool ip6 = false, const char *addr = "127.0.0.1");
#line 40
        int Put(Text::String str);
        inline int Put(const void *data, int size);
#line 45
        inline void Timeout(int ms);
    };
};

namespace Network
{
#line 31
    inline TcpSocket::TcpSocket()
    {
#line 31
        s.Create();
    };
    
#line 32
    inline TcpSocket::~TcpSocket() {};
    
#line 35
    inline bool TcpSocket::Accept(TcpSocket& sock)
    {
#line 35
        return s -> Accept(*sock.s);
    };
    
#line 37
    inline void TcpSocket::Close()
    {
#line 37
        s -> Close();
    };
    
#line 42
    inline int TcpSocket::Get(void *data, int size)
    {
#line 42
        return s -> Get(data, size);
    };
    
#line 36
    inline bool TcpSocket::IsOpen()
    {
#line 36
        return s -> IsOpen();
    };
    
#line 34
    inline bool TcpSocket::Listen(int port, int max_conn, bool ip6, const char *addr)
    {
#line 34
        return s -> Listen(port, max_conn, ip6, addr);
    };
    
#line 41
    inline int TcpSocket::Put(const void *data, int size)
    {
#line 41
        return s -> Put(data, size);
    };
    
#line 45
    inline void TcpSocket::Timeout(int ms)
    {
#line 45
        s -> Timeout(ms);
    };
    
};

#endif
