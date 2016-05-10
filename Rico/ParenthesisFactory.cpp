#include "ParenthesisFactory.h"

TokenFactory::token_ptr ParenthesisFactory::getToken(const std::string& token_str, const unsigned int &line) const
{
	parenthesis_ptr return_value=NULL;

	std::string str_appendix("_pt");

	if (token_str.compare("(")==0)
		return_value=new LeftParenthesis(line,(std::string("LeftParenthesis")+str_appendix).c_str());
	else if (token_str.compare(")")==0)
		return_value=new RightParenthesis(line,(std::string("RightParenthesis")+str_appendix).c_str());
	else if (token_str.compare("[")==0)
		return_value=new SquaredBracketOpen(line,(std::string("SquaredBracketOpen")+str_appendix).c_str());
	else if (token_str.compare("]")==0)
		return_value=new SquaredBracketClose(line,(std::string("SquaredBracketClose")+str_appendix).c_str());
	else if (token_str.compare("{")==0)
		return_value=new LeftCurlyBracket(line,(std::string("LeftCurlyBracket")+str_appendix).c_str());
	else if (token_str.compare("}")==0)
		return_value=new RightCurlyBracket(line,(std::string("RightCurlyBracket")+str_appendix).c_str());
	//else if (parenthesis_str.compare(":=")==0)
	//	return_value=new InitAssign(line,(std::string("InitAssign")+str_appendix).c_str());
	//else if (operator_str.compare("go")==0)
	//	return_value=new Go(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("map")==0)
	//	return_value=new Map(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("struct")==0)
	//	return_value=new Struct(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("chan")==0)
	//	return_value=new Chan(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("else")==0)
	//	return_value=new Else(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("goto")==0)
	//	return_value=new Goto(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("package")==0)
	//	return_value=new Package(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("switch")==0)
	//	return_value=new Switch(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("const")==0)
	//	return_value=new Const(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("fallthrough")==0)
	//	return_value=new Fallthrough(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("if")==0)
	//	return_value=new If(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("range")==0)
	//	return_value=new Range(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("type")==0)
	//	return_value=new Type(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("continue")==0)
	//	return_value=new Continue(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("for")==0)
	//	return_value=new For(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("import")==0)
	//	return_value=new Import(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("return")==0)
	//	return_value=new Return(line,(std::string(operator_str)+str_appendix).c_str());
	//else if (operator_str.compare("var")==0)
	//	return_value=new Var(line,(std::string(operator_str)+str_appendix).c_str());

	return static_cast<token_ptr>(return_value);
}