/* PR c/17023 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

void
f(a, b)
     int a;
     int b[({ void h() {} 1; })];	/* { dg-error "braced-group" } */
{
}
