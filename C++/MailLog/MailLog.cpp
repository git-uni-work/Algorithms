#ifndef __PROGTEST__
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <memory>
#include <functional>
using namespace std;


class CTimeStamp
{

private:

    int d,mon,y,h,min;
    double s;

public:

    CTimeStamp(){};
    CTimeStamp ( int year , int month , int day , int hour , int minute , double sec )
    {
        d = day;
        mon = month;
        y = year;
        h = hour;
        min = minute;
        s = sec;
    }

    int Compare ( const CTimeStamp & x ) const
    {
        long double t1 = 0;
        long double t2 = 0;
        t1 += ( y * 365 * 24 * 60 * 60 ) + ( mon * 30 * 24 * 60 * 60 ) + ( d * 24 * 60 * 60 ) + ( h * 60 * 60 ) + ( min * 60 ) + s;
        t2 += ( x.y * 365 * 24 * 60 * 60 ) + ( x.mon * 30 * 24 * 60 * 60 ) + ( x.d * 24 * 60 * 60 ) + ( x.h * 60 * 60 ) + ( x.min * 60 ) + x.s;
        if ( t1 > t2 )
        {return 100;}
        else if ( t2 > t1 )
        {return -100;}
        else
        {return 0;}
    }

    friend ostream & operator << ( ostream & os , const CTimeStamp & x )
    {
        os << x.y << "-" << setfill('0') << setw(2) << x.mon << "-" << setfill('0') << setw(2) << x.d << " ";
        os << setfill('0') << setw(2) << x.h << ":" << setfill('0') << setw(2) << x.min << ":" << fixed << setprecision(3) <<  x.s;
        return os;
    }

};

class CMail
{

private:

    CTimeStamp times;
    string emailfrom;
    string emailto;
    string emailsubject;

public:

    CMail ( const CTimeStamp & timeStamp , const string & from , const string & to , const string & subject )
    {
        times = timeStamp;
        emailfrom = from;
        emailto = to;
        emailsubject = subject;
    }

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

    const string & From ( void ) const
    {   return emailfrom;}

    const string & To ( void ) const
    {   return emailto;}

    const string & Subject ( void ) const
    {   return emailsubject;}

    const CTimeStamp & TimeStamp ( void ) const
    {   return times;}

    friend ostream & operator << ( ostream & os , const CMail & x )
    {
        string f , t , s;
        f = x.emailfrom;
        f.erase(0,6);
        t = x.emailto;
        t.erase(0,4);
        s = x.emailsubject;
        s[8] = ':';
        s.insert(9,1,' ');
        os << x.TimeStamp();
        os << " " << f << " -> " << t << "," << s;
        return os;
    }

};


// your code will be compiled in a separate namespace
namespace MysteriousNamespace {
#endif /* __PROGTEST__ */
//----------------------------------------------------------------------------------------

    class CMailLog {

    private:

        multimap<string, class CMail> log;

        struct emaildata
        {
            string id;
            int from = 0;
            int to = 0;
        };

        static bool comparetime( const CMail & first, const CMail & second )
        {
            return first.CompareByTime(second) < 0;
        }

    public:

        vector<emaildata> emailcount;
        char mon[4], server[100], ID[100], msg[1000], d[3], y[5], h[3], m[3], s[7];
        int day, month, year, hour, min;
        double sec;
        string relay, id, message;
        char space = ' ';
        char colon = ':';
        char nl = '\n';
        string to = "to=";
        string from = "from=";
        string subject = "subject=";
        string empty = "";

        CMailLog(){};
        ~CMailLog(){};

