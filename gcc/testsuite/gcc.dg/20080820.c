/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-fshow-column -fms-extensions -pedantic -std=gnu89" } */

struct { struct a { int x; }; int bar; } hot; /* { dg-warning "29:ISO C90 doesn't support unnamed" } */
