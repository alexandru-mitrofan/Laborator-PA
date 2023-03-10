/*
*	Created by Nan Mihai on 05.03.2020
*	Copyright (c) 2020 Nan Mihai. All rights reserved.
*	Laborator 3 - Proiectarea algoritmilor (Greedy)
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2019-2020, Seria CD
*/
#include "huffman.h"

int treeNode_compare(const void* a_pointer, const void* b_pointer) {
	TreeNode a, b;
	a = *(TreeNode*) a_pointer;
	b = *(TreeNode*) b_pointer;
	if (a->frequency > b->frequency) {
		return -1;
	} else if (a->frequency < b->frequency) {
		return 1;
	} else {
		return 0;
	}
}

TreeNode initHuffman(double frequency,
                     unsigned char value,
                     TreeNode left,
                     TreeNode right) {
	TreeNode huffman = (TreeNode)malloc(sizeof(struct treeNode));
	huffman->frequency = frequency;
	huffman->value = value;
	huffman->left = left;
	huffman->right = right;
	huffman->idx = idx++;
	return huffman;
}

void drawHeapAux(Heap h, int index, FILE* stream) {
    static int nullcount = 0;

    if (2 * index + 1 < h->size) {
    	int left = 2 * index + 1;
        fprintf(stream, "    %lf -> %lf;\n", h->vector[index]->frequency, h->vector[left]->frequency);
        drawHeapAux(h, left, stream);
    }
    if (2 * index + 2 < h->size) {
    	int right = 2 * index + 2;
        fprintf(stream, "    %lf -> %lf;\n", h->vector[index]->frequency, h->vector[right]->frequency);
        drawHeapAux(h, right, stream);
    }
}

void drawHeap(Heap h, int index, char *fileName) {
	FILE* stream = fopen("test.dot", "w");
	char buffer[SIZE];
    fprintf(stream, "digraph HEAP {\n");
    fprintf(stream, "    node [fontname=\"Arial\", shape=circle, style=filled, fillcolor=yellow];\n");
    if (!h)
        fprintf(stream, "\n");
    else if (2 * index + 1 > h->size)
        fprintf(stream, "    %lf;\n", h->vector[index]->frequency);
    else
        drawHeapAux(h, index, stream);
    fprintf(stream, "}\n");
    fclose(stream);
    sprintf(buffer, "dot test.dot | neato -n -Tpng -o %s", fileName);
	system(buffer);
}

TreeNode createHuffmanTree(char *text) {
	return NULL;
}

TreeNode freeTree(TreeNode root) {
	if (!root) return NULL;
	root->left = freeTree(root->left);
	root->right = freeTree(root->right);
	free(root);
	return NULL;
}
