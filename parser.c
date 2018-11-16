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

// driver to test the scanner 
void parser(FILE *fileIn) {
	
	fin = fileIn;
	while(getc(fin) != EOF){
		fseek(fin, -1, SEEK_CUR);
		scanner();
	}

}

void program(){


	return;
}