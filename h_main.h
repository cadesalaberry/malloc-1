/*
** h_main.h for malloc in /media/dwarfnet/DATA/REV/Malloc
**
** Made by DwarfNet
** Login   <dwarfnet@epitech.net>
**
** Started on  Fri Jun 19 11:37:57 2015 DwarfNet
** Last update Fri Jun 26 16:37:39 2015 DwarfNet
*/

#ifndef H_MAIN_H_
# define H_MAIN_H_

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
  struct s_list		*next;
  struct s_list		*prev;
  size_t		size;
  int			free;
  void			*ptr;
}			t_list;


/* my_malloc.c */
t_list		*my_get_free_block(t_list	*block, size_t size);
t_list		*my_set_size(t_list *ptr, size_t size);
void		*my_malloc(size_t size);
t_list		*my_get_ptr_block(void *ptr, t_list *list);
/* free.c */
void		my_free(void *ptr);
/* my_list1.c */
t_list		*my_init_page();
t_list		*my_add_new_page(t_list *page);
t_list		*my_init_list(t_list *prev, t_list *next, size_t size, t_list *list);
t_list		*my_goto_start_list(struct s_list *ptr);
t_list		*my_goto_end_list(struct s_list *ptr);
/* my_list2.c */
t_list		*my_fusion(t_list *keep, t_list *rmv);
t_list		*my_splitt(t_list *origin, size_t size);
t_list	        *my_get_next_struct(size_t i, t_list *start);
int		my_get_size_alloc(size_t size);
/* my_error1.c */
void		my_error(char *str);
t_list		*my_sbrk_faillure();
t_list		*my_page_faillure();
void		my_ptr_error();
/* my_structure.c */
t_list		*my_get_static(t_list *);
void		my_set_static(t_list *set);
/* realloc.c */
void		*my_realloc(void *ptr, size_t size);
t_list		*my_ptr_block(void * ptr, t_list *list);
/* show_alloc_mem() */
void		show_alloc_mem();

#endif /* !H_MAIN_H_ */
