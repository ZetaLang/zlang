#ifndef __ZLANG_ZZERROR_H__
#define __ZLANG_ZZERROR_H__

#include <cstddef>
#include "AST.hpp"

std::unique_ptr<__EXPRESSION_AST__> LogError(const char* str) {
	fprintf(stderr, "zlang log error: %s\n", str);
	return nullptr;
}

std::unique_ptr<prototypeAST> LogErrorP(const char* str) {
	LogError(str);
	return nullptr;
}


#endif /* !__ZLANG_ZZERROR_H__ */