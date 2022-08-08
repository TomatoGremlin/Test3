#include <stdio.h>
#include <string.h>

void binary(int n){

    int j, k, mask;
    for (int i = 7; i >= 0; i--)
    {
        j=i;
        mask= 1 << j;
        k = n & mask;
        k == 0?printf("0"):printf("1");
    }
    putchar(' ');  
}

int main(int argc, char **argv) {

   // filename = argv[1];
   //print_mode = argv[2]

  FILE* f = fopen (argv[1], "r");

  int current_symbol; 
  if (f == NULL)
  {
    perror("Could not open file\n");
    return 0;
  }
 
  if (!strcmp(argv[2], "-H")) //print hex
  {
    while ((current_symbol = fgetc(f)) != EOF) 
    {
        printf("%x ", current_symbol);
    }
    putchar('\n');
  }
  else if (!strcmp(argv[2], "-B"))
  {
    while ((current_symbol = fgetc(f)) != EOF) 
    {
        binary(current_symbol);
    }
    putchar('\n');
  }
  
    fclose(f);

    return 0;
}
