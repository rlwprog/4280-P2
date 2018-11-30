#
# makefile
#
# Created by Ricky Wilson on 11/11/18.
# CS 4280
# Project 2
#


all: parser 

parser: 
	gcc -Wall tree.c node.c token.c main.c parser.c scanner.c testtree.c -o parser

clean:
	rm parser  
