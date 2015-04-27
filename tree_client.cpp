#include <iostream>
#include "tree.h"
using namespace std;
int main(void){
	Tree *t;
	t = new Tree();
	t->insert(5);
	t->insert(7);
	t->insert(3);
	t->insert(1);
	t->insert(9);
	t->print_inorder();
}