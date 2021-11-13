#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double min( double a, double b )
{
    if( a > b )
        return b;
    return a;
}
int main() {
    double a1, a2, b1, b2, c1, c2, d1, d2, e1, e2, f1, f2;
    double ab, bc, ac, de, ef, df, l1, l2,s1,s2,s3,s4;
    char a, b, c, d;
    double ep = 1e-12;
    double t1[3] = {0};
    double t2[3] = {0};
    int i,j,x;

    printf("Triangle #1:\n");
    if ((scanf(" %c", &a) != 1) || (a != '{')) {
        printf("Invalid input.\n");
        return 0;
    }
    if ((scanf(" %lf , %lf , %lf %c", &ab, &bc, &ac, &b) == 4) )
    {
        if ( b != '}')
        {
            printf("Invalid input.\n");
            return 0;
        }
        t1[0] = ab;
        t1[1] = bc;
        t1[2] = ac;
        l1 = (double) ab+bc+ac;
        if (   ( ( ab + bc - ac ) <= ( ep * ac ) )
               || ( ( ab + ac - bc ) <= ( ep * bc ) )
               || ( ( bc + ac - ab ) <= ( ep * ab ) ) )
        {
            printf("Invalid triangle.\n");
            return 0;
        }
        for (i = 0; i < 3; i++)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (t1[i] > t1[j])
                {
                    x = t1[i];
                    t1[i] = t1[j];
                    t1[j] = x;
                }

            }
        }
    }
    else if ( scanf(" %c %lf ; %lf ] , [ %lf ; %lf ] , [ %lf ; %lf ] %c", &c, &a1, &a2, &b1, &b2, &c1, &c2, &d) == 8 )
    {
        if ( (c != '[') || (d != '}') )
        {
            printf("Invalid input.\n");
            return 0;
        }
        ab = sqrt( pow((a1-b1),2) + pow((a2-b2),2) );
        bc = sqrt( pow((b1-c1),2) + pow((b2-c2),2) );
        ac = sqrt( pow((a1-c1),2) + pow((a2-c2),2) );
        s1 = (b2 - a2) / (b1 - a1);
        s2 = (c2 - b2) / (c1 - b1);
        t1[0] = ab;
        t1[1] = bc;
        t1[2] = ac;
        l1 = (double) ab+bc+ac;
        if (   ( ( ab + bc - ac ) <= ( ep * ac ) )
               || ( ( ab + ac - bc ) <= ( ep * bc ) )
               || ( ( bc + ac - ab ) <= ( ep * ab ) ) )
        {
            printf("Invalid triangle.\n");
            return 0;
        }
        if( s1 == s2 )
        {
            printf("Invalid triangle.\n");
            return 0;
        }
        for (i = 0; i < 3; i++)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (t1[i] > t1[j])
                {
                    x = t1[i];
                    t1[i] = t1[j];
                    t1[j] = x;
                }

            }
        }
    }
    else
    {
        printf("Invalid input.\n");
        return 0;
    }

    printf("Triangle #2:\n");
    if ((scanf(" %c", &a) != 1) || (a != '{')) {
        printf("Invalid input.\n");
        return 0;
    }
    if ((scanf(" %lf , %lf , %lf %c", &de, &ef, &df, &b) == 4) )
    {
        if ( b != '}')
        {
            printf("Invalid input.\n");
            return 0;
        }
        l2 = (double)de+ef+df;
        t2[0] = de;
        t2[1] = ef;
        t2[2] = df;
        if(    ( ( de + ef - df ) <= ( ep * df ) )
               || ( ( de + df - ef ) <= ( ep * ef ) )
               || ( ( ef + df - de ) <= ( ep * de ) ) )
        {
            printf("Invalid triangle.\n");
            return 0;
        }
        for (i = 0; i < 3; i++)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (t2[i] > t2[j])
                {
                    x = t2[i];
                    t2[i] = t2[j];
                    t2[j] = x;
                }

            }
        }
    }
    else if ( scanf(" %c %lf ; %lf ] , [ %lf ; %lf ] , [ %lf ; %lf ] %c", &c, &d1, &d2, &e1, &e2, &f1, &f2, &d) == 8 )
    {
        if ( (c != '[') || (d != '}') )
        {
            printf("Invalid input.\n");
            return 0;
        }
        de = sqrt( pow((d1-e1),2) + pow((d2-e2),2) );
        ef = sqrt( pow((e1-f1),2) + pow((e2-f2),2) );
        df = sqrt( pow((d1-f1),2) + pow((d2-f2),2) );
        l2 = (double)de+ef+df;
        t2[0] = de;
        t2[1] = ef;
        t2[2] = df;
        s3 = (e2 - d2) / (e1 - d1);
        s4 = (f2 - e2) / (f1 - e1);

        if(    ( ( de + ef - df ) <= ( ep * df ) )
               || ( ( de + df - ef ) <= ( ep * ef ) )
               || ( ( ef + df - de ) <= ( ep * de ) ) )
        {
            printf("Invalid triangle.\n");
            return 0;
        }
        if( s3 == s4 )
        {
            printf("Invalid triangle.\n");
            return 0;
        }
        for (i = 0; i < 3; i++)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (t2[i] > t2[j])
                {
                    x = t2[i];
                    t2[i] = t2[j];
                    t2[j] = x;
                }

            }
        }
    }
    else
    {
        printf("Invalid input.\n");
        return 0;
    }

    if( fabs( l1 - l2 ) < ( ep * ( min(l1,l2) ) ) )
    {
        if (    ( ( t1[0] / t2[0] ) == ( t1[1] / t2[1] ) )
                && ( ( t1[1] / t2[1] ) == ( t1[2] / t2[2] ) ) )
        {
            printf("The triangles are identical.\n");
        }
        else
        {
            printf("The triangles are not identical, however, they have the same circumference.\n");
        }
    }
    else
    {
        if( l1 > l2 )
        {
            printf("Triangle #1 has a longer circumference.\n");
        }
        else
        {
            printf("Triangle #2 has a longer circumference.\n");
        }
    }

    return 0;
}

