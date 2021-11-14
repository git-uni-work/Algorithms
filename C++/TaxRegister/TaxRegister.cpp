#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>

using namespace std;

#endif /* __PROGTEST__ */

// class used to represent a record entity in the database
class Person
{

private:

  // name , address & ID fields of a record
  string name;
  string addy;
  string id;

  // income & expense fields of a record
  int income;
  int expense;

public:

  // Constructor for creating a new instance of a record to add to the database
  Person( const string & n , const string & a , const string & x )
  {
    name = n;
    addy = a;
    id = x;
    income = expense = 0;
  }

  // Constructor used to create an object instance to use for the name comparator
  Person( const string & n , const string & a )
  {
    name = n;
    addy = a;
  }

  // Constructor used to create an object instance to use for the id comparator
  Person( const string & x )
  { id = x; }

  // "getters" for the fields of a record
  string getName() const
  { return name; }
  string getAddy() const
  { return addy; }
  string getID() const
  { return id; }
  int getIncome() const
  { return income; }
  int getExpense() const
  { return expense; }

  // "setters" for incrementing the income and expense fields
  void addIncome( int no )
  { income += no; }
  void addExpense( int no )
  { expense += no; }

};

class CIterator
{

private:

  // container for all the records in the tax register ordered lexographically by name & address
  vector<Person> database;
  // number of records in the database
  int size;
  // counter used as an index to access the database
  int index = 0;

public:

  // Constructor creates an instance and copies the passed container and its size
  CIterator( vector<Person> v , int x ) : database(v) , size(x) {};

  // function increments the current index to access the next record
  void Next( void )
  { index++; }

  // function checks the current index against the size of the database
  bool AtEnd( void ) const
  {
    if( index == size )
    { return true; }
    else
    { return false; }
  }

  // CIterator "getters" of the different fields at the currently indexed record
  string Name( void ) const
  { return database.at( index ).getName(); }
  string Addr( void ) const
  { return database.at( index ).getAddy(); }
  string Account( void ) const
  { return database.at( index ).getID(); }

};

class CTaxRegister
{

private:

  // container that stores records ordered by "ID"
  vector<Person> idDB;

  // container that stores records lexographically ordered by "name" then "address"
  vector<Person> nameDB;

  // higher-order comparator function used for binary insertion sort by "ID"
  static bool compareid( const Person & r , const Person & l )
  { return ( r.getID() < l.getID() ); }

  // higher-order comparator function used for binary insertion sort by "name" and "address"
  static bool comparename( const Person & r , const Person & l )
  {
    if( r.getName() != l.getName() )
    { return( r.getName() < l.getName() ); }
    else
    { return( r.getAddy() < l.getAddy() ); }
  }

public:

  // Constructor creates a new empty instance of a database
  CTaxRegister(){};

  // "Binary Insertion Sort" into the database
  bool Birth( const string & name , const string & addr , const string & account )
  {
    // constructs an instance of a record from the given parameters
    Person x( name , addr , account );

    // "lower bound" function uses a binary search implementation with the custom comparator functions,
    // given the constructed object to compare against Person(x) it returns an iterator to the position
    // where the next element is the smallest greater instance
    auto IDit = lower_bound( idDB.begin() , idDB.end() , x , compareid );
    auto NAMEit = lower_bound( nameDB.begin() , nameDB.end() , x , comparename );

    // if the name or id iterator found a position ; as in it didnt reach the "end" of the containers and the "id" OR "name" & "address"
    // of the pointed to instance are the same as the one to be inserted ; then it can't be inserted to maintain uniqueness in the database
    if( (IDit != idDB.end() && IDit->getID() == x.getID()) || (NAMEit != nameDB.end() && NAMEit->getName() == x.getName() && NAMEit->getAddy() == x.getAddy()) )
    { return false; }
    else
    {
      // else we insert the instance into both containers at the iterator positions
      idDB.insert( IDit , x );
      nameDB.insert( NAMEit , x );
      return true;
    }
  }

  // Erases a record from the database identified by its "name" and "address"
  bool Death( const string & name , const string & addr )
  {
    // construct a "dummy" instance to use in binary search by "name" & "address"
    Person x( name , addr );
    auto NAMEit = lower_bound( nameDB.begin() , nameDB.end() , x , comparename );

    // if the search found the position and the name and address matched
    if( NAMEit != nameDB.end() && NAMEit->getName() == x.getName() && NAMEit->getAddy() == x.getAddy() )
    {
      // construct a "dummy" instance with the "ID" of the found record
      Person x( name , addr , NAMEit->getID() );
      auto IDit = lower_bound( idDB.begin() , idDB.end() , x , compareid );

      // erase instances from both containers at the found iterator positions
      idDB.erase( IDit );
      nameDB.erase( NAMEit );
      return true;
    }
    else
    { return false; }
  }

