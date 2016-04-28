#ifndef _SUBSET_
#define _SUBSET_

#include <string>

class Subset
{
	private:
		std::string _subset;
	
	private:
		inline						Subset(void)								{};
		inline	const std::string&	getSubset(void) const						{ return _subset; };

	public:
		inline	explicit			Subset(const char* const sourceStr) : _subset(sourceStr) {};
		inline						~Subset(void)								{};

				bool				isSubset (const char& chr) const;
};

#endif _SUBSET_