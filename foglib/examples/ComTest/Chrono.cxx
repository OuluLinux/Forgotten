#ifndef CHRONO_CXX
#define CHRONO_CXX

#include <new>

#ifndef CHRONO_HXX
#include <Chrono.hxx>
#endif

namespace Chrono
{
#line 9 "../../src/Com/Chrono.fog"
    void Date::Set(int y, int m, int d)
    {
#line 10
        year = y;
        month = m;
        day = d;
    };
    
#line 35
    Lang::uint32 Time::GetHashValue()
    {
#line 35
        return sec + 32 * (min + 32 * (hour + 16 * (day + 32 * (month + 8 * year))));
    };
    
#line 56
    void Time::Set(Lang::int64 scalar)
    {
#line 57
        int q = (int)(scalar / (24 * 3600));
        Date::Set(q);
        int n = int(scalar - (Lang::int64) q * 24 * 3600);
        hour = n / 3600;
        n %= 3600;
        minute = n / 60;
        second = n % 60;
    };
    
#line 26
    void Time::Set(int y, int m, int d, int h, int min, int s)
    {
#line 27
        Date::Set(y, m, d);
        hour = h;
        this -> min = min;
        sec = s;
    };
    
};

#endif
