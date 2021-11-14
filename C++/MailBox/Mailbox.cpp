#ifndef __PROGTEST__
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>
#include <stdexcept>
#endif /* __PROGTEST */
using namespace std;

#ifndef __PROGTEST__
class CTimeStamp
{
private:
  int y,m,d,h,min,s;

  public:
    // CTimeStamp(){};
    CTimeStamp( int year , int month , int day , int hour , int minute , int sec )
    {
      y = year;
      m = month;
      d = day;
      h = hour;
      min = minute;
      s = sec;
    }

    int Compare( const CTimeStamp & x ) const
    {
      long double t1 = 0;
      long double t2 = 0;
      t1 += ( y * 365 * 24 * 60 * 60 ) + ( m * 30 * 24 * 60 * 60 ) + ( d * 24 * 60 * 60 ) + ( h * 60 * 60 ) + ( min * 60 ) + s;
      t2 += ( x.y * 365 * 24 * 60 * 60 ) + ( x.m * 30 * 24 * 60 * 60 ) + ( x.d * 24 * 60 * 60 ) + ( x.h * 60 * 60 ) + ( x.min * 60 ) + x.s;
      if ( t1 > t2 )
      {return 100;}
      else if ( t2 > t1 )
      {return -100;}
      else
      {return 0;}
    }

    friend ostream & operator <<( ostream & os , const CTimeStamp & x )
    {
      os << x.y << "-" << setfill('0') << setw(2) << x.m << "-" << setfill('0') << setw(2) << x.d << " ";
      os << setfill('0') << setw(2) << x.h << ":" << setfill('0') << setw(2) << x.min << ":" << fixed << setprecision(2) << x.s;
      return os;
    }
};
//=================================================================================================
class CMailBody
{
private:
  int m_Size;
  char * m_Data;

  public:
    // CMailBody(){};
    CMailBody( int size , const char * data )
    { m_Size = size; }

    // copy cons/op=/destructor is correctly implemented in the testing environment

    friend ostream & operator <<( ostream & os , const CMailBody & x )
    { return os << "mail body: " << x.m_Size << " B"; }
};
//=================================================================================================
class CAttach
{
public:
  CAttach( int x ) : m_X (x) , m_RefCnt ( 1 ){}

  void AddRef( void ) const
  { m_RefCnt++; }

  void Release( void ) const
  {return;}

  friend ostream & operator <<( ostream & os , const CAttach & x )
  { return os << "attachment: " << x.m_X << " B"; }

private:
  int m_X;
  mutable int m_RefCnt;

  CAttach( const CAttach & x ) : m_X(x.m_X) , m_RefCnt(x.m_RefCnt){};

  CAttach & operator = ( const CAttach & x )
  { this->m_X = x.m_X; this->m_RefCnt = x.m_RefCnt; return *this; }
  ~CAttach( void ) = default;
};
//=================================================================================================
#endif /* __PROGTEST__, DO NOT remove */


class CMail
{
private:
  CTimeStamp time;
  string addy;
  CMailBody mail;
  const CAttach * attachment;

public:
    CMail( const CTimeStamp & timeStamp , const string & from , const CMailBody & body , const CAttach * attach )
    : time(timeStamp), addy(from), mail(body), attachment(attach){};

    const string & From( void ) const
    { return addy; }
    const CMailBody & Body( void ) const
    { return mail; }
    const CTimeStamp & TimeStamp( void ) const
    { return time; }
    const CAttach * Attachment( void ) const
    { return attachment; }

    int CompareByTime ( const CTimeStamp & x ) const
    {
        int cmpresult = this->TimeStamp().Compare(x);
        return cmpresult;
    }
    int CompareByTime ( const CMail & x ) const
    {
        int cmpresult = this->TimeStamp().Compare(x.TimeStamp());
        return cmpresult;
    }

    friend ostream & operator <<( ostream & os , const CMail & x )
    {
      os << x.time;
      os << " " << x.addy << " " << x.mail;
      if( x.attachment != NULL )
      { os << " + " << *x.attachment; }
      return os;
    }
};

//=================================================================================================
class timecompare
{
public:
    bool operator () (const CTimeStamp & r, const CTimeStamp & l) const
    {
      int result = r.Compare(l);
      return (result < 0);
    }
};
class compareting
{
public:
    bool operator () (const pair<string,CTimeStamp> & r, const pair<string,CTimeStamp> & l) const
    {
      int result = r.second.Compare(l.second);
      return (result < 0);
    }
};

class CMailBox
{
private:
  multimap<pair<string,class CTimeStamp>,class CMail,compareting> mailbox;
  map<class CTimeStamp,string,timecompare> ye;
  int year = 1999;

public:
    CMailBox( void )
    {
      CMail x( CTimeStamp(0,0,0,0,0,0),"",CMailBody (0,""), nullptr );
      mailbox.insert({make_pair("inbox",x.TimeStamp()),x});
      ye.insert(make_pair(x.TimeStamp(),"inbox"));
    }

    static bool comparetime( const CMail & first, const CMail & second )
    { return first.CompareByTime(second) < 0; }

