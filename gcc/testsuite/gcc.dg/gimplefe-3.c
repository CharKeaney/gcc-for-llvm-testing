/* { dg-do compile } */
/* { dg-options "-fgimple" } */
/* { dg-require-effective-target gcc_internals } */

void __GIMPLE () foo ()
{
  int *b;
  *b = 1;
}
