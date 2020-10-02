#ifndef MATH_CXX
#define MATH_CXX

#include <new>

#ifndef MATH_HXX
#include <Math.hxx>
#endif

namespace Math
{
#line 400 "../../src/Com/Math.fog"
    int Choose(int n, int k)
    {
        if (0 <= k && k <= n)
        {
#line 403
            Lang::int64 ntok = 1;
            Lang::int64 ktok = 1;
            int count = Algorithm::Minimum(k, n - k) + 1;
            for (int t = 1; t < count; t ++ )
                {
#line 407
                    ntok *= n;
                    ktok *= t;
                    n -= 1;
                }
            {
#line 411
                if (!(ktok != 0))
                {
#line 411
                    Lang::SysBreak("Assertion failed: ktok != 0");
                }
            }
#line 412
            ;
#line 412
            return(int)(ntok / ktok);
        }
        else
            return 0;
    };
    
#line 535
    double FindPowFrom1(double ratio, double outcome)
    {
#line 536
        double a = FastLn(ratio);
        double b = FastLn(outcome);
        double res = b / a;
        return res;
    };
    
#line 543
    double FindPowTo1(double begin, double ratio)
    {
#line 544
        double a = FastLn(ratio);
        double b = FastLn(begin);
        double res = - (b / a);
        return res;
    };
    
#line 386
    double NormalCDF(double value, double mean, double deviation)
    {
#line 387
        if (deviation == 0)
        {
#line 388
            if (value < mean)
#line 388
                return 0;
            else
#line 389
                return 1;
        }
        double d = (value - mean) / deviation;
        d = StandardNormalCDF(d);
        if (! ::Native::IsFinite(d))
        {
#line 394
            if (value < mean)
#line 394
                return 0;
            else
#line 395
                return 1;
        }
        return d;
    };
    
#line 355
    double NormalPDF(double x, double mean, double dev)
    {
#line 356
        double a = dev * Native::pow_fast_precise(2 * 3.14159265358979323846, 0.5);
        double b = 1.0 / a;
        double c = x - mean;
        double d = - (c * c) / (2 * dev * dev);
        double e = Native::exp_fast(d);
        return b * e;
    };
    
#line 369
    double NormalPDFRelative(double value, double mean, double deviation)
    {
#line 370
        if (deviation == 0)
            return 0;
#line 373
        double low = mean - 4 * deviation;
        double high = mean + 4 * deviation;
        if (mean < low || high < mean)
            return 0;
#line 378
        double a = (value - mean) / deviation;
        double b = - 0.5 * a * a;
        if (b < - 10)
            return 0;
        double c = FastExp(b);
        return c;
    };
    
#line 345
    double StandardNormalCDF(double x)
    {
#line 346
        double sum = x;
        double value = x;
        for (int i = 1; i < 100; i ++ )
            {
#line 349
                value = (value * x * x / (2 * i + 1));
                sum += value;
            }
        return 0.5 + (sum / Native::pow_fast_precise(2 * 3.14159265358979323846, 0.5)) * Native::pow_fast_precise(2.71828182845904523536, - 1 * x * x / 2);
    };
    
#line 338
    double nround(double n, unsigned int c)
    {
#line 339
        double marge = Native::pow_fast_precise(10, c);
        double up = n * marge;
        double ret = Native::Round(up) / marge;
        return ret;
    };
    
#line 70
    const int FastTrig::accuracy = 10000;
    
#line 297
    FastTrig::FastTrig()
    {
#line 298
        sin.SetCount(accuracy);
        cos.SetCount(accuracy);
        tan.SetCount(accuracy);
        asin.SetCount(accuracy);
        acos.SetCount(accuracy);
        atan.SetCount(accuracy);
        double * s = sin.Begin();
        double * c = cos.Begin();
        double * t = tan.Begin();
        double * as = asin.Begin();
        double * ac = acos.Begin();
        double * at = atan.Begin();
        for (int i = 0; i < accuracy; i ++ )
            {
#line 311
                double a = (6.283185307179586 * i) / accuracy;
                *s = Native::Sin(a);
#line 312
                *c = Native::Cos(a);
#line 312
                *t = Native::Tan(a);
                *as = Native::ASin(a);
#line 313
                *ac = Native::ACos(a);
#line 313
                *at = Native::ATan(a);
#line 315
                s ++ ;
#line 315
                c ++ ;
#line 315
                t ++ ;
                as ++ ;
#line 316
                ac ++ ;
#line 316
                at ++ ;
            }
    };
    
