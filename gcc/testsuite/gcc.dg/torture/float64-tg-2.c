/* Test _Float64 type-generic built-in functions: __builtin_isinf_sign.  */
/* { dg-do run } */
/* { dg-options "" } */
/* { dg-add-options float64 } */
/* { dg-add-options ieee } */
/* { dg-require-effective-target float64_runtime } */
/* { dg-require-effective-target builtin_isinf } */

#define WIDTH 64
#define EXT 0
#include "floatn-tg-2.h"
