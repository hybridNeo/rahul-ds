#include <iostream>
#include "tree.h"
#include <stdlib.h>
using namespace std;	
Tree::Tree(){
	root = NULL;
}
void Tree::print_inorder(){
	inorder(root);
}
void Tree::inorder(t_node *n){
	if(n!=NULL){
		Tree::inorder(n->left);
		cout << n->val << endl;
		Tree::inorder(n->right);
	}
}
void Tree::insert(int val){
	if(root==NULL){
		root = new t_node;
		root->val = val;
	}else{
		Tree::t_node* parent;
		parent = NULL;
		Tree::t_node *ptr;
		ptr = this->root;
		while(ptr){
			parent = ptr;
			if(val > ptr->val)
				ptr = ptr->right;
			else
				ptr= ptr->left;
		}
		Tree::t_node *t = new t_node;
		t->val = val;
		if(t->val < parent->val)
			parent->left = t;
		else
			parent->right = t;
	}
}