    bool Delivery( const CMail & mail )
    {
      auto lower = mailbox.lower_bound(make_pair("inbox",CTimeStamp(0,0,0,0,0,0)));
      mailbox.emplace_hint(lower,make_pair("inbox",mail.TimeStamp()),mail);
      ye.insert(make_pair(mail.TimeStamp(),"inbox"));
      return true;
    }

    bool NewFolder( const string & folderName )
    {
      for(auto i : ye)
      {
        if( i.second == folderName )
        { return false; }
      }
      CMail x( CTimeStamp(year,year,year,year,year,year),"",CMailBody (0,""), nullptr );
      mailbox.insert({make_pair(folderName,x.TimeStamp()),x});
      ye.insert(make_pair(x.TimeStamp(),folderName));
      year++;
      return true;
    }

    bool MoveMail( const string & fromFolder , const string & toFolder )
    {
      for(auto i : ye)
      {
        if( i.second == fromFolder )
        {
          auto x = mailbox.find(make_pair(fromFolder,i.first));
          if( x->second.From() == "" )
          { continue; }
          mailbox.insert({make_pair(toFolder,x->second.TimeStamp()),move(x->second)});
          ye[move(x->second).TimeStamp()] = toFolder;
          mailbox.erase(x);
        }
      }
      CMail x( CTimeStamp(0,0,0,0,0,0),"",CMailBody (0,""), nullptr );
      mailbox.insert({make_pair(fromFolder,x.TimeStamp()),x});
      return true;
    }

    list<CMail> ListMail( const string & folderName , const CTimeStamp & from , const CTimeStamp & to ) const
    {
      list<CMail> emails;
      list<CMail>::iterator pos = emails.begin();

      auto range1 = ye.equal_range(from);
      auto range2 = ye.equal_range(to);
      for(auto i = range1.first ; i != range2.second ; i++ )
      {
        if( i->second == folderName )
        {
          auto m = mailbox.find(make_pair(folderName,i->first));
          if( m->second.From() == "" )
          { continue; }
          emails.emplace(pos,m->second);
        }
      }

      // for(auto & i : emails)
      // {cout << i << endl;}
      // cout << "=====" << endl;
      return emails;
    }

    set<string> ListAddr( const CTimeStamp & from , const CTimeStamp & to ) const
    {
      set<string> users;
      set<string>::iterator pos = users.begin();

      auto range1 = ye.equal_range(from);
      auto range2 = ye.equal_range(to);
      for(auto i = range1.first ; i != range2.second ; i++ )
      {
        auto m = mailbox.find(make_pair(i->second,i->first));
        if( m->second.From() == "" )
        { continue; }
        users.insert(pos,m->second.From());
      }

      // for(auto & i : users)
      // {cout << i << endl;}
      // cout << "=====" << endl;
      return users;
    }
};

//=================================================================================================
#ifndef __PROGTEST__

static string showMail ( const list<CMail> & l )
{
  ostringstream oss;
  for ( const auto & x : l )
    oss << x << endl;
  return oss . str ();
}

static string showUsers ( const set<string> & s )
{
  ostringstream oss;
  for ( const auto & x : s )
    oss << x << endl;
  return oss . str ();
}

