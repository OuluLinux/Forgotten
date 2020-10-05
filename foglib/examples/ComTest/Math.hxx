#ifndef MATH_HXX
#define MATH_HXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

namespace Math
{
#line 400 "../../src/Com/Math.fog"
    int Choose(int n, int k);
#line 89
    inline double FastACos(double a);
#line 88
    inline double FastASin(double a);
#line 90
    inline double FastATan(double a);
    inline float FastATan2(float y, float x);
#line 86
    inline double FastCos(double a);
#line 61
    inline double FastExp(double a);
#line 60
    inline double FastLn(double a);
#line 62
    inline double FastPow(double a, double b);
#line 85
    inline double FastSin(double a);
#line 63
    inline double FastSqrt(double a);
#line 87
    inline double FastTan(double a);
#line 535
    double FindPowFrom1(double ratio, double outcome);
#line 543
    double FindPowTo1(double begin, double ratio);
};

namespace Math {
struct FastTrig;
}

namespace Math
{
#line 83
    inline FastTrig& GetFastTrig();
};

namespace Math {
class RandomGaussian;
}

namespace Math
{
#line 282
    inline RandomGaussian& GetRandomGaussian(int length);
#line 386
    double NormalCDF(double value, double mean, double deviation);
#line 355
    double NormalPDF(double x, double mean, double dev);
#line 369
    double NormalPDFRelative(double value, double mean, double deviation);
#line 65
    template < class _1 >
    inline _1 PowFastT(_1 v, _1 e);
#line 66
    template <>
    inline double PowFastT < double > (double v, double e);
#line 67
    template <>
    inline float PowFastT < float > (float v, float e);
#line 345
    double StandardNormalCDF(double x);
#line 338
    double nround(double n, unsigned int c);
    
    struct FastTrig
    {
#line 71
        Container::Vector < double > sin;
#line 71
        Container::Vector < double > cos;
#line 71
        Container::Vector < double > tan;
#line 71
        Container::Vector < double > asin;
#line 71
        Container::Vector < double > acos;
#line 71
        Container::Vector < double > atan;
        
#line 297
        FastTrig();
#line 79
        inline double ACos(double a) const;
#line 78
        inline double ASin(double a) const;
#line 80
        inline double ATan(double a) const;
#line 76
        inline double Cos(double a) const;
#line 320
        int Pos(double a) const;
#line 75
        inline double Sin(double a) const;
#line 77
        inline double Tan(double a) const;
        
#line 70
        static const int accuracy;
    };
};

namespace Math {
struct OnlineVariance;
}

namespace Math
{
    class MovingOnlineVariance
    {
#line 144
        Container::Vector < OnlineVariance > vec;
        int period;
        bool skip;
        
    public:
        MovingOnlineVariance();
#line 152
        void AddResult(double d);
#line 154
        void Clear();
#line 150
        inline OnlineVariance& Get();
#line 157
        inline double GetCDF(double cursor, int type);
#line 156
        inline double GetDeviation();
#line 155
        inline double GetMean();
#line 153
        void Next();
#line 151
        void SetPeriod(int i);
    };
};

namespace Math {
class StepDistribution;
}

namespace Math
{
    class MovingStepDistribution
    {
#line 242
        Container::Vector < StepDistribution > vec;
        int period;
        bool skip;
        
    public:
#line 246
        MovingStepDistribution();
#line 249
        void AddResult(double d);
#line 251
        void Clear();
#line 247
        inline StepDistribution& Get();
#line 253
        inline double Get(double prob);
#line 252
        inline double GetMean();
#line 250
        void Next();
#line 254
        inline void Serialize(Abstract::StreamBase& s);
#line 248
        void SetPeriod(int i);
    };
    
    namespace Native
    {
#line 14
        double ACos(double a);
#line 13
        double ASin(double a);
#line 15
        double ATan(double a);
#line 11
        double Cos(double a);
    };
};

namespace Math
{
    namespace Native {
    class StdRandomGaussian;
    }
    
