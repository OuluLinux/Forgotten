#ifndef CHRONO_CXX
#define CHRONO_CXX

#include <new>

#ifndef CHRONO_HXX
#include <Chrono.hxx>
#endif

namespace Chrono
{
#line 282 "../../src/Com/Chrono.fog"
    Text::String GetTimeDurationString(Time begin, Time end)
    {
#line 283
        Lang::int64 diff = end.Get() - begin.Get();
        Time t;
        t.Set(diff);
        return t.AsDiffString();
    };
    
#line 17
    bool Date::operator== (const Date& d) const
    {
#line 17
        return year == d.year && month == d.month && day == d.day;
    };
    
#line 123
    const int *Date::DaysInMonth()
    {
#line 124
        static int month_days[] = 
        {
            31,
            28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31
        };
#line 125
        return month_days;
    };
    
#line 142
    Lang::int64 Date::Get() const
    {
#line 143
        Lang::int64 y400 = (year / 400) - 2;
        Lang::int64 ym = year - y400 * 400;
        return y400 * (400 * 365 + 100 - 3) + ym * 365 + MonthDayOffset()[month - 1] + (day - 1) + (ym - 1) / 4 - (ym - 1) / 100 + (ym - 1) / 400 + 1 + (month > 2) * IsLeapYear(ym);
    };
    
#line 137
    int Date::GetDaysOfMonth(int m, int y)
    {
        {
#line 138
            if (!(m >= 1 && m <= 12))
            {
#line 138
                Lang::SysBreak("Assertion failed: m >= 1 && m <= 12");
            }
        }
#line 139
        ;
#line 139
        return DaysInMonth()[m - 1] + (m == 2) * IsLeapYear(y);
    };
    
#line 133
    bool Date::IsLeapYear(int year)
    {
#line 134
        return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    };
    
#line 128
    const int *Date::MonthDayOffset()
    {
#line 129
        static int month_off[] = 
        {
            0,
            31,
            59,
            90,
            120,
            151,
            181,
            212,
            243,
            273,
            304,
            334
        };
#line 130
        return month_off;
    };
    
#line 157
    void Date::Set(int d)
    {
#line 158
        if (d == 0)
        {
#line 159
            day = 0;
#line 159
            month = 0;
#line 159
            year = 0;
            return;
        }
        int q;
        int leap;
        year = 0;
        q = d / (400 * 365 + 100 - 3);
        year += 400 * q;
        d -= q * (400 * 365 + 100 - 3);
        if (d < 0)
        {
#line 169
            year -= 400;
            d += 400 * 365 + 100 - 3;
        }
        leap = 1;
        if (d >= 100 * 365 + 24 + 1)
        {
#line 174
            d -- ;
            q = d / (100 * 365 + 24);
            year += 100 * q;
            d -= q * (100 * 365 + 24);
            leap = 0;
        }
        if (d >= 365 * 4 + leap)
        {
#line 181
            q = (d + 1 - leap) / (365 * 4 + 1);
            year += 4 * q;
            d -= q * (365 * 4 + 1) - 1 + leap;
            leap = 1;
        }
        if (d >= 365 + leap)
        {
#line 187
            q = (d - leap) / 365;
            year += q;
            d -= q * 365 + leap;
            leap = 0;
        }
        int i;
        const int * s_month = DaysInMonth();
        for (i = 0; i < 12; i ++ )
            {
#line 195
                int q = s_month[i] + (i == 1) * leap;
                if (q > d)
#line 196
                    break;
                
#line 197
                d -= q;
            }
        month = i + 1;
        day = d + 1;
    };
    
#line 151
    void Date::Set(int y, int m, int d)
    {
#line 152
        year = y;
        month = m;
        day = d;
    };
    
#line 89
    double OnlineFrequency::Get() const
    {
#line 89
        return(double) ticks / timer.Elapsed() * 1000;
    };
    
#line 101
    OnlineFrequencyWindow::OnlineFrequencyWindow()
    :
        which(0),
        interval(0.5)
    {};
    
#line 316
    double OnlineFrequencyWindow::Get() const
    {
#line 317
        if (which)
#line 317
            return freq1.Get();
        else
#line 318
            return freq0.Get();
    };
    
#line 297
    OnlineFrequency& OnlineFrequencyWindow::GetActive()
    {
#line 298
        if (which)
#line 298
            return freq1;
        else
#line 299
            return freq0;
    };
    
    OnlineFrequency& OnlineFrequencyWindow::GetInactive()
    {
#line 303
        if (which)
#line 303
            return freq0;
        else
#line 304
            return freq1;
    };
    