int main ( void )
{
  list<CMail> mailList;
  set<string> users;
  CAttach   * att;

  CMailBox m0;
  assert ( m0 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 15, 24, 13 ), "user1@fit.cvut.cz", CMailBody ( 14, "mail content 1" ), nullptr ) ) );
  assert ( m0 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 15, 26, 23 ), "user2@fit.cvut.cz", CMailBody ( 22, "some different content" ), nullptr ) ) );
  att = new CAttach ( 200 );
  assert ( m0 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 11, 23, 43 ), "boss1@fit.cvut.cz", CMailBody ( 14, "urgent message" ), att ) ) );
  assert ( m0 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 18, 52, 27 ), "user1@fit.cvut.cz", CMailBody ( 14, "mail content 2" ), att ) ) );
  att -> Release ();
  att = new CAttach ( 97 );
  assert ( m0 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 16, 12, 48 ), "boss1@fit.cvut.cz", CMailBody ( 24, "even more urgent message" ), att ) ) );
  att -> Release ();
  assert ( showMail ( m0 . ListMail ( "inbox",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "2014-03-31 11:23:43 boss1@fit.cvut.cz mail body: 14 B + attachment: 200 B\n"
                        "2014-03-31 15:24:13 user1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 15:26:23 user2@fit.cvut.cz mail body: 22 B\n"
                        "2014-03-31 16:12:48 boss1@fit.cvut.cz mail body: 24 B + attachment: 97 B\n"
                        "2014-03-31 18:52:27 user1@fit.cvut.cz mail body: 14 B + attachment: 200 B\n" );
  assert ( showMail ( m0 . ListMail ( "inbox",
                      CTimeStamp ( 2014, 3, 31, 15, 26, 23 ),
                      CTimeStamp ( 2014, 3, 31, 16, 12, 48 ) ) ) == "2014-03-31 15:26:23 user2@fit.cvut.cz mail body: 22 B\n"
                        "2014-03-31 16:12:48 boss1@fit.cvut.cz mail body: 24 B + attachment: 97 B\n" );
  assert ( showUsers ( m0 . ListAddr ( CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                       CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "boss1@fit.cvut.cz\n"
                        "user1@fit.cvut.cz\n"
                        "user2@fit.cvut.cz\n" );
  assert ( showUsers ( m0 . ListAddr ( CTimeStamp ( 2014, 3, 31, 15, 26, 23 ),
                       CTimeStamp ( 2014, 3, 31, 16, 12, 48 ) ) ) == "boss1@fit.cvut.cz\n"
                        "user2@fit.cvut.cz\n" );

  CMailBox m1;
  assert ( m1 . NewFolder ( "work" ) );
  assert ( m1 . NewFolder ( "spam" ) );
  assert ( !m1 . NewFolder ( "spam" ) );
  assert ( m1 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 15, 24, 13 ), "user1@fit.cvut.cz", CMailBody ( 14, "mail content 1" ), nullptr ) ) );
  att = new CAttach ( 500 );
  assert ( m1 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 15, 26, 23 ), "user2@fit.cvut.cz", CMailBody ( 22, "some different content" ), att ) ) );
  att -> Release ();
  assert ( m1 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 11, 23, 43 ), "boss1@fit.cvut.cz", CMailBody ( 14, "urgent message" ), nullptr ) ) );
  att = new CAttach ( 468 );
  assert ( m1 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 18, 52, 27 ), "user1@fit.cvut.cz", CMailBody ( 14, "mail content 2" ), att ) ) );
  att -> Release ();
  assert ( m1 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 16, 12, 48 ), "boss1@fit.cvut.cz", CMailBody ( 24, "even more urgent message" ), nullptr ) ) );
  assert ( showMail ( m1 . ListMail ( "inbox",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "2014-03-31 11:23:43 boss1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 15:24:13 user1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 15:26:23 user2@fit.cvut.cz mail body: 22 B + attachment: 500 B\n"
                        "2014-03-31 16:12:48 boss1@fit.cvut.cz mail body: 24 B\n"
                        "2014-03-31 18:52:27 user1@fit.cvut.cz mail body: 14 B + attachment: 468 B\n" );
  assert ( showMail ( m1 . ListMail ( "work",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "" );
  assert ( m1 . MoveMail ( "inbox", "work" ) );
  assert ( showMail ( m1 . ListMail ( "inbox",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "" );
  assert ( showMail ( m1 . ListMail ( "work",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "2014-03-31 11:23:43 boss1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 15:24:13 user1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 15:26:23 user2@fit.cvut.cz mail body: 22 B + attachment: 500 B\n"
                        "2014-03-31 16:12:48 boss1@fit.cvut.cz mail body: 24 B\n"
                        "2014-03-31 18:52:27 user1@fit.cvut.cz mail body: 14 B + attachment: 468 B\n" );
  assert ( m1 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 19, 24, 13 ), "user2@fit.cvut.cz", CMailBody ( 14, "mail content 4" ), nullptr ) ) );
  att = new CAttach ( 234 );
  assert ( m1 . Delivery ( CMail ( CTimeStamp ( 2014, 3, 31, 13, 26, 23 ), "user3@fit.cvut.cz", CMailBody ( 9, "complains" ), att ) ) );
  att -> Release ();
  assert ( showMail ( m1 . ListMail ( "inbox",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "2014-03-31 13:26:23 user3@fit.cvut.cz mail body: 9 B + attachment: 234 B\n"
                        "2014-03-31 19:24:13 user2@fit.cvut.cz mail body: 14 B\n" );
  assert ( showMail ( m1 . ListMail ( "work",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "2014-03-31 11:23:43 boss1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 15:24:13 user1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 15:26:23 user2@fit.cvut.cz mail body: 22 B + attachment: 500 B\n"
                        "2014-03-31 16:12:48 boss1@fit.cvut.cz mail body: 24 B\n"
                        "2014-03-31 18:52:27 user1@fit.cvut.cz mail body: 14 B + attachment: 468 B\n" );
  assert ( m1 . MoveMail ( "inbox", "work" ) );
  assert ( showMail ( m1 . ListMail ( "inbox",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "" );
  assert ( showMail ( m1 . ListMail ( "work",
                      CTimeStamp ( 2000, 1, 1, 0, 0, 0 ),
                      CTimeStamp ( 2050, 12, 31, 23, 59, 59 ) ) ) == "2014-03-31 11:23:43 boss1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 13:26:23 user3@fit.cvut.cz mail body: 9 B + attachment: 234 B\n"
                        "2014-03-31 15:24:13 user1@fit.cvut.cz mail body: 14 B\n"
                        "2014-03-31 15:26:23 user2@fit.cvut.cz mail body: 22 B + attachment: 500 B\n"
                        "2014-03-31 16:12:48 boss1@fit.cvut.cz mail body: 24 B\n"
                        "2014-03-31 18:52:27 user1@fit.cvut.cz mail body: 14 B + attachment: 468 B\n"
                        "2014-03-31 19:24:13 user2@fit.cvut.cz mail body: 14 B\n" );

  return 0;
}
#endif /* __PROGTEST__ */
