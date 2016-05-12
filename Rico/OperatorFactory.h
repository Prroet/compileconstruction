#ifndef _OPERATORFACTORY_
#define _OPERATORFACTORY_

#include "Operator.h"
#include "TokenFactory.h"
#include <string>

class OperatorFactory : public TokenFactory
{
	public:
		typedef Operator* operator_ptr;

	public:
		inline								~OperatorFactory(void)													{};
				TokenFactory::token_ptr		getToken(const std::string& token_str, const unsigned int& line) const;
};

#endif _OPERATORFACTORY_