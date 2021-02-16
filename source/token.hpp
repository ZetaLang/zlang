#ifndef __ZLANG_TOKEN_HPP__
#define __ZLANG_TOKEN_HPP__

#include <fstream>
#include <string>
#include <cctype>

typedef enum __ZZ_TOKEN__ {
	/* EOF token */
	zzeof = -1,

	/* keywords */
	zzfun = -2,     // fun [function_name][args]    | function definition
	zzext = -3,     // ext [function_name][args]    | extern function definition
	zzlet = -4,     // let [variable_name] = [args] | variable declaration

	/* types */
	zzidentifier = -5, // for example: x
	zznumber     = -6, // for example: 2
	zzstring     = -7  // for example: "Hello"
} zztoken;


static std::string identifier;
static std::string string;
static double      number;


static zztoken gettok(std::fstream file) {
	static int last_char = ' ';

	while (isspace(last_char))
		file.get(last_char);

	if (last_char == '"' || last_char == '\'') {
		int used_char = last_char;
		string = last_char;
		file.get(last_char);
		while (last_char != used_char) {
			string += last_char;
			file.get(last_char);
		}

		return zzstring;

	} else if (isalpha(last_char)) {
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
		else if (identifier == "let") // variable declaration
			return zzlet;

		return zzidentifier;

	} else if (isdigit(last_char) || last_char == '.') {
		std::string number_str;
		do {
			number_str += last_char;
			file.get(last_char);
		} while (isdigit(last_char) || last_char == '.');

		number = strtod(number_str.c_str(), 0);
		return zznumber;

	} else if (last_char == '#') {   // 1 line comment
		do
			file.get(last_char);
		while (last_char != EOF && last_char != '\n' && last_char != '\r');

		if (last_char != EOF)
			return gettok(file)
	}

	if (last_char == EOF)
		return zzeof;

	int c = last_char;
	file.get(last_char);
	return c;
}


#endif /* !__ZLANG_TOKEN_HPP__ */
