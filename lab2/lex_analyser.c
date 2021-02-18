#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "token.h"

#define BUFF_SIZE 50

int lex_analyser();
int isKeyword(char str[]);

FILE * ifp;
char tokstr[BUFF_SIZE];

int main(int argc, char * argv[]) {
	if(argc < 2 || (ifp = fopen(argv[1], "r")) == NULL ) {
		printf("ERROR::file not found\n");
		exit(1);
	}

	int token;
	while((token = lex_analyser()) != TOK_EOF) {
		printf("%d (%s)\n", token, tokstr);
	}

	fclose(ifp);
	exit(0);
}


int isKeyword(char str[]) {
	if (strcmp(str, "STOP"))
		return TOK_STOP;
	else if (strcmp(str, "ADD"))
                return TOK_ADD;
	else if (strcmp(str, "ONE"))
		return TOK_ONE;
	else if (strcmp(str, "SUB"))
		return TOK_SUB;
	else if (strcmp(str, "NUM"))
		return TOK_NUM;
	else if (strcmp(str, "MULT"))
		return TOK_MULT;
	else if (strcmp(str, "TERM"))
		return TOK_TERM;
	else if (strcmp(str, "LOAD"))
		return TOK_LOAD;
	else if (strcmp(str, "STORE"))
		return TOK_STORE;
	else if (strcmp(str, "RESULT"))
		return TOK_RESULT;
	else if (strcmp(str, "TRANS"))
		return TOK_TRANS;
	else if (strcmp(str, "NEXT"))
		return TOK_NEXT;
	else if (strcmp(str, "TRIM"))
		return TOK_TRIM;
	else if (strcmp(str, "DIV"))
		return TOK_DIV;
	else if (strcmp(str, "READ"))
		return TOK_READ;
	else if (strcmp(str, "PRINT"))
		return TOK_PRINT;
	else if (strcmp(str, "COUNT"))
		return TOK_COUNT;
	else if (strcmp(str, "LIR"))
		return TOK_LIR;
	else if (strcmp(str, "IIR"))
		return TOK_IIR;
	else if (strcmp(str, "LOOP"))
		return TOK_LOOP;
	else if (strcmp(str, "AGAIN"))
		return TOK_AGAIN;
	else if (strcmp(str, "START"))
		return TOK_START;
	else if (strcmp(str, "END"))
		return TOK_END;
	else if (strcmp(str, "LTORG"))
		return TOK_LTORG;
	else if (strcmp(str, "DS"))
		return TOK_DS;
	else if (strcmp(str, "DC"))
		return TOK_DC;
	else
		return 0;
}


int lex_analyser() {
	int i = 0, ch;
	while((ch = fgetc(ifp)) != EOF) {
		switch(ch) {
			case ',':
				tokstr[0] = ','; tokstr[1] = '\0';
				return TOK_COMMA;
			case ';':
				tokstr[0] = ';'; tokstr[1] = '\0';
				return TOK_SEMICOLON;
			case '(':
				tokstr[0] = '('; tokstr[1] = '\0';
				return TOK_OPEN_BRACE;
			case ')':
				tokstr[0] = ')'; tokstr[1] = '\0';
				return TOK_CLOSE_BRACE;
			case ':':
				tokstr[0] = ':'; tokstr[1] = '\0';
				return TOK_COLON;
			default:
				if(isalpha(ch)) {
					int ch1, kw;
					tokstr[i++] = ch;
					while(isalnum(ch1 = fgetc(ifp)))
						tokstr[i++] = ch1;
					tokstr[i] = '\0';
					ungetc(ch1, ifp);
					if((kw = isKeyword(tokstr)) != 0)
						return kw;
					else
						return TOK_ID;
				} else if (isdigit(ch)) {
					int ch1;
					tokstr[i++] = ch;
					while(isdigit(ch1 = fgetc(ifp)))
						tokstr[i++] = ch1;
					tokstr[i] = '\0';
					ungetc(ch1, ifp);
					return TOK_NUM;
				} else if (isspace(ch)) {
					int ch1;
					tokstr[i++] = ch;
					while(isspace(ch1 = fgetc(ifp)))
						tokstr[i++] = ch1;
					tokstr[i] = '\0';
					ungetc(ch1, ifp);
					return TOK_SPACE;
				}
		}
	}
	return TOK_EOF;
}
