/* { dg-do compile { target { ! dfp } } } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu99 -Wunknown-pragmas" } */

#pragma STDC FLOAT_CONST_DECIMAL64 ON	/* { dg-warning "not supported on this target" } */
double d = 1.0;
