#ifndef _STRINGSET_
#define _STRINGSET_

#include <set>
#include <string>

class StringSet
{
	public:
		typedef std::set<std::string> string_set;
	
	private:	
		string_set _strings;

	private:
		inline	string_set&			getStrSet(void)									{ return _strings; };
		inline	const string_set&	getStrSet(void)	const							{ return _strings; };

	public:
		inline						StringSet(void)									{};
		inline 	explicit			StringSet(char** const StringList)				{ readFromStringList(StringList); };
		inline 						~StringSet(void)								{};

				void				readFromStringList(char** const stringList);
		inline	void				insertString(const std::string& _string)		{ getStrSet().insert(_string); };
				bool				isInSet(const std::string& str) const;
};

#endif _STRINGSET_