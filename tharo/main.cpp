#include <iostream>

#include "Lexor.class.h"

using namespace std;

int main() {
	Lexor* lex = (new Lexor())->Read("input.txt")->Print();

	cout << endl;
	return 0;
}
