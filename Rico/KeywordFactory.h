#ifndef _KEYWORDFACTORY_
#define _KEYWORDFACTORY_

#include "Keyword.h"
#include "TokenFactory.h"
#include <string>

class KeywordFactory : public TokenFactory
{
	public:
		typedef Keyword* keyword_ptr;

	public:
		inline								~KeywordFactory(void)													{};
				TokenFactory::token_ptr		getToken(const std::string& token_str, const unsigned int& line) const;
};

#endif _KEYWORDFACTORY_