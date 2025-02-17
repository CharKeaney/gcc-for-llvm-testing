/* { dg-do compile } */ 
/* { dg-options "-O2 -fdump-tree-pre-stats" } */
/* { dg-require-effective-target gcc_frontend } */
double cos (double) __attribute__ ((const));
double sin (double) __attribute__ ((const));
double f(double a)
{
  double b;
  double c,d;
  double (*fp) (double) __attribute__ ((const));
  /* Fully redundant call, but we need a phi node to merge the results.  */
  if (a < 2.0)
    {
      fp = sin;
      c = fp (a);
    }
  else
    {
      c = 1.0; 
      fp = cos;
      c = fp (a);
    }
  d = fp (a);
  return d + c;
}

/* { dg-final { scan-tree-dump-times "Eliminated: 1" 1 "pre"} } */
