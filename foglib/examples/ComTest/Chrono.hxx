#ifndef CHRONO_HXX
#define CHRONO_HXX

#include <new>

#ifndef LANG_HXX
#include <Lang.hxx>
#endif

namespace {
namespace Text;
}

namespace Chrono
{
};

namespace Chrono {
class Time;
}

namespace Chrono
{
#line 39 "../../src/Com/Chrono.fog"
    inline Time operator+ (const Time& t, Lang::int64 seconds);
    
    class Date
    {
#line 4
        Lang::byte year;
#line 4
        Lang::byte month;
#line 4
        Lang::byte day;
        
    public:
        inline Date();
#line 9
        void Set(int y, int m, int d);
    };
    
    class Time : public Chrono::Date
    {
#line 17
        Lang::byte hour;
#line 17
        Lang::byte min;
#line 17
        Lang::byte sec;
        
    public:
        inline Time();
        inline Time(const Time& t);
        inline Time(int y, int m, int d);
        inline Time(int y, int m, int d, int h, int min, int s);
        Text::String AsString() const;
#line 33
        inline Lang::int64 Get() const;
#line 35
        Lang::uint32 GetHashValue();
#line 56
        void Set(Lang::int64 scalar);
#line 26
        void Set(int y, int m, int d, int h, int min, int s);
    };
};

namespace Chrono
{
#line 39
    inline Time operator+ (const Time& t, Lang::int64 seconds)
    {
#line 40
        Time o;
        o.Set(t.Get() + seconds);
        return o;
    };
    
#line 7
    inline Date::Date() {};
    
#line 20
    inline Time::Time() {};
    
#line 21
    inline Time::Time(const Time& t)
    {
#line 21
        Lang::Memory::Copy(this, &t, sizeof (Time));
    };
    
#line 22
    inline Time::Time(int y, int m, int d)
    {
#line 22
        Set(y, m, d, 0, 0, 0);
    };
    
#line 23
    inline Time::Time(int y, int m, int d, int h, int min, int s)
    {
#line 23
        Set(y, m, d, h, min, s);
    };
    
#line 33
    inline Lang::int64 Time::Get() const
    {
#line 33
        return Native::Native::TimeSeconds(year, month, day, hour, min, sec);
    };
    
};

#endif
