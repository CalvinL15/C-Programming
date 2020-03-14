/* 
// C program for different tree traversals 
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}; 

struct node* newNode(int data) 
{ 
     struct node* node = (struct node*) 
                                  malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 
 
void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return;
     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->data); 
} 
void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printInorder(node->left); 
     printf("%d ", node->data);   
     printInorder(node->right); 
} 
 
void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->data);   
  
     printPreorder(node->left);   
     printPreorder(node->right); 
}     
int main() 
{ 
     struct node *root  = newNode(1); 
     root->left             = newNode(2); 
     root->right           = newNode(3); 
     root->left->left     = newNode(4); 
     root->left->right   = newNode(5);  
  
     printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 
  
     printf("\nInorder traversal of binary tree is \n"); 
     printInorder(root);   
  
     printf("\nPostorder traversal of binary tree is \n"); 
     printPostorder(root); 
  
     getchar(); 
     return 0; 
} 
*/

/*
// C program to merge two sorted linked lists 
#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 

struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

// pull off the front node of the source and put it in dest 
void MoveNode(struct Node** destRef, struct Node** sourceRef); 

// Takes two lists sorted in increasing order, and splices their nodes together to make one big sorted list which is returned. 
struct Node* SortedMerge(struct Node* a, struct Node* b) 
{ 
	// a dummy first node to hang the result on 
	struct Node dummy; 

	// tail points to the last result node 
	struct Node* tail = &dummy; 

	// so tail->next is the place to add new nodes to the result 
	dummy.next = NULL; 
	while (1) 
	{ 
		if (a == NULL) 
		{ 
			// if either list runs out, use the other list 
			tail->next = b; 
			break; 
		} 
		else if (b == NULL) 
		{ 
			tail->next = a; 
			break; 
		} 
		if (a->data <= b->data) 
			MoveNode(&(tail->next), &a); 
		else
			MoveNode(&(tail->next), &b); 

		tail = tail->next; 
	} 
	return(dummy.next); 
} 

// UTILITY FUNCTIONS 
// MoveNode() function takes the node from the front of the 
//source, and move it to the front of the dest. 
//It is an error to call this with the source list empty. 

void MoveNode(struct Node** destRef, struct Node** sourceRef) 
{ 
	struct Node* newNode = *sourceRef; 
	assert(newNode != NULL); 
	*sourceRef = newNode->next; 
	newNode->next = *destRef; 
	*destRef = newNode; 
} 


// Function to insert a node at the beginging of the linked list
void push(struct Node** head_ref, int new_data) 
{ 
	// allocate node 
	struct Node* new_node = 
		(struct Node*) malloc(sizeof(struct Node)); 

	// put in the data 
	new_node->data = new_data; 

	// link the old list off the new node 
	new_node->next = (*head_ref); 

	//move the head to point to the new node 
	(*head_ref) = new_node; 
} 

// Function to print nodes in a given linked list 
void printList(struct Node *node) 
{ 
	while (node!=NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 

// Driver program to test above functions
int main() 
{ 
	// Start with the empty list 
	struct Node* res = NULL; 
	struct Node* a = NULL; 
	struct Node* b = NULL; 

	// Let us create two sorted linked lists to test 
	push(&a, 15); 
	push(&a, 10); 
	push(&a, 5); 

	push(&b, 20); 
	push(&b, 3); 
	push(&b, 2); 

	// Remove duplicates from linked list 
	res = SortedMerge(a, b); 

	printf("Merged Linked List is: \n"); 
	printList(res); 

	return 0; 
} 
*/


//Linked list (sorted) to binary tree

