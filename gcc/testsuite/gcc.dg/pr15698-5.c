/* Test diagnostics for old-style definition not matching prior
   prototype are present and give correct location for that prototype
   (bug 15698).  Unprototyped built-in function with user prototype at
   inner scope.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=gnu99" } */

void f(void) { int isnan(void); } /* { dg-error "prototype declaration" } */
int isnan(a) int a; {} /* { dg-error "number of arguments doesn't match prototype" } */
