/* Basic test on number of inserted callbacks.  */
/* { dg-do compile } */
/* { dg-options "-fsanitize-coverage=trace-pc -fdump-tree-optimized" } */
/* { dg-require-effective-target gcc_frontend } */

void foo (int *a, int *b, int *c)
{
  *a = 1;
  if (*b)
    *c = 2;
}

/* { dg-final { scan-tree-dump-times "__builtin___sanitizer_cov_trace_pc \\(\\)" 3 "optimized" } } */