    void OnlineFrequencyWindow::Tick()
    {
#line 308
        freq0.Tick();
        freq1.Tick();
        if (GetInactive().timer.Elapsed() >= interval)
        {
#line 311
            SwitchActive();
            GetActive().Reset();
        }
    };
    
#line 43
    bool Time::operator== (const Time& t) const
    {
#line 43
        return hour == t.hour && min == t.min && sec == t.sec;
    };
    
#line 238
    Text::String Time::AsDiffString() const
    {
#line 239
        Text::String out;
        Lang::int64 seconds = Get();
#line 242
        if (seconds > - 60 && seconds < 60)
#line 242
            return "Now";
#line 244
        if (seconds < 0)
        {
#line 244
            out += "-";
#line 244
            seconds *= - 1;
        }
        else 
#line 245
        if (seconds > 0)
#line 245
            out += "+";
#line 247
        Lang::int64 years;
        Lang::int64 months;
        Lang::int64 days;
        Lang::int64 hours;
        Lang::int64 minutes;
#line 253
#line 235
        years = seconds / (31536000);
#line 235
        seconds = seconds % (31536000);;
#line 254
#line 235
        months = seconds / (2592000);
#line 235
        seconds = seconds % (2592000);;
#line 255
#line 235
        days = seconds / (86400);
#line 235
        seconds = seconds % (86400);;
#line 256
#line 235
        hours = seconds / (3600);
#line 235
        seconds = seconds % (3600);;
#line 257
#line 235
        minutes = seconds / (60);
#line 235
        seconds = seconds % (60);;
#line 258
#line 236
        if (years)
        {
#line 236
            out.Cat(' ');
#line 236
            out += Text::String::IntStr64(years) + " " + "years";
        }
#line 236
        ;;
#line 259
#line 236
        if (months)
        {
#line 236
            out.Cat(' ');
#line 236
            out += Text::String::IntStr64(months) + " " + "months";
        }
#line 236
        ;;
#line 260
#line 236
        if (days)
        {
#line 236
            out.Cat(' ');
#line 236
            out += Text::String::IntStr64(days) + " " + "days";
        }
#line 236
        ;;
#line 261
#line 236
        if (hours)
        {
#line 236
            out.Cat(' ');
#line 236
            out += Text::String::IntStr64(hours) + " " + "hours";
        }
#line 236
        ;;
#line 262
#line 236
        if (minutes)
        {
#line 236
            out.Cat(' ');
#line 236
            out += Text::String::IntStr64(minutes) + " " + "minutes";
        }
#line 236
        ;;
#line 263
        return out;
    };
    
#line 221
    Text::String Time::AsString() const
    {
#line 222
        char m[3];
        m[0] = '0' + min / 10;
        m[1] = '0' + min / 10;
        m[2] = 0;
        char s[3];
        s[0] = '0' + sec / 10;
        s[1] = '0' + sec / 10;
        s[2] = 0;
        return Text::String::IntStr(day) + "." + Text::String::IntStr(month) + "." + Text::String::IntStr(day) + " " + Text::String::IntStr(hour) + ":" + Text::String(m) + ":" + Text::String(s);
    };
    
#line 39
    Lang::int64 Time::Get() const
    {
#line 39
        return Date::Get() * (Lang::int64)24 * 3600 + hour * 3600 + min * 60 + sec;
    };
    
#line 40
    Lang::uint32 Time::GetHashValue()
    {
#line 40
        return sec + 32 * (min + 32 * (hour + 16 * (day + 32 * (month + 8 * year))));
    };
    
#line 277
    int Time::GetStamp() const
    {
#line 278
        static Lang::int64 begin = Time(1970, 1, 1).Get();
        return Get() - begin;
    };
    
#line 266
    Time Time::GetSys()
    {
#line 267
        Time t;
        t.Set(Native::CurrentTime());
        return t;
    };
    
#line 211
    void Time::Set(Lang::int64 scalar)
    {
#line 212
        int q = (int)(scalar / (24 * 3600));
        Date::Set(q);
        int n = int(scalar - (Lang::int64) q * 24 * 3600);
        hour = n / 3600;
        n %= 3600;
        min = n / 60;
        sec = n % 60;
    };
    
#line 204
    void Time::Set(int y, int mon, int d, int h, int m, int s)
    {
#line 205
        Date::Set(y, mon, d);
        hour = h;
        min = m;
        sec = s;
    };
    
#line 272
    void Time::SetFromStamp(int seconds)
    {
#line 273
        static Lang::int64 begin = Time(1970, 1, 1).Get();
        Set(begin + (Lang::int64) seconds);
    };
    
#line 62
    TimeStop::TimeStop()
    :
        tp(0)
    {
#line 62
        tp = Native::HighResTimePoint::Create();
    };
    
#line 70
    Text::String TimeStop::AsString() const
    {
#line 71
        double d = ElapsedSeconds();
        int sec = d;
        int ms = (d - (double) sec) * 1000;
        Text::String s;
        if (!sec && !ms)
#line 75
            return "0 ms";
        if (sec)
        {
#line 76
            s << Text::String::IntStr(sec) << " seconds";
        }
#line 77
        if (ms)
        {
#line 77
            if (sec)
            {
#line 77
                s.Cat(' ');
            }
#line 77
            s << Text::String::IntStr(ms) << " ms";
        }
#line 78
        return s;
    };
    
};

#endif
