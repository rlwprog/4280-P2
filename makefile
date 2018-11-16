#
# makefile
#
# Created by Ricky Wilson on 11/11/18.
# CS 4280
# Project 2
#


all: scanner 

scanner: 
	gcc -Wall token.c main.c parser.c scanner.c -o scanner

clean:
	rm scanner  
