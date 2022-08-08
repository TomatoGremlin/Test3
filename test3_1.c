#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    //  stores element of type int
    int data;
    // pointer to next element after current Node
    struct Node *next;
} Node;

void print(Node *cll) { // pointer to first element
  
    Node *curNode = cll;
   
    while(curNode) {
        printf("addr: %p,  data: %ld,   next: %p\n",
            curNode, curNode->data, curNode->next);
       
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
 
    new_node -> data = new_data;
    
    new_node -> next = NULL;
 
   
    Node *last_node = head;
    
    while(last_node->next != NULL) {
        last_node = last_node->next;
    }
 
    last_node -> next = new_node;
}


void pop_front(Node **head_pp) {

    Node *deleted_node = *head_pp;
 
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
