//
//  main.c
//
//  Created by Ricky Wilson on 11/11/18.
//
//  CS 4280
//  Project 2
//  Dr. Janikow

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "parser.h"


int main(int argc, char *argv[]){
	
	TreeNode * root;

	// make sure there are only zero or one arguments 
	if (argc > 2) {
		errno = 8;
		perror("Error: Too many arguments, run the program P1 with either zero or 1 argument");
		return 1;
	}
	
	char *infile;

	FILE * fp = stdin;


	if (argc == 2){
		
		// concatenates the strings of the first passed argument and extension ".sp18"
		infile = malloc(strlen(argv[1]) + strlen(".fs182") + 1);
		strcpy(infile, argv[1]);
		strcat(infile, ".fs182");
		fp = fopen(infile, "r");


	} 

	root = parser(fp);

	printf("Printing tree:\n");

	printTree(0, root);

	// close the input file
	fclose(fp);
	
	return 0;
}