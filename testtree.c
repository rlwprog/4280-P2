//
//  testtree.c
//
//  Created by Ricky Wilson on 11/20/18.
//  CS 4280
//  Project 2
//
#include "testtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A utility function to do preorder traversal of BST
void printTree(int lvl, TreeNode *root)
{
    int i;

    if (root != NULL)
    {
        for (i = 0; i < lvl; i++){
            printf("  ");

        }  
        printf("%s ", root->label);
                 
        listPrint(root->head);
        printf("\n");

        printTree(lvl + 1, root->child1);
        printTree(lvl + 1, root->child2);
        printTree(lvl + 1, root->child3);
        printTree(lvl + 1, root->child4);

    }

}