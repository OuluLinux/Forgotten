#ifndef CHRONO_CXX
#define CHRONO_CXX

#include <new>

#ifndef CHRONO_HXX
#include <Chrono.hxx>
#endif

namespace Chrono
{
#line 272 "../../src/Com/Chrono.fog"
    Text::String GetTimeDurationString(Time begin, Time end)
    {
#line 273
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
    
#line 113
    const int *Date::DaysInMonth()
    {
#line 114
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
#line 115
        return month_days;
    };
    
#line 132
    Lang::int64 Date::Get() const
    {
#line 133
        Lang::int64 y400 = (year / 400) - 2;
        Lang::int64 ym = year - y400 * 400;
        return y400 * (400 * 365 + 100 - 3) + ym * 365 + MonthDayOffset()[month - 1] + (day - 1) + (ym - 1) / 4 - (ym - 1) / 100 + (ym - 1) / 400 + 1 + (month > 2) * IsLeapYear(ym);
    };
    
#line 127
    int Date::GetDaysOfMonth(int m, int y)
    {
        {
#line 128
            if (!(m >= 1 && m <= 12))
            {
#line 128
                Lang::SysBreak("Assertion failed: m >= 1 && m <= 12");
            }
        }
#line 129
        ;
#line 129
        return DaysInMonth()[m - 1] + (m == 2) * IsLeapYear(y);
    };
    
#line 123
    bool Date::IsLeapYear(int year)
    {
#line 124
        return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    };
    
#line 118
    const int *Date::MonthDayOffset()
    {
#line 119
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
#line 120
        return month_off;
    };
    
#line 147
    void Date::Set(int d)
    {
#line 148
        if (d == 0)
        {
#line 149
            day = 0;
#line 149
            month = 0;
#line 149
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
#line 159
            year -= 400;
            d += 400 * 365 + 100 - 3;
        }
        leap = 1;
        if (d >= 100 * 365 + 24 + 1)
        {
#line 164
            d -- ;
            q = d / (100 * 365 + 24);
            year += 100 * q;
            d -= q * (100 * 365 + 24);
            leap = 0;
        }
        if (d >= 365 * 4 + leap)
        {
#line 171
            q = (d + 1 - leap) / (365 * 4 + 1);
            year += 4 * q;
            d -= q * (365 * 4 + 1) - 1 + leap;
            leap = 1;
        }
        if (d >= 365 + leap)
        {
#line 177
            q = (d - leap) / 365;
            year += q;
            d -= q * 365 + leap;
            leap = 0;
        }
        int i;
        const int * s_month = DaysInMonth();
        for (i = 0; i < 12; i ++ )
            {
#line 185
                int q = s_month[i] + (i == 1) * leap;
                if (q > d)
#line 186
                    break;
                
#line 187
                d -= q;
            }
        month = i + 1;
        day = d + 1;
    };
    
#line 141
    void Date::Set(int y, int m, int d)
    {
#line 142
        year = y;
        month = m;
        day = d;
    };
    
#line 79
    double OnlineFrequency::Get() const
    {
#line 79
        return(double) ticks / timer.Elapsed() * 1000;
    };
    
#line 91
    OnlineFrequencyWindow::OnlineFrequencyWindow()
    :
        which(0),
        interval(0.5)
    {};
    
#line 306
    double OnlineFrequencyWindow::Get() const
    {
#line 307
        if (which)
#line 307
            return freq1.Get();
        else
#line 308
            return freq0.Get();
    };
    
#line 287
    OnlineFrequency& OnlineFrequencyWindow::GetActive()
    {
#line 288
        if (which)
#line 288
            return freq1;
        else
#line 289
            return freq0;
    };
    
    OnlineFrequency& OnlineFrequencyWindow::GetInactive()
    {
#line 293
        if (which)
#line 293
            return freq0;
        else
#line 294
            return freq1;
    };
    
    void OnlineFrequencyWindow::Tick()
    {
#line 298
        freq0.Tick();
        freq1.Tick();
        if (GetInactive().timer.Elapsed() >= interval)
        {
#line 301
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
    
#line 228
    Text::String Time::AsDiffString() const
    {
#line 229
        Text::String out;
        Lang::int64 seconds = Get();
#line 232
        if (seconds > - 60 && seconds < 60)
#line 232
            return "Now";
#line 234
        if (seconds < 0)
        {
#line 234
            out += "-";
#line 234
            seconds *= - 1;
        }
        else 
#line 235
        if (seconds > 0)
#line 235
            out += "+";
#line 237
        Lang::int64 years;
        Lang::int64 months;
        Lang::int64 days;
        Lang::int64 hours;
        Lang::int64 minutes;
#line 243
#line 225
        years = seconds / (31536000);
#line 225
        seconds = seconds % (31536000);;
#line 244
#line 225
        months = seconds / (2592000);
#line 225
        seconds = seconds % (2592000);;
#line 245
#line 225
        days = seconds / (86400);
#line 225
        seconds = seconds % (86400);;
#line 246
#line 225
        hours = seconds / (3600);
#line 225
        seconds = seconds % (3600);;
#line 247
#line 225
        minutes = seconds / (60);
#line 225
        seconds = seconds % (60);;
#line 248
#line 226
        if (years)
        {
#line 226
            out.Cat(' ');
#line 226
            out += Text::String::IntStr64(years) + " " + "years";
        }
#line 226
        ;;
#line 249
#line 226
        if (months)
        {
#line 226
            out.Cat(' ');
#line 226
            out += Text::String::IntStr64(months) + " " + "months";
        }
#line 226
        ;;
#line 250
#line 226
        if (days)
        {
#line 226
            out.Cat(' ');
#line 226
            out += Text::String::IntStr64(days) + " " + "days";
        }
#line 226
        ;;
#line 251
#line 226
        if (hours)
        {
#line 226
            out.Cat(' ');
#line 226
            out += Text::String::IntStr64(hours) + " " + "hours";
        }
#line 226
        ;;
#line 252
#line 226
        if (minutes)
        {
#line 226
            out.Cat(' ');
#line 226
            out += Text::String::IntStr64(minutes) + " " + "minutes";
        }
#line 226
        ;;
#line 253
        return out;
    };
    
#line 211
    Text::String Time::AsString() const
    {
#line 212
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
    
#line 267
    int Time::GetStamp() const
    {
#line 268
        static Lang::int64 begin = Time(1970, 1, 1).Get();
        return Get() - begin;
    };
    
#line 256
    Time Time::GetSys()
    {
#line 257
        Time t;
        t.Set(Native::CurrentTime());
        return t;
    };
    
#line 201
    void Time::Set(Lang::int64 scalar)
    {
#line 202
        int q = (int)(scalar / (24 * 3600));
        Date::Set(q);
        int n = int(scalar - (Lang::int64) q * 24 * 3600);
        hour = n / 3600;
        n %= 3600;
        min = n / 60;
        sec = n % 60;
    };
    
#line 194
    void Time::Set(int y, int mon, int d, int h, int m, int s)
    {
#line 195
        Date::Set(y, mon, d);
        hour = h;
        min = m;
        sec = s;
    };
    
#line 262
    void Time::SetFromStamp(int seconds)
    {
#line 263
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
    
};

#endif
