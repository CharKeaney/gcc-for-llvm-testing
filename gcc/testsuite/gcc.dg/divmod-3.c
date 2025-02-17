/* { dg-require-effective-target divmod } */
/* { dg-options "-O2 -fdump-tree-widening_mul-details" } */
/* { dg-require-effective-target gcc_internals } */
/* div comes before mod in same bb.  */ 

typedef int SImode __attribute__((mode(SI)));
typedef unsigned USImode __attribute__((mode(SI)));

typedef int DImode __attribute__((mode(DI)));
typedef unsigned UDImode __attribute__((mode(DI)));

extern int cond;
void foo(void);

#define FOO(smalltype, bigtype, no)      \
bigtype f_##no(smalltype x, bigtype y)   \
{					 \
  bigtype q = x / y;                     \
  bigtype r = x % y;                     \
  return q + r;                          \
}

FOO(SImode, DImode, 1)
FOO(SImode, UDImode, 2)
FOO(USImode, DImode, 3)
FOO(USImode, UDImode, 4)
FOO(DImode, DImode, 5)
FOO(DImode, UDImode, 6)
FOO(UDImode, UDImode, 7)

/* { dg-final { scan-tree-dump-times "DIVMOD" 7 "widening_mul" } } */
