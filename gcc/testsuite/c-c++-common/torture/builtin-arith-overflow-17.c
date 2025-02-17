/* Test __builtin_{add,sub,mul}_overflow.  */
/* { dg-do run { target int128 } } */
/* { dg-skip-if "" { ! run_expensive_tests }  { "*" } { "-O0" "-O2" } } */
/* { dg-require-effective-target noclone } */

#include "builtin-arith-overflow-12.h"

#define INT128_MAX ((signed __int128) (((unsigned __int128) 1 << (__SIZEOF_INT128__ * __CHAR_BIT__ - 1)) - 1))
#define INT128_MIN (-INT128_MAX - 1)

TESTS (__int128, INT128_MIN, INT128_MAX)

#undef T
#define T(n, t1, t2, tr, v1, v2, vr, b, o) t##n##b ();

int
main ()
{
  TESTS (__int128, INT128_MIN, INT128_MAX)
  return 0;
}
