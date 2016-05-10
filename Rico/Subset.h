#ifndef _SUBSET_
#define _SUBSET_

#include <string>

class Subset
{
	private:
		std::string _subset;
	
	private:
		inline						Subset(void)								{};

	protected:
		inline	const std::string&	getSubset(void) const						{ return _subset; };

	public:
		inline	explicit			Subset(const char* const sourceStr) : _subset(sourceStr) {};
		inline						~Subset(void)								{};

				bool				isSubset (const char& chr) const;
};

class TerminatorSet : public Subset
{

	public:
		inline	explicit			TerminatorSet(const char* const sourceStr) : Subset(sourceStr) {};
		inline						~TerminatorSet(void)						{};
		
		inline	const char&			getFirstTerminator(void) const				{ return *Subset::getSubset().begin(); };
};

#endif _SUBSET_