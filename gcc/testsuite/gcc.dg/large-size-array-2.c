/* PR c/25309 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-O2" } */
static char * name[] = {
    [0x80000000]  = "bar"
  };
/* { dg-error "too large" "" { target { { ! lp64 } && { ! llp64 } } }  .-1 } */
