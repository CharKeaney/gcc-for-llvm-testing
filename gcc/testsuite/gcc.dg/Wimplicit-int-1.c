/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

static l; /* { dg-warning "type defaults to" } */

foo (a) /* { dg-warning "return type defaults to" } */
/* { dg-warning "type of .a. defaults to .int." "type" { target *-*-* } .-1 } */
{
  auto p; /* { dg-warning "type defaults to" } */
  typedef bar; /* { dg-warning "type defaults to" } */
}
