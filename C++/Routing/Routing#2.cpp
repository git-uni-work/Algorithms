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
public:
    NoRouteException() throw() {}
};

template <typename _T, typename _E>
class CRoute
{ 
    map <_T, vector<pair<_T, _E> > > cities;
public:
   // default constructor
   // destructor
    CRoute & Add (const _T & node1, const _T & node2, const _E & edge)
    {
        cities[node1].emplace_back(node2, edge);
        cities[node2].emplace_back(node1, edge);
        return *this;
    }
    static bool Default_func(const _E &)    { return true; }
    
    const list<_T> Find (const _T & u, const _T & v) const
    {
        return Find(u, v, Default_func);
    }

    template <typename _F>
    const list<_T> Find (const _T & u, const _T & v , const _F & filter) const
    {
        list <_T> path;
        if (u == v){
            path.push_back(u);
            return path;
        }
        if (cities.find(v) == cities.end()){
            throw NoRouteException();
        }
        
        bool path_exists = false;
        int level = 0;
        queue<_T> Que;
        Que.push(u);
        set <_T> visited;
        map < _T, vector < pair <_T, int > > > subcities; 

        while (!Que.empty())
        {
            _T front = Que.front();
            vector < pair <_T, _E> > adj_vert = cities.at(front);
            visited.insert(front);
            Que.pop();
            for ( const auto & adjv : adj_vert)
            {
                if (visited.find( adjv.first) == visited.end() && filter(adjv.second))
                {
                    Que.push( adjv.first);
                    visited.insert( adjv.first);
                    // cout << "visiting: " << adjv.first << endl;
                    subcities[ adjv.first].push_back(make_pair(front, level));
                    if ( adjv.first == v){
                        // cout << "found you" << endl;
                        path_exists = true;
                        break;
                    }
                }    
            }
            if (path_exists)
                break;

            level++;
        }

        if (!path_exists){
            // cout <<" what is happening\n";
            throw NoRouteException();
        }
      
        int min_level = 9999999;
        _T node = v;
        path.push_back(v);
        while (1){
            vector < pair < _T, int > > neighbours = subcities[node];
            for ( const auto & neigh : neighbours)
            {
                if ( neigh.second < min_level){
                    min_level = neigh.second;
                    node = neigh.first;
                }
            }
            path.push_back(node);
            if (node == u){
                break;
            }
        }
        path.reverse();
        /*
        for (const auto & p : path){
            cout << p << " " ;
        }
        cout << endl;
        */
        return path;
    }

};

#ifndef __PROGTEST__
//=================================================================================================
class CTrain
{
public:
    CTrain ( const string & company, int speed ): m_Company ( company ), m_Speed ( speed ) {}
    //---------------------------------------------------------------------------------------------
    string m_Company;
    int    m_Speed; 
};
//=================================================================================================
class TrainFilterCompany
{
public:
    TrainFilterCompany ( const set<string> & companies ) : m_Companies ( companies ) {}
    //---------------------------------------------------------------------------------------------
    bool operator () ( const CTrain & train ) const
    { 
      return m_Companies . find ( train . m_Company ) != m_Companies . end (); 
    }
    //---------------------------------------------------------------------------------------------
  private:  
    set <string> m_Companies;    
};
//=================================================================================================
class TrainFilterSpeed
{
public:
    TrainFilterSpeed ( int min, int max ) : m_Min ( min ), m_Max ( max ) {}
    //---------------------------------------------------------------------------------------------
    bool operator () ( const CTrain & train ) const
    { 
      return train . m_Speed >= m_Min && train . m_Speed <= m_Max; 
    }
    //---------------------------------------------------------------------------------------------
  private:  
    int m_Min;
    int m_Max; 
};
//=================================================================================================
bool NurSchnellzug ( const CTrain & zug )
{
  return ( zug . m_Company == "OBB" || zug . m_Company == "DB" ) && zug . m_Speed > 100;
}
//=================================================================================================
static string toText ( const list<string> & l )
{
  ostringstream oss;
  
  auto it = l . cbegin();
  oss << *it;
  for ( ++it; it != l . cend (); ++it )
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
        
  list<string> r1 = lines . Find ( "Berlin", "Linz" );
  assert ( toText ( r1 ) == "Berlin > Prague > Linz" );
  
  list<string> r2 = lines . Find ( "Linz", "Berlin" );
  assert ( toText ( r2 ) == "Linz > Prague > Berlin" );

  list<string> r3 = lines . Find ( "Wien", "Berlin" );
  assert ( toText ( r3 ) == "Wien > Prague > Berlin" );

  list<string> r4 = lines . Find ( "Wien", "Berlin", NurSchnellzug );
  assert ( toText ( r4 ) == "Wien > Linz > Munchen > Dresden > Berlin" );

  list<string> r5 = lines . Find ( "Wien", "Munchen", TrainFilterCompany ( set<string> { "CD", "DB" } ) );
  assert ( toText ( r5 ) == "Wien > Prague > Munchen" );

  list<string> r6 = lines . Find ( "Wien", "Munchen", TrainFilterSpeed ( 120, 200 ) );
  assert ( toText ( r6 ) == "Wien > Linz > Munchen" );

  list<string> r7 = lines . Find ( "Wien", "Munchen", [] ( const CTrain & x ) { return x . m_Company == "CD"; } );
  assert ( toText ( r7 ) == "Wien > Prague > Munchen" );

    
  list<string> r8 = lines . Find ( "Munchen", "Munchen" );
  assert ( toText ( r8 ) == "Munchen" );
    
 

  list<string> r9 = lines . Find ( "Marseille", "Prague" );
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
  assert ( toText ( r11 ) == "Salzburg" );
  

  list<string> r12 = lines . Find ( "Salzburg", "Salzburg", [] ( const CTrain & x ) { return x . m_Company == "SNCF"; }  );
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

