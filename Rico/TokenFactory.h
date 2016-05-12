#ifndef _TOKENFACTORY_
#define _TOKENFACTORY_

#include "Token.h"
#include <string>

class TokenFactory
{
	public:
		typedef Token* token_ptr;

	public:
		TokenFactory(void);
		virtual ~TokenFactory(void);
		
		virtual token_ptr getToken(const std::string& token_str, const unsigned int& line) const = 0;
};
#endif _TOKENFACTORY_