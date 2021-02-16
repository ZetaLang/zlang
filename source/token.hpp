#ifndef __ZLANG_TOKEN_HPP__
#define __ZLANG_TOKEN_HPP__

#include <string>

typedef enum __ZZ_TOKEN__ {
	/* EOF token */
	zzeof = -1,

	/* keywords */
	zzfun = -2,     // fun [function_name][args] | function definition
	zzext = -3,     // ext [function_name][args] | extern function definition

	/* types */
	zzidentifier = -4, // for example: x
	zznumber     = -5, // for example: 2
	zzstring     = -6  // for example: "Hello"
} zztoken;


#endif /* !__ZLANG_TOKEN_HPP__ */