/* Verify that preprocessor does not insert redundant newlines
   after #pragma */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
int
main ()
{
#pragma unknown
  {
    error;
  /* { dg-error "undeclared" "undeclared-variable message" { target *-*-* } .-1 } */
  /* { dg-message "function it appears in" "reminder message" { target *-*-* } .-2 } */ 
  }
}
