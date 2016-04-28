#ifndef _TOKENIZERLIB_
#define _TOKENIZERLIB_

#include "Subset.h"

class AlphaNum
{
	private:
		const Subset _alpha;
		const Subset _numeric;

	private:
		inline AlphaNum (void) : _alpha(Subset("")), _numeric(Subset("")) {};
		inline AlphaNum& operator= (const AlphaNum& right) { right; return *this; };

		inline const Subset& getAlpha(void) const { return _alpha; };
		inline const Subset& getNum(void) const { return _numeric; };
		

	public:
		AlphaNum (const Subset& alpha, const Subset& numeric);
		bool isAlphaNum (const char& chr) const;

};


#endif _TOKENIZERLIB_