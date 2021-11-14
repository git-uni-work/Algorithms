#ifndef __PROGTEST__
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>

#if defined ( __cplusplus ) && __cplusplus > 199711L /* C++ 11 */
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <functional>
#endif /* C++ 11 */

using namespace std;
#endif /* __PROGTEST__ */

class NoRouteException
{
};

template <typename _T, typename _E>
class CRoute
{

private:

    map < const _T , vector < pair <_T,_E> > > m;

  public:

    //constructor & destructor
    CRoute <_T,_E> () = default;
    ~CRoute <_T,_E> () = default;

    //ADD
    CRoute & Add ( const _T & start , const _T & end , const _E & train )
    {
        m[start].emplace_back(end,train);
        m[end].emplace_back(start,train);
        return *this;
    }

     /*void printmap ()
     {
        for ( auto i : m )
        {
            for ( auto x : i.second )
            {
                cout << i.first <<  " -> " << x.first << " : ";
                cout << x.second.m_Company << " "<< x.second.m_Speed << endl;
            }
            cout << "----------" << endl;
        }
     }*/

     static bool alwaystrue(const _E &)
     { return true; }

    //FIND
    const list < _T > Find ( const _T & start , const _T & end ) const
    { return Find(start,end,alwaystrue); }

    template <typename _F>
    const list < _T > Find ( const _T & start , const _T & end , const _F & filter) const
    {
        list < _T > final;

        if (start == end)
        {
            final.push_back(start);
            return final;
        }

        auto check1 = m.find(start);
        auto check2 = m.find(end);
        if (check1 == m.end() || check2 == m.end())
        { throw NoRouteException(); }

        queue < _T > q;
        map < _T , pair < int , char > > x;
        map < int , _T > tmp;

        //BFS
        q.push(start);
        x.insert( { start , make_pair(0, 'O') } );
        for (const auto & i : m.at(start) )
        { x.insert( { i.first , make_pair(0, 'X') } ); }

//        for ( auto a : x )
//        {cout << a.first << " " << a.second.first << " " << a.second.second << endl;}
//        cout << "---------" << endl;

        int flag = 0;
        while ( !q.empty() )
        {
            _T current = q.front();
            q.pop();

            int level = x.at(current).first;
            for ( const auto & i : m.at(current) )
            {
                if ( i.first != start && x[i.first].second != '!' && x[i.first].first == 0 )
                {
                    x.at(i.first) = make_pair(0, 'X');
                }

                if ( i.first != end && x[i.first].second == 'X' && filter(i.second) )
                {
                    x.at(i.first) = make_pair(level + 1, 'O');
                    q.push(i.first);
                }
                if ( i.first == end )
                {
                    x.at(i.first) = make_pair(level + 1, '!');
//                    cout << "!!! FOUND !!!" << endl;
                    flag = 1;
                    break;
                }

//                cout << "x---------x" << endl;
//                for ( auto a : x )
//                {cout << a.first << " -> " << a.second.first << " - " << a.second.second << endl;}
//                cout << "x---------x" << endl;

            }
            x.at(current).second = '!';
            if ( flag ) break;

//            cout << "+---------+" << endl;
//            for ( auto a : x )
//            {cout << a.first << " -> " << a.second.first << " - " << a.second.second << endl;}
//            cout << "+---------+" << endl;

        }
        if (!flag)
        { throw NoRouteException(); }

        tmp[0] = start;
      //  tmp.insert( {0 , start} );
        tmp[x.at(end).first] = end;
       // insert( {x.at(end).first , end} );

        for ( int b = x.at(end).first - 1 ; b >= 1 ; --b )
        {
            for ( const auto & i : m.at(tmp[b+1]) )
            {
                for ( const auto & a : x )
                {
                    if ( a.first == i.first && a.second.second == '!' )
                    {
                        tmp[a.second.first] = a.first;
                       // tmp.insert( {a.second.first , a.first} );
                    }
                }
            }
        }

        for ( const auto & i : tmp )
        { final.push_back(i.second); }

       /*cout << "==========" << endl;
       auto it = final.begin();
       cout << *it;
       for ( ++it ; it != final.end() ; ++it )
       {cout << " > " << *it;}
       cout << endl << "==========" << endl;*/

        while(!q.empty())
        { q.pop(); }

       return final;
   }

};

template <typename _T>
class node {
    string t;
public:
    node (const _T & src)
    {t = src.t;}
    node & operator = (node src)
    {
        swap (this->t , src.t);
        return * this;
    }
    bool operator == (const _T & rhs) const
    {return t == rhs.t;}
    bool operator != (const _T & rhs) const
    {return! (rhs == * this);}
    bool operator <(const _T & rhs) const
    {return t <rhs.t;}
    bool operator > (const _T & rhs) const
    {return rhs <* this;}
    bool operator <= (const _T & rhs) const
    {return! (rhs <* this);}
    bool operator >= (const _T & rhs) const
    {return !(* this <rhs);}
    friend ostream & operator << (ostream & os, const _T & test)
    {
        os << test.t;
        return os;
    }
};
template <typename _E>
class edge {
    string test;
public:
    edge (const _E & Test)
    {this->test = Test.test;}
    edge & operator = (_E src)
    {
        swap (this-> test, src.test);
        return *this;
    }
};

