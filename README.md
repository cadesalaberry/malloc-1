# `malloc`

recode of a malloc, free and realloc fonctions. Epitech tek2 Project.


### Usage

```
$ make
gcc -fPIC -W -Wall -Wextra -Werror -I./include/ -g3   -c -o my_malloc.o my_malloc.c
gcc -fPIC -W -Wall -Wextra -Werror -I./include/ -g3   -c -o my_structure.o my_structure.c
gcc -fPIC -W -Wall -Wextra -Werror -I./include/ -g3   -c -o my_error1.o my_error1.c
gcc -fPIC -W -Wall -Wextra -Werror -I./include/ -g3   -c -o my_list1.o my_list1.c
gcc -fPIC -W -Wall -Wextra -Werror -I./include/ -g3   -c -o my_list2.o my_list2.c
gcc -fPIC -W -Wall -Wextra -Werror -I./include/ -g3   -c -o realloc.o realloc.c
gcc -fPIC -W -Wall -Wextra -Werror -I./include/ -g3   -c -o free.o free.c
gcc -fPIC -W -Wall -Wextra -Werror -I./include/ -g3   -c -o show_alloc_mem.o show_alloc_mem.c
gcc -shared -o libmy_malloc_.so my_malloc.o my_structure.o my_error1.o my_list1.o my_list2.o realloc.o free.o show_alloc_mem.o
ln -f -s libmy_malloc_.so libmy_malloc.so

# Then run any command that would use malloc loading your own implementation.
$ LD_PRELOAD=./libmy_malloc.so ls
```

Here, `ls` is the command you want to test whith this malloc.


### To Do

Encore quelques bug a corriger.
- dans my_list2.c : my_get_next_struct et my_get_size_alloc a perfectionner. Pour le moment la formule donne entre 0 et sizeof(t_list) octets en trop.
- Free final a implementer.

