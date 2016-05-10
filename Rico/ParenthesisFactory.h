#ifndef _PARENTHESISFACTORY_
#define _PARENTHESISFACTORY_

#include "Parenthesis.h"
#include "TokenFactory.h"
#include <string>

class ParenthesisFactory : public TokenFactory
{
	public:
		typedef Parenthesis* parenthesis_ptr;

	public:
		inline								~ParenthesisFactory(void)													{};
				TokenFactory::token_ptr		getToken(const std::string& token_str, const unsigned int& line) const;
};
#endif _PARENTHESISFACTORY_