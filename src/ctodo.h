#ifndef CTODO_H_
#define CTODO_H_

#include <ncurses.h>
#include <stdlib.h>
#include <ctype.h>


#define _p(str) printf (str) 
#define p_ printf ("----------------------\n");






/* mem_exp enum */






/* args.c */
void get_args (int argc, char *argv[]);

/* ctodo.c */
void pnt_memu (void);//printf menu;
void choice_menu (void);
void do_menu (char ch);

void malloc_exp2(void);

/* files */

/* mem.c */

void * Xmalloc (size_t size);
void  Xfree (void * p);

/* mem_exp.c */
void mem_exp_exec (const char * exp_name);

#endif

