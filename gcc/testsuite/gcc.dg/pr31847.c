/* PR 31847 */

/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-pre-all" } */
/* { dg-require-effective-target gcc_internals } */

extern int bar(int);

int foo()
{
  int a = 0;
  return bar(a);
}

/* { dg-final { scan-tree-dump-not "Created value  for " "pre"} } */
