/*
** my_error.c for error in /home/saint-_a/Documents/malloc
**
** Made by Augustin Saint Olive
** Login   <saint-_a@epitech.net>
**
** Started on  Thu Jun 18 12:54:17 2015 Augustin Saint Olive
** Last update Fri Jun 26 14:41:07 2015 DwarfNet
*/

#include "h_main.h"

void	my_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      write(2, &str[i], 1);
      i = i + 1;
    }
  write(2, "\n", 1);
}

void	my_ptr_error()
{
  my_error("PTR don't point to an allocated memory space.\0");
}

t_list	*my_sbrk_faillure()
{
  return (NULL);
}

t_list	*my_page_faillure()
{
  return (NULL);
}
