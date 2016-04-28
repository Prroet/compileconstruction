#include "TokenizerLib.h"

AlphaNum::AlphaNum(const Subset &alpha, const Subset &numeric) 
: _alpha(alpha), _numeric(numeric)
{

}

bool AlphaNum::isAlphaNum(const char& chr) const
{
	return ( getAlpha().isSubset(chr) || getNum().isSubset(chr) );
}