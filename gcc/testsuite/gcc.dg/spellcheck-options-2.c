/* { dg-do compile } */
/* { dg-options "-Wthis-should-not-get-a-hint" } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-bogus "did you mean" "" { target *-*-* } 0 } */
/* { dg-error "unrecognized command line option '-Wthis-should-not-get-a-hint'"  "" { target *-*-* } 0 } */

