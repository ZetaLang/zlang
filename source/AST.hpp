#ifndef __ZLANG_AST_HPP__
#define __ZLANG_AST_HPP__

#include <string>
#include <memory>

/* expression abstract syntax tree class */
class __EXPRESSION_AST__ {
public:
	virtual ~__EXPRESSION_AST__() {}
};

/* number expression AST */
class numexprAST : public __EXPRESSION_AST__ {
	double Val;

public:
	numexprAST(double Val) : Val(Val) {}
};

/* variable expression AST */
class varexprAST : public __EXPRESSION_AST__ {
	std::string Name;

public:
	varexprAST(const std::string& Name) : Name(Name) {}
};

/* binary expression AST */
class binexprAST : public __EXPRESSION_AST__ {
	char Op;
	std::unique_ptr<__EXPRESSION_AST__> LHS, RHS;

public:
	binexprAST(char op, std::unique_ptr<__EXPRESSION_AST__> LHS,
	           std::unique_ptr<__EXPRESSION_AST__> RHS)
	           : Op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};

/* function calls AST */
class callexprAST : public __EXPRESSION_AST__ {
	std::string Callee;
	std::vector<std::unique_ptr<__EXPRESSION_AST__>> Args;

public:
	CallExprAST(const std::string& Callee,
		std::vector<std::unique_ptr<__EXPRESSION_AST__>> Args)
		: Callee(Callee), Args(std::move(Args)) {}
};


#endif /* !__ZLANG_AST_HPP__ */