        int ParseLog ( istream & in )
        {
            int parsed = 0;

            while ( 1 )
            {
                if ( in.eof() )
                {break;}
                else
                {
                    in.getline(mon,4,space);
                    string mont(mon);
                    if ( mont == "Jan" ) { month = 1;}
                    if ( mont == "Feb" ) { month = 2;}
                    if ( mont == "Mar" ) { month = 3;}
                    if ( mont == "Apr" ) { month = 4;}
                    if ( mont == "May" ) { month = 5;}
                    if ( mont == "Jun" ) { month = 6;}
                    if ( mont == "Jul" ) { month = 7;}
                    if ( mont == "Aug" ) { month = 8;}
                    if ( mont == "Sep" ) { month = 9;}
                    if ( mont == "Oct" ) { month = 10;}
                    if ( mont == "Nov" ) { month = 11;}
                    if ( mont == "Dec" ) { month = 12;}
                    if ( in.eof() )
                    {break;}
                    in.getline(d,3,space);
                    day = atoi(d);
                    in.getline(y,5,space);
                    year = atoi(y);
                    in.getline(h,3,colon);
                    hour = atoi(h);
                    in.getline(m,3,colon);
                    min = atoi(m);
                    in.getline(s,7,space);
                    sec = stod(s);
                    in.getline(server,100,space);
                    relay = server;
                    in.getline(ID,100,colon);
                    id = ID;
                    in.getline(msg,1000,nl);
                    message = msg;

                    if ( message.find(from) != std::string::npos )
                    {
                        CTimeStamp time ( year , month , day , hour , min , sec );
                        CMail email ( time , message , empty , empty );
                        log.insert({id,email});
                    }
                    else if ( message.find(to) != std::string::npos )
                    {
                        CTimeStamp time ( year , month , day , hour , min , sec );
                        CMail email ( time , empty , message , empty );
                        log.insert({id,email});
                        parsed++;
                    }
                    else if ( message.find(subject) != std::string::npos )
                    {
                        CTimeStamp time ( year , month , day , hour , min , sec );
                        CMail email ( time , empty , empty , message );
                        log.insert({id,email});
                    }

                    /*cout << "-------------------" << endl;
                    cout << day << "/" << month << "/" << year << " - ";
                    cout << hour << ":" << min << ":" << setfill('0') << setw(6) << left << sec << endl;
                    cout << "RELAY = " << relay << endl;
                    cout << "ID = " << id << endl;
                    cout << "MSG = " << message << endl;
                    cout << "-------------------";*/

                }
            }

            multimap < string , class CMail >::iterator i;
            for ( i = log.begin() ; i != log.end() ; i++ )
            {
                bool flag = false;
                vector<emaildata>::iterator m;
                for ( m = emailcount.begin() ; m  != emailcount.end() ; m++ )
                {
                    if ( i->first == m->id )
                    {
                        if ( i->second.From().find(from) != std::string::npos )
                        { m->from++;}
                        else if ( i->second.To().find(to) != std::string::npos )
                        { m->to++;}
                        flag = true;
                        break;
                    }
                }
                if ( !flag )
                {
                    emaildata x;
                    x.id = i->first;
                    if ( i->second.From().find(from) != std::string::npos )
                    { x.from++;}
                    else if ( i->second.To().find(to) != std::string::npos )
                    { x.to++;}
                    emailcount.push_back(x);
                }
            }

            vector<emaildata>::iterator e;
            for ( e = emailcount.begin() ; e  != emailcount.end() ; e++ )
            {
                if ( e->to < 1 || e->from < 1 )
                {
                    log.erase(e->id);
                    emailcount.erase(e);
                }
//            cout << "ID = " << i->id << endl;
//            cout << "FROM = " << i->from << endl;
//            cout << "TO = " << i->to << endl;
            }

            /* for ( i = log.begin() ; i != log.end() ; i++ )
             {
                 cout << "-------------------" << endl;
                 cout << i->second.TimeStamp().d << "/" << i->second.TimeStamp().mon << "/" << i->second.TimeStamp().y << " - ";
                 cout << i->second.TimeStamp().h << ":" << i->second.TimeStamp().min << ":" << i->second.TimeStamp().s << endl;
                 cout << "ID = " << i->first << " --- " <<  "EMAIL =" << i->second.To() << i->second.From() << i->second.Subject() <<  endl;
                 cout << "-------------------" << endl;
             }*/

            return parsed;
        }



