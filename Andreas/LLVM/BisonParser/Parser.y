%{
 
/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */
 
#include "AbstractNode.h"
#include "NonTerminalNode.h"
#include "TerminalNode.h"
#include "Parser.h"
#include "Lexer.h"

int yyerror(AbstractNode **node, yyscan_t scanner, const char *msg) {
    // Add error handling routine as needed
	fprintf(stdout, "Error Parsing! %s\n", msg);
}
 
%}

%code requires {

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

}

%output  "Parser.c"
%defines "Parser.h"
 
%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { AbstractNode **node }
%parse-param { yyscan_t scanner }

%union {
	int value;
	char* identifier;
	char* keyword;
	char* stringLiteral;
	char* operatorString;
	AbstractNode *node;
}
 
%left '+' TOKEN_PLUS
%left '*' TOKEN_MULTIPLY
%right ":=" TOKEN_ASSIGNMENT


%token TOKEN_SEMICOLON 
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_CLPAREN
%token TOKEN_CRPAREN
%token TOKEN_PLUS 
%token TOKEN_MULTIPLY
%token TOKEN_ASSIGNMENT
%token TOKEN_DECLARE_ASSIGN
%token TOKEN_EOF
%token TOKEN_KEYWORD_FUNC
%token TOKEN_KEYWORD_PACKAGE
%token TOKEN_KEYWORD_IMPORT
%token <identifier> TOKEN_IDENTIFIER
%token <keyword> TOKEN_KEYWORD
%token <stringLiteral> TOKEN_STRING_LIT
%token <value> TOKEN_NUMBER
%token <value> TOKEN_NUM_LIT

%type <node> A P PPrime I M S F B BPrime N L 
 
%%
/*get the tree from the parser */
input: A{
		*node = $1;
		}

A:  P PPrime {
				AbstractNode *A = new NonTerminalNode("A");
				A->append($1);
				A->append($2);
				$$ = A;
			 };
P:	TOKEN_KEYWORD_PACKAGE I TOKEN_SEMICOLON{
		AbstractNode* P = new NonTerminalNode("P");
		P->append(new TerminalNode("package"));
		P->append($2);
		P->append(new TerminalNode(";"));
		$$ = P;
	};
PPrime: F {
			AbstractNode *PPrime = new NonTerminalNode("PPrime");
			PPrime->append($1);
			$$ = PPrime;
		  } | M F {
					AbstractNode *PPrime = new NonTerminalNode("PPrime");
					PPrime->append($1);
					PPrime->append($2);
					$$ = PPrime;
				  };
I:	TOKEN_IDENTIFIER {
			$$ = new TerminalNode($1);
		};
M: TOKEN_KEYWORD_IMPORT S  TOKEN_SEMICOLON{
			AbstractNode *M = new NonTerminalNode("M");
			M->append(new TerminalNode("import"));
			M->append($2);
			M->append(new TerminalNode(";"));
			$$ = M;
		};
S: TOKEN_STRING_LIT {
	 $$ = new TerminalNode($1); 
	};
F: TOKEN_KEYWORD_FUNC I TOKEN_LPAREN TOKEN_RPAREN B {
														AbstractNode *F = new NonTerminalNode("F");
														F->append(new TerminalNode("func"));
														F->append($2);
														F->append(new TerminalNode("("));
														F->append(new TerminalNode(")"));
														F->append($5);
														$$ = F;
													};
B: TOKEN_CLPAREN BPrime TOKEN_CRPAREN {
										AbstractNode *B = new NonTerminalNode("B");
										B->append(new TerminalNode("{"));
										B->append($2);
										B->append(new TerminalNode("}"));
										$$ = B;
	};
BPrime: {
		AbstractNode* BPrime = new NonTerminalNode("BPrime"); $$ = BPrime;} | N BPrime { AbstractNode *BPrime = new NonTerminalNode("BPrime"); 
		BPrime->append($1);
		BPrime->append($2);
		$$ = BPrime;
					  };
N: I TOKEN_DECLARE_ASSIGN L TOKEN_SEMICOLON { 
		AbstractNode* N = new NonTerminalNode("N");
		N->append($1);
		N->append(new TerminalNode(":="));
		N->append($3);
		N->append(new TerminalNode(";"));
		$$ = N;
	}
 | I TOKEN_ASSIGNMENT L  TOKEN_SEMICOLON {
		AbstractNode* N = new NonTerminalNode("N");
		N->append($1);
		N->append(new TerminalNode("="));
		N->append($3);
		N->append(new TerminalNode(";"));
		$$ = N;
	};
L: L TOKEN_PLUS L {
				   AbstractNode* L = new NonTerminalNode("L");
				   L->append($1);
				   L->append(new TerminalNode("+"));
				   L->append($3);
				   $$ = L;
				  } | 
				 I {
					AbstractNode *L = new NonTerminalNode("L");
					L->append($1);
					$$ = L;
				   } | 
				 TOKEN_NUM_LIT {
					AbstractNode *L =new NonTerminalNode("L");
					L->append(new TerminalNode($1));
					$$ = L;
};

%%
