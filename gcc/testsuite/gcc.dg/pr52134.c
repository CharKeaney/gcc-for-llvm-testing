/* { dg-do compile } */
/* { dg-options "-fdump-tree-original" } */
/* { dg-require-effective-target gcc_internals } */

unsigned f(unsigned t)
{
    return (t*4)&-4;
}
int f1(int t)
{
    return (t*4)&-4;
}

/* { dg-final { scan-tree-dump-not "\\\&" "original" } } */
