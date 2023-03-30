/*
Nama 		: Devina Lusiana
NIM 		: 211511011
Tanggal 	: 18 Mei 2022
Mata Kuliah : Struktur Data & Algoritma
*/

#ifndef heap_h
#define heap_h
#include "list.h"

#include <stdio.h>

typedef struct TreeNode *TreeAddr;
typedef struct TreeNode
{
    int data;
    TreeAddr left;
    TreeAddr right;
    TreeAddr parent;
} ElmtTreeNode;

void menuHeapSort();
void deleteBinaryTree(TreeAddr root);
TreeAddr CreateNodeHeap(int X);
void SwapValue(TreeAddr a, TreeAddr b);
void inorder(TreeAddr root);
void heapify(TreeAddr node);
TreeAddr BuildMaxHeap(List *L);
int height(TreeAddr root);
TreeAddr getLastNodeAndItsParent(TreeAddr root, int level, TreeAddr parent);
TreeAddr getLastNode(TreeAddr root);
void HeapSort(List L_data);

#endif