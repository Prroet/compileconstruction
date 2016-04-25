#include <iostream>
#include <cctype>

using namespace std;

#include "Lexor.class.h"

// ---------------------------------------

/** operanten (Deren Bestandteile) im Sinne unseres Syntaxes**/
int isOperator(int c) {
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='=' || c=='<' || c=='>') || 
		   (c==':') || (c=='.') || (c==',') || 
		   (c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}');
}


/** delimiter, ergo trennzeichen zwischen befehlen **/
int isDelimiter(int c) {
	return (c=='\n' || c==';');
	//TODO: \n is not always delimiter
}


// ----------------------- 

Lexor::Lexor() {
	this->keyWords = {"break","default","func","interface","select","case","defer","go","map","struct","chan",
    "else","goto","package","switch","const", "fallthrough", "if", "range", "type", "continue","for", "import", "return", "var"};
}


/** starts reading and tokenisize the given filename **/
Lexor* Lexor::Read(std::string fname) {
	this->filename = fname;
	this->instream.open(this->filename.c_str(), ios_base::in);
	
	if(!this->instream) {
		//TODO: throw something
	}

	token toki;
	while(!this->instream.eof()) {
		toki = this->getToken();
		this->tokens.push_back(toki);
	}

	this->instream.close();
	return this;
}


/** prints out our tokens **/
Lexor* Lexor::Print() {
	for (auto t : this->tokens ) {
		cout << "\033[1;31m(" << t.type << ")\033[0m";
		cout << t.value << " ";
	}
	return this;
}


/** catches the next token **/
token Lexor::getToken() {
	char lastChar;
	token ret;
	ret.type = ECast(eof);
	ret.value = "";

	// get char
	this->instream.get(lastChar);

	// kill "spaces"
	while (lastChar==' ' || lastChar=='\t' || lastChar=='\r') {
		if(this->instream.eof()) return ret;
   		this->instream.get(lastChar);
	}

	// singletons
	ret.value += lastChar;
	if(lastChar=='(') {	ret.type = ECast(list_open); return ret; }
	if(lastChar==')') {	ret.type = ECast(list_close); return ret; }
	if(lastChar=='[') {	ret.type = ECast(option_open); return ret; }
	if(lastChar==']') {	ret.type = ECast(option_close); return ret; }
	if(lastChar=='{') {	ret.type = ECast(block_open); return ret; }
	if(lastChar=='}') {	ret.type = ECast(block_close); return ret; }

	// delimiter?
	if(isDelimiter(lastChar)) {
		// merge delimiters
		//return buildWord(isDelimiter, is, lastChar, ECast(delimiter));

		while(isDelimiter(lastChar)) {
			if(this->instream.eof()) return ret;
   			this->instream.get(lastChar);
		}

		// last read was NOT valid: restore it, cut it!
		this->instream.seekg(-1, ios::cur);

		ret.type = ECast(delimiter); 
		return ret;
	}

	// get identifyers and controll words
	if (isalpha(lastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
		auto fp = [](int c)->int{return isalnum(c);};
		// could be a keyword
		token myToken = this->buildWord(fp, lastChar, ECast(identifier));
		return findKeyWord(myToken);
//		return this->buildWord(fp, lastChar, ECast(identifier));
	}

	// numbers
	if (isdigit(lastChar)) {   // Number: [0-9.]+
		auto fp = [](int c)->int{return isdigit(c);};
		return this->buildWord(fp, lastChar, ECast(number));
	
		//TODO: use for something - should we check for "this is a number"?
		//NumVal = strtod(NumStr.c_str(), 0);
	}

	// comments
	if (lastChar == '/' && this->instream.peek() == '/') {
		auto fp = [](int c)->int{ return (c!='\n' && c!='\r'); };
		return this->buildWord(fp, lastChar, ECast(oneline_comment));
	}

	// get operants
	if(isOperator(lastChar)) {
		return this->buildWord(isOperator, lastChar, ECast(operand));
	}
	
	// double quoted strings
	if(lastChar == '"') {
		return buildString(lastChar, ECast(string));
	}

	// whatever.
	ret.type = 0;
	ret.value = "unknown";
	return ret;
}


/** baut ein wort. erwartet eine vergleichsoption die char nimmt und bool zurück gibt **/
token Lexor::buildWord(function<int (int)> fp, char lastChar, int id) {
	token ret = {0, "EOF"};	
	string str = {lastChar};	

	while (fp(lastChar)) {
		if(this->instream.eof()) break;		// eof als Abschluss
   		this->instream.get(lastChar);
		str += lastChar;
	}

	// last read was NOT valid: restore it, cut it!
	this->instream.seekg(-1, ios::cur);
	str.pop_back();

	ret.type = id;
	ret.value = str;/**/

	return ret;
}

token Lexor::buildString(char lastChar, int id) {
	token ret = {0, "EOF"};	
	string str = "";
	char esc = lastChar;

	do {
		if(this->instream.eof()) break;
   		this->instream.get(lastChar);
		if(lastChar==esc) break;
		if(lastChar=='\n' || lastChar=='\r') {
			ret.type = id;
			ret.value = "Unsescaped String";
			return ret;
		}

		str += lastChar;
	} while (1);

	ret.type = id;
	ret.value = str;
    return ret;
}

/** is this token an keyword? **/ 
token Lexor::findKeyWord(token& theToken)
{
	for(auto i: this->keyWords)
	{
		if(i.compare(theToken.value) == 0)
			theToken.type = ECast(keyWord);
	}
	return theToken;
}
