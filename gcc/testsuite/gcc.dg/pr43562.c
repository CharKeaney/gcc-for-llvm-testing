/* { dg-options "-O0" } */
/* { dg-do compile } */
/* { dg-require-effective-target attr_optimize } */

extern unsigned foo (void);
extern void bar (void);

__attribute__ ((optimize ("O2")))
void bak ()
{
  unsigned a;
  while (1)
    {
      a = foo ();
      while (a)
	{
	  a &= 1;
	  bar ();
	}
    }
}
