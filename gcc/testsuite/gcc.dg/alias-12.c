/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-require-alias "" } */
/* { dg-options "-O2" } */
static void f (void) __attribute__((alias("f"))); // { dg-error "part of alias cycle" }

void g ()
{
  f ();
}
