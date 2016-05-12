#ifndef _TOKEN_
#define _TOKEN_

#include <string>

class Token {
private:
    const unsigned int _line;
    const std::string _tokenName;

private:

    inline Token& operator=(const Token& right) {
        right;
        return *this;
    };

    inline Token(void) : _line(0), _tokenName("") {
    };

public:

    inline explicit Token(const unsigned int& line, const char* const tokenName)
    : _line(line), _tokenName(tokenName) {
    };

    inline virtual ~Token(void) {
    };

    inline const unsigned int& getLineNumber(void) const {
        return _line;
    };

    inline const std::string& getTokenName(void) const {
        return _tokenName;
    };
};

class Identifier : public Token {
private:
    const unsigned int _attribute_value;

private:

    inline Identifier& operator=(const Identifier& right) {
        right;
        return *this;
    };

    inline Identifier(void) : Token(0, ""), _attribute_value(0) {
    };

public:

    inline Identifier(const unsigned int& line, const char* const tokenName, const unsigned int& attribute_value) : Token(line, tokenName), _attribute_value(attribute_value) {
    };

    inline const unsigned int& getAttributeValue(void) const {
        return _attribute_value;
    };
};

class Delimiter : public Token {
public:

    inline Delimiter(const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {
    };
};

class Terminator : public Token {
public:

    inline Terminator(const unsigned int& line, const char* const tokenName) : Token(line, tokenName) {
    };
};

template<typename T>
class Literal : public Token {
public:
    typedef T value_type;

private:
    const value_type _value;

public:

    inline Literal(const unsigned int& line, const char* const tokenName, const value_type& value) : Token(line, tokenName), _value(value) {
    };

    inline const value_type& getValue(void) const {
        return _value;
    };
};

class Integer : public Literal<int> {
public:

    inline Integer(const unsigned int& line, const char* const tokenName, const int& value) : Literal(line, tokenName, value) {
    };
};

class String : public Literal<std::string> {
public:

    inline String(const unsigned int& line, const char* const tokenName, const std::string& value)
    : Literal(line, tokenName, value) {
    };

};
#endif _TOKEN_