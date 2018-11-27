//
//  parser.c
//
//  Created by Ricky Wilson on 11/11/18.
//  CS 4280
//  Project 2
//

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

static Token * tk;

// driver to test the scanner 
void parser(FILE *fileIn) {
	
	fin = fileIn;
	// while(getc(fin) != EOF){
	// 	fseek(fin, -1, SEEK_CUR);
	// 	scanner();
	// }
	// getc(fin);
	// scanner();

	tk = scanner();
	program();
	if (tk->tokenID == 1004){

	} else {

		printf("Error: %d Program didn't end correctly with EOF\n", -4);
		tokenPrint(tk);

	}
	return;
}

void program(){
	if(strcmp(tk->tokenName, "void") == 0){

		tk = scanner();

		vars();
		block();	
		return;	
	} else {
		printf("Error: Unsupported program, occurred in program()\n");
	}
}

void block(){
	if(strcmp(tk->tokenName, "start") == 0){
		tk = scanner();
		vars();
		stats();
		if(strcmp(tk->tokenName,"stop") == 0){
			tk = scanner();
			return;
		} else {
			printf("Error: Unsupported program, occurred in block() after start\n");
		}
	} else {
		printf("Error: Unsupported program, occurred in block() before start.\n");

	}
}

void vars(){
	if(strcmp(tk->tokenName,"var") == 0){
		tk = scanner();
	

		if(tk->tokenID == 1000){
			tk = scanner();

			if(strcmp(tk->tokenName, ":") == 0){
				tk = scanner();

				if(tk->tokenID == 1001){
					tk = scanner();
					vars();
					return;
				} else {
					printf("Error: Unsupported program, occurred in vars() after ':'\n");
				}
			} else {
				printf("Error: Unsupported program, occurred in vars() after Identifier\n");
			}
		} else {
			printf("Error: Unsupported program, occurred in vars() after Keyword\n");
		}
	} else {
		return;
	}
}

void expr(){
	A();
	if((strcmp(tk->tokenName, "/") == 0) || (strcmp(tk->tokenName, "*") == 0)){
		tk = scanner();
		expr();
		return;
	} else {
		return;
	}
}

void A(){
	M();
	if((strcmp(tk->tokenName, "+") == 0) || (strcmp(tk->tokenName, "-") == 0)){
		tk = scanner();
		A();
		return;
	} else {
		return;
	}
}

void M(){
	if(strcmp(tk->tokenName,"-") == 0){
		tk = scanner();
		M();
		return;
	} else {
		R();
		return;
	} 
}

void R(){
	if(strcmp(tk->tokenName,"(") == 0){
		tk = scanner();
		expr();

		if(strcmp(tk->tokenName,")") == 0){
			tk = scanner();

			return;
		} else {
			printf("Error: Unsupported program, occurred in R() after '('\n");	
		}
	} else if (tk->tokenID == 1000){
		tk = scanner();
		return;
	} else if (tk->tokenID == 1001){
		tk = scanner();
		return;
	} else {
		printf("Error: Unsupported program, occurred in R() after ')'\n");			
	}
}

void stats(){
	stat();
	mStat();
}

void mStat(){
	if(strcmp(tk->tokenName, "scan") == 0 || strcmp(tk->tokenName, "out") == 0 || strcmp(tk->tokenName, "start") == 0 || strcmp(tk->tokenName, "if") == 0 || strcmp(tk->tokenName, "loop") == 0 || strcmp(tk->tokenName, "let") == 0){
		stat();
		mStat();
		return;
	} else {
		return;
	}
}

void stat(){
	if(strcmp(tk->tokenName, "scan") == 0){
		in();
		return;
	} else if(strcmp(tk->tokenName, "out") == 0){
		out();
		return;
	} else if(strcmp(tk->tokenName, "start") == 0){
		block();
		return;
	} else if(strcmp(tk->tokenName, "if") == 0){
		If();
		return;
	} else if(strcmp(tk->tokenName, "loop") == 0){
		loop();
		return;
	} else if (strcmp(tk->tokenName, "let") == 0){
		assign();
		return;
	} else {
		printf("Error: Unsupported program, occurred in stat()\n");
	}
}

void in(){
	tk = scanner();
	if(strcmp(tk->tokenName, "Identifier") == 0){
		tk = scanner();
		if(strcmp(tk->tokenName, ".") == 0){
			tk = scanner();
			return;
		}
	} else {
		printf("Error: Unsupported program, occurred in in() after 'scan'\n");

	}
}

void out(){
	tk = scanner();
	if(strcmp(tk->tokenName, "[") == 0){
		tk = scanner();
		expr();

		if(strcmp(tk->tokenName, "]") == 0){
			tk = scanner();

			if(strcmp(tk->tokenName, ".") == 0){
				tk = scanner();
				return;
			} else {
				printf("Error: Unsupported program, occurred in out() after ']'\n");
			}
		} else {
			printf("Error: Unsupported program, occurred in out() after '['\n");
		}
	} else {
		printf("Error: Unsupported program, ocurred in out() before '['\n");
	}
}

void If(){
	tk = scanner();
	if(strcmp(tk->tokenName, "(") == 0){
		tk = scanner();
		expr();
		RO();
		expr();

		if(strcmp(tk->tokenName, ")") == 0){
			tk = scanner();
			stat();
			return;
		} else {
			printf("Error: Unsupported program, ocurred in If() after '('\n");
		}
	} else {
		printf("Error: Unsupported program, ocurred in If() before '('\n");
	}
}

void loop(){
	tk = scanner();
	if(strcmp(tk->tokenName, "(") == 0){
		tk = scanner();
		expr();
		RO();
		expr();

		if(strcmp(tk->tokenName, ")") == 0){
			tk = scanner();
			stat();
			return;
		} else {
			printf("Error: Unsupported program, ocurred in loop() after '('\n");
		}
	} else {
		printf("Error: Unsupported program, ocurred in loop() before '('\n");
	}
}

void assign(){
	tk = scanner();
	if(tk->tokenID == 1000){
		tk = scanner();

		if(strcmp(tk->tokenName, "=") == 0){
			tk = scanner();
			expr();

			if(strcmp(tk->tokenName, ".") == 0){
				tk = scanner();
				return;
			} else {
				printf("Error: Unsupported program, ocurred in assign() before '.'\n");
			}
		} else {
			printf("Error: Unsupported program, occurred in assign() after 'Identifier'\n");
		}
	} else {
		printf("Error: Unsupported program, occurred in assign() before 'Identifier'\n");
	}
}

void RO(){
	if(strcmp(tk->tokenName, "<") == 0){
		tk = scanner();

		if(strcmp(tk->tokenName, "=") == 0){
			tk = scanner();
			return;
		} else {
			return;
		}
	} else if (strcmp(tk->tokenName, ">") == 0){
		tk = scanner();

		if(strcmp(tk->tokenName, "=") == 0){
			tk = scanner();
			return;
		} else {
			return;
		}
	} else if(strcmp(tk->tokenName, "=") == 0){
		tk = scanner();

		if(strcmp(tk->tokenName, "=") == 0){
			tk = scanner();
			return;
		} else {
			return;
		}
	} else {
		printf("Error: Unsupported program, occurred in RO()\n");
	}
}

















