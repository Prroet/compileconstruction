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

A:  P PPrime {	AbstractNode* A = new NonTerminalNode("A");
				AbstractNode* P = new NonTerminalNode("P");
				AbstractNode* PPrime = new NonTerminalNode("PPrime");
				P->append($1);
				PPrime->append($2);
				A->append(P);
				A->append(PPrime);
				$$ = A;
	 };

P:  Kp I C { AbstractNode* Kp = new NonTerminalNode("Kp");
			 Kp->append($1);
			 AbstractNode* I = new NonTerminalNode("I");
			 I->append($2);
			 AbstractNode* C = new NonTerminalNode("C");
			 C->append($3);
			 AbstractNode* P = new NonTerminalNode("P");
			 P->append(Kp);
			 P->append(I);
			 P->append(C);
			 $$ = P; 
			};

PPrime: F { AbstractNode* F = new NonTerminalNode("F");
			F->append($1);
			AbstractNode* PPrime = new NonTerminalNode("PPrime");
			PPrime->append(F);
			$$ = PPrime;
		   }
 	| M F {
			AbstractNode* M = new NonTerminalNode("M");
			M->append($1);
			AbstractNode* F = new NonTerminalNode("F");
			F->append($2);
			AbstractNode* PPrime = new NonTerminalNode("PPrime");
			PPrime->append(M);
			PPrime->append(F);
			$$ = PPrime;
		  };

M: Ki S C {
			AbstractNode* Ki = new NonTerminalNode("Ki");
			AbstractNode* S = new NonTerminalNode("S");
			AbstractNode* C = new NonTerminalNode("C");
			AbstractNode* M = new NonTerminalNode("M");
			Ki->append($1);
			S->append($2);
			C->append($3);
			M->append(Ki);
			M->append(S);
			M->append(C);
			M->append(M);
			$$=M;
		  };

F: Kf I R RPrime B {
						AbstractNode* Kf = new NonTerminalNode("Kf");
						AbstractNode* I = new NonTerminalNode("I");
						AbstractNode* R = new NonTerminalNode("R");
						AbstractNode* RPrime = new NonTerminalNode("RPrime");
						AbstractNode* B = new NonTerminalNode("B");
						AbstractNode* F = new NonTerminalNode("F");
						Kf->append($1);
						I->append($2);
						R->append($3);
						RPrime->append($4);
						B->append($5);
						F->append(Kf);
						F->append(I);
						F->append(R);
						F->append(RPrime);
						F->append(B);
						$$ = F;
				   };

B: G BPrime GPrime {
						AbstractNode *G = new NonTerminalNode("G");
						G->append($1);
						AbstractNode *BPrime = new NonTerminalNode("BPrime");
						BPrime->append($2);
						AbstractNode *GPrime = new NonTerminalNode("GPrime");
						GPrime->append($3);
						Abstract *B = new NonTerminalNode("B");
						B->append(G);
						B->append(BPrime);
						B->append(GPrime);
						$$ = B;
				   };

BPrime: { 
			AbstractNode *BPrime = new NonTerminalNode("BPrime");
			$$ = BPrime;
		 } 
	| N BPrime {
					AbstractNode *N = new NonTerminalNode("N");
					N->append($1);
					AbstractNode *BPrime1 = new NonTerminalNode("BPrime");
					BPrime->append($2);
					AbstractNode *BPrime2 = new NonTerminalNode("BPrime");
					BPrime2.append(N);
					BPrime2.append(BPrime1);
					$$ = BPrime2;
			   };

N: I O L C { AbstractNode *I = new NonTerminalNode("I");
			 I->append($1);
			 AbstractNode *O = new NonTerminalNode("O");
			 O->append($2);
			 AbstractNode *L = new NonTerminalNode("L");
			 L->append($3);
			 AbstractNode* C = new NonTerminalNode("C");
			 C->append($4);
			 AbstractNode* N = new NonTerminalNode("N");
			 N->append(I);
			 N->append(O);
			 N->append(L);
			 N->append(C);
			 $$=N;
		   };

L:
	I {
		AbstractNode *I =  new NonTerminalNode("I");
		I->append($1);
		AbstractNode *L = new NonTerminalNode("L");
		L->append(I);
		$$ = L;
			  }
	| Z {AbstractNode *Z =  new NonTerminalNode("Z");
		Z->append($1);
		AbstractNode *L = new NonTerminalNode("L");
		L->append(Z);
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
