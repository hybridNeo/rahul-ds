#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int val;
	struct Node *next;
}Node;
void reverse(Node **root){
	//1 2 3 4 5
	Node *prev = NULL;
	Node *cur = *root;
	Node *next;
	while(cur != NULL){
		next = cur->next; //2
		cur->next = prev; //null
		prev = cur; //1
		cur = next; //2
	}
	*root = prev;
}
void display(Node **root){
	Node *cur = *root;
	while(cur!=NULL){
		printf("%d ",cur->val );
		cur = cur->next;
	}
}

void ktolast(Node **root,int k){
	Node *ptr = *root;
	int count = 0;
	while(count<k && ptr->next != NULL){
		ptr = ptr->next;
		count++;
	}
	while(ptr != NULL){
		printf("%d ",ptr->val );
		ptr = ptr->next;
	}
	printf("\n");
}	
void mid(Node **root){
	Node *ptr = *root;
	Node *dup;
	while(ptr->next !=NULL){
		ptr->val = ptr->next->val;
		if(ptr->next->next == NULL){
			dup = ptr->next;
			ptr->next = NULL;
		}else
		ptr = ptr->next;
	}

	free(dup);

}
void midHelper(Node **root){
	Node *ptr = *root;
	ptr = ptr->next->next;
	mid(&ptr);
}

/*
* A function to remove duplicates from unsorted linked list
*/
void removeDup(Node **root){
	Node *ptr1,*ptr2,*dup;
	ptr1 = *root;
	while(ptr1 != NULL && ptr1->next != NULL){
			ptr2 = ptr1;
			while(ptr2->next != NULL){
				if(ptr1->val == ptr2->next->val){
					dup = ptr2->next;
					ptr2->next = ptr2->next->next;
					free(dup);
				}else{
					ptr2 = ptr2->next;
				}
			}
		ptr1 = ptr1->next;
	}
}

void insert(int val,Node **root){
	if(*root == NULL){
		
		*root =(Node *)malloc(sizeof(Node));
		Node *cur ;
		cur =  *root;
		cur->val = val;

	}else{
		Node *cur ;
		cur =  *root;
	
		while(cur->next != NULL){
			cur = cur->next;			
		}
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->val = val;
		cur->next = temp;
	}
}
Node* partitionPrint(Node **root,int pivot){
	Node *ptr,*lt=NULL,*gt=NULL;
	ptr= *root;
	while(ptr!=NULL){
		if(ptr->val < pivot){
			insert(ptr->val , &lt);
		}else{
			insert(ptr->val , &gt);
		}
		ptr = ptr->next;
	}
	Node *dup = lt;
	while(lt->next != NULL)
		lt = lt->next;
	lt->next = gt;
	return dup;
}

void addRev(Node **first,Node **second){
	Node *ptr1,*ptr2;
	ptr1=*first;
	ptr2=*second;
	Node *ans=NULL;
	int rem = 0;
	while(ptr1!= NULL){
		int temp = ptr1->val + ptr2->val;
		temp += rem;
		int val = temp%10;
		rem = temp-val;
		insert(val,&ans);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	display(&ans);
}
int loopfinder(Node **root){
	Node *ptr = *root;
	int arr[1000]={0};
	while(ptr!=NULL){
		if(arr[ptr->val] == 1){
			return ptr->val;
		}
		arr[ptr->val] = 1;
		ptr = ptr->next;
	}
	return -1;
}
int isPallindrome(Node **root ,int size){	
	if(size<=1){
		return 1;
	}
	Node *start_ptr ,*end_ptr;
	end_ptr = start_ptr = *(root);
	int i=1;
	while(i<size){
		end_ptr = end_ptr->next;
		i++;
	}
	if(end_ptr->val != start_ptr->val){
		return 0;
	}
	return isPallindrome(&(start_ptr->next),size-2);
}
int main(void){
#if 0 
	Node *first=NULL;
	insert(3,&first);
	insert(5,&first);
	insert(1,&first);
	Node *second=NULL;
	insert(1,&second);
	insert(4,&second);
	insert(2,&second);
	display(&first);
	printf("\n");
	display(&second);
	printf("\n");
	addRev(&first,&second);
	// Node  *part = partitionPrint(&root,3);
	// printf("\n");
	// display(&part);
	
	//ktolast(&root,2);
#endif
	// A -> B -> C -> D -> E -> C
	Node *root =NULL;
	insert(1,&root);
	insert(2,&root);
	insert(3,&root);
	insert(4,&root);
	display(&root);
	reverse(&root);
	printf("\n");
	display(&root);
}