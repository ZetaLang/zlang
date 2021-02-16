#ifndef __ZLANG_TOKEN_HPP__
#define __ZLANG_TOKEN_HPP__

#include <fstream>
#include <string>
#include <cctype>

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


static std::string identifier;
static double      number;


static zztoken gettok(std::fstream file) {
	static int last_char = ' ';

	while (isspace(last_char))
		file.get(last_char);

	if (isalpha(last_char)) {
		identifier = last_char;
		file.get(last_char);
		while (isalnum(last_char)) {
			identifier += last_char;
			file.get(last_char);
		}

		if (identifier == "fun") // function
			return zzfun;
		else if (identifier == "ext") // extern function
			return zzext;

		return zzidentifier;

	} else if (isdigit(last_char) || last_char == '.') {
		std::string number_str;
		do {
			number_str += last_char;
			file.get(last_char);
		} while (isdigit(last_char) || last_char == '.');

		number = strtod(number_str.c_str(), 0);
		return zznumber;
	}
}


#endif /* !__ZLANG_TOKEN_HPP__ */