        list<CMail> ListMail ( const CTimeStamp & from , const CTimeStamp & to ) const
        {
            list < CMail > tmpemails;
            list < CMail > emails;
            int lowerbound;
            int upperbound;
            string sender , subject;

            multimap < string , class CMail >::const_iterator e;
            for ( e = log.begin() ; e != log.end() ; e++ )
            {
                if ( e->second.From().find("from=") != std::string::npos )
                {sender = e->second.From();}
                else if ( e->second.Subject().find("subject=") != std::string::npos )
                {subject = e->second.Subject();}
                else if ( e->second.To().find("to=") != std::string::npos )
                {
                    vector<emaildata>::const_iterator i;
                    for ( i = emailcount.begin() + 1 ; i  != emailcount.end() ; i++ )
                    {
                        if ( e->first == i->id && i->to == 1)
                        {
                            multimap<string, class CMail>::const_iterator a;
                            for (a = log.begin(); a != log.end(); a++) {
                                if (a->first == e->first)
                                {
                                    if (!a->second.Subject().empty())
                                    {break;}
                                }
                                else { subject = " subject:"; }
                            }
                        }
                        else
                        {break;}
                    }
                    CMail email ( e->second.TimeStamp() , sender , e->second.To() , subject );
                    emails.push_back(email);
                }
            }

            list < CMail >::const_iterator x;
            for ( x = emails.begin() ; x != emails.end() ; x++ )
            {
                lowerbound = x->CompareByTime(from);
                upperbound = x->CompareByTime(to);
                if ( lowerbound >= 0 && upperbound <= 0 )
                {tmpemails.push_back(*x);}
            }
            tmpemails.sort(comparetime);

            /*for ( list < CMail >::const_iterator y = emails2.begin() ; y != emails2.end() ; y++ )
            {
                cout << "-------------------" << endl;
                cout << y->TimeStamp().d << "/" << y->TimeStamp().mon << "/" << y->TimeStamp().y << " - ";
                cout << y->TimeStamp().h << ":" << y->TimeStamp().min << ":" << y->TimeStamp().s << endl;
                cout << y->From() << " ->" <<y->To() << " ," << y->Subject() <<  endl;
                cout << "-------------------" << endl;
            }*/

            return tmpemails;
        }

        set<string> ActiveUsers ( const CTimeStamp & from , const CTimeStamp & to ) const
        {
            list < CMail > tmpmail = ListMail(from,to);
            set < string > users;
            int lowerbound , upperbound;
            list < CMail >::const_iterator e;
            for ( e = tmpmail.begin() ; e != tmpmail.end() ; e++ )
            {
                lowerbound = e->CompareByTime(from);
                upperbound = e->CompareByTime(to);
                if ( lowerbound >= 0 && upperbound <= 0 )
                {
                    string f , t;
                    f = e->From();
                    f.erase(0,6);
                    t = e->To();
                    t.erase(0,4);
                    if ( !e->From().empty() )
                        users.insert(f);
                    if ( !e->To().empty() )
                        users.insert(t);
                }
            }


            /*for ( set < string >::const_iterator y = users.begin() ; y != users.end() ; y++ )
            {
                cout << "-------------------" << endl;
                cout << *y << endl;
                cout << "-------------------";
            }*/

            return users;
        }

    };

//----------------------------------------------------------------------------------------
#ifndef __PROGTEST__
} // namespace

string printMail ( const list<CMail> & all )
{
    ostringstream oss;
    for ( const auto & mail : all )
        oss << mail << endl;
    return oss . str ();
}

string printUsers ( const set<string> & all )
{
    ostringstream oss;
    bool first = true;
    for ( const auto & name : all )
    {
        if ( ! first )
            oss << ", ";
        else
            first = false;
        oss << name;
    }
    return oss . str ();
}

