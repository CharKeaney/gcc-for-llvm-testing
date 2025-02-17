/* { dg-do compile } */
/* { dg-options "-O2 -ftree-parallelize-loops=4 -fdump-tree-parloops2-details -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

void abort (void);

void parloop (int N)
{
  int i, j;
  int x[500][500];

  for (i = 0; i < N; i++)
    for (j = 0; j < i; j++)
      x[i][j] = i + j + 3;

  for (i = 0; i < N; i++)
    for (j = 0; j < i; j++)
      if (x[i][j] != i + j + 3)
	abort ();
}

int main(void)
{
  parloop(500);

  return 0;
}


/* Check that outer loop is parallelized.  */
/* { dg-final { scan-tree-dump-times "parallelizing outer loop" 1 "parloops2" } } */
/* { dg-final { scan-tree-dump-times "loopfn" 4 "optimized" } } */
