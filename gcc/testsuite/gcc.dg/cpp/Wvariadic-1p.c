/* { dg-do compile } */
/* { dg-options "-std=iso9899:1990 " } */
/* { dg-require-effective-target gcc_frontend } */
#pragma GCC diagnostic error "-Wpedantic"

#define f(x,...)	/* { dg-error "variadic" } */
#define g(x,y...)	/* { dg-error "variadic" } */
int not_empty;
/* { dg-message "warnings being treated as errors" "" { target *-*-* } 0 } */
