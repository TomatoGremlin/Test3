#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    //  stores element of type int
    int data;
    // pointer to next element after current Node
    struct Node *next;
} Node;

void print(Node *cll) { // pointer to first element
    // curNode is used for iterating all elements
    Node *curNode = cll;
    //currentNode != NULL
    while(curNode) {
        printf("addr: %p,  data: %ld,   next: %p\n",
            curNode, curNode->data, curNode->next);
        // adress of next Node into curNode
        curNode = curNode->next;
    }
}

struct Node*  insertNth(Node** cll,  int skipCount, int newElem){
    Node* node = create_node(newElem);
    if (skipCount == 0 || *cll == NULL){
        //node->next = *cll;
        *cll = node;
        return;
    }
    Node* current = *cll;
    Node* prev = current;
    // n steps
    while (current != NULL && skipCount--){
        prev = current;
        current = current->next;
    }
    prev->next = node;
    node->next = current;

    return node;
}

void push_back(Node *head, long new_data) {
    
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        perror("Push_back: Could not malloc\n");
        exit(-1);
    }
    // Set Node fields
    new_node -> data = new_data;
    // new_node is going to be last, so new_node->next=NULL
    new_node -> next = NULL;
 
    // We need to attach new_node to linked list
    // We must find the last node
    Node *last_node = head;
    // While loop ends when it finds Node that has no next Node
    while(last_node->next != NULL) {
        last_node = last_node->next;
    }
    // Attach new_node to last elements of linked list
    last_node -> next = new_node;
}


void pop_front(Node **head_pp) {
    // Store deleted node in local temp variable
    Node *deleted_node = *head_pp;
 
    // Change value of head pointer
    // Point it to second element
    // This is not possible without pointer to pointer   
    *head_pp = (*head_pp)->next;
 
    free(deleted_node);
}


Node *cll1;
int main() {
    unsigned n;
    int numbers;
    scanf("%u", n);
    

    Node *a = malloc(sizeof(Node)),
         *b = malloc(sizeof(Node)),
         *c = malloc(sizeof(Node)),
         *d = malloc(sizeof(Node));
    a->data = 5;
    a->next = b;
    cll1 = a;
    b->data = 8;
    b->next = c;
    c->data = 3;
    c->next = d;
    d->data = 12;

    for (size_t i = 0; i < n; i++)
    {
       scanf("%d ", numbers);
       push_back(cll1, numbers);
    }
    
    print_ll(cll1);
    printf("\n");

    pop_front(&cll1);
    print_ll(cll1);

    return 0;
}