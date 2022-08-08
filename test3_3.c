#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct Product {
    double new_price;
    double old_price;
    unsigned int id;
    char product_name[10];
    char product_type;
} Product;


char *product_names_list[] = {
    "product1",
    "product2",
    "product3",
    "product4",
    "product5",
    "product6",
    "product7",
    "product8",
    "product9",
    "product10"
};

void random_product(Product *p) {
    static int id_counter = 0;
    p->id = id_counter++;

    p->new_price = (499 + rand()%(10045 - 499))/100.;
    p->old_price = (499 + rand()%(10045 - 499))/100.;

    p->product_type =('A' + rand()%('D' - 'A'));

    strcpy(p->product_name, product_names_list[rand()%10]);
}

void print_product(Product *p) {
    printf("Id:%d, Old price: %lf, New price:%lf, Type: %c, Name:%s\n",
         p->id, p->old_price, p->new_price, p->product_type, p->product_name);
}

int compare_products(const void *p1, const void *p2) {
    const Product *prod1 = p1, *prod2 = p2;
    double price_diff = prod1->new_price - prod2->old_price;

    int compare_type = fabs(prod1->product_type - prod2->product_type);
    if(fabs(price_diff) > 0.01) {
    
        return price_diff*100;
    }

    if(compare_type != 0) {
        return compare_type;
    }
     
    int compare_name = strcmp(prod1->product_name, prod2->product_name);
    if(compare_name != 0) {
        return compare_name;
    }
   
    return prod1->id - prod2->id;
}

int main() {
   
    Product *product_list;
    product_list = malloc(40*sizeof(Product));
    if(!product_list) {
        perror("Malloc failed\n");
        return -1;
    }

    srand(time(NULL));

    for(int i = 0; i < 40; i++) {
        random_product(product_list + i);
    }

    qsort(product_list, 40, sizeof(Product), compare_products);

    for(int i = 0; i < 40; i++) {
        print_product(product_list + i);
    }
    free(product_list);
    
}
