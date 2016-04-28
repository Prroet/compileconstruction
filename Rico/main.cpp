#include <fstream>
#include "Tokenizer.h"

int main (int argc, char** argv)
{
	std::ifstream goFile("Beispiel2.go", std::ios::in);

	Tokenizer Lexer(&goFile);

	goFile.close();

	//AlphaNum AlNu(Alpha,Digit);
	//
	////if (ops.isOperator("="))
	////	return 0;
	////else
	////	return 1;
	////	
	//std::string str;
	//

	//goFile>>str;

	//
	//bool legalAlphaNum = true;
	//bool Semicolon = false;

	//if (*--str.end() == ';') 
	//{
	//	Semicolon = true;
	//	str.erase(--str.end());
	//}

	//for (unsigned int i = 0; (i<str.size()) && (legalAlphaNum == true); i++)
	//	legalAlphaNum = AlNu.isAlphaNum(str.at(i));

	//using std::vector;
	//
	//typedef std::vector<Token*> vector_type;

	//vector_type tokenVec;

	//if (keywords.isInSet(str))
	//	tokenVec.push_back(new Keyword(1,str.c_str()));

	//

	//goFile>>str;
	//goFile>>str;


	//char inputLine[200];

	//goFile.getline(inputLine,200, '\n');

	
	


	return 0;
}