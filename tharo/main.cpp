#include <iostream>

#include "lexor.h"

using namespace std;

int main() {
	(new Lexor())->Read("input.txt")->Print();

	cout << endl;
	return 0;	
}
