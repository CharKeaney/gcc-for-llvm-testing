/* { dg-do compile } */
/* { dg-options "-Ofast -fno-split-loops -fdump-tree-ifcvt-stats-blocks-details" } */
/* { dg-require-visibility "" } */
/* { dg-require-effective-target gcc_frontend } */

int b[256] = {0}, y;
void bar (int *);
int foo (int x, int n)
{
  int i;
  int a[128];

  for (i = 0; i < n; i++)
    {
      a[i] = i;
      if (x > i)
	b[i] = y;
    }
  bar (a);
  return 0;
}

/* { dg-final { scan-tree-dump-times "Applying if-conversion" 1 "ifcvt" } } */

/* We insert into code
   if (LOOP_VECTORIZED (...))
   which is folded by vectorizer.  Both outgoing edges must have probability
   100% so the resulting profile match after folding.  */
/* { dg-final { scan-tree-dump-times "Invalid sum of outgoing probabilities 200.0" 1 "ifcvt" } } */
/* { dg-final { scan-tree-dump-times "Invalid sum of incoming counts" 1 "ifcvt" } } */