/*
#include<stdio.h> 
#include<stdlib.h> 
  
struct LNode 
{ 
    int data; 
    struct LNode* next; 
}; 
  
struct TNode 
{ 
    int data; 
    struct TNode* left; 
    struct TNode* right; 
}; 
  
struct TNode* newNode(int data); 
int countLNodes(struct LNode *head); 
struct TNode* sortedListToBSTRecur(struct LNode **head_ref, int n); 
  
struct TNode* sortedListToBST(struct LNode *head) 
{
    int n = countLNodes(head); 
    return sortedListToBSTRecur(&head, n); 
} 
  
struct TNode* sortedListToBSTRecur(struct LNode **head_ref, int n) 
{ 
    if (n <= 0) 
        return NULL; 
  
    // Recursively construct the left subtree 
    struct TNode *left = sortedListToBSTRecur(head_ref, n/2); 
  
    // Allocate memory for root, and link the above constructed left  
    //   subtree with root 
    struct TNode *root = newNode((*head_ref)->data); 
    root->left = left; 
  
    // Change head pointer of Linked List for parent recursive calls 
    *head_ref = (*head_ref)->next; 
  
    // Recursively construct the right subtree and link it with root  
    //  The number of nodes in right subtree  is total nodes - nodes in  
    //  left subtree - 1 (for root) which is n-n/2-1
    root->right = sortedListToBSTRecur(head_ref, n-n/2-1); 
  
    return root; 
} 
  
  
  
// UTILITY FUNCTIONS 
  
// A utility function that returns count of nodes in a given Linked List 
int countLNodes(struct LNode *head) 
{ 
    int count = 0; 
    struct LNode *temp = head; 
    while(temp) 
    { 
        temp = temp->next; 
        count++; 
    } 
    return count; 
} 
  
// Function to insert a node at the beginning of the linked list 
void push(struct LNode** head_ref, int new_data) 
{ 
    struct LNode* new_node = (struct LNode*) malloc(sizeof(struct LNode)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  
// Function to print nodes in a given linked list 
void printList(struct LNode *node) 
{ 
    while(node!=NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
  
// Helper function that allocates a new node with the 
//   given data and NULL left and right pointers. 
struct TNode* newNode(int data) 
{ 
    struct TNode* node = (struct TNode*) 
                         malloc(sizeof(struct TNode)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 
  
// A utility function to print preorder traversal of BST 
void preOrder(struct TNode* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 
  
// Driver program to test above functions
int main() 
{ 
    // Start with the empty list 
    struct LNode* head = NULL; 
  
    // Let us create a sorted linked list to test the functions 
    // Created linked list will be 1->2->3->4->5->6->7 
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
  
    printf("\n Given Linked List "); 
    printList(head); 
  
    // Convert List to BST
    struct TNode *root = sortedListToBST(head); 
    printf("\n PreOrder Traversal of constructed BST "); 
    preOrder(root); 
  
    return 0; 
} 

*/

//alternative ways of merge lists (recursive)
/*struct Node* SortedMerge(struct Node* a, struct Node* b)  
{ 
  struct Node* result = NULL; 
  if (a == NULL)  
     return(b); 
  else if (b==NULL)  
     return(a); 
  if (a->data <= b->data)  
  { 
     result = a; 
     result->next = SortedMerge(a->next, b); 
  } 
  else 
  { 
     result = b; 
     result->next = SortedMerge(a, b->next); 
  } 
  return(result); 
} 

*/
#include "construct.h"
#include <stdint.h>
#include <stdlib.h>
#define MAXN 32768
static int64_t S[MAXN], M[MAXN];
static Node* build(int l, int r) {    
    if (r < l)
        return NULL;
    int64_t s = S[r] - S[l-1], m = M[r] - (M[l-1] + (r-l+1)*S[l-1]);
    if (r-l < 2 || s == 0 || m%s) {
        Node *ret = (Node *) calloc(1, sizeof(Node)), *p;
        ret->value = S[r]-S[r-1], p = ret;
        for (int i = r-1; i >= l; i--) {
            Node *q = (Node *) calloc(1, sizeof(Node));
            q->value = S[i]-S[i-1];
            p->left = q;
            p = q;
        }
        return ret;
    }
    int pos = r-(int) (m/s);
    Node *ret = (Node *) calloc(1, sizeof(Node));
    ret->value = S[pos]-S[pos-1];
    ret->left = build(l, pos-1);
    ret->right = build(pos+1, r);
    return ret;
}
Node* ConstructTree(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        M[i] = M[i-1] + S[i-1];
        S[i] = S[i-1] + A[i-1];
    }
    return build(1, n);
}
