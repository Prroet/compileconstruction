#include <iostream>

#include "Lexor.class.h"
#include "Parser.class.h"

using namespace std;

int main(int argc, char *argv[]) {
	string file = "input.txt";
	
	if(argc==2) file = argv[1];

	Lexor* lex = (new Lexor())->Read(file)->Filter()->Print();
	Parser* pa = (new Parser(lex))->Start()->Print();

	cout << endl;
	return 0;
}
