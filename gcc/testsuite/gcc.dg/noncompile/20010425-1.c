/* { dg-require-effective-target gcc_frontend } */
__inline__ void bar(int x)
{
  (void)x;
}

void foo(void)
{
  bar(baz);  /* { dg-error "undeclared|for each function" } */
}
