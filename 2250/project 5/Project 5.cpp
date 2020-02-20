//============================================================================
// Name        : Project5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include<malloc.h>
using namespace std;
struct node {
	char character;
	int count;
	node *left;
	node *right;
};
class BTree {
	node *root;
public:
	Btree()
	{
		root=NULL;
	}
	struct node *newNode(char key) {
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		temp->character = key;
		temp->count = 1;
		temp->left = temp->right = NULL;
		return temp;
	}
	struct node* insert(struct node* node, char character) {
		if (node == NULL)
			return newNode(character);
		if (character < node->character)
			node->left = insert(node->left, character);
		else if (character > node->character)
			node->right = insert(node->right, character);
		else
			node->count += 1;
		return node;
	}
	void inorder(struct node *root) {
		if (root != NULL) {
			inorder(root->left);
			cout << "\n" << root->character << " : " << root->count;
			inorder(root->right);
		}
	}
};
int main() {
	BTree bt;
	struct node *root = NULL;
	ifstream file;
	file.open("C:\\Users\\Brandon London\\Desktop\\input.txt");
	char ch;
	int i = 0;
	if (!file) {
		cout << "\nFile not found";
		return 1;
	}
	while (file) {
		file >> ch;
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
			if (i == 0)
				root = bt.insert(root, ch);
			bt.insert(root, ch);
			i++;
		}
	}
	bt.inorder(root);
	return 0;
}
