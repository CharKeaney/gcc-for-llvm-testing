/* PR c/57821 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2" } */
static char * name[] = {
    [0x8000000000000000]  = "bar"
  }; /* { dg-error "too large" } */
