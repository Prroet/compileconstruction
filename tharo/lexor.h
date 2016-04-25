#ifndef LEXOR_H
#define LEXOR_H

#include <vector>
#include <string>
#include <fstream>
#include <functional>

enum class token_ident {
	eof,

	// litherals
	operand,
	delimiter,

	// primary
	identifier,
	number,
	string, 
	
	// comments
	oneline_comment,

	// blocks
	list_open, list_close,		// ( )
	option_open, option_close,	// [ ]
	block_open,	block_close,	// { }

	// others
	error,
};

typedef struct {
	int type;
	std::string value;
} token;


class Lexor {
	private:
		std::vector<token>	tokens;
		std::string 		filename;
		std::ifstream		instream;
		
		token getToken();
		token buildWord(std::function<int (int)>, char, int);

	public:
		Lexor();
		Lexor* Read(std::string);
		Lexor* Print();
};

#endif

