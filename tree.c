//
//  tree.c
//
//  Created by Ricky Wilson on 9/25/18.
//
//  CS 4280
//  Project 0
//  Dr. Janikow

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// A utility function to create a new BST node
TreeNode *newTreenode(char *label)
{
    TreeNode *temp;
    temp = malloc(sizeof(TreeNode));
    temp->label = malloc(sizeof(label) + 1);
    temp->label = label;
    temp->head = malloc(sizeof(Node));
    temp->head = NULL;
    temp->child1 = NULL;
    temp->child2 = NULL;
    temp->child3 = NULL;
    temp->child4 = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void traversePreorder(int lvl, TreeNode *root)
{
    int i;

    if (root != NULL)
    {
        for (i = 0; i < lvl; i++){
            printf("  ");

        }  
        printf("%s ", root->label);
        // for (i = 0; i < lvl; i++){
        //     printf("\t");
        // }           
        listPrint(root->head);
        printf("\n");

        traversePreorder(lvl + 1, root->child1);
        traversePreorder(lvl + 1, root->child2);
        traversePreorder(lvl + 1, root->child3);
        traversePreorder(lvl + 1, root->child4);

    }

}

// // A utility function to do inorder traversal of BST
// void traverseInorder(int lvl, TreeNode *root, FILE * fout)
// {

//     if (root != NULL)
//     {
//         traverseInorder(lvl + 1, root->left, fout);
//         fprintf(fout, "\n");           
//         int i;
//         for (i = 0; i < lvl; i++){
//             fprintf(fout, "\t");
//         }
//         listPrint(root->head, fout);
        
//         traverseInorder(lvl + 1, root->right, fout);
//     }

//     // fprintf(fout, "\n");

// }

// // A utility function to do inorder traversal of BST
// void traversePostorder(int lvl, TreeNode *root, FILE * fout)
// {

//     if (root != NULL)
//     {
//         traversePostorder(lvl + 1, root->left, fout);
//         traversePostorder(lvl + 1, root->right, fout);

//         fprintf(fout, "\n%d ", root->key);   
//         int i;
//         for (i = 0; i < lvl; i++){
//             fprintf(fout, "\t");
//         }    
//         listPrint(root->head, fout);

//     }
    
// }

// /* A utility function to insert a new treenode with given key in BST */
// TreeNode *buildTree(TreeNode *treenode, char key, char *str)
// {
//     // create a new tree if tree is empty
//     if (treenode == NULL)
//     {
//         return newTreenode(key, str);
//     }
    
//     // if not empty, fill the tree in the correct place after final level of recursion
//     if (key < treenode->key)
//     {

    
//         treenode->left  = buildTree(treenode->left, key, str);

//     }
//     else if (key > treenode->key)
//     {
//         treenode->right = buildTree(treenode->right, key, str);

//     } else {
        
//         // inserts a new node with a new string if the string isn't already in the linked list
//         if(!listSearch(treenode->head, str)){

//             treenode->head = listInsert(treenode->head, str);

//         }
//     }
    
//     return treenode;
// }

