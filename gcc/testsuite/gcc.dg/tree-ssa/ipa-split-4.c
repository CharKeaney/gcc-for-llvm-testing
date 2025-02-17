/* { dg-do compile } */
/* { dg-options "-O3 -fdump-tree-fnsplit" } */
/* { dg-require-effective-target gcc_frontend } */
int make_me_big (void);
void abort (void);

int
split_me (int a)
{
  if (__builtin_expect(a<10, 1))
    {
      abort ();
    }
  else
    {
      make_me_big ();
      make_me_big ();
      make_me_big ();
      make_me_big ();
      return a+1;
    }
}

int
test(void)
{
  return split_me (0)+split_me(1)+split_me(2);
}
/* { dg-final { scan-tree-dump-times "Splitting function" 1 "fnsplit"} } */