  // updates the "income" of a record in the database identified by its "ID"
  bool Income( const string & account , int amount )
  {
    // construct a "dummy" instance to use in binary search by "ID"
    Person x( account );
    auto IDit = lower_bound( idDB.begin() , idDB.end() , x , compareid );

    // if the search found the position and the ID matched
    if( IDit != idDB.end() && IDit->getID() == x.getID() )
    {
      // increment the income by the given amount in the id container
      IDit->addIncome( amount );
      string name = IDit->getName();
      string addy = IDit->getAddy();

      // construct a "dummy" instance with the "name" & "address" of the found record
      Person x( name , addy );
      auto NAMEit = lower_bound( nameDB.begin() , nameDB.end() , x , comparename );

      // check if the search found the position and the name & address matched
      // increment the income by the givent amount in the nameid container
      if( NAMEit != nameDB.end() && NAMEit->getName() == x.getName() && NAMEit->getAddy() == x.getAddy() )
      { NAMEit->addIncome( amount ); }
      return true;
    }
    else
    { return false; }
  }

  // same implementation logic as the previous Income ^
  // the record is identified by its "name" and "address"
  bool Income( const string & name , const string & addr , int amount )
  {
    Person x( name , addr );
    auto NAMEit = lower_bound( nameDB.begin() , nameDB.end() , x , comparename );

    if( NAMEit != nameDB.end() && NAMEit->getName() == x.getName() && NAMEit->getAddy() == x.getAddy() )
    {
      NAMEit->addIncome( amount );
      string account = NAMEit->getID();

      Person x( account );
      auto IDit = lower_bound( idDB.begin() , idDB.end() , x , compareid );

      if( IDit != idDB.end() && IDit->getID() == x.getID() )
      { IDit->addIncome( amount ); }
      return true;
    }
    else
    { return false; }
  }

  // same as the Income but updates the "expense" field of a record
  bool Expense ( const string & account , int amount )
  {
    Person x( account );
    auto IDit = lower_bound( idDB.begin() , idDB.end() , x , compareid );

    if( IDit != idDB.end() && IDit->getID() == x.getID() )
    {
      IDit->addExpense( amount );
      string name = IDit->getName();
      string addy = IDit->getAddy();

      Person x( name , addy );
      auto NAMEit = lower_bound( nameDB.begin() , nameDB.end() , x , comparename );

      if( NAMEit != nameDB.end() && NAMEit->getName() == x.getName() && NAMEit->getAddy() == x.getAddy() )
      { NAMEit->addExpense( amount ); }
      return true;
    }
    else
    { return false; }
  }

  // same as the Income but updates the "expense" field of a record
  bool Expense( const string & name , const string & addr , int amount )
  {
    Person x( name , addr );
    auto NAMEit = lower_bound( nameDB.begin() , nameDB.end() , x , comparename );

    if( NAMEit != nameDB.end() && NAMEit->getName() == x.getName() && NAMEit->getAddy() == x.getAddy() )
    {
      NAMEit->addExpense( amount );
      string account = NAMEit->getID();

      Person x( account );
      auto IDit = lower_bound( idDB.begin() , idDB.end() , x , compareid );

      if( IDit != idDB.end() && IDit->getID() == x.getID() )
      { IDit->addExpense( amount ); }
      return true;
    }
    else
    { return false; }
  }

  // searches the database for a record identified by its "name" and "address" and returns the fields
  // "ID" , "income" and "expense" as output parameters
  bool Audit( const string & name , const string & addr , string & account , int & sumIncome , int & sumExpense ) const
  {
    // construct a "dummy" instance to use in binary search by "name" & "address"
    Person x( name , addr );
    auto NAMEit = lower_bound( nameDB.begin() , nameDB.end() , x , comparename );

    // if the search found the position and the name and address matched
    if( NAMEit != nameDB.end() && NAMEit->getName() == x.getName() && NAMEit->getAddy() == x.getAddy() )
    {
      // sets the output parameters to the found record's fields
      account = NAMEit->getID();
      sumIncome = NAMEit->getIncome();
      sumExpense = NAMEit->getExpense();
      return true;
    }
    else
    { return false; }
  }

  // creates and RETURNs a CIterator instance of the current database
  CIterator ListByName ( void ) const
  {
    // constructs an instance of the CIterator class and passes the container lexographically sorted
    // by "name" & "address" aswell as the number of records in that container
    CIterator x( nameDB , nameDB.size() );
    return x;
  }
};



