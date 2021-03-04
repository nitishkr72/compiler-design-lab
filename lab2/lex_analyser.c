%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"

#define MAXL 100
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
	fwrite("Opcode\t\tToken Value\t\tToken String\n", 1, MAXL, outfile);

	while((token = yylex())!=TOK_EOF) {
		char s[MAXL] = "";
		char num[10];
		if(token != TOK_SPACE) {
			if(token>0 && token<14) {
				fprintf(stdout, "%d\t\t%d\t\t%s\n", token-1, token, yytext);
				sprintf(num, "%d", token-1); strcat(s, num);
				strcat(s, "\t\t");
				sprintf(num, "%d", token); strcat(s, num);
				strcat(s, "\t\t");
				strcat(s, yytext);
				strcat(s, "\n");
				fwrite(s, 1, sizeof(s), outfile);
				
			} else {
				fprintf(stdout, "\t\t%d\t\t%s\n", token, yytext);
				strcat(s, "\t\t");
				sprintf(num, "%d", token); strcat(s, num);
				strcat(s, "\t\t");
				strcat(s, yytext);
				strcat(s, "\n");
				fwrite(s, 1, sizeof(s), outfile);
			}
		}
	}

	fclose(yyin);
	fclose(outfile);
}
