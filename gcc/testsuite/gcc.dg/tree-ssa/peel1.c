/* { dg-do compile } */
/* { dg-options "-O3 -fno-tree-vectorize -fdump-tree-cunroll-details" } */
/* { dg-require-effective-target gcc_frontend } */
struct foo {int b; int a[3];} foo;
void add(struct foo *a,int l)
{
  int i;
  for (i=0;i<l;i++)
    a->a[i]++;
}
/* { dg-final { scan-tree-dump "Loop 1 likely iterates at most 3 times." "cunroll"} } */
/* { dg-final { scan-tree-dump "Peeled loop 1, 4 times." "cunroll"} } */
