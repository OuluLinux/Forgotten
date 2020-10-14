#include "Com.h"

NAMESPACE_MATH_BEGIN

namespace Native {


double Pow(double a, double b) {return ::pow(a, b);}
double Floor(double a) {return ::floor(a);}
double Round(double a) {return ::round(a);}
double Sin(double a)   {return ::sin(a);}
double Cos(double a)   {return ::cos(a);}
double Tan(double a)   {return ::tan(a);}
double ASin(double a)  {return ::asin(a);}
double ACos(double a)  {return ::acos(a);}
double ATan(double a)  {return ::atan(a);}

double exp_fast_lb(double a) {
	union {
		double d;
		long long x;
	} u;
	u.x = (long long)(6497320848556798LL * a) + 4606794787981043020LL;
	return u.d;
}

/* 4607182418800017408 + 1 */
double exp_fast_ub(double a) {
	union {
		double d;
		long long x;
	} u;
	u.x = (long long)(6497320848556798LL * a) + 4607182418800017409LL;
	return u.d;
}

double exp_fast(double a) {
	union {
		double d;
		long long x;
	} u;
	u.x = (long long)(6497320848556798LL * a) + 0x3fef127e83d16f12LL;
	return u.d;
}

double better_exp_fast(double a) {
	union {
		double d;
		long long x;
	} u, v;
	u.x = (long long)(3248660424278399LL * a) + 0x3fdf127e83d16f12LL;
	v.x = 0x3fdf127e83d16f12LL - (long long)(3248660424278399LL * a);
	return u.d / v.d;
}

/* Schraudolph's published algorithm */
double exp_fast_schraudolph(double a) {
	union {
		double d;
		int x[2];
	} u;
	u.x[1] = (int)(1512775 * a) + 1072632447;
	u.x[0] = 0;
	return u.d;
}

/* 1065353216 + 1 */
float expf_fast_ub(float a) {
	union {
		float f;
		int x;
	} u;
	u.x = (int)(12102203 * a) + 1065353217;
	return u.f;
}

/* Schraudolph's published algorithm with John's constants */
/* 1065353216 - 486411 = 1064866805 */
float expf_fast(float a) {
	union {
		float f;
		int x;
	} u;
	u.x = (int)(12102203 * a) + 1064866805;
	return u.f;
}

//  1056478197
double better_expf_fast(float a) {
	union {
		float f;
		int x;
	} u, v;
	u.x = (long long)(6051102 * a) + 1056478197;
	v.x = 1056478197 - (long long)(6051102 * a);
	return u.f / v.f;
}

/* 1065353216 - 722019 */
float expf_fast_lb(float a) {
	union {
		float f;
		int x;
	} u;
	u.x = (int)(12102203 * a) + 1064631197;
	return u.f;
}

/* Ankerl's inversion of Schraudolph's published algorithm, converted to explicit multiplication */
double log_fast_ankerl(double a) {
	union {
		double d;
		int x[2];
	} u = { a };
	return (u.x[1] - 1072632447) * 6.610368362777016e-7; /* 1 / 1512775.0; */
}

double log_fast_ub(double a) {
	union {
		double d;
		long long x;
	} u = { a };
	return (u.x - 4606794787981043020) * 1.539095918623324e-16; /* 1 / 6497320848556798.0; */
}

/* Ankerl's inversion of Schraudolph's published algorithm with my constants */
double log_fast(double a) {
	union {
		double d;
		long long x;
	} u = { a };
	return (u.x - 4606921278410026770) * 1.539095918623324e-16; /* 1 / 6497320848556798.0; */
}

double log_fast_lb(double a) {
	union {
		double d;
		long long x;
	} u = { a };
	return (u.x - 4607182418800017409) * 1.539095918623324e-16; /* 1 / 6497320848556798.0; */
}


/* 1065353216 - 722019 */
float logf_fast_ub(float a) {
	union {
		float f;
		int x;
	} u = { a };
	return (u.x - 1064631197) * 8.262958405176314e-8f; /* 1 / 12102203.0; */
}

/* Ankerl's adaptation of Schraudolph's published algorithm with John's constants */
/* 1065353216 - 486411 = 1064866805 */
float logf_fast(float a) {
	union {
		float f;
		int x;
	} u = { a };
	return (u.x - 1064866805) * 8.262958405176314e-8f; /* 1 / 12102203.0; */
}

/* 1065353216 + 1 */
float logf_fast_lb(float a) {
	union {
		float f;
		int x;
	} u = { a };
	return (u.x - 1065353217) * 8.262958405176314e-8f; /* 1 / 12102203.0 */
}

/* Ankerl's version of Schraudolph's approximation. */
double pow_fast_ankerl(double a, double b) {
	union {
		double d;
		int x[2];
	} u = { a };
	u.x[1] = (int)(b * (u.x[1] - 1072632447)) + 1072632447;
	u.x[0] = 0;
	return u.d;
}

/*
 These constants are based loosely on the following comment off of Ankerl's blog:
 "I have used the same trick for float, not double, with some slight modification to the constants to suite IEEE754 float format. The first constant for float is 1<<23/log(2) and the second is 127<<23 (for double they are 1<<20/log(2) and 1023<<20)." -- John
*/

/* 1065353216 + 1      = 1065353217 ub */
/* 1065353216 - 486411 = 1064866805 min RMSE */
/* 1065353216 - 722019 = 1064631197 lb */
float powf_fast(float a, float b) {
	union {
		float d;
		int x;
	} u = { a };
	u.x = (int)(b * (u.x - 1064866805)) + 1064866805;
	return u.d;
}

float powf_fast_lb(float a, float b) {
	union {
		float d;
		int x;
	} u = { a };
	u.x = (int)(b * (u.x - 1065353217)) + 1064631197;
	return u.d;
}

float powf_fast_ub(float a, float b) {
	union {
		float d;
		int x;
	} u = { a };
	u.x = (int)(b * (u.x - 1064631197)) + 1065353217;
	return u.d;
}

/*
  Now that 64 bit arithmetic is cheap we can (try to) improve on Ankerl's algorithm.
 double long long approximation: round 1<<52/log(2) 6497320848556798,
  mask = 0x3ff0000000000000LL = 4607182418800017408LL
>>> round (2**52 * log (3 / (8 * log 2) + 1/2) / log 2 - 1/2)
261140389990638
>>> 0x3ff0000000000000 - round (2**52 * log (3 / (8 * log 2) + 1/2) / log 2 - 1/2)
4606921278410026770
*/

double pow_fast_ub(double a, double b) {
	union {
		double d;
		long long x;
	} u = { a };
	u.x = (long long)(b * (u.x - 4606794787981043020LL)) + 4607182418800017409LL;
	return u.d;
}

double pow_fast(double a, double b) {
	union {
		double d;
		long long x;
	} u = { a };
	u.x = (long long)(b * (u.x - 4606921278410026770LL)) + 4606921278410026770LL;
	return u.d;
}

double pow_fast_lb(double a, double b) {
	union {
		double d;
		long long x;
	} u = { a };
	u.x = (long long)(b * (u.x - 4607182418800017409LL)) + 4606794787981043020LL;
	return u.d;
}

/* should be much more precise with large b, still ~3.3x faster. */
double pow_fast_precise_ankerl(double a, double b) {
	int flipped = 0;
	
	if (b < 0) {
		flipped = 1;
		b = -b;
	}
	
	/* calculate approximation with fraction of the exponent */
	int e = (int) b;
	
	union {
		double d;
		int x[2];
	} u = { a };
	u.x[1] = (int)((b - e) * (u.x[1] - 1072632447)) + 1072632447;
	u.x[0] = 0;
	
	double r = 1.0;
	
	while (e) {
		if (e & 1) {
			r *= a;
		}
		a *= a;
		e >>= 1;
	}
	
	r *= u.d;
	
	return flipped ? 1.0 / r : r;
}

/* should be much more precise with large b, still ~3.3x faster. */
double pow_fast_precise(double a, double b) {
	int flipped = 0;
	
	if (b < 0) {
		flipped = 1;
		b = -b;
	}
	
	/* calculate approximation with fraction of the exponent */
	int e = (int) b;
	double d = exp_fast(b - e);
	double r = 1.0;
	
	while (e) {
		if (e & 1)
			r *= a;
		a *= a;
		e >>= 1;
	}
	
	r *= d;
	
	return flipped ? 1.0 / r : r;
}

double better_pow_fast_precise(double a, double b) {
	int flipped = 0;
	
	if (b < 0) {
		flipped = 1;
		b = -b;
	}
	
	/* calculate approximation with fraction of the exponent */
	int e = (int) b;
	
	double d = better_exp_fast(b - e);
	
	double r = 1.0;
	
	while (e) {
		if (e & 1)
			r *= a;
		a *= a;
		e >>= 1;
	}
	
	r *= d;
	
	return flipped ? 1.0 / r : r;
}


/* should be much more precise with large b */
float powf_fast_precise(float a, float b) {
	int flipped = 0;
	
	if (b < 0) {
		flipped = 1;
		b = -b;
	}
	
	/* calculate approximation with fraction of the exponent */
	int e = (int) b;
	
	union {
		float f;
		int x;
	} u = { a };
	u.x = (int)((b - e) * (u.x - 1065353216)) + 1065353216;
	
	float r = 1.0f;
	
	while (e) {
		if (e & 1) {
			r *= a;
		}
		a *= a;
		e >>= 1;
	}
	
	r *= u.f;
	
	return flipped ? 1.0f / r : r;
}

/* should be much more precise with large b */
float better_powf_fast_precise(float a, float b) {
	int flipped = 0;
	
	if (b < 0) {
		flipped = 1;
		b = -b;
	}
	
	/* calculate approximation with fraction of the exponent */
	int e = (int) b;
	float f = (float)better_expf_fast(b - e);
	float r = 1.0f;
	
	while (e) {
		if (e & 1) {
			r *= a;
		}
		a *= a;
		e >>= 1;
	}
	
	r *= f;
	
	return flipped ? 1.0f / r : r;
}









float fast_atan2(float y, float x) {
    const float n1 = 0.97239411f;
    const float n2 = -0.19194795f;
    float result = 0.0f;
    
    if (x != 0.0f) {
        const union { float flVal; unsigned int nVal; } tYSign = { y };
        const union { float flVal; unsigned int nVal; } tXSign = { x };
        if (fabsf(x) >= fabsf(y)) {
            union { float flVal; unsigned int nVal; } tOffset = { M_PI };
            // Add or subtract PI based on y's sign.
            tOffset.nVal |= tYSign.nVal & 0x80000000u;
            // No offset if x is positive, so multiply by 0 or based on x's sign.
            tOffset.nVal *= tXSign.nVal >> 31;
            result = tOffset.flVal;
            const float z = y / x;
            result += (n1 + n2 * z * z) * z;
        }
        // Use atan(y/x) = pi/2 - atan(x/y) if |y/x| > 1.
        else {
            union { float flVal; unsigned int nVal; } tOffset = { M_PI_2 };
            // Add or subtract PI/2 based on y's sign.
            tOffset.nVal |= tYSign.nVal & 0x80000000u;
            result = tOffset.flVal;
            const float z = x / y;
            result -= (n1 + n2 * z * z) * z;
        }
    }
    else if (y > 0.0f) {
        result = M_PI_2;
    }
    else if (y < 0.0f) {
        result = -M_PI_2;
    }
    return result;
}



class StdRandomGaussian {
	mutable std::default_random_engine generator;
	mutable std::normal_distribution<double> distribution;
public:
	StdRandomGaussian(int length);
	double Get() const;
	void Seed();
};

StdRandomGaussian::StdRandomGaussian(int length) : distribution(0, sqrt((float)(1.0 / (double)(length)))) {Seed();}
double StdRandomGaussian::Get() const {return distribution(generator);}
void StdRandomGaussian::Seed() {generator.seed(::Native::NanoSeconds());}

StdRandomGaussian* CreateStdRandomGaussian(int length) {
	return new StdRandomGaussian(length);
}

}




NAMESPACE_MATH_END


