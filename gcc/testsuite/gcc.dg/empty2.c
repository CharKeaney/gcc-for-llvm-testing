/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-pedantic" } */
double d=0;

struct A {} a; /* { dg-warning "struct has no members" } */

void foo(struct A x)
{
  d=0;
}

void bar()
{
  if (d) foo(a);
}
