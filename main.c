#include <stdlib.h>
#include "./include/h_main.h"

int main()
{
  char c = 'd';
  char *s = &c;
  char **w = &s;
  char	*j = NULL;
  char	d = 'c';

  j = *w;
  printf("c = %c :: s = %c :: w = %s :: i = %c\n", c, *s, *w, *j);
  j = &d;
  printf("c = %c :: s = %c :: w = %s :: i = %c\n", c, *s, *w, *j);
  *w = &d;
  printf("c = %c :: s = %c :: w = %s :: i = %c\n", c, *s, *w, *j);

  char	*ptr;
  int	*ptr2;
  void *ptr3;

  malloc(32);
  free(NULL);
  ptr = malloc(51266);
  free(ptr - 20000000);
  show_alloc_mem();
  ptr[0] = 'a';
  ptr2 = malloc(564);
  show_alloc_mem();
  ptr3 = malloc(300);
  show_alloc_mem();
  free(ptr);
  show_alloc_mem();
  ptr = malloc(750);
  show_alloc_mem();
  ptr[0] = 'a';
  ptr =  realloc(ptr, 16);
  show_alloc_mem();
  ptr2 =  realloc(ptr2, sizeof(int) * 65);
  show_alloc_mem();
  ptr3 =  realloc(ptr3, 656);
  show_alloc_mem();
  int	i = 0;
  //  printf("\033[33mptr addr = %p\033[0m\n", ptr2);
  while (i < 64)
    {
      //printf("ptr addr = %p\n", &ptr2[i]);
      ptr2[i] = 1;
      i++;
    }
  //  printf("\033[33mptr addr = %p\033[0m\n", ptr2);
  free(ptr);
  show_alloc_mem();
  free(ptr2);
  show_alloc_mem();
  /* while (i < 5465646) */
  /*   { */
  /*     malloc(10 * i); */
  /*     i++; */
  /* }  */
  show_alloc_mem();
  return (0);
}
