#include "user_atof.hpp"


/*
	double representation = [sign] mantissa(normalized) * 10 ^ [sign]exponent;
*/
double user_atof(const char* str) {
	if (str == nullptr)
		return 0.;
	double denormMantissa;    //raw mantissa
    double decPart;    //for normalization
    double exp;           //exponent

    int sign = 1;       //mantissa's sign
    int expSign = 1;      //10^(expSign*p)

    while (*str && isspace(*str))
        ++str;

    if (*str == '+')
        ++str;
    if (*str == '-') {
        sign = -1;
        ++str;
    }
    if ((*str == 'n' || *str == 'N') && 
       (str[1] == 'a' || str[1] == 'A') 
       && (str[2] == 'n' || str[2] == 'N'))
            return NAN * sign;
    if ((*str == 'i' || *str == 'I') && (str[1] == 'n' || str[1] == 'N') && 
        (str[2] == 'f' || str[2] == 'F'))
              return INFINITY * sign;

    for (denormMantissa = 0; *str && isdigit(*str); ++str)
        denormMantissa = denormMantissa * 10 + (*str - '0');

    if (*str == '.')
        ++str;
    for (decPart = 1.; *str && isdigit(*str); ++str, decPart *= 10.)
        denormMantissa = denormMantissa * 10. + (*str - '0');

    if (*str == 'e' || *str == 'E') {
        //default raw mantissa = 1
        if (denormMantissa == 0)
            denormMantissa = 1;
        ++str;
        if (*str == '-') {
            expSign = -1;
            ++str;
        }
        if (*str == '+')
            ++str;
        for (exp = 0; *str && isdigit(*str); ++str)
            exp = exp * 10 + (*str - '0');

        exp *= expSign;
    }
    else
        exp = 0;

    return static_cast<double>((denormMantissa * sign / decPart) * pow(10, exp));
}