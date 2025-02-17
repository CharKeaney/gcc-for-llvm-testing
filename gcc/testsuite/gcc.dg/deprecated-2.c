/* Test __attribute__((deprecated)).  Test types without names.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "" } */

struct { int a; } __attribute__((deprecated)) x; /* { dg-warning "type is deprecated" } */
typeof(x) y; /* { dg-warning "type is deprecated" } */
