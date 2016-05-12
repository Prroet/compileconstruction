#include "Tokenizer.h"
#include <sstream>
#include <iostream>
//#include "Keyword.h"

Tokenizer::Tokenizer(std::ifstream* goFile, SymbolTable* symbolTable)
: _fileStream(goFile),	_symbolTable(symbolTable),	
						_lowerCase("abcdefghijklmnopqrstuvwxyz"), 
						_upperCase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
						_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"),
						_digit("0123456789"), 
						_delimiterSet("\t\n "), 
						_terminatorSet(";"),
						_parenthesis("(){}[]"),
						_stringQuote("\""),
						_integerLiteral(_digit),
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

	//_keywordFactory.setStringSet(_keywords);
	//_operatorFactory.setStringSet(_operands);

	getCurrentTokenID() = 0;

	if (islegalInput())
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

Tokenizer::token_value Tokenizer::peekNextToken(void) const
{
	if (getCurrentTokenID()<getTokenVector().size()) 
		return getTokenVector().at(getCurrentTokenID());
	else
		return NULL;	
}

void Tokenizer::tokenizeInput(void)
{
	std::string expression;
	const unsigned int str_size=256;
	char str_line[str_size];
	unsigned int line=1;
        
        std::ifstream* bla = &getFileStream();
	while(!bla->eof())
	{
		expression.clear();
		getFileStream().getline(str_line,str_size,'\n');
		std::stringstream lineStream(str_line);
		bool hasTerminator = false;

		while(!lineStream.eof())
		{
			lineStream>>expression;
                        std::cout << "expression: " <<expression << std::endl;
			
			//must have to avoid accessviolation in empty lines through iterators in expression
			if (str_line[0]=='\0')
				expression.push_back('\n');

			if (_terminatorSet.isSubset(*--expression.end())) 
			{
				hasTerminator= true;
				expression.erase(--expression.end());
			}
			
			pushToken(expression,line,hasTerminator);
		}
		++line;
	}
}

void Tokenizer::pushToken(const std::string& expression, unsigned int line, bool hasTerminator)
{
	static unsigned int symbolEntry=0;

	if (_keywords.isInSet(expression))
		getTokenVector().push_back(getKeywordFactory().getToken(expression.c_str(),line));
	else
		if (_operands.isInSet(expression))
			getTokenVector().push_back(getOperatorFactory().getToken(expression.c_str(),line));
		else
			if (_parenthesis.isSubset(*expression.begin()))
				getTokenVector().push_back(getParenthesisFactory().getToken(expression.c_str(),line));
			else
				if (_stringQuote.isString(expression))
					getTokenVector().push_back(new String(line,"str",_stringQuote.truncString(expression).c_str()));
				else									
					if(_integerLiteral.isInteger(expression))
						getTokenVector().push_back(new Integer(line,"num", _integerLiteral.StrToInt(expression)));	
					else
						if (!_delimiterSet.isSubset(*expression.begin()))
						{
							if(!getSymbolTable().isTableEntry(expression))
							{	
								++symbolEntry;
								getSymbolTable().insertEntry(symbolEntry,SymbolInfo(expression.c_str()));
								getTokenVector().push_back(new Identifier(line,"id",symbolEntry));
							}
							else
								getTokenVector().push_back(new Identifier(line,"id",getSymbolTable().findFirst(expression)));			
						}
	//Delimiters are ignored
	if (hasTerminator)
		getTokenVector().push_back(new Terminator(line,"term"));
}

bool Tokenizer::isLegalExpression(const std::string& expression) const
{
	if (	_operands.isInSet(expression) ||
			_stringQuote.isString(expression)	)
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

bool Tokenizer::islegalInput(void)
{
	std::string expression;
	bool result=true;
	const unsigned int str_size=256;

	char str_line[str_size];

	unsigned int line=1;

	while(!getFileStream().eof())
	{
		expression.clear();
		getFileStream().getline(str_line,str_size,'\n');
		std::stringstream lineStream(str_line);
		
		while(!lineStream.eof())
		{
			lineStream>>expression;
			if (str_line[0]=='\0')
				expression.push_back('\n');

			if (!isLegalExpression(expression))
			{			
				std::cout<<"Lexical Error in line: "<<line<<" ... '"<<expression<<"'"<<std::endl;
				result=false;
	//			option to throw exceptions
			}
		}
		++line;
	}
	getFileStream().seekg(0);
	return result;
}