#ifndef _TOKENIZERLIB_
#define _TOKENIZERLIB_

#include "Subset.h"
#include <string>
//#include <map>
#include <vector>
#include <cstdlib>

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

class StringCheck
{
	private:
		const Subset _stringQuote;

	private:
		inline StringCheck (void) : _stringQuote(Subset("")) {};
		inline StringCheck& operator= (const StringCheck& right) { right; return *this; };

		inline const Subset& getQuote(void) const { return _stringQuote; };		

	public:
		inline StringCheck (const char* const sourceStr) : _stringQuote(sourceStr) {};
		bool isString (const std::string& str) const;
		const std::string truncString(std::string sourceStr) const;
};

class IntegerCheck
{
	private:
		const Subset _digit;

	private:
		inline IntegerCheck (void) : _digit(Subset("")) {};
		inline IntegerCheck& operator= (const IntegerCheck& right) { right; return *this; };

		inline const Subset& getDigits(void) const { return _digit; };		

	public:
		inline IntegerCheck (const char* const sourceStr) : _digit(sourceStr) {};
		inline IntegerCheck (const Subset& sourceSubset) : _digit(sourceSubset) {};
		bool isInteger (const std::string& str) const;
		inline int StrToInt(const std::string& str) const { return atoi(str.c_str()); };
};

class SymbolInfo
{
	private:
		std::string _identifierName;
		//other SymbolInfos

	private:
//		inline						SymbolInfo (void) : _identifierName("")											{};
//		inline						SymbolInfo& operator= (const SymbolInfo& right)									{ right; return *this; };

	public:
		inline						SymbolInfo (const char* const identifierName) : _identifierName(identifierName)	{};
		inline						~SymbolInfo (void)																{};

		inline	const std::string&	getName(void) const															{ return _identifierName; };
		inline  bool				operator==(const SymbolInfo& right) const	{ return (getName()==right.getName()); };
		inline	bool				operator!=(const SymbolInfo& right) const	{ return (getName()!=right.getName()); };
};

//test code
#include <iostream>
using std::cout;
using std::endl;

class SymbolTable
{
	private:
		typedef unsigned int						first_type;
		typedef SymbolInfo							second_type;	
		typedef std::pair<first_type, second_type>	tableValue;
		typedef std::vector<tableValue>				tableType;
		//typedef std::map<first_type, second_type>	tableType;
		
	private:
		tableType _symbolTable;

	private:
		inline	tableType&			getTable(void)			{ return _symbolTable; };
		inline	const tableType&	getTable (void) const	{ return _symbolTable; };

	public:
				void							insertEntry(const first_type& keyType, const second_type& symbolInfo);	
		inline	const second_type				getSymbol(const first_type& keyType) const 	{ return findSecond(keyType); };
		const second_type						findSecond(const first_type& findFirst) const;
		const first_type						findFirst(const std::string& findSecond) const;
		bool									isTableEntry(const std::string& searchVal) const;
		//test code
		inline	void							printSymbolTable(void)	{ for(tableType::const_iterator it=getTable().begin(); it!=getTable().end(); ++it) cout<<endl<<it->first<<" "<<it->second.getName()<<endl; };
};

#endif _TOKENIZERLIB_