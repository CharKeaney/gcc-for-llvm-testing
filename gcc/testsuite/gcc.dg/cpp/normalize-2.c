/* { dg-do preprocess } */
/* { dg-require-effective-target gcc_frontend } */
/* { dg-options "-std=c99 -Wnormalized=nfkc" } */

\u00AA  /* { dg-warning "not in NFKC" } */
\u00B7
\u0F43  /* { dg-warning "not in NFC" } */
a\u05B8\u05B9\u05B9\u05BBb
 a\u05BB\u05B9\u05B8\u05B9b  /* { dg-warning "not in NFC" } */
\u09CB
\u09C7\u09BE /* { dg-warning "not in NFC" } */
\u0B4B
\u0B47\u0B3E /* { dg-warning "not in NFC" } */
\u0BCA
\u0BC6\u0BBE /* { dg-warning "not in NFC" } */
\u0BCB
\u0BC7\u0BBE /* { dg-warning "not in NFC" } */
\u0CCA
\u0CC6\u0CC2 /* { dg-warning "not in NFC" } */
\u0D4A
\u0D46\u0D3E /* { dg-warning "not in NFC" } */
\u0D4B
\u0D47\u0D3E /* { dg-warning "not in NFC" } */

K
\u212A /* { dg-warning "not in NFC" } */

\u03AC
\u1F71 /* { dg-warning "not in NFC" } */

\uAC00
\u1100\u1161 /* { dg-warning "not in NFC" } */
\uAC01
\u1100\u1161\u11A8 /* { dg-warning "not in NFC" } */
\uAC00\u11A8 /* { dg-warning "not in NFC" } */