    namespace Native
    {
#line 54
        StdRandomGaussian *CreateStdRandomGaussian(int length);
#line 8
        double Floor(double a);
        double Round(double a);
        double Sin(double a);
#line 12
        double Tan(double a);
#line 20
        double better_exp_fast(double a);
#line 24
        double better_expf_fast(float a);
#line 42
        double better_pow_fast_precise(double a, double b);
#line 44
        float better_powf_fast_precise(float a, float b);
#line 19
        double exp_fast(double a);
#line 17
        double exp_fast_lb(double a);
#line 21
        double exp_fast_schraudolph(double a);
#line 18
        double exp_fast_ub(double a);
#line 23
        float expf_fast(float a);
#line 25
        float expf_fast_lb(float a);
#line 22
        float expf_fast_ub(float a);
#line 46
        float fast_atan2(float y, float x);
#line 28
        double log_fast(double a);
#line 26
        double log_fast_ankerl(double a);
#line 29
        double log_fast_lb(double a);
#line 27
        double log_fast_ub(double a);
#line 31
        float logf_fast(float a);
        float logf_fast_lb(float a);
#line 30
        float logf_fast_ub(float a);
#line 38
        double pow_fast(double a, double b);
#line 33
        double pow_fast_ankerl(double a, double b);
#line 39
        double pow_fast_lb(double a, double b);
#line 41
        double pow_fast_precise(double a, double b);
#line 40
        double pow_fast_precise_ankerl(double a, double b);
#line 37
        double pow_fast_ub(double a, double b);
#line 34
        float powf_fast(float a, float b);
        float powf_fast_lb(float a, float b);
#line 43
        float powf_fast_precise(float a, float b);
#line 36
        float powf_fast_ub(float a, float b);
        
        class StdRandomGaussian
        {
        public:
#line 50
            double Get() const;
            void Seed();
        };
    };
    
    struct OnlineAverage
    {
#line 103
        double mean;
        Lang::int64 count;
        Lang::AtomicFlag lock;
        
#line 106
        OnlineAverage();
#line 113
        inline bool operator()(const OnlineAverage& a, const OnlineAverage& b) const;
#line 425
        void Add(double a);
#line 108
        inline void Clear();
#line 111
        inline double GetMean() const;
#line 109
        inline void Resize(Lang::int64 i);
#line 112
        inline void Serialize(Abstract::StreamBase& s);
    };
    
    struct OnlineCovariance
    {
#line 188
        double meanx;
#line 188
        double meany;
#line 188
        double C;
        Lang::dword n;
        
        inline OnlineCovariance();
        inline OnlineCovariance(const OnlineCovariance& s);
        void operator= (const OnlineCovariance& s);
#line 195
        void Add(double x, double y);
#line 194
        void Clear();
#line 196
        inline double Get() const;
        void Serialize(Abstract::StreamBase& s);
    };
    
    struct OnlineVariance
    {
#line 119
        double k;
        double count;
        double ex;
        double ex2;
        
#line 463
        void Add(double x);
#line 472
        void Add(double x, double weight);
#line 445
        void Clear();
#line 495
        double GetCDF() const;
#line 500
        double GetCDF(double limit, bool rside) const;
#line 132
        inline double GetDeviation() const;
#line 488
        double GetMean() const;
#line 131
        double GetVariance() const;
#line 481
        void Remove(double x);
#line 452
        void Resize(double d);
#line 135
        void Serialize(Abstract::StreamBase& s);
    };
    
    struct OnlineBivariate
    {
#line 203
        OnlineVariance x;
#line 203
        OnlineVariance y;
        OnlineCovariance co;
        
        inline OnlineBivariate();
        inline OnlineBivariate(const OnlineBivariate& s);
        void operator= (const OnlineBivariate& s);
        void Add(double x, double y);
#line 211
        double GetPDF(double x, double y) const;
#line 210
        inline void Serialize(Abstract::StreamBase& s);
    };
    
    class RandomGaussian
    {
#line 258
        Container::One < Native::StdRandomGaussian > n;
        
    public:
        inline RandomGaussian(int length);
#line 263
        inline operator double();
#line 262
        inline double Get();
#line 264
        inline void Seed();
    };
    
    struct RandomGaussianCache
    {
#line 268
        Container::ArrayMap < int, RandomGaussian > cache;
        Lang::AtomicFlag lock;
        
        RandomGaussian& Get(int length);
    };
    
