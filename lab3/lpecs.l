%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

#define MAXV 100
%}

DIGIT	[0-9]+
ID	[a-zA-Z][a-zA-Z0-9]*

%%
START		return TOK_START;
STOP		return TOK_STOP;
ADD		return TOK_ADD;
SUB		return TOK_SUB;
MULT		return TOK_MULT;
LOAD		return TOK_LOAD;
STORE		return TOK_STORE;
{DIGIT}		return TOK_NUM;
TRANS		return TOK_TRANS;
TRIM		return TOK_TRIM;
DIV		return TOK_DIV;
READ		return TOK_DIV;
PRINT		return TOK_PRINT;
LIR		return TOK_LIR;
IIR		return TOK_IIR;
LOOP		return TOK_LOOP;
END		return TOK_END;
LTORG		return TOK_LTORG;
DS		return TOK_DS;
DC		return TOK_DC;
{ID}		return TOK_ID;
","		return TOK_COMMA;
"("		return TOK_OPEN_BRACE;
")"		return TOK_CLOSE_BRACE;
";"		return TOK_SEMICOLON;
":"		return TOK_COLON;
[ \t\n]+	return TOK_SPACE;
<<EOF>>		return TOK_EOF;
%%

int main(int argc, char *argv[]) {
	if(argc < 2)
		printf("Please enter filename\n");

	int token;
	extern FILE * yyin;
	FILE * outfile;

	yyin = fopen(argv[1], "r");
	outfile = fopen("code.bin", "wb");

	printf("Opcode\t\tToken Value\t\tToken String\n");
	fwrite("Opcode\t\tToken Value\t\tToken String\n", 1, MAXV, outfile);

	while((token = yylex())!=TOK_EOF) {
		if(token != TOK_SPACE) {
			if(token>0 && token<14) {
				printf("%d\t\t%d\t\t%s\n", token-1, token, yytext);
				string outline;
				
			} else {
				printf("\t\t%d\t\t%s\n", token, yytext);
				fscanf(outfile, "\t\t%d\t\t%s\n", token, yytext);
			}
		}
	}

	fclose(yyin);
	fclose(outfile);
}
