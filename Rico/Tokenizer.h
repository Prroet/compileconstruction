#ifndef _TOKENIZER_
#define _TOKENIZER_

#include <fstream>
#include <vector>
#include <string>


#include "Token.h"
#include "Subset.h"
#include "StringSet.h"
#include "TokenizerLib.h"

class Tokenizer
{
	private:
		typedef Token*						token_value;
		typedef std::vector<token_value>	vector_type;


	private:
		vector_type		_tokenVector;
		std::ifstream*	_fileStream;

		const Subset	_lowerCase;	
		const Subset	_upperCase;	
		const Subset	_alpha;		
		const Subset	_digit;		
		const Subset	_delimiterSet;	
		const Subset	_terminatorSet;
		const Subset	_parenthesis;
		const AlphaNum	_alphaNum;

		StringSet		_keywords;
		StringSet		_operands;

		unsigned int	_currentTokenID;

	private:
		inline						Tokenizer(void):_lowerCase(""), _upperCase(""), _alpha(""), _digit(""), _delimiterSet(""), _terminatorSet(""), _parenthesis(""),_alphaNum(_alpha,_digit) {};
		inline	Tokenizer&			operator= (const Tokenizer& right)	{ right; return *this; };
	
		inline	vector_type&		getTokenVector(void)				{ return _tokenVector; };
		inline	unsigned int&		getCurrentTokenID(void)		 		{ return _currentTokenID; };
		inline	std::ifstream&		getFileStream(void)					{ return *_fileStream; };
				void				tokenizeInput(void);
				bool				isLegalExpression(const std::string& expression) const;
				bool				legalInput(void);

	public:
		explicit					Tokenizer(std::ifstream* goFile);
				token_value			getNextToken(void);
									~Tokenizer(void);


};

#endif _TOKENIZER_