/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-evrp -fdelete-null-pointer-checks" } */
/* { dg-require-effective-target gcc_frontend } */

void foo (void *p) __attribute__((nonnull(1)));

void bar (void *p)
{
  foo (p);
  if (!p)
    __builtin_abort ();
}

/* { dg-final { scan-tree-dump-not "abort" "evrp" } } */
