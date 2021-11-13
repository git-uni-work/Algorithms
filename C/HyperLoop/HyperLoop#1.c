#ifndef __PROGTEST__
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

unsigned long long int hyperloop                           ( unsigned long long int length,
                                                             unsigned int        s1,
                                                             unsigned int        s2,
                                                             unsigned int        bulkhead,
                                                             unsigned int      * c1,
                                                             unsigned int      * c2 )
{
  if ( s1 == 0 && s2 == 0 && bulkhead == length )
  {
    *c1 = 0;
    *c2 = 0;
    return 1;
  }
  if ( s1 == 0 && s2 == 0)
      return 0;
  if( (s1 == 0 && s2 == 0) || length == 0 )
    return 0;
  if ( bulkhead >= length )
    return 0;

  unsigned long long int nlength = length - bulkhead;
  unsigned int ns1 = s1 + bulkhead;
  unsigned int ns2 = s2 + bulkhead;

  if ( !s1 )
  {
    *c1 = 0;
    if ( (!( nlength % ns2 )) && (ns2 != 0) )
    {
        *c2 = nlength / ns2;
        return 1;
    }
    return 0;
  }
  if ( !s2 )
  {
    *c2 = 0;
    if ( (!( nlength % ns1 )) && (ns1 != 0) )
    {
        *c1 = nlength / ns1;
        return 1;
    }
    return 0;
  }
  if ( ns1 == ns2 )
  {
    if ( nlength % ns2 )
      return 0;
    *c1 = 0;
    *c2 = nlength / ns2;
    return 1;
  }

   unsigned long long int counter = 0;
   unsigned long long int tmpl = nlength;
   unsigned long long int i;

    for ( i = 0 ; i <= (nlength / ns1) ; i++ )
    {
        if( !(tmpl % ns2) )
        {
            *c1 = i;
            *c2 = (nlength - (ns1 * i)) / ns2;
            counter++;
        }
        tmpl -= ns1;
    }
    return counter;

}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  unsigned int c1, c2;
  assert ( hyperloop ( 100, 4, 7, 0, &c1, &c2 ) == 4
           && 4 * c1 + 7 * c2 + 0 * (c1 + c2 + 1) == 100 );
  assert ( hyperloop ( 123456, 8, 3, 3, &c1, &c2 ) == 1871
           && 8 * c1 + 3 * c2 + 3 * (c1 + c2 + 1) == 123456 );
  assert ( hyperloop ( 127, 12, 8, 0, &c1, &c2 ) == 0 );
  assert ( hyperloop ( 127, 12, 4, 3, &c1, &c2 ) == 1
           && 12 * c1 + 4 * c2 + 3 * (c1 + c2 + 1) == 127 );
  assert ( hyperloop ( 100, 35, 0, 10, &c1, &c2 ) == 1
           && c2 == 0
           && 35 * c1 + 10 * (c1 + 1) == 100 );
  assert ( hyperloop ( 110, 30, 30, 5, &c1, &c2 ) == 1
           && 30 * c1 + 30 * c2 + 5 * (c1 + c2 + 1) == 110 );
  c1 = 2;
  c2 = 7;
  assert ( hyperloop ( 110, 30, 30, 0, &c1, &c2 ) == 0 && c1 == 2 && c2 == 7 );
  c1 = 4;
  c2 = 8;
  assert ( hyperloop ( 9, 1, 2, 10, &c1, &c2 ) == 0 && c1 == 4 && c2 == 8 );
  return 0;
}
#endif /* __PROGTEST__ */
