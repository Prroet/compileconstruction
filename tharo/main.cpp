#include <iostream>

#include "lexor.h"

using namespace std;

int main() {
	Lexor* lex = new Lexor();
	lex->Read("input.txt");
	lex->Print();

	cout << endl;
	return 0;	
}