int main ( void )
{
    MysteriousNamespace::CMailLog m;
    list<CMail> mailList;
    set<string> users;
    istringstream iss;

    iss . clear ();
    iss . str (
            "Mar 29 2019 12:35:32.233 relay.fit.cvut.cz ADFger72343D: from=user1@fit.cvut.cz\n"
            "Mar 29 2019 12:37:16.234 relay.fit.cvut.cz JlMSRW4232Df: from=person3@fit.cvut.cz\n"
            "Mar 29 2019 12:55:13.023 relay.fit.cvut.cz JlMSRW4232Df: subject=New progtest homework!\n"
            "Mar 29 2019 13:38:45.043 relay.fit.cvut.cz Kbced342sdgA: from=office13@fit.cvut.cz\n"
            "Mar 29 2019 13:36:13.023 relay.fit.cvut.cz JlMSRW4232Df: to=user76@fit.cvut.cz\n"
            "Mar 29 2019 13:55:31.456 relay.fit.cvut.cz KhdfEjkl247D: from=PR-department@fit.cvut.cz\n"
            "Mar 29 2019 14:18:12.654 relay.fit.cvut.cz Kbced342sdgA: to=boss13@fit.cvut.cz\n"
            "Mar 29 2019 14:48:32.563 relay.fit.cvut.cz KhdfEjkl247D: subject=Business partner\n"
            "Mar 29 2019 14:58:32.000 relay.fit.cvut.cz KhdfEjkl247D: to=HR-department@fit.cvut.cz\n"
            "Mar 29 2019 14:25:23.233 relay.fit.cvut.cz ADFger72343D: mail undeliverable\n"
            "Mar 29 2019 15:02:34.231 relay.fit.cvut.cz KhdfEjkl247D: to=CIO@fit.cvut.cz\n"
            "Mar 29 2019 15:02:34.230 relay.fit.cvut.cz KhdfEjkl247D: to=CEO@fit.cvut.cz\n"
            "Mar 29 2019 15:02:34.230 relay.fit.cvut.cz KhdfEjkl247D: to=dean@fit.cvut.cz\n"
            "Mar 29 2019 15:02:34.230 relay.fit.cvut.cz KhdfEjkl247D: to=vice-dean@fit.cvut.cz\n"
            "Mar 29 2019 15:02:34.230 relay.fit.cvut.cz KhdfEjkl247D: to=archive@fit.cvut.cz\n" );
    assert ( m . ParseLog ( iss ) == 8 );
    mailList = m . ListMail ( CTimeStamp ( 2019, 3, 28, 0, 0, 0 ),
                              CTimeStamp ( 2019, 3, 29, 23, 59, 59 ) );
//    printMail(mailList);
//    cout << "===================================" << endl;
    assert ( printMail ( mailList ) ==
             "2019-03-29 13:36:13.023 person3@fit.cvut.cz -> user76@fit.cvut.cz, subject: New progtest homework!\n"
             "2019-03-29 14:18:12.654 office13@fit.cvut.cz -> boss13@fit.cvut.cz, subject: \n"
             "2019-03-29 14:58:32.000 PR-department@fit.cvut.cz -> HR-department@fit.cvut.cz, subject: Business partner\n"
             "2019-03-29 15:02:34.230 PR-department@fit.cvut.cz -> CEO@fit.cvut.cz, subject: Business partner\n"
             "2019-03-29 15:02:34.230 PR-department@fit.cvut.cz -> dean@fit.cvut.cz, subject: Business partner\n"
             "2019-03-29 15:02:34.230 PR-department@fit.cvut.cz -> vice-dean@fit.cvut.cz, subject: Business partner\n"
             "2019-03-29 15:02:34.230 PR-department@fit.cvut.cz -> archive@fit.cvut.cz, subject: Business partner\n"
             "2019-03-29 15:02:34.231 PR-department@fit.cvut.cz -> CIO@fit.cvut.cz, subject: Business partner\n" );
    mailList = m . ListMail ( CTimeStamp ( 2019, 3, 28, 0, 0, 0 ),
                              CTimeStamp ( 2019, 3, 29, 14, 58, 32 ) );
//    printMail(mailList);
//    cout << "===================================" << endl;
    assert ( printMail ( mailList ) ==
             "2019-03-29 13:36:13.023 person3@fit.cvut.cz -> user76@fit.cvut.cz, subject: New progtest homework!\n"
             "2019-03-29 14:18:12.654 office13@fit.cvut.cz -> boss13@fit.cvut.cz, subject: \n"
             "2019-03-29 14:58:32.000 PR-department@fit.cvut.cz -> HR-department@fit.cvut.cz, subject: Business partner\n" );
    mailList = m . ListMail ( CTimeStamp ( 2019, 3, 30, 0, 0, 0 ),
                              CTimeStamp ( 2019, 3, 30, 23, 59, 59 ) );
//    printMail(mailList);
//    cout << "===================================" << endl;
    assert ( printMail ( mailList ) == "" );
    users = m . ActiveUsers ( CTimeStamp ( 2019, 3, 28, 0, 0, 0 ),
                              CTimeStamp ( 2019, 3, 29, 23, 59, 59 ) );
//    printUsers(users);
//    cout << "\n===================================" << endl;
    assert ( printUsers ( users ) == "CEO@fit.cvut.cz, CIO@fit.cvut.cz, HR-department@fit.cvut.cz, PR-department@fit.cvut.cz, archive@fit.cvut.cz, boss13@fit.cvut.cz, dean@fit.cvut.cz, office13@fit.cvut.cz, person3@fit.cvut.cz, user76@fit.cvut.cz, vice-dean@fit.cvut.cz" );
    users = m . ActiveUsers ( CTimeStamp ( 2019, 3, 28, 0, 0, 0 ),
                              CTimeStamp ( 2019, 3, 29, 13, 59, 59 ) );
//    printUsers(users);
//    cout << "\n===================================" << endl;
    assert ( printUsers ( users ) == "person3@fit.cvut.cz, user76@fit.cvut.cz" );
    return 0;
}

#endif /* __PROGTEST__ */
