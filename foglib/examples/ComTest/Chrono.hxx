#ifndef CHRONO_HXX
#define CHRONO_HXX

#include <new>

#ifndef MATH_HXX
#include <Math.hxx>
#endif
#ifndef NATIVE_HXX
#include <Native.hxx>
#endif

namespace Chrono
{
};

namespace Chrono {
class Time;
}

namespace Chrono
{
#line 52 "../../src/Com/Chrono.fog"
    inline Time operator+ (const Time& t, Lang::int64 seconds);
#line 272
    Text::String GetTimeDurationString(Time begin, Time end);
    
    class Date
    {
    protected:
#line 8
        short year;
        Lang::byte month;
#line 9
        Lang::byte day;
        
    public:
        inline Date();
#line 17
        bool operator== (const Date& d) const;
#line 132
        Lang::int64 Get() const;
#line 15
        void Set(Lang::int64 scalar);
#line 147
        void Set(int d);
#line 141
        void Set(int y, int m, int d);
        
    public:
#line 113
        static const int *DaysInMonth();
#line 127
        static int GetDaysOfMonth(int m, int y);
#line 123
        static bool IsLeapYear(int year);
#line 118
        static const int *MonthDayOffset();
    };
    
    class Time : public Chrono::Date
    {
#line 27
        Lang::byte hour;
#line 27
        Lang::byte min;
#line 27
        Lang::byte sec;
        
    public:
        inline Time();
        inline Time(const Time& t);
        inline Time(int y, int m, int d);
        inline Time(int y, int m, int d, int h, int min, int s);
#line 43
        bool operator== (const Time& t) const;
#line 228
        Text::String AsDiffString() const;
#line 211
        Text::String AsString() const;
#line 39
        Lang::int64 Get() const;
        Lang::uint32 GetHashValue();
#line 267
        int GetStamp() const;
#line 201
        void Set(Lang::int64 scalar);
#line 194
        void Set(int y, int mon, int d, int h, int m, int s);
#line 262
        void SetFromStamp(int seconds);
        
    public:
#line 256
        static Time GetSys();
    };
    
    class TimeStop
    {
#line 59
        Native::HighResTimePoint *tp;
        
    public:
        TimeStop();
        inline ~TimeStop();
#line 66
        inline int Elapsed() const;
        inline double ElapsedSeconds() const;
#line 65
        inline void Reset();
#line 68
        inline int ResetElapsed();
        inline double ResetElapsedSeconds();
    };
    
    struct OnlineFrequency
    {
        TimeStop timer;
        int ticks;
        
        inline OnlineFrequency();
#line 83
        inline double operator++ ();
#line 82
        inline operator double() const;
#line 79
        double Get() const;
#line 78
        inline void Reset();
#line 80
        inline void Tick();
    };
    
    struct OnlineFrequencyWindow
    {
#line 87
        OnlineFrequency freq0;
#line 87
        OnlineFrequency freq1;
        bool which;
        double interval;
        
        OnlineFrequencyWindow();
#line 98
        inline double operator++ ();
#line 97
        inline operator double() const;
#line 306
        double Get() const;
#line 287
        OnlineFrequency& GetActive();
#line 292
        OnlineFrequency& GetInactive();
#line 94
        inline void SwitchActive();
#line 297
        void Tick();
    };
};

namespace Chrono
{
#line 52
    inline Time operator+ (const Time& t, Lang::int64 seconds)
    {
#line 53
        Time o;
        o.Set(t.Get() + seconds);
        return o;
    };
    
#line 12
    inline Date::Date() {};
    
#line 77
    inline OnlineFrequency::OnlineFrequency()
    :
        ticks(0)
    {};
    
#line 83
    inline double OnlineFrequency::operator++ ()
    {
#line 83
        Tick();
#line 83
        return Get();
    };
    
#line 82
    inline OnlineFrequency::operator double() const
    {
#line 82
        return Get();
    };
    
#line 78
    inline void OnlineFrequency::Reset()
    {
#line 78
        timer.Reset();
#line 78
        ticks = 0;
    };
    
#line 80
    inline void OnlineFrequency::Tick()
    {
#line 80
        ticks ++ ;
    };
    
#line 98
    inline double OnlineFrequencyWindow::operator++ ()
    {
#line 98
        Tick();
#line 98
        return Get();
    };
    
#line 97
    inline OnlineFrequencyWindow::operator double() const
    {
#line 97
        return Get();
    };
    
#line 94
    inline void OnlineFrequencyWindow::SwitchActive()
    {
#line 94
        which = !which;
    };
    
#line 30
    inline Time::Time() {};
    
#line 31
    inline Time::Time(const Time& t)
    {
#line 31
        Lang::Memory::Copy(this, &t, sizeof (Time));
    };
    
#line 32
    inline Time::Time(int y, int m, int d)
    {
#line 32
        Set(y, m, d, 0, 0, 0);
    };
    
#line 33
    inline Time::Time(int y, int m, int d, int h, int min, int s)
    {
#line 33
        Set(y, m, d, h, min, s);
    };
    
#line 63
    inline TimeStop::~TimeStop()
    {
#line 63
        delete tp;
#line 63
        tp = 0;
    };
    
    inline int TimeStop::Elapsed() const
    {
#line 66
        return tp -> Elapsed();
    };
    
#line 67
    inline double TimeStop::ElapsedSeconds() const
    {
#line 67
        return tp -> ElapsedSeconds();
    };
    
#line 65
    inline void TimeStop::Reset()
    {
#line 65
        tp -> Reset();
    };
    
    inline int TimeStop::ResetElapsed()
    {
#line 68
        return tp -> ResetElapsed();
    };
    
#line 69
    inline double TimeStop::ResetElapsedSeconds()
    {
#line 69
        return tp -> ResetElapsedSeconds();
    };
    
};

#endif
