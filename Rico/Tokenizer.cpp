#include "Tokenizer.h"
#include <sstream>
#include <iostream>

Tokenizer::Tokenizer(std::ifstream* goFile)
: _fileStream(goFile),	_lowerCase("abcdefghijklmnopqrstuvwxyz"), 
						_upperCase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
						_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"),
						_digit("0123456789"), 
						_delimiterSet("\t\n "), 
						_terminatorSet(";"),
						_parenthesis("(){}[]"),
						_alphaNum(_alpha, _digit)
{
	char* keywordCStr[26]	= {	"break", "default", "func", "interface", "select", 
								"case", "defer", "go", "map", "struct", 
								"chan", "else", "goto", "package", "switch",
								"const", "fallthrough", "if", "range", "type", 
								"continue", "for", "import", "return", "var", "\0" };
	_keywords.readFromStringList(keywordCStr);

	char* operandCStr[40]	= {	"+", "*", "=", "+=", "&=", "==", "&&", "!=",
								"-", "|", "-=", "|=", "||", "<", "<=", "*=", 
								"^", "^=", "<-", ">", ">=", "/", "<<", "/=", 
								"<<=", "++", ":=", "%", ">>", "%=", ">>=", "--",
								"!", "...", ".", ",", ":", "&^", "&^=", "\0"};
	_operands.readFromStringList(operandCStr);

	getCurrentTokenID() = 0;

	if (legalInput())
		tokenizeInput();
}

Tokenizer::~Tokenizer(void)
{
	for (unsigned int i=0; i<getTokenVector().size(); i++)
		delete getTokenVector().at(i);
}

Tokenizer::token_value Tokenizer::getNextToken(void) 
{
	if (getCurrentTokenID()<getTokenVector().size()) 
		return getTokenVector().at(getCurrentTokenID()++);
	else
		return NULL;
}

void Tokenizer::tokenizeInput(void)
{
	std::string expression;

	const unsigned int str_size=256;

	char str_line[str_size];

	unsigned int line=1;

	while(!getFileStream().eof())
	{
		expression.clear();
		getFileStream().getline(str_line,str_size,'\n');

		std::stringstream lineStream(str_line);
		
		bool hasSemicolon = false;

		while(!lineStream.eof())
		{
			lineStream>>expression;
			
			//must have to avoid accessviolation in empty lines through iterators in expression
			if (str_line[0]=='\0')
				expression.push_back('\n');

			if (_terminatorSet.isSubset(*--expression.end())) 
			{
				hasSemicolon = true;
				expression.erase(--expression.end());
			}

			if (_keywords.isInSet(expression))
				getTokenVector().push_back(new Keyword(line,expression.c_str()));
			else
				if (_operands.isInSet(expression))
					getTokenVector().push_back(new Operator(line,expression.c_str()));
				else
					if (_parenthesis.isSubset(*expression.begin()))
						getTokenVector().push_back(new Parenthesis(line,expression.c_str()));
					else
						if (!_delimiterSet.isSubset(*expression.begin()))
							getTokenVector().push_back(new Identifier(line,expression.c_str()));
			//Delimiters are ignored

			if (hasSemicolon)
				getTokenVector().push_back(new Semicolon(line,";"));
		}
		++line;
	}
}

bool Tokenizer::isLegalExpression(const std::string& expression) const
{
	if (_operands.isInSet(expression))
		return true;
	else
		for (unsigned int i = 0; i<expression.size(); i++)
		{
			if (!(	_alphaNum.isAlphaNum(expression.at(i))			||
					_terminatorSet.isSubset(expression.at(i))		||						
					_delimiterSet.isSubset(expression.at(i))		||	
					_parenthesis.isSubset(expression.at(i))		))
				return false;
		}	

	return true;
}

bool Tokenizer::legalInput(void)
{
	std::string expression;
	bool result=true;
	const unsigned int str_size=256;

	char str_line[str_size];

	unsigned int line=1;

	while(!getFileStream().eof())
	{
		getFileStream().getline(str_line,str_size,'\n');
		std::stringstream lineStream(str_line);
		
		while(!lineStream.eof())
		{
			lineStream>>expression;

			if (!isLegalExpression(expression))
			{			
				std::cout<<"Lexical Error in line: "<<line<<" ... '"<<expression<<"'"<<std::endl;
				result=false;
			}
	//			throwing exceptions
		}
		++line;
	}
	getFileStream().seekg(0);
	return result;
}