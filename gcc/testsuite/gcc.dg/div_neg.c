/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

float
div_neg (float x, float y)
{
  return (-x / y) * (x / -y);
}

/* { dg-final { scan-tree-dump-times " / " 1 "optimized" } } */
