/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-evrp" } */
/* { dg-require-effective-target gcc_frontend } */

int foo (int i);
int bar (int j)
{
  if (j > 2)
    return foo (j + 2);
  else
    return j;
}

/* { dg-final { scan-tree-dump "\\\[5, \\+INF" "evrp" } } */
