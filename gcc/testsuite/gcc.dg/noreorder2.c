/* { dg-do compile } */
/* { dg-options "-O2 -fno-toplevel-reorder" } */
/* { dg-require-effective-target gcc_frontend } */

__attribute__((no_reorder)) int foobar;

static int barbar;
int bozo;

/* { dg-final { scan-assembler "foobar" } } */
/* { dg-final { scan-assembler "bozo" } } */
/* { dg-final { scan-assembler "barbar" } } */