    struct StdDeviant
    {
#line 164
        double mean;
        double dev;
        
#line 178
        inline void operator*= (double d);
#line 176
        void operator+= (const StdDeviant& s);
        void operator-= (const StdDeviant& s);
#line 179
        inline void operator/= (double d);
#line 181
        inline bool operator<= (const StdDeviant& s) const;
#line 180
        inline void operator= (double d);
#line 182
        inline bool operator> (const StdDeviant& s) const;
#line 175
        inline operator double() const;
#line 523
        Text::String AsString() const;
#line 168
        inline void Clear();
#line 172
        inline double GetCDF() const;
#line 516
        double GetCDF(double limit, bool rside) const;
#line 170
        inline double GetDeviation() const;
#line 169
        inline double GetMean() const;
#line 171
        inline double GetVariance() const;
#line 167
        inline void Serialize(Abstract::StreamBase& s);
    };
    
    class StepDistribution
    {
#line 225
        Container::Vector < int > values;
        double mean;
#line 226
        double M2;
        double value_step;
        
    public:
#line 571
        StepDistribution();
#line 577
        void AddResult(double value);
#line 592
        void Clear();
#line 598
        double Get(double prob);
#line 235
        inline int GetCount() const;
        inline double GetMean();
#line 231
        void Serialize(Abstract::StreamBase& s);
    };
};

namespace Math
{
#line 89
    inline double FastACos(double a)
    {
#line 89
        return GetFastTrig().ACos(a);
    };
    
#line 88
    inline double FastASin(double a)
    {
#line 88
        return GetFastTrig().ASin(a);
    };
    
#line 90
    inline double FastATan(double a)
    {
#line 90
        return GetFastTrig().ATan(a);
    };
    
#line 91
    inline float FastATan2(float y, float x)
    {
#line 91
        return Native::fast_atan2(y, x);
    };
    
#line 86
    inline double FastCos(double a)
    {
#line 86
        return GetFastTrig().Cos(a);
    };
    
#line 61
    inline double FastExp(double a)
    {
#line 61
        return Native::exp_fast(a);
    };
    
#line 60
    inline double FastLn(double a)
    {
#line 60
        return Native::log_fast(a);
    };
    
#line 62
    inline double FastPow(double a, double b)
    {
#line 62
        return Native::pow_fast(a, b);
    };
    
#line 85
    inline double FastSin(double a)
    {
#line 85
        return GetFastTrig().Sin(a);
    };
    
#line 63
    inline double FastSqrt(double a)
    {
#line 63
        return Native::pow_fast(a, 0.5);
    };
    
#line 87
    inline double FastTan(double a)
    {
#line 87
        return GetFastTrig().Tan(a);
    };
    
#line 83
    inline FastTrig& GetFastTrig()
    {
#line 83
        return Util::Single < FastTrig > ();
    };
    
#line 282
    inline RandomGaussian& GetRandomGaussian(int length)
    {
#line 283
        static RandomGaussianCache cache;
        return cache.Get(length);
    };
    
#line 65
    template < class _1 >
    inline _1 PowFastT(_1 v, _1 e)
    {
#line 65
        Lang::SysBreak("Unimplemented");
    };
    
#line 66
    template <>
    inline double PowFastT < double > (double v, double e)
    {
#line 66
        return Native::pow_fast_precise(v, e);
    };
    
#line 67
    template <>
    inline float PowFastT < float > (float v, float e)
    {
#line 67
        return Native::powf_fast_precise(v, e);
    };
    
#line 79
    inline double FastTrig::ACos(double a) const
    {
#line 79
        return acos[Pos(a)];
    };
    
#line 78
    inline double FastTrig::ASin(double a) const
    {
#line 78
        return asin[Pos(a)];
    };
    
#line 80
    inline double FastTrig::ATan(double a) const
    {
#line 80
        return atan[Pos(a)];
    };
    
#line 76
    inline double FastTrig::Cos(double a) const
    {
#line 76
        return cos[Pos(a)];
    };
    
#line 75
    inline double FastTrig::Sin(double a) const
    {
#line 75
        return sin[Pos(a)];
    };
    
#line 77
    inline double FastTrig::Tan(double a) const
    {
#line 77
        return tan[Pos(a)];
    };
    
#line 150
    inline OnlineVariance& MovingOnlineVariance::Get()
    {
#line 150
        return vec[0];
    };
    
#line 157
    inline double MovingOnlineVariance::GetCDF(double cursor, int type)
    {
#line 157
        return Get().GetCDF(cursor, type);
    };
    
#line 156
    inline double MovingOnlineVariance::GetDeviation()
    {
#line 156
        return Get().GetDeviation();
    };
    
#line 155
    inline double MovingOnlineVariance::GetMean()
    {
#line 155
        return Get().GetMean();
    };
    
#line 247
    inline StepDistribution& MovingStepDistribution::Get()
    {
#line 247
        return vec[0];
    };
    
#line 253
    inline double MovingStepDistribution::Get(double prob)
    {
#line 253
        return Get().Get(prob);
    };
    
#line 252
    inline double MovingStepDistribution::GetMean()
    {
#line 252
        return Get().GetMean();
    };
    
#line 254
    inline void MovingStepDistribution::Serialize(Abstract::StreamBase& s)
    {
#line 254
        s % vec % period % skip;
    };
    
#line 113
    inline bool OnlineAverage::operator()(const OnlineAverage& a, const OnlineAverage& b) const
    {
#line 113
        return a.mean < b.mean;
    };
    
#line 108
    inline void OnlineAverage::Clear()
    {
#line 108
        mean = 0.0;
#line 108
        count = 0;
    };
    