    int FastTrig::Pos(double a) const
    {
#line 321
        double posf = a / 6.283185307179586;
        posf -= Native::Floor(posf);
        int pos = posf * accuracy;
        return pos;
    };
    
#line 149
    MovingOnlineVariance::MovingOnlineVariance()
    {
#line 149
        skip = false;
#line 149
        period = 10;
#line 149
        vec.Add();
    };
    
    void MovingOnlineVariance::AddResult(double d)
    {
#line 152
        for (int i = 0; i < vec.GetCount(); i ++ )
            {
#line 152
                vec[i].Add(d);
            }
    };
    
#line 154
    void MovingOnlineVariance::Clear()
    {
#line 154
        vec.SetCount(1);
#line 154
        vec[0].Clear();
    };
    
#line 153
    void MovingOnlineVariance::Next()
    {
#line 153
        if (skip)
#line 153
            return;
#line 153
        while (vec.GetCount() >= period)
            {
#line 153
                vec.Remove(0);
            }
#line 153
        vec.Add();
    };
    
#line 151
    void MovingOnlineVariance::SetPeriod(int i)
    {
#line 151
        if (i > 0)
        {
#line 151
            period = i;
#line 151
            skip = false;
        }
        else
        {
#line 151
            period = 1;
#line 151
            skip = true;
#line 151
            vec.SetCount(1);
        }
    };
    
#line 246
    MovingStepDistribution::MovingStepDistribution()
    {
#line 246
        skip = false;
#line 246
        period = 10;
#line 246
        vec.Add();
    };
    
    void MovingStepDistribution::AddResult(double d)
    {
#line 249
        for (int i = 0; i < vec.GetCount(); i ++ )
            {
#line 249
                vec[i].AddResult(d);
            }
    };
    
#line 251
    void MovingStepDistribution::Clear()
    {
#line 251
        vec.SetCount(1);
#line 251
        vec[0].Clear();
    };
    
#line 250
    void MovingStepDistribution::Next()
    {
#line 250
        if (skip)
#line 250
            return;
#line 250
        while (vec.GetCount() >= period)
            {
#line 250
                vec.Remove(0);
            }
#line 250
        vec.Add();
    };
    
#line 248
    void MovingStepDistribution::SetPeriod(int i)
    {
#line 248
        if (i > 0)
        {
#line 248
            period = i;
#line 248
            skip = false;
        }
        else
        {
#line 248
            period = 1;
#line 248
            skip = true;
#line 248
            vec.SetCount(1);
        }
    };
    
#line 106
    OnlineAverage::OnlineAverage()
    :
        mean(0),
        count(0)
    {};
    
#line 425
    void OnlineAverage::Add(double a)
    {
#line 426
        lock.Enter();
        if (count == 0)
        {
#line 428
            mean = a;
        }
        else
        {
#line 431
            double delta = a - mean;
            mean += delta / count;
        }
        count ++ ;
        lock.Leave();
    };
    
#line 208
    void OnlineBivariate::operator= (const OnlineBivariate& s)
    {
#line 208
        x = s.x;
#line 208
        y = s.y;
#line 208
        co = s.co;
    };
    
#line 193
    void OnlineCovariance::operator= (const OnlineCovariance& s)
    {
#line 193
        meanx = s.meanx;
#line 193
        meany = s.meany;
#line 193
        C = s.C;
#line 193
        n = s.n;
    };
    
#line 194
    void OnlineCovariance::Clear()
    {
#line 194
        meanx = 0;
#line 194
        meany = 0;
#line 194
        C = 0;
#line 194
        n = 0;
    };
    
    void OnlineCovariance::Serialize(Abstract::StreamBase& s)
    {
#line 197
        s % meanx % meany % C % n;
    };
    
#line 463
    void OnlineVariance::Add(double x)
    {
#line 464
        if (count == 0)
            k = x;
        count = count + 1;
        double diff = x - k;
        ex += diff;
        ex2 += diff * diff;
    };
    
    void OnlineVariance::Add(double x, double weight)
    {
#line 473
        if (count == 0)
            k = x;
        count += weight;
        double diff = x - k;
        ex += diff * weight;
        ex2 += diff * diff * weight;
    };
    
#line 445
    void OnlineVariance::Clear()
    {
#line 446
        k = 0;
        count = 0;
        ex = 0;
        ex2 = 0;
    };
    
#line 495
    double OnlineVariance::GetCDF() const
    {
#line 496
        if (count == 0.0)
#line 496
            return 0;
        return NormalCDF(0, GetMean(), GetDeviation());
    };
    
