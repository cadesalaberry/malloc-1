/*
** malloc.c for malloc in /home/saint-_a/Documents/malloc
**
** Made by Augustin Saint Olive
** Login   <saint-_a@epitech.net>
**
** Started on  Thu Jun 18 12:39:36 2015 Augustin Saint Olive
** Last update Fri Jun 26 16:18:50 2015 DwarfNet
*/

#include "h_main.h"

t_list		*my_get_free_block(t_list	*block, size_t size)
{
  int	blz;

  blz = 0;
  block = my_goto_start_list(block);
  while (blz == 0)
    {
      if (block->next == NULL && (block->size < size || block->free == 0))
	if ((block = my_add_new_page(block)) == NULL)
	  return (NULL);
      if (block->next != NULL && (block->free == 0 || block->size < size))
	block = block->next;
      if (block->free == 1 && block->size >= size)
	blz = 1;
    }
  return (block);
}

t_list		*my_set_size(t_list *ptr, size_t size)
{
  if (ptr->size > size)
    ptr = my_splitt(ptr, size);
  ptr->size = size;
  return (ptr);
}

void		*malloc(size_t size)
{
  static t_list	*ptr = NULL;

  printf("\033[32mMALLOC :: %zu\033[0m\n", size);
  if (size == 0)
    return (NULL);
  if ((ptr = my_get_static(ptr)) == NULL)
    if ((ptr = my_init_page()) == NULL)
      return (NULL);
  if ((ptr = my_get_free_block(ptr, size)) == NULL)
    return (NULL);
  ptr = my_set_size(ptr, size);
  ptr->free = 0;
  ptr->ptr = ptr + 1;
  my_set_static(ptr);
  printf("\033[32mMALLOC :: END\033[0m\n");
  return(ptr->ptr);
}

t_list		*my_get_ptr_block(void *ptr, t_list *list)
{
  list = my_goto_start_list(list);
  while (list->ptr != ptr && list->next != NULL)
    list = list->next;
  if (list->ptr != ptr)
    return (NULL);
  return (list);
}
