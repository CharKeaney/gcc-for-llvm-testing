/* { dg-do compile } */
/* { dg-options "-fgnu-tm -fdump-tree-tmmark-asmname" } */
/* { dg-require-effective-target gcc_frontend } */

void foo(void);

void bar(void)
{
  __transaction_relaxed {
    foo();
  }
}

/* { dg-final { scan-tree-dump-times "_ZGTt3foo" 0 "tmmark" } } */
