#include <iostream>

#include "Lexor.class.h"
#include "Parser.class.h"

using namespace std;

int main() {
	Lexor* lex = (new Lexor())->Read("input.txt")->Print();
	//Parser* pa = (new Parser(lex))->Start();

	cout << endl;
	return 0;
}
