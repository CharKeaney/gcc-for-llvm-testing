/* PR tree-optimization/83521 */
/* { dg-do compile } */
/* { dg-options "-O1 -fno-tree-forwprop" } */
/* { dg-require-effective-target gcc_frontend } */

int
foo (unsigned int x, int y)
{
  int *z = (int *)&x;
  return (y == 0) ? y : *z;
}
