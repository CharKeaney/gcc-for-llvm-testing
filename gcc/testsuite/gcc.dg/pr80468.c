/* PR c/80468 */
/* { dg-do compile { target { ! int128 } } } */
/* { dg-options "" } */
/* { dg-additional-options "-Wno-unused-comparison" } */
/* { dg-require-effective-target gcc_frontend } */

void
foo (void)
{
  __attribute__ ((__vector_size__ (4 * sizeof (unsigned)))) __int128 b;	/* { dg-error "is not supported on this target" } */
  0 != b;
}
