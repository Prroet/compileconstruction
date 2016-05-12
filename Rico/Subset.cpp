#include "Subset.h"
#include <iostream>

bool Subset::isSubset(const char &chr) const
{
	//return (getSubset().find(chr) != std::string.npos);
        return(getSubset().find(chr) != std::string::npos);
}