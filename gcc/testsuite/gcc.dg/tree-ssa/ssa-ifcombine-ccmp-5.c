/* { dg-do compile { target { ! { { logical_op_short_circuit && { ! avr-*-* } } || { m68k*-*-* mmix*-*-* bfin*-*-* v850*-*-* moxie*-*-* cris*-*-* m32c*-*-* fr30*-*-* mcore*-*-* powerpc*-*-* xtensa*-*-* arc*-*-* mips*-*-* } } } } } */
/* { dg-require-effective-target gcc_frontend } */

/* { dg-options "-O2 -g -fdump-tree-optimized" } */
/* { dg-additional-options "-mbranch-cost=2" { target branch_cost } } */

int t (int a, int b, int c)
{
  if (a > 0 && b > 0 && c > 0)
      return 0;
  return 1;
}
/* { dg-final { scan-tree-dump-times "\&" 2 "optimized" } } */
