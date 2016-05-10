#include "KeywordFactory.h"

TokenFactory::token_ptr KeywordFactory::getToken(const std::string& token_str, const unsigned int& line) const
{
	keyword_ptr return_value=NULL;

	std::string str_appendix("_kw");

	if (token_str.compare("break")==0)
		return_value=new Break(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("default")==0)
		return_value=new Default(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("func")==0)
		return_value=new Func(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("interface")==0)
		return_value=new Interface(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("select")==0)
		return_value=new Select(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("case")==0)
		return_value=new Case(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("defer")==0)
		return_value=new Defer(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("go")==0)
		return_value=new Go(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("map")==0)
		return_value=new Map(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("struct")==0)
		return_value=new Struct(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("chan")==0)
		return_value=new Chan(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("else")==0)
		return_value=new Else(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("goto")==0)
		return_value=new Goto(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("package")==0)
		return_value=new Package(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("switch")==0)
		return_value=new Switch(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("const")==0)
		return_value=new Const(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("fallthrough")==0)
		return_value=new Fallthrough(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("if")==0)
		return_value=new If(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("range")==0)
		return_value=new Range(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("type")==0)
		return_value=new Type(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("continue")==0)
		return_value=new Continue(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("for")==0)
		return_value=new For(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("import")==0)
		return_value=new Import(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("return")==0)
		return_value=new Return(line,(std::string(token_str)+str_appendix).c_str());
	else if (token_str.compare("var")==0)
		return_value=new Var(line,(std::string(token_str)+str_appendix).c_str());

	return static_cast<token_ptr>(return_value);
}