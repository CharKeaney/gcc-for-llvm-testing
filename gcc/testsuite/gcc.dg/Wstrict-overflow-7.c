/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-fstrict-overflow -O2 -Wstrict-overflow" } */

/* Source: Ian Lance Taylor.  */

int
foo (int i)
{
  return i + 10 > i; /* { dg-warning "assuming signed overflow does not occur" "correct warning" { xfail *-*-* } } */
}
