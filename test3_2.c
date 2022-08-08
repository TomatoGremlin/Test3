#include <stdio.h>
#include<stdlib.h>

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
        printf("%x", current_symbol);
    }
    putchar('\n');
  }
  else if (!strcmp(argv[2], "-B"))
  {
    while ((current_symbol = fgetc(f)) != EOF) 
    {
        for(int bit = sizeof(current_symbol)*8-1; bit >= 0; bit --)
        {
            printf("%d",!!(current_symbol & (1 << bit)));
        }
    }
    putchar('\n');
  }

    return 0;
}