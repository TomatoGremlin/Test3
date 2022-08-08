#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
   
    struct Node *next;
} Node;

int size;

void print(Node *cll)
{ 
    
    Node *current_node = cll;
    for (int i = 0; i < size; i++)
    {
        printf("Address: %p,  Data: %d, Next node address: %p\n",
               current_node, current_node->data, current_node->next);
      
        current_node = current_node->next;
    }
}

struct Node *insertNth(Node **cll, int skipCount, int newElem)
{
   
    Node *new_node = malloc(sizeof(Node));
    new_node->data = newElem;
    new_node->next = NULL;

    if (*cll == NULL)
    {
        *cll = new_node;
        size = 1;
        return *cll;
    }
    size += 1;
    if (skipCount == 0 || skipCount % (size - 1) == 0)
    {
        *cll = new_node;
        new_node->next = *cll;
        (*cll + (size - 1))->next = new_node;

        return *cll;
    }
   
    Node *before_new = *cll; 
    Node *after_new = before_new;

   
    while (skipCount--)
    {
        before_new = after_new;
        after_new = after_new->next;
    }
    before_new->next = new_node;
    new_node->next = after_new;

    return new_node;
}

int main()
{
    unsigned n;
    int numbers;
    scanf("%u", &n);
    if (n < 0)
    {
        perror("Error. Number should be bigger than 0.");
        return -1;
    }
    size = n;

    Node *node_list;
    node_list = malloc(sizeof(Node) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers);
        (node_list + i)->data = numbers;
        if (i == n - 1)
        {
            (node_list + i)->next = node_list;
            break;
        }
        (node_list + i)->next = (node_list + i + 1);
    }
 
    print(node_list);
    printf("\n");
    Node **pointer_to_nodelist = &node_list;

    int insert_number = 77;
    int position_afterFirst = 5;
    insertNth(pointer_to_nodelist, position_afterFirst, insert_number);

    printf("After inserting %d on position %d:\n", insert_number, (position_afterFirst + 1) % (size - 1));
    print(node_list);

    free(node_list);
    return 0;
}
