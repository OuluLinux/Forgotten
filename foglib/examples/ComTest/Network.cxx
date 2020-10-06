#ifndef NETWORK_CXX
#define NETWORK_CXX

#include <new>

#ifndef NETWORK_HXX
#include <Network.hxx>
#endif

namespace Network
{
#line 44 "../../src/Com/Network.fog"
    bool TcpSocket::Connect(Text::String addr, int port)
    {
#line 44
        return s -> Connect(addr.Begin(), port);
    };
    
#line 48
    Text::String TcpSocket::Get(int size)
    {
#line 49
        Container::Vector < char > buf;
        buf.SetCount(size);
        int got = Get(buf.Begin(), size);
        buf.SetCount(got);
        return Text::String(buf.Begin(), got);
    };
    
#line 38
    Text::String TcpSocket::GetLine(int max_len)
    {
#line 57
        if (!IsOpen())
            return "";
#line 60
        Text::String out;
        while (out.GetCount() < max_len)
            {
#line 62
                char chr;
                int received = Get(&chr, 1);
                if (!received)
                {
#line 65
                    Close();
                    break;
                
                }
#line 68
                if (chr == '\n')
                    break;
                
#line 70
                out.Cat(chr);
            }
        return out;
    };
    
#line 39
    Text::String TcpSocket::GetPeerAddr()
    {
#line 39
        char b[1024];
#line 39
        s -> GetPeerAddr(b, 1024);
#line 39
        return b;
    };
    
#line 40
    int TcpSocket::Put(Text::String str)
    {
#line 40
        return Put((void * ) str.Begin(), str.GetCount());
    };
    
};

#endif
