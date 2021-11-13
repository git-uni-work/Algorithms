#ifndef __PROGTEST__
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

unsigned long long int hyperloop                           ( unsigned long long int length,
                                                             unsigned int        s1,
                                                             unsigned int        s2,
                                                             unsigned int        s3,
                                                             unsigned int        bulkhead,
                                                             unsigned int      * c1,
                                                             unsigned int      * c2,
                                                             unsigned int      * c3 )
{
    unsigned long long int nlength = length - bulkhead;
    unsigned int ns1 = s1 + bulkhead;
    unsigned int ns2 = s2 + bulkhead;
    unsigned int ns3 = s3 + bulkhead;

    if ( s1 == 0 && s2 == 0 && s3 == 0 && bulkhead == length )
    {
        *c1 = 0;
        *c2 = 0;
        *c3 = 0;
        return 1;
    }
    if( length == 0 || bulkhead >= length )
        return 0;
    if ( s1 == 0 && s2 == 0 && s3 == 0 )
        return 0;

    if ( s1 == 0 && s2 == 0 )
    {
        *c1 = 0;
        *c2 = 0;
        if ( (!( nlength % ns3 )) )
        {
            *c3 = nlength / ns3;
            return 1;
        }
        return 0;
    }
    if( s2 == 0 && s3 == 0 )
    {
        *c2 = 0;
        *c3 = 0;
        if ( (!( nlength % ns1 )) )
        {
            *c1 = nlength / ns1;
            return 1;
        }
        return 0;
    }
    if ( s1 == 0 && s3 == 0 )
    {
        *c1 = 0;
        *c3 = 0;
        if ( (!( nlength % ns2 )) )
        {
            *c2 = nlength / ns2;
            return 1;
        }
        return 0;
    }

    if ( s1 == 0 && s2 == s3 )
    {
        *c1 = 0;
        *c2 = 0;
        if ( (!( nlength % ns3 )) )
        {
            *c3 = nlength / ns3;
            return 1;
        }
        return 0;
    }
    if ( s2 == 0 && s1 == s3 )
    {
        *c2 = 0;
        *c1 = 0;
        if ( (!( nlength % ns3 )) )
        {
            *c3 = nlength / ns3;
            return 1;
        }
        return 0;
    }
    if ( s3 == 0 && s1 == s2 )
    {
        *c3 = 0;
        *c1 = 0;
        if ( (!( nlength % ns2 )) )
        {
            *c2 = nlength / ns2;
            return 1;
        }
        return 0;
    }
    
    if ( ns1 == ns2 && ns2 == ns3 )
    {
        if ( nlength % ns1 )
            return 0;
        *c1 = nlength / ns1;
        *c2 = 0;
        *c3 = 0;
        return 1;
    }

    if ( !s1 )
    {
        unsigned long long int counter = 0;
        unsigned long long int tmpl = nlength;
        unsigned long long int i;
        *c1 = 0;
        for ( i = 0 ; i <= (nlength / ns2) ; i++ )
        {
            if( !(tmpl % ns3) )
            {
                *c2 = i;
                *c3 = (nlength - (ns2 * i)) / ns3;
                counter++;
            }
            tmpl -= ns2;
        }
        return counter;
    }
    if ( !s2 )
    {
        unsigned long long int counter = 0;
        unsigned long long int tmpl = nlength;
        unsigned long long int i;
        *c2 = 0;
        for ( i = 0 ; i <= (nlength / ns1) ; i++ )
        {
            if( !(tmpl % ns3) )
            {
                *c1 = i;
                *c3 = (nlength - (ns1 * i)) / ns3;
                counter++;
            }
            tmpl -= ns1;
        }
        return counter;
    }
    if ( !s3 )
    {
        unsigned long long int counter = 0;
        unsigned long long int tmpl = nlength;
        unsigned long long int i;
        *c3 = 0;
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

    if ( ns1 == ns2 )
    {
        unsigned long long int counter = 0;
        unsigned long long int tmpl = nlength;
        unsigned long long int i;
        *c2 = 0;
        for ( i = 0 ; i <= (nlength / ns1) ; i++ )
        {
            if( !(tmpl % ns3) )
            {
                *c1 = i;
                *c3 = (nlength - (ns1 * i)) / ns3;
                counter++;
            }
            tmpl -= ns1;
        }
        return counter;
    }
    if ( ns2 == ns3 )
    {
        unsigned long long int counter = 0;
        unsigned long long int tmpl = nlength;
        unsigned long long int i;
        *c3 = 0;
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
    if ( ns1 == ns3 )
    {
        unsigned long long int counter = 0;
        unsigned long long int tmpl = nlength;
        unsigned long long int i;
        *c3 = 0;
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

    unsigned long long int counter5 = 0;
    unsigned long long int i;
    unsigned long long int j;
    unsigned long long int x;
    unsigned long long int y;
    for ( i = 0 ; i <= (nlength/ns2); i++ )
    {
        for( j = 0 ; j <= (nlength/ns3) ; j++ )
        {
            x = ( nlength - ( i * ns2 ) - ( j * ns3 ) ) / ns1;
            y = ( (x * ns1) + (i * ns2) + (j * ns3) );
            if ( ( ( i * ns2 ) + ( j * ns3 ) ) > nlength )
                break;
            if( y == nlength )
            {
                counter5++;
                *c1 = x;
                *c2 = i;
                *c3 = j;
            }
        }
    }
    return counter5;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
    unsigned int c1, c2, c3;
    assert ( hyperloop ( 100, 4, 7, 5, 0, &c1, &c2, &c3 ) == 42
             && 4 * c1 + 7 * c2 + 5 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 100 );
    assert ( hyperloop ( 12345, 8, 3, 11, 3, &c1, &c2, &c3 ) == 82708
             && 8 * c1 + 3 * c2 + 11 * c3 + 3 * ( c1 + c2 + c3 + 1 ) == 12345 );
    c1 = 8;
    c2 = 9;
    c3 = 10;
    assert ( hyperloop ( 127, 12, 8, 10, 0, &c1, &c2, &c3 ) == 0
             && c1 == 8
             && c2 == 9
             && c3 == 10 );
    assert ( hyperloop ( 127, 12, 8, 10, 3, &c1, &c2, &c3 ) == 4
             && 12 * c1 + 8 * c2 + 10 * c3 + 3 * ( c1 + c2 + c3 + 1 ) == 127 );
    assert ( hyperloop ( 100, 35, 0, 0, 10, &c1, &c2, &c3 ) == 1
             && c2 == 0
             && c3 == 0
             && 35 * c1 + 10 * ( c1 + 1 ) == 100 );
    assert ( hyperloop ( 100, 35, 0, 35, 10, &c1, &c2, &c3 ) == 1
             && c2 == 0
             && 35 * c1 + 35 * c3 + 10 * ( c1 + c3 + 1 ) == 100 );
    assert ( hyperloop ( 100, 35, 35, 35, 10, &c1, &c2, &c3 ) == 1
             && 35 * c1 + 35 * c2 + 35 * c3 + 10 * ( c1 + c2 + c3 + 1 ) == 100 );
    c1 = 42;
    c2 = 43;
    c3 = 44;
    assert ( hyperloop ( 9, 1, 2, 3, 10, &c1, &c2, &c3 ) == 0
             && c1 == 42
             && c2 == 43
             && c3 == 44 );
    return 0;
}
#endif /* __PROGTEST__ */


