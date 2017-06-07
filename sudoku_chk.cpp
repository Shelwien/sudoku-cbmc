
char s[] 
//= { 55, 51, 56, 52, 57, 49, 53, 54, 50, 52, 57, 54, 50, 53, 55, 56, 49, 51, 50, 53, 49, 56, 51, 54, 57, 55, 52, 51, 52, 57, 53, 55, 56, 49, 50, 54, 53, 54, 55, 49, 50, 57, 52, 51, 56, 49, 56, 50, 51, 54, 52, 55, 53, 57, 57, 55, 52, 54, 49, 50, 51, 56, 53, 56, 50, 53, 55, 52, 51, 54, 57, 49, 54, 49, 51, 57, 56, 53, 50, 52, 55, 1 };
#include "solution.inc"
;

#define N 9

#include <stdio.h>

typedef unsigned long long int qword;
typedef unsigned char byte;
typedef unsigned int  uint;
typedef byte* pbyte;

struct X {
  byte tbl[N*N];
  byte flag;
};

extern byte stream[ sizeof(X) ];

int main( void ) {

  uint i,j,k,m; byte c;

  X& x = (X&)s[0];

  for( i=0;; i++ ) {
    if( i%3==0 ) { for( j=0; j<=N*4/3; j++ ) printf( "-" ); printf( "\n" ); }
    if( i>=N ) break;
    for( j=0; j<N; j++ ) {
      if( j%3==0 ) printf( "|" );
      c = x.tbl[i*N+j];
      printf( "%c", c );
    }
    printf( "|\n" );
  }


}



