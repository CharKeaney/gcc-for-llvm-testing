/* PR c/14069 */
/* { dg-do compile } */
/* { dg-require-effective-target gcc_frontend } */
struct S { int a; char b[]; char *c; }; /* { dg-error "" "flexible array member not" } */
struct S s = { .b = "foo", .c = .b }; /* { dg-error "" "parse error before" } */
