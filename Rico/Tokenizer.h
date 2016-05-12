#ifndef _TOKENIZER_
#define _TOKENIZER_

#include <fstream>
#include <vector>
#include <string>


#include "Token.h"
#include "Subset.h"
#include "StringSet.h"
#include "TokenizerLib.h"
#include "KeywordFactory.h"
#include "OperatorFactory.h"
#include "ParenthesisFactory.h"

class Tokenizer
{
	private:
		typedef Token*						token_value;
		typedef std::vector<token_value>	vector_type;


	private:
		vector_type		_tokenVector;
		std::ifstream*	_fileStream;
		SymbolTable*	_symbolTable;

		const Subset		_lowerCase;	
		const Subset		_upperCase;	
		const Subset		_alpha;		
		const Subset		_digit;		
		const Subset		_delimiterSet;	
		const TerminatorSet	_terminatorSet;
		const Subset		_parenthesis;
		const StringCheck	_stringQuote;
		const IntegerCheck	_integerLiteral;
		const AlphaNum		_alphaNum;
	
		StringSet			_keywords;
		StringSet			_operands;

		KeywordFactory	_keywordFactory;
		OperatorFactory _operatorFactory;
		ParenthesisFactory _parenthesisFactory;
	
		unsigned int	_currentTokenID;

	private:
		inline						Tokenizer(void):_lowerCase(""), _upperCase(""), _alpha(""), _digit(""), 
													_delimiterSet(""), _terminatorSet(""), _parenthesis(""),
													_stringQuote(""), _integerLiteral(""), _alphaNum(_alpha,_digit) {};
		inline	Tokenizer&			operator= (const Tokenizer& right)	{ right; return *this; };
	
		inline	vector_type&		getTokenVector(void)				{ return _tokenVector; };
		inline	const vector_type&	getTokenVector(void) const			{ return _tokenVector; };
		inline	unsigned int&		getCurrentTokenID(void)		 		{ return _currentTokenID; };
		inline	const unsigned int&	getCurrentTokenID(void) const		{ return _currentTokenID; };
		inline	std::ifstream&		getFileStream(void)					{ return *_fileStream; };
		inline	SymbolTable&		getSymbolTable(void)				{ return *_symbolTable; };
		inline	const KeywordFactory&		getKeywordFactory(void) const		{ return _keywordFactory; };
		inline	const OperatorFactory&		getOperatorFactory(void) const		{ return _operatorFactory; };
		inline	const ParenthesisFactory&	getParenthesisFactory(void) const	{ return _parenthesisFactory; };
				void				tokenizeInput(void);
				bool				isLegalExpression(const std::string& expression) const;
				bool				islegalInput(void);
				void				pushToken(const std::string& expression, unsigned int line, bool hasTerminator);


	public:
		explicit					Tokenizer(std::ifstream* goFile, SymbolTable* symbolTable);
				token_value			getNextToken(void);
				token_value			peekNextToken(void) const;
									~Tokenizer(void);


};

#endif _TOKENIZER_