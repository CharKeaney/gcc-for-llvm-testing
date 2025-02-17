/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2 -Wall -ftrack-macro-expansion=0" } */

extern void abort (void);

#include "../gcc.c-torture/execute/builtins/chk.h"

extern char *mallocminus1(int size) __attribute__((alloc_size(-1))); /* { dg-warning "parameter outside range" } */
extern char *malloc0(int size) __attribute__((alloc_size(0))); /* { dg-warning "parameter outside range" } */
extern char *malloc1(int size) __attribute__((alloc_size(1)));
extern char *malloc2(int empty, int size) __attribute__((alloc_size(2)));
extern char *calloc1(int size, int elements) __attribute__((alloc_size(1,2)));
extern char *calloc2(int size, int empty, int elements) __attribute__((alloc_size(1,3)));
extern char *balloc1(void *size) __attribute__((alloc_size(1)));

void
test (void)
{
  char *p;

  p = malloc0 (6);
  strcpy (p, "Hello");
  p = malloc1 (6);
  strcpy (p, "Hello");
  strcpy (p, "Hello World"); /* { dg-warning "writing" "strcpy" } */
  p = malloc2 (__INT_MAX__ >= 1700000 ? 424242 : __INT_MAX__ / 4, 6);
  strcpy (p, "World");
  strcpy (p, "Hello World"); /* { dg-warning "writing" "strcpy" } */
  p = calloc1 (2, 5);
  strcpy (p, "World");
  strcpy (p, "Hello World"); /* { dg-warning "writing" "strcpy" } */
  p = calloc2 (2, __INT_MAX__ >= 1700000 ? 424242 : __INT_MAX__ / 4, 5);
  strcpy (p, "World");
  strcpy (p, "Hello World"); /* { dg-warning "writing" "strcpy" } */
}

