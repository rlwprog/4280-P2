//
//  tree.h
//
//  Created by Ricky Wilson on 9/25/18.
//
//  CS 4280
//  Project 0
//  Dr. Janikow

#include <stdio.h>
#include "node.h"

// struct for a tree node within the bst
typedef struct treenode
{
    char *label;
    struct node * head;
    struct treenode *child1;
    struct treenode *child2;
    struct treenode *child3;
    struct treenode *child4;

}TreeNode;

// function creates a new treenode for the bst
TreeNode *newTreenode(char *label);

// traverses the file in preorder, at each treenode traverses each list of unique strings
void traversePreorder(int lvl, TreeNode *root);

// // traverses the file in order, at each treenode traverses each list of unique strings
// void traverseInorder(int lvl, TreeNode *root, FILE * fout);

// // traverses the file in postorder, at each treenode traverses each list of unique strings
// void traversePostorder(int lvl, TreeNode *root, FILE * fout);

// builds the bst with a linked list of unique strings and a key depicting their length (all same length in a particular node)
// TreeNode* buildTree(TreeNode* treenode, char key, char *str);


