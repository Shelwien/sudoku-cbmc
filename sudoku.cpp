
char s[] =
"...49...."
"49625..13"
"..1...9.4"
"..9.7..2."
"56.1.9.38"
".8..6.7.."
"9.4...3.."
"82..43691"
"....85..."
;

#define N 9

#include <stdio.h>

typedef unsigned char byte;
typedef unsigned int  uint;

struct X {
  byte tbl[N*N];
  byte flag;
};

extern byte stream[ sizeof(X) ];

int main( void ) {

  uint i,j,k,m; byte c;

  X& x = (X&)stream[0];

  for( i=0; i<N; i++ ) {
    for( j=0; j<N; j++ ) {
      c = s[i*N+j];
      if( (c>='1') && (c<='9') ) {
        __CPROVER_assume( x.tbl[i*N+j]==c );
      } else {
        __CPROVER_assume( (x.tbl[i*N+j]>='1') && ((x.tbl[i*N+j]<='9')) );
      }
    }
  }

  uint rowflags=1,colflags=1,blkflags=1;
  for( i=0; i<N; i++ ) {

    uint rowmask=0,colmask=0,blkmask=0;

    for( j=0; j<N; j++ ) {
      c = x.tbl[i*N+j];
      m = ((c>='1') && (c<='9')) ? (1<<(c-'0')) : 1;
      rowmask |= m;

      c = x.tbl[j*N+i];
      m = ((c>='1') && (c<='9')) ? (1<<(c-'0')) : 1;
      colmask |= m;

      c = x.tbl[ (i-i%3+(j/3))*N + (i%3)*3+(j%3) ];
      m = ((c>='1') && (c<='9')) ? (1<<(c-'0')) : 1;
      blkmask |= m;
    }

    rowflags &= (rowmask==((2<<N)-2));
    colflags &= (colmask==((2<<N)-2));
    blkflags &= (blkmask==((2<<N)-2));
  }

  x.flag = rowflags && colflags && blkflags;

  if( x.flag ) {
    match: {}
  }

}



