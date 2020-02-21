#include "user_atof.hpp"

float user_atof(const char* str) {
	    double a;           /* the a value in a*10^b */
    double decplace;    /* number to divide by if decimal point is seen */
    double b;           /* The b value (exponent) in a*10^b */

    int sign = 1;       /* stores the sign of a */
    int bsign = 1;      /* stores the sign of b */

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

    for (a = 0; *str && isdigit(*str); ++str)
        a = a * 10 + (*str - '0');

    if (*str == '.')
        ++str;
    for (decplace = 1.; *str && isdigit(*str); ++str, decplace *= 10.)
        a = a * 10. + (*str - '0');

    if (*str == 'e' || *str == 'E') {
        /* if the user types a string starting from e, make the base be 1 */
        if (a == 0)
            a = 1;
        ++str;
        if (*str == '-') {
            bsign = -1;
            ++str;
        }
        if (*str == '+')
            ++str;
        for (b = 0; *str && isdigit(*str); ++str)
            b = b * 10 + (*str - '0');

        b *= bsign;
    }
    else
        b = 0;

    return (a * sign / decplace) * pow(10, b);
}