    double OnlineVariance::GetCDF(double limit, bool rside) const
    {
#line 501
        if (count == 0.0)
#line 501
            return 0;
        if (rside == 1)
            return 1 - NormalCDF(limit, GetMean(), GetDeviation());
        else
            return NormalCDF(limit, GetMean(), GetDeviation());
    };
    
#line 488
    double OnlineVariance::GetMean() const
    {
#line 489
        if (count == 0.0)
            return 0.0;
        else
            return k + ex / count;
    };
    
#line 131
    double OnlineVariance::GetVariance() const
    {
#line 131
        return(ex2 - (ex * ex) / count) / (count - 1);
    };
    
#line 481
    void OnlineVariance::Remove(double x)
    {
#line 482
        count = count - 1;
        double diff = x - k;
        ex -= diff;
        ex2 -= diff * diff;
    };
    
#line 452
    void OnlineVariance::Resize(double d)
    {
#line 453
        if (count > 0.0)
        {
#line 454
            ex /= count;
            ex2 /= count;
            count = 1.0;
            ex *= d;
            ex2 *= d;
            count = d;
        }
    };
    
#line 135
    void OnlineVariance::Serialize(Abstract::StreamBase& s)
    {
#line 135
        s % k % count % ex % ex2;
    };
    
#line 271
    RandomGaussian& RandomGaussianCache::Get(int length)
    {
#line 272
        lock.Enter();
        int i = cache.Find(length);
        RandomGaussian * g;
        if (i >= 0)
#line 275
            g = &cache[i];
        else
#line 276
            g = &cache.Add(length, new RandomGaussian(length));
        lock.Leave();
        return *g;
    };
    
#line 176
    void StdDeviant::operator+= (const StdDeviant& s)
    {
#line 176
        mean += s.mean;
#line 176
        dev += s.dev;
    };
    
#line 177
    void StdDeviant::operator-= (const StdDeviant& s)
    {
#line 177
        mean -= s.mean;
#line 177
        dev -= s.dev;
    };
    
#line 523
    Text::String StdDeviant::AsString() const
    {
#line 524
        return(Text::String)"mean=" + Text::String::DblStr(mean) + (Text::String)", dev=" + Text::String::DblStr(dev);
    };
    
#line 516
    double StdDeviant::GetCDF(double limit, bool rside) const
    {
#line 517
        if (rside == 1)
            return 1 - NormalCDF(limit, GetMean(), GetDeviation());
        else
            return NormalCDF(limit, GetMean(), GetDeviation());
    };
    
#line 571
    StepDistribution::StepDistribution()
    {
#line 572
        mean = 0;
        M2 = 0;
        value_step = 0.01;
    };
    
    void StepDistribution::AddResult(double value)
    {
#line 578
        double delta = value - mean;
        mean += delta / values.GetCount();
        M2 += delta * (value - mean);
#line 582
        int valuei = (int)(value / value_step);
        for (int i = 0; i < values.GetCount(); i ++ )
            {
#line 584
                if (valuei < values[i])
                {
#line 585
                    values.Insert(i, valuei);
                    return;
                }
            }
        values.Add(valuei);
    };
    
    void StepDistribution::Clear()
    {
#line 593
        values.SetCount(0);
        mean = 0;
        M2 = 0;
    };
    
    double StepDistribution::Get(double prob)
    {
        {
#line 599
            if (!(prob >= 0.0 && prob <= 1.0))
            {
#line 599
                Lang::SysBreak("Assertion failed: prob >= 0.0 && prob <= 1.0");
            }
        }
#line 600
        ;
        {
#line 600
            if (!(values.GetCount()))
            {
#line 600
                Lang::SysBreak("Assertion failed: values.GetCount()");
            }
        }
#line 601
        ;
#line 601
        int count = values.GetCount() - 1;
        if (count < 0)
            return 0.0;
        double pos_step = 1.0 / (double) count;
        int pos = (int)(prob / pos_step);
        if (pos >= count)
            return values.Top() * value_step;
        if (pos < 0)
            return values[0] * value_step;
        double begin = pos * pos_step;
        double v0 = values[pos] * value_step;
        double v1 = values[pos + 1] * value_step;
        double f = (prob - begin) / pos_step;
        double linear_value = v0 * f + v1 * (1.0 - f);
        return linear_value;
    };
    
#line 231
    void StepDistribution::Serialize(Abstract::StreamBase& s)
    {
#line 231
        s % values % mean % M2 % value_step;
    };
    
};

#endif
