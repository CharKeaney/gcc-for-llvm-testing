/* { dg-do compile { target { ! { { logical_op_short_circuit && { ! avr-*-* } } || { m68k*-*-* mmix*-*-* bfin*-*-* v850*-*-* moxie*-*-* cris*-*-* m32c*-*-* fr30*-*-* mcore*-*-* powerpc*-*-* xtensa*-*-* arc*-*-* mips*-*-* } } } } } */
/* { dg-require-effective-target gcc_frontend } */

/* { dg-options "-O2 -g -fdump-tree-optimized" } */
/* { dg-additional-options "-mbranch-cost=2" { target branch_cost } } */

int t (int a, int b)
{
  if (a > 0)
    goto L1;
  if (b > 0)
    goto L2;
L1:
  return 0;
L2:
  return 1;
}
/* { dg-final { scan-tree-dump "\&" "optimized" } } */
