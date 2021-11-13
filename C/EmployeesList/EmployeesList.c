#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TCar
{
  struct TCar              * m_Next;
  char                     * m_Model;
} TCAR;

typedef struct TEmployee
{
  struct TEmployee         * m_Next;
  struct TCar              * m_Car;
  char                     * m_Name;
} TEMPLOYEE;

typedef struct TOffice
{
  TEMPLOYEE                * m_Emp;
  TCAR                     * m_Car;
} TOFFICE;

#endif /* __PROGTEST__ */

TOFFICE          * initOffice   ()
{
    TOFFICE * anoffice = (TOFFICE *) malloc( sizeof(TOFFICE) );
    anoffice->m_Emp = NULL;
    anoffice->m_Car = NULL;
    return anoffice;
}
void               addEmployee  ( TOFFICE         * office,
                                  const char      * name )
{
    char * empname = strdup(name);
    TEMPLOYEE * newemp = (TEMPLOYEE *) malloc ( sizeof(TEMPLOYEE) );
    newemp -> m_Name = empname;
    newemp -> m_Car = NULL;

    newemp -> m_Next = office -> m_Emp;
    office -> m_Emp  = newemp;
}
void               addCar       ( TOFFICE         * office,
                                  const char      * model )
{
    char * car = strdup(model);
    TCAR * newcar = (TCAR *) malloc ( sizeof(TCAR) );
    newcar -> m_Model = car;

    newcar -> m_Next = office -> m_Car;
    office -> m_Car  = newcar;}
