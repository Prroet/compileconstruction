#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <functional>

using namespace std;



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
	string value;
} token;


/** baut ein wort. erwartet eine vergleichsoption die char nimmt und bool zurück gibt **/
token buildWord(function<int (int)> fp, ifstream &is, char lastChar, int id) {
	token ret = {0, "EOF"};	
	string str = {lastChar};	

	while (fp(lastChar)) {
		if(is.eof()) break;		// eof als Abschluss
   		is.get(lastChar);
		str += lastChar;
	}

	// last read was NOT valid: restore it, cut it!
	is.seekg(-1, ios::cur);
	str.pop_back();

	ret.type = id;
	ret.value = str;/**/

	return ret;
}/**/


/** operanten (Deren Bestandteile) im Sinne unseres Syntaxes**/
int isOperator(int c) {
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='=' || c=='<' || c=='>') || 
		   (c==':') || (c=='.') || (c==',') || 
		   (c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}');
}


/** delimiter, ergo trennzeichen zwischen befehlen **/
int isDelimiter(int c) {
	return (c=='\n' || c==';');
}


/** **/
token getToken(ifstream &is) {
	char lastChar;
	token ret;
	ret.type = static_cast<int>(token_ident::eof);
	ret.value = "";

	// get char
	is.get(lastChar);

	// kill "spaces"
	while (lastChar==' ' || lastChar=='\t' || lastChar=='\r') {
		if(is.eof()) return ret;
   		is.get(lastChar);
	}

	// singletons
	ret.value += lastChar;
	if(lastChar=='(') {	ret.type = static_cast<int>(token_ident::list_open); return ret; }
	if(lastChar==')') {	ret.type = static_cast<int>(token_ident::list_close); return ret; }
	if(lastChar=='[') {	ret.type = static_cast<int>(token_ident::option_open); return ret; }
	if(lastChar==']') {	ret.type = static_cast<int>(token_ident::option_close); return ret; }
	if(lastChar=='{') {	ret.type = static_cast<int>(token_ident::block_open); return ret; }
	if(lastChar=='}') {	ret.type = static_cast<int>(token_ident::block_close); return ret; }
	
	// delimiter?
	if(isDelimiter(lastChar)) {
		// merge delimiters
		//return buildWord(isDelimiter, is, lastChar, static_cast<int>(token_ident::delimiter));

		while(isDelimiter(lastChar)) {
			if(is.eof()) return ret;
   			is.get(lastChar);
		}

		// last read was NOT valid: restore it, cut it!
		is.seekg(-1, ios::cur);

		ret.type = static_cast<int>(token_ident::delimiter); 
		return ret;
	}

	// get identifyers and controll words
	if (isalpha(lastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
		auto fp = [](int c)->int{return isalnum(c);};
		return buildWord(fp, is, lastChar, static_cast<int>(token_ident::identifier));
	}

	// get numbers
	if (isdigit(lastChar)) {   // Number: [0-9.]+
		auto fp = [](int c)->int{return isdigit(c);};
		return buildWord(fp, is, lastChar, static_cast<int>(token_ident::number));
	
		//TODO: use for something - should we check for "this is a number"?
		//NumVal = strtod(NumStr.c_str(), 0);
	}

	// get comments
	if (lastChar == '#') {
		auto fp = [](int c)->int{ return (c!='\n' && c!='\r'); };
		return buildWord(fp, is, lastChar, static_cast<int>(token_ident::oneline_comment));
	}
	if (lastChar == '/' && is.peek() == '/') {
		auto fp = [](int c)->int{ return (c!='\n' && c!='\r'); };
		return buildWord(fp, is, lastChar, static_cast<int>(token_ident::oneline_comment));
	}	

	// get operants
	if(isOperator(lastChar)) {
		return buildWord(isOperator, is, lastChar, static_cast<int>(token_ident::operand));
	}

	if(lastChar == '"') {
		string StrValue = "";
		//TODO: needs an advanced lambda function. since its the only "block"-lex we do so far
		// i leave it as it was

		do {
			if(is.eof()) {
				ret.type = static_cast<int>(token_ident::string);
				ret.value = "Unsescaped String (EOF)";
				return ret;
			}

   			is.get(lastChar);
			if(lastChar=='"') break;
			if(lastChar=='\n' || lastChar=='\r') {
				ret.type = static_cast<int>(token_ident::string);
				ret.value = "Unsescaped String";
				return ret;
			}

			StrValue += lastChar;
		} while (1);

		ret.type = static_cast<int>(token_ident::string);
		ret.value = StrValue;
    	return ret;
	}

	// whatever.
	ret.type = 0;
	ret.value = "unknown";
	return ret;
}


/** öffnet eine Datei und ließt den Inhalt characterweise ein **/
void readFile(std::string filename) {
	ifstream is;
	is.open(filename.c_str(), ios_base::in);
	
	if(!is) {

	}

	token toki;
	while(!is.eof()) {
		toki = getToken(is);

		// for debugging
		if(toki.type!=2)
			cout << "(" << toki.type << ") " << toki.value << endl;
	}

	is.close();
} 



int main() {
	readFile("input.txt");
	cout << endl;
	return 0;	
}
