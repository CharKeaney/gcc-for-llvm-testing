/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-specs=${srcdir}/gcc.dg/pr48524.spec -D_TEST_D" } */
# ifdef _FOO
# error works /* { dg-error "works" } */
# endif

