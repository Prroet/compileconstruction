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
#include <string>

int yyerror(AbstractNode **abstractNode, yyscan_t scanner, const char *msg) {
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
%parse-param { AbstractNode **abstractNode }
%parse-param { yyscan_t scanner }

%union {
	int value;
	char* identifier;
	char* keyword;
	char* stringLiteral;
	char* operatorString;
	AbstractNode *node;
}

%right TOKEN_ASSIGNMENT
%left TOKEN_PLUS

%token TOKEN_SEMICOLON 
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_CLPAREN
%token TOKEN_CRPAREN
%token<operatorString> TOKEN_PLUS
%token<operatorString> TOKEN_ASSIGNMENT
%token <identifier> TOKEN_IDENTIFIER
%token <keyword> TOKEN_KEYWORD
%token <stringLiteral> TOKEN_STRING_LIT
%token <value> TOKEN_NUM_LIT

%type <node> A P PPrime I M S F B BPrime N L Z C R RPrime G GPrime O Kp Kf Ki
 
%%
/*
	First can be empty, so the file is empty and we are happy
	NonTerminalNode("A");
*/
input : A {*abstractNode = $1;}

A:  P PPrime {	AbstractNode* A = new NonTerminalNode("A");
				A->append($1);
				A->append($2);
				$$ = A;
	 };

P:  Kp I C { AbstractNode* P = new NonTerminalNode("P");
			 P->append($1);
			 P->append($2);
			 P->append($3);
			 $$ = P; 
			};

PPrime: F { 	AbstractNode* PPrime = new NonTerminalNode("PPrime");
			PPrime->append($1);
			$$ = PPrime;
		   }
 	| M F {	AbstractNode* PPrime = new NonTerminalNode("PPrime");
			PPrime->append($1);
			PPrime->append($2);
			$$ = PPrime;
		  };

M: Ki S C {		AbstractNode* M = new NonTerminalNode("M");
			Ki->append($1);
			S->append($2);
			C->append($3);
			M->append($1);
			M->append($2);
			M->append($3);
			$$=M;
		  };

F: Kf I R RPrime B {	AbstractNode* F = new NonTerminalNode("F");
						F->append($1);
						F->append($2);
						F->append($3);
						F->append($4);
						F->append($5);
						$$ = F;
				   };

B: G BPrime GPrime {Abstract *B = new NonTerminalNode("B");
						B->append($1);
						B->append($2);
						B->append($3);
						$$ = B;
				   };

BPrime: { /*Epsilon*/
			
		 } 
	| N BPrime {AbstractNode *BPrime = new NonTerminalNode("BPrime");
					BPrime.append($1);
					BPrime.append($2);
					$$ = BPrime;
			   };

N: I O L C { 		 AbstractNode* N = new NonTerminalNode("N");
			 N->append($1);
			 N->append($2);
			 N->append($3);
			 N->append($4);
			 $$=N;
		   };

L:
	I {	AbstractNode *L = new NonTerminalNode("L");
		L->append($1);
		$$ = L;
			  }
	| Z {	AbstractNode *L = new NonTerminalNode("L");
		L->append($1);
		$$ = L;
		} ;

/*Hier kommen die Produktionen auf Terminalsymbole*/
S: TOKEN_STRING_LIT { $$ = (new TerminalNode($1));};

I: TOKEN_IDENTIFIER {fprintf(stdout, "%s\n", $1);
					$$ = new TerminalNode($1); 
};
Kp: TOKEN_KEYWORD { if(strcmp($1, "package"))
					 $$ = new TerminalNode($1);
				  };

Kf:	TOKEN_KEYWORD {if(strcmp($1, "func") == 0)
						$$ = new TerminalNode($1);
				  }

Ki:	TOKEN_KEYWORD { if(strcmp($1, "import") == 0)
					{
						$$ = new TerminalNode($1);
					}
					else
						fprintf(stdout, "Found no keyword!!\n");
					 }

Z: TOKEN_NUM_LIT {$$ = new TerminalNode($1);};

C: TOKEN_SEMICOLON {$$ = new TerminalNode(";");};

R: TOKEN_LPAREN {$$ = new TerminalNode("(");};

RPrime: TOKEN_RPAREN {$$ = new TerminalNode(")");};

G: TOKEN_CLPAREN {$$ = new TerminalNode("{");};

GPrime: TOKEN_CRPAREN {$$ = new TerminalNode("}");};

O: TOKEN_ASSIGNMENT {$$ = new TerminalNode($1);};

%%
