/* PR driver/81650 */
/* { dg-do compile } */
/* { dg-require-effective-target builtin_malloc } */
/* { dg-options "-Walloc-size-larger-than=9223372036854775807" } */

void *
foo (void)
{
  return __builtin_malloc (5);
}
