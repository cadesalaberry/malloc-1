/*
** list.c for list in /home/saint-_a/Documents/malloc
**
** Made by Augustin Saint Olive
** Login   <saint-_a@epitech.net>
**
** Started on  Thu Jun 18 12:43:37 2015 Augustin Saint Olive
** Last update Fri Jun 26 14:43:03 2015 DwarfNet
*/

#include "h_main.h"

struct s_list	*my_init_page()
{
  t_list	*ptr;
  size_t	size;

  size = 512 - sizeof(t_list);
  if ((ptr = sbrk(512)) == NULL)
    return (NULL);
  ptr = my_init_list(NULL, NULL, size, ptr);
  ptr->ptr = ptr + 1;
  return (ptr);
}

struct s_list	*my_add_new_page(t_list *page)
{
  t_list	*new;

  if ((new = my_init_page()) == NULL)
    return (NULL);
  page = my_goto_end_list(page);
  new->prev = page;
  new->next = page->next;
  page->next = new;
  if (page->free == 1)
    {
      page = my_fusion(page, new);
      return (page);
    }
  return (new);
}

struct s_list	*my_init_list(t_list *prev, t_list *next, size_t size, t_list *list)
{
  t_list	*ptr;

  ptr = list;
  ptr->prev = prev;
  ptr->next = next;
  ptr->size = size;
  ptr->free = 1;
  ptr->ptr = ptr + 1;
  return (ptr);
}

struct s_list	*my_goto_start_list(struct s_list *ptr)
{
  while (ptr->prev != NULL)
    ptr = ptr->prev;
  return (ptr);
}

struct s_list	*my_goto_end_list(struct s_list *ptr)
{
  while (ptr->next != NULL)
    ptr = ptr->next;
  return (ptr);
}
