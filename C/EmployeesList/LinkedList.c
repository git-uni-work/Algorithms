#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void printemp(TOFFICE * office) {
    TEMPLOYEE * tmp = office->m_Emp;
    int i = 1;
    while (tmp != NULL)
    {
        printf(" EMP#%d Name : %s ",i++, tmp->m_Name);
        if( tmp->m_Car != NULL)
        {
            printf(" - Car : %s \n", tmp->m_Car->m_Model);
        }
        else
            printf(" - NULL \n");
        tmp = tmp->m_Next;
    }

}
void printcars(TOFFICE * office) {
    TCAR * tmp = office->m_Car;
    int i = 1;
    while (tmp != NULL)
    {
        printf(" Car#%d Model : %s \n",i++, tmp->m_Model );
        tmp = tmp->m_Next;
    }
}


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
    office -> m_Car  = newcar;
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
    if ( office -> m_Emp -> m_Next != NULL )
        officedup -> m_Emp = office -> m_Emp -> m_Next;
    if ( office -> m_Car -> m_Next != NULL )
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

/*        printf("\n---CLONED---\n");
        printf("EMPLOYEES:\n");
        printemp(officedup);*/
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

/*        printf("CARS:\n");
        printcars(officedup);*/
    }

    return officedup;
}



int main()
{
    TOFFICE * a = initOffice ();
    addEmployee ( a, "Peter" );
    addEmployee ( a, "John" );
    addEmployee ( a, "Joe" );
    addEmployee ( a, "Maria" );
    addCar ( a, "Skoda Octavia" );
    addCar ( a, "VW Golf" );
    a -> m_Emp -> m_Car = a -> m_Car;
    a -> m_Emp -> m_Next -> m_Next -> m_Car = a -> m_Car -> m_Next;
    a -> m_Emp -> m_Next -> m_Next -> m_Next -> m_Car = a -> m_Car;

    TOFFICE * b = cloneOffice ( a );

    printf("---A---\n");
    printf("EMPLOYEES:\n");
    printemp(a);
    printf("CARS:\n");
    printcars(a);
    printf("---B---\n");
    printf("EMPLOYEES:\n");
    printemp(b);
    printf("CARS:\n");
    printcars(b);

    freeOffice(a);
    freeOffice(b);

    return 0;
}