TOFFICE          * cloneOffice  ( TOFFICE         * office )
{
    TEMPLOYEE * currentemp = office -> m_Emp;
    while ( currentemp != NULL )
    {
        TEMPLOYEE * clonedemp = (TEMPLOYEE *) malloc ( sizeof(TEMPLOYEE) );
        clonedemp -> m_Car = NULL;
        char * clonedname = strdup(currentemp -> m_Name);
        clonedemp -> m_Name = clonedname;
        clonedemp -> m_Next = currentemp -> m_Next;
        currentemp -> m_Next = clonedemp;

        currentemp = currentemp -> m_Next -> m_Next;
    }

    TCAR * currentcar = office -> m_Car;
    while ( currentcar != NULL )
    {
        TCAR * clonedcar = (TCAR *) malloc ( sizeof(TCAR) );
        char * clonedmodel = strdup(currentcar -> m_Model);
        clonedcar -> m_Model = clonedmodel;
        clonedcar -> m_Next = currentcar -> m_Next;
        currentcar -> m_Next = clonedcar;

        currentcar = currentcar -> m_Next -> m_Next;
    }

    TOFFICE * officedup = initOffice();
    if ( office -> m_Emp != NULL )
        officedup -> m_Emp = office -> m_Emp -> m_Next;
    if ( office -> m_Car != NULL )
        officedup -> m_Car = office -> m_Car -> m_Next;

    TEMPLOYEE * cemp = office -> m_Emp;
    while ( cemp != NULL )
    {
        if ( cemp -> m_Car != NULL )
            cemp -> m_Next -> m_Car = cemp -> m_Car -> m_Next;

        TEMPLOYEE * tmp = cemp -> m_Next;
        cemp -> m_Next = tmp -> m_Next;

        if ( tmp -> m_Next == NULL )
            break;
        tmp -> m_Next = cemp -> m_Next -> m_Next;

        cemp = cemp -> m_Next;
    }

    TCAR * ccar = office -> m_Car;
    while ( ccar != NULL )
    {
        TCAR * tmpc = ccar -> m_Next;
        ccar -> m_Next = tmpc -> m_Next;

        if ( tmpc -> m_Next == NULL )
            break;
        tmpc -> m_Next = ccar -> m_Next -> m_Next;

        ccar = ccar -> m_Next;
    }

    return officedup;
}
void               freeOffice   ( TOFFICE         * office )
{
    TEMPLOYEE * removeemp = office->m_Emp;
    while ( removeemp != NULL )
    {
        TEMPLOYEE * tmpe = removeemp -> m_Next;
        free(removeemp->m_Name);
        free(removeemp);
        removeemp = tmpe;
    }

    TCAR * removecar = office->m_Car;
    while ( removecar != NULL )
    {
        TCAR * tmpc = removecar -> m_Next;
        free(removecar->m_Model);
        free(removecar);
        removecar = tmpc;
    }

    free(office);
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TOFFICE * a, *b;
  char tmp[100];

  assert ( sizeof ( TOFFICE ) == 2 * sizeof ( void * ) );
  assert ( sizeof ( TEMPLOYEE ) == 3 * sizeof ( void * ) );
  assert ( sizeof ( TCAR ) == 2 * sizeof ( void * ) );
  a = initOffice ();
  addEmployee ( a, "Peter" );
  addEmployee ( a, "John" );
  addEmployee ( a, "Joe" );
  addEmployee ( a, "Maria" );
  addCar ( a, "Skoda Octavia" );
  addCar ( a, "VW Golf" );
  a -> m_Emp -> m_Car = a -> m_Car;
  a -> m_Emp -> m_Next -> m_Next -> m_Car = a -> m_Car -> m_Next;
  a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car = a -> m_Car;
  assert ( a -> m_Emp
           && ! strcmp ( a -> m_Emp -> m_Name, "Maria" )
           && a -> m_Emp -> m_Car == a -> m_Car );
  assert ( a -> m_Emp -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Name, "Joe" )
           && a -> m_Emp -> m_Next -> m_Car == NULL );
  assert ( a -> m_Emp -> m_Next -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Emp -> m_Next -> m_Next -> m_Car == a -> m_Car -> m_Next );
  assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car == a -> m_Car );
  assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  assert ( a -> m_Car
           && ! strcmp ( a -> m_Car -> m_Model, "VW Golf" ) );
  assert ( a -> m_Car -> m_Next
           && ! strcmp ( a -> m_Car -> m_Next -> m_Model, "Skoda Octavia" ) );
  assert ( a -> m_Car -> m_Next -> m_Next == NULL );
  b = cloneOffice ( a );
  strncpy ( tmp, "Moe", sizeof ( tmp ) );
  addEmployee ( a, tmp );
  strncpy ( tmp, "Victoria", sizeof ( tmp ) );
  addEmployee ( a, tmp );
  strncpy ( tmp, "Peter", sizeof ( tmp ) );
  addEmployee ( a, tmp );
  strncpy ( tmp, "Citroen C4", sizeof ( tmp ) );
  addCar ( a, tmp );
  b -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car = b -> m_Car -> m_Next -> m_Next;
  assert ( a -> m_Emp
           && ! strcmp ( a -> m_Emp -> m_Name, "Peter" )
           && a -> m_Emp -> m_Car == NULL );
  assert ( a -> m_Emp -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Name, "Victoria" )
           && a -> m_Emp -> m_Next -> m_Car == NULL );
  assert ( a -> m_Emp -> m_Next -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Name, "Moe" )
           && a -> m_Emp -> m_Next -> m_Next -> m_Car == NULL );
  assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Name, "Maria" )
           && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car == a -> m_Car -> m_Next );
  assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Joe" )
           && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Car == NULL );
  assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Car == a -> m_Car -> m_Next -> m_Next );
  assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Car == a -> m_Car -> m_Next );
  assert ( a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  assert ( a -> m_Car
           && ! strcmp ( a -> m_Car -> m_Model, "Citroen C4" ) );
  assert ( a -> m_Car -> m_Next
           && ! strcmp ( a -> m_Car -> m_Next -> m_Model, "VW Golf" ) );
  assert ( a -> m_Car -> m_Next -> m_Next
           && ! strcmp ( a -> m_Car -> m_Next -> m_Next -> m_Model, "Skoda Octavia" ) );
  assert ( a -> m_Car -> m_Next -> m_Next -> m_Next == NULL );
  assert ( b -> m_Emp
           && ! strcmp ( b -> m_Emp -> m_Name, "Maria" )
           && b -> m_Emp -> m_Car == b -> m_Car );
  assert ( b -> m_Emp -> m_Next
           && ! strcmp ( b -> m_Emp -> m_Next -> m_Name, "Joe" )
           && b -> m_Emp -> m_Next -> m_Car == NULL );
  assert ( b -> m_Emp -> m_Next -> m_Next
           && ! strcmp ( b -> m_Emp -> m_Next -> m_Next -> m_Name, "John" )
           && b -> m_Emp -> m_Next -> m_Next -> m_Car == b -> m_Car -> m_Next );
  assert ( b -> m_Emp -> m_Next -> m_Next -> m_Next
           && ! strcmp ( b -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && b -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car == NULL );
  assert ( b -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  assert ( b -> m_Car
           && ! strcmp ( b -> m_Car -> m_Model, "VW Golf" ) );
  assert ( b -> m_Car -> m_Next
           && ! strcmp ( b -> m_Car -> m_Next -> m_Model, "Skoda Octavia" ) );
  assert ( b -> m_Car -> m_Next -> m_Next == NULL );
  freeOffice ( a );
  freeOffice ( b );
  return 0;
}
#endif /* __PROGTEST__ */
