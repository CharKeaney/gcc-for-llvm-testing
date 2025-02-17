/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

int f(int x){
  int y = x;
  int z = 0;
  return x / y - x % y + z / y;
}

/* { dg-final { scan-tree-dump "return 1;" "optimized"} } */
