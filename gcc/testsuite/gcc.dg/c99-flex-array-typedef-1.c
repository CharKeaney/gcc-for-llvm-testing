/* Test for invalid uses of flexible array members.  */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=iso9899:1999 -pedantic-errors" } */

typedef int A[];
struct s1 { A x; }; /* { dg-error "no named members" "members" } */
struct s2 { int :1; A x; }; /* { dg-error "no named members" "members" } */
struct s3 { A x; int y; }; /* { dg-error "not at end" "not at end" } */
struct s4 { int x; A y; };
