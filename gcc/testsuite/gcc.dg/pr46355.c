/* { dg-do compile } */
/* { dg-options "-O -ftree-loop-distribution -fstrict-overflow" } */
/* { dg-require-effective-target gcc_internals } */

void
foo (int *dest, int i, int u, int v)
{
  int j = i;
  while (i)
    {
      dest[j--] = v;
      dest[j--] = u;
    }
}