    inline double OnlineAverage::GetMean() const
    {
#line 111
        return mean;
    };
    
#line 109
    inline void OnlineAverage::Resize(Lang::int64 i)
    {
#line 109
        count = i;
    };
    
    inline void OnlineAverage::Serialize(Abstract::StreamBase& s)
    {
#line 112
        s % mean % count;
    };
    
#line 206
    inline OnlineBivariate::OnlineBivariate() {};
    
#line 207
    inline OnlineBivariate::OnlineBivariate(const OnlineBivariate& s)
    {
#line 207
        *this = s;
    };
    
    inline void OnlineBivariate::Serialize(Abstract::StreamBase& s)
    {
#line 210
        s % x % y % co;
    };
    
#line 191
    inline OnlineCovariance::OnlineCovariance()
    {
#line 191
        Clear();
    };
    
#line 192
    inline OnlineCovariance::OnlineCovariance(const OnlineCovariance& s)
    {
#line 192
        *this = s;
    };
    
#line 196
    inline double OnlineCovariance::Get() const
    {
#line 196
        return C / n;
    };
    
#line 132
    inline double OnlineVariance::GetDeviation() const
    {
#line 132
        return FastPow(GetVariance(), 0.5);
    };
    
#line 261
    inline RandomGaussian::RandomGaussian(int length)
    {
#line 261
        n = Native::CreateStdRandomGaussian(length);
    };
    
#line 263
    inline RandomGaussian::operator double()
    {
#line 263
        return n -> Get();
    };
    
#line 262
    inline double RandomGaussian::Get()
    {
#line 262
        return n -> Get();
    };
    
#line 264
    inline void RandomGaussian::Seed()
    {
#line 264
        n -> Seed();
    };
    
#line 178
    inline void StdDeviant::operator*= (double d)
    {
#line 178
        mean *= d;
#line 178
        dev *= d;
    };
    
#line 179
    inline void StdDeviant::operator/= (double d)
    {
#line 179
        mean /= d;
#line 179
        dev /= d;
    };
    
#line 181
    inline bool StdDeviant::operator<= (const StdDeviant& s) const
    {
#line 181
        return mean <= s.GetMean();
    };
    
#line 180
    inline void StdDeviant::operator= (double d)
    {
#line 180
        mean = d;
#line 180
        dev = 0;
    };
    
#line 182
    inline bool StdDeviant::operator> (const StdDeviant& s) const
    {
#line 182
        return mean > s.GetMean();
    };
    
#line 175
    inline StdDeviant::operator double() const
    {
#line 175
        return mean;
    };
    
#line 168
    inline void StdDeviant::Clear()
    {
#line 168
        mean = 0;
#line 168
        dev = 0;
    };
    
#line 172
    inline double StdDeviant::GetCDF() const
    {
#line 172
        return NormalCDF(0, GetMean(), GetDeviation());
    };
    
#line 170
    inline double StdDeviant::GetDeviation() const
    {
#line 170
        return dev;
    };
    
#line 169
    inline double StdDeviant::GetMean() const
    {
#line 169
        return mean;
    };
    
#line 171
    inline double StdDeviant::GetVariance() const
    {
#line 171
        return dev * dev;
    };
    
#line 167
    inline void StdDeviant::Serialize(Abstract::StreamBase& s)
    {
#line 167
        s % mean % dev;
    };
    
#line 235
    inline int StepDistribution::GetCount() const
    {
#line 235
        return values.GetCount();
    };
    
#line 236
    inline double StepDistribution::GetMean()
    {
#line 236
        return mean;
    };
    
};

#endif