#ifndef __PROGTEST__
int main ( void )
{
  string acct;
  int    sumIncome, sumExpense;
  CTaxRegister b1;
  assert ( b1 . Birth ( "John Smith", "Oak Road 23", "123/456/789" ) );
  assert ( b1 . Birth ( "Jane Hacker", "Main Street 17", "Xuj5#94" ) );
  assert ( b1 . Birth ( "Peter Hacker", "Main Street 17", "634oddT" ) );
  assert ( b1 . Birth ( "John Smith", "Main Street 17", "Z343rwZ" ) );
  assert ( b1 . Income ( "Xuj5#94", 1000 ) );
  assert ( b1 . Income ( "634oddT", 2000 ) );
  assert ( b1 . Income ( "123/456/789", 3000 ) );
  assert ( b1 . Income ( "634oddT", 4000 ) );
  assert ( b1 . Income ( "Peter Hacker", "Main Street 17", 2000 ) );
  assert ( b1 . Expense ( "Jane Hacker", "Main Street 17", 2000 ) );
  assert ( b1 . Expense ( "John Smith", "Main Street 17", 500 ) );
  assert ( b1 . Expense ( "Jane Hacker", "Main Street 17", 1000 ) );
  assert ( b1 . Expense ( "Xuj5#94", 1300 ) );
  assert ( b1 . Audit ( "John Smith", "Oak Road 23", acct, sumIncome, sumExpense ) );
  assert ( acct == "123/456/789" );
  assert ( sumIncome == 3000 );
  assert ( sumExpense == 0 );
  assert ( b1 . Audit ( "Jane Hacker", "Main Street 17", acct, sumIncome, sumExpense ) );
  assert ( acct == "Xuj5#94" );
  assert ( sumIncome == 1000 );
  assert ( sumExpense == 4300 );
  assert ( b1 . Audit ( "Peter Hacker", "Main Street 17", acct, sumIncome, sumExpense ) );
  assert ( acct == "634oddT" );
  assert ( sumIncome == 8000 );
  assert ( sumExpense == 0 );
  assert ( b1 . Audit ( "John Smith", "Main Street 17", acct, sumIncome, sumExpense ) );
  assert ( acct == "Z343rwZ" );
  assert ( sumIncome == 0 );
  assert ( sumExpense == 500 );
  CIterator it = b1 . ListByName ();
  assert ( ! it . AtEnd ()
           && it . Name () == "Jane Hacker"
           && it . Addr () == "Main Street 17"
           && it . Account () == "Xuj5#94" );
  it . Next ();
  assert ( ! it . AtEnd ()
           && it . Name () == "John Smith"
           && it . Addr () == "Main Street 17"
           && it . Account () == "Z343rwZ" );
  it . Next ();
  assert ( ! it . AtEnd ()
           && it . Name () == "John Smith"
           && it . Addr () == "Oak Road 23"
           && it . Account () == "123/456/789" );
  it . Next ();
  assert ( ! it . AtEnd ()
           && it . Name () == "Peter Hacker"
           && it . Addr () == "Main Street 17"
           && it . Account () == "634oddT" );
  it . Next ();
  assert ( it . AtEnd () );

  assert ( b1 . Death ( "John Smith", "Main Street 17" ) );

  CTaxRegister b2;
  assert ( b2 . Birth ( "John Smith", "Oak Road 23", "123/456/789" ) );
  assert ( b2 . Birth ( "Jane Hacker", "Main Street 17", "Xuj5#94" ) );
  assert ( !b2 . Income ( "634oddT", 4000 ) );
  assert ( !b2 . Expense ( "John Smith", "Main Street 18", 500 ) );
  assert ( !b2 . Audit ( "John Nowak", "Second Street 23", acct, sumIncome, sumExpense ) );
  assert ( !b2 . Death ( "Peter Nowak", "5-th Avenue" ) );
  assert ( !b2 . Birth ( "Jane Hacker", "Main Street 17", "4et689A" ) );
  assert ( !b2 . Birth ( "Joe Hacker", "Elm Street 23", "Xuj5#94" ) );
  assert ( b2 . Death ( "Jane Hacker", "Main Street 17" ) );
  assert ( b2 . Birth ( "Joe Hacker", "Elm Street 23", "Xuj5#94" ) );
  assert ( b2 . Audit ( "Joe Hacker", "Elm Street 23", acct, sumIncome, sumExpense ) );
  assert ( acct == "Xuj5#94" );
  assert ( sumIncome == 0 );
  assert ( sumExpense == 0 );
  assert ( !b2 . Birth ( "Joe Hacker", "Elm Street 23", "AAj5#94" ) );

  return 0;
}
#endif /* __PROGTEST__ */