#ifndef __PROGTEST__
//=================================================================================================
class CTrain
{
public:
    CTrain ( const string & company , int speed ) : m_Company ( company ) , m_Speed ( speed ) {}
    //---------------------------------------------------------------------------------------------
    string m_Company;
    int m_Speed;
};
//=================================================================================================
class TrainFilterCompany
{
public:
    TrainFilterCompany ( const set < string > & companies ) : m_Companies ( companies ) {}
    //---------------------------------------------------------------------------------------------
    bool operator () ( const CTrain & train ) const
    {return m_Companies.find ( train.m_Company ) != m_Companies.end ();}
    //---------------------------------------------------------------------------------------------
private:
    set < string > m_Companies;
};
//=================================================================================================
class TrainFilterSpeed
{
public:
    TrainFilterSpeed ( int min , int max ) : m_Min ( min ) , m_Max ( max ) {}
    //---------------------------------------------------------------------------------------------
    bool operator () ( const CTrain & train ) const
    {return train.m_Speed >= m_Min && train.m_Speed <= m_Max;}
    //---------------------------------------------------------------------------------------------
private:
    int m_Min;
    int m_Max;
};
//=================================================================================================
bool NurSchnellzug ( const CTrain & zug )
{return ( zug.m_Company == "OBB" || zug.m_Company == "DB" ) && zug.m_Speed > 100;}
//=================================================================================================
static string toText ( const list<string> & l )
{
  ostringstream oss;
  auto it = l.cbegin();
  oss << *it;
  for ( ++it ; it != l.cend () ; ++it )
    oss << " > " << *it;
  return oss . str ();
}
//=================================================================================================

int main ( void )
{
  CRoute<string,CTrain> lines;
  
  lines . Add ( "Berlin", "Prague", CTrain ( "DB", 120 ) )
        . Add ( "Berlin", "Prague", CTrain ( "CD",  80 ) )
        . Add ( "Berlin", "Dresden", CTrain ( "DB", 160 ) )
        . Add ( "Dresden", "Munchen", CTrain ( "DB", 160 ) )
        . Add ( "Munchen", "Prague", CTrain ( "CD",  90 ) )
        . Add ( "Munchen", "Linz", CTrain ( "DB", 200 ) )
        . Add ( "Munchen", "Linz", CTrain ( "OBB", 90 ) )
        . Add ( "Linz", "Prague", CTrain ( "CD", 50 ) )
        . Add ( "Prague", "Wien", CTrain ( "CD", 100 ) )
        . Add ( "Linz", "Wien", CTrain ( "OBB", 160 ) )
        . Add ( "Paris", "Marseille", CTrain ( "SNCF", 300 ))
        . Add ( "Paris", "Dresden",  CTrain ( "SNCF", 250 ) );

//  lines.printmap();

    list<string> r1 = lines . Find ( "Berlin", "Linz" );
//  toText(r1);
  assert ( toText ( r1 ) == "Berlin > Prague > Linz" );

  list<string> r2 = lines . Find ( "Linz", "Berlin" );
//  cout << endl << "==========" << endl;
//  toText(r2);
  assert ( toText ( r2 ) == "Linz > Prague > Berlin" );

  list<string> r3 = lines . Find ( "Wien", "Berlin" );
//    cout << endl << "==========" << endl;
//    toText(r3);
  assert ( toText ( r3 ) == "Wien > Prague > Berlin" );

  list<string> r4 = lines . Find ( "Wien", "Berlin", NurSchnellzug );
//    cout << endl << "==========" << endl;
//    toText(r4);
  assert ( toText ( r4 ) == "Wien > Linz > Munchen > Dresden > Berlin" );

  list<string> r5 = lines . Find ( "Wien", "Munchen", TrainFilterCompany ( set<string> { "CD", "DB" } ) );
//    cout << endl << "==========" << endl;
//    toText(r5);
  assert ( toText ( r5 ) == "Wien > Prague > Munchen" );

  list<string> r6 = lines . Find ( "Wien", "Munchen", TrainFilterSpeed ( 120, 200 ) );
//    cout << endl << "==========" << endl;
//    toText(r6);
  assert ( toText ( r6 ) == "Wien > Linz > Munchen" );

  list<string> r7 = lines . Find ( "Wien", "Munchen", [] ( const CTrain & x ) { return x . m_Company == "CD"; } );
//    cout << endl << "==========" << endl;
//    toText(r7);
  assert ( toText ( r7 ) == "Wien > Prague > Munchen" );

  list<string> r8 = lines . Find ( "Munchen", "Munchen" );
//  cout << endl << "==========" << endl;
//  toText(r8);
  assert ( toText ( r8 ) == "Munchen" );

  list<string> r9 = lines . Find ( "Marseille", "Prague" );
//  cout << endl << "==========" << endl;
//  toText(r9);
  assert ( toText ( r9 ) == "Marseille > Paris > Dresden > Berlin > Prague"
           || toText ( r9 ) == "Marseille > Paris > Dresden > Munchen > Prague" );

  try
  {
    list<string> r10 = lines . Find ( "Marseille", "Prague", NurSchnellzug );
    assert ( "Marseille > Prague connection does not exist!!" == NULL );
  }
  catch ( const NoRouteException & e )
  {
  }

  list<string> r11 = lines . Find ( "Salzburg", "Salzburg" );
//  cout << endl << "==========" << endl;
//  toText(r11);
  assert ( toText ( r11 ) == "Salzburg" );

  list<string> r12 = lines . Find ( "Salzburg", "Salzburg", [] ( const CTrain & x ) { return x . m_Company == "SNCF"; }  );
//    cout << endl << "==========" << endl;
//    toText(r12);
  assert ( toText ( r12 ) == "Salzburg" );

  try
  {
    list<string> r13 = lines . Find ( "London", "Oxford" );
    assert ( "London > Oxford connection does not exist!!" == NULL );
  }
  catch ( const NoRouteException & e )
  {
  }

  return 0;
}
#endif  /* __PROGTEST__ */
