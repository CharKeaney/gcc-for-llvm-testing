/* This test needs runtime that provides __*_chk functions.  */
/* { dg-do run { target *-*-linux* *-*-gnu* } } */
/* { dg-options "-O2 -fdump-tree-strlen" } */
/* { dg-require-effective-target gcc_internals } */

#define FORTIFY_SOURCE 2
#include "strlenopt-2.c"

/* { dg-final { scan-tree-dump-times "strlen \\(" 2 "strlen" } } */
/* { dg-final { scan-tree-dump-times "__memcpy_chk \\(" 5 "strlen" } } */
/* { dg-final { scan-tree-dump-times "__strcpy_chk \\(" 0 "strlen" } } */
/* { dg-final { scan-tree-dump-times "__strcat_chk \\(" 0 "strlen" } } */
/* { dg-final { scan-tree-dump-times "strchr \\(" 0 "strlen" } } */
/* { dg-final { scan-tree-dump-times "__stpcpy_chk \\(" 0 "strlen" } } */
/* { dg-final { scan-tree-dump-times "memcpy \\(" 0 "strlen" } } */
/* { dg-final { scan-tree-dump-times "strcpy \\(" 0 "strlen" } } */
/* { dg-final { scan-tree-dump-times "strcat \\(" 0 "strlen" } } */
/* { dg-final { scan-tree-dump-times "stpcpy \\(" 0 "strlen" } } */
