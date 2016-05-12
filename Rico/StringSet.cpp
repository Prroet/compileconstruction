#include "StringSet.h"

void StringSet::readFromStringList(char** const stringList)
{
	for (unsigned int i=0; *stringList[i]!='\0'; i++)
		insertString(std::string(stringList[i]));
}

bool StringSet::isInSet(const std::string& str) const
{ 
	return (getStrSet().find(str) != getStrSet().end()); 
}