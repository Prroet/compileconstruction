#include "TokenizerLib.h"

AlphaNum::AlphaNum(const Subset &alpha, const Subset &numeric)
: _alpha(alpha), _numeric(numeric)
{

}

bool AlphaNum::isAlphaNum(const char& chr) const
{
	return ( getAlpha().isSubset(chr) || getNum().isSubset(chr) );
}

bool StringCheck::isString(const std::string &str) const
{
	bool stringClosed=false;

	if(str.size()!=0)
		if (str.at(0)=='\"') //string opened
		{
			for (std::string::const_iterator it=(++str.begin()); it!=str.end(); ++it)
			{
				if (stringClosed && *it!=';')
					return false;

				if (*it=='\"') stringClosed=true;
			}
			return true;
		}
		else
			return false;
	else
		return false;
}

const std::string StringCheck::truncString(std::string sourceStr) const
{
	if(sourceStr.size()!=0)
		if (sourceStr.at(0)=='\"') //string opened
		{
			sourceStr.erase(sourceStr.begin());
			for (std::string::iterator it=sourceStr.begin(); it!=sourceStr.end(); ++it)
				if (*it=='\"')
				{
					sourceStr.erase(it--);
				}
			return sourceStr;
		}
		else
			return sourceStr;
	else
		return sourceStr;
}

bool IntegerCheck::isInteger(const std::string& str) const
{
	bool result=true;

	if (!str.empty())
		for(unsigned int i=0; i<str.size() ; ++i)
			if(!getDigits().isSubset(str.at(i)))
				result=false;
	return result;
}

const SymbolTable::second_type SymbolTable::findSecond(const SymbolTable::first_type& findFirst) const
{
	tableType::const_iterator it=getTable().begin();
	if (!getTable().empty())
	{
		for(; (it!=getTable().end()) && (it->first!=findFirst); ++it);

		if (it->first==findFirst)
			return it->second;
		else
			return SymbolTable::second_type("");
	}
	else
		return SymbolTable::second_type("");
}

const SymbolTable::first_type SymbolTable::findFirst(const std::string& findSecond) const
{
	tableType::const_iterator it=getTable().begin();
	if (!getTable().empty())
	{
		for(; (it!=getTable().end()) && (it->second.getName()!=findSecond); ++it);

		if (it->second.getName()==findSecond)
			return it->first;
		else
			return SymbolTable::first_type(0);
	}
	else
		return SymbolTable::first_type(0);
}

void SymbolTable::insertEntry(const SymbolTable::first_type& keyType, const SymbolTable::second_type& symbolInfo)
{
	if (!getTable().empty())
		getTable().insert(--getTable().end(),tableValue(keyType,symbolInfo));
	else
		getTable().insert(getTable().begin(),tableValue(keyType,symbolInfo));
}

bool SymbolTable::isTableEntry(const std::string& searchVal) const
{
	for (tableType::const_iterator it=getTable().begin(); it!=getTable().end(); ++it)
		if (it->second.getName()==searchVal) return true;
	return false;
}
