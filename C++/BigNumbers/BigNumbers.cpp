#ifndef __PROGTEST__
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <climits>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include <stdexcept>
using namespace std;
#endif /* __PROGTEST__ */


bool isSmaller( string str1 , string str2 )
{
    long long int n1 = str1.length();
    long long int n2 = str2.length();

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for( long long int i = 0 ; i < n1 ; i++ )
    if (str1[i] < str2[i])
        return true;
    else if (str1[i] > str2[i])
        return false;

    return false;
}
string subtract( string x , string y )
{
    if (isSmaller(x, y))
        swap(x, y);

    string str = "";
    long long int n1 = x.length(), n2 = y.length();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    long long int carry = 0;
    for( long long int i = 0 ; i < n2 ; i++ )
    {
        long long int sub = ( ( x[i] - '0' ) - ( y[i] - '0' ) -carry );
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
          carry = 0;
        str.push_back(sub + '0');
    }
    for( long long int i = n2 ; i < n1 ; i++ )
    {
        long long int sub = ( ( x[i] - '0' ) - carry );
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
          carry = 0;
        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());
    return str;
}
string sum( string x , string y )
{
  if( x.length() > y.length() )
      swap(x, y);
  string str = "";
  long long int n1 = x.length(), n2 = y.length();
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  long long int carry = 0;
  for( long long int i = 0 ; i < n1 ; i++ )
  {
      long long int sum = ( ( x[i] - '0' ) + ( y[i] - '0' ) + carry );
      str.push_back(sum % 10 + '0');
      carry = sum / 10;
  }
  for( long long int i = n1 ; i < n2 ; i++ )
  {
      long long int sum = ( ( y[i] - '0' ) +carry );
      str.push_back(sum % 10 + '0');
      carry = sum / 10;
  }
  if(carry)
      str.push_back(carry+'0');
  reverse(str.begin(), str.end());
  return str;
}
string multiply( string num1 , string num2 )
{
  long long int len1 = num1.size();
  long long int len2 = num2.size();
  if(len1 == 0 || len2 == 0 || num1[0] == '0' || num2[0] == '0')
    return "0";
  vector<long long int> result(len1 + len2, 0);
  long long int i_n1 = 0;
  long long int i_n2 = 0;
  for( long long int i = len1 - 1 ; i >= 0 ; i-- )
  {
      long long int carry = 0;
      long long int n1 = num1[i] - '0';
      i_n2 = 0;
      for( long long int j = len2 - 1 ; j >= 0 ; j-- )
      {
          long long int n2 = num2[j] - '0';
          long long int sum = n1*n2 + result[i_n1 + i_n2] + carry;
          carry = sum/10;
          result[i_n1 + i_n2] = sum % 10;
          i_n2++;
      }
      if( carry > 0 )
      { result[i_n1 + i_n2] += carry; }
      i_n1++;
  }
  long long int i = result.size() - 1;
  while( i >= 0 && result[i] == 0 )
  i--;
  if (i == -1)
  return "0";
  string s = "";
  while (i >= 0)
    s += to_string(result[i--]);

  return s;
}
bool isNegative( string numro )
{
    long long int i = 0;
    if (numro[i] == '-')
    { return true; }
    else
    { return false; }
}

class CBigInt
{
private:
  string numro;
  int sign = 0;

  public:
    // default constructor
    CBigInt()
    { numro = "0"; }
    // int constructor
    CBigInt( long long int num )
    {
      numro = to_string(num);
      if( isNegative(numro) )
      {
        sign = 1;
        numro.erase(0,1);
      }
    }
    // string constructor
    CBigInt( string num )
    {
      numro = num;
      if( isNegative(numro) )
      {
        sign = 1;
        numro.erase(0,1);
      }
    }

    // assignment - CBigInt instance
    CBigInt operator = ( const CBigInt & x )
    {
      this->numro = x.numro;
      this->numro.erase(0, min(this->numro.find_first_not_of('0'), this->numro.size()-1));
      this->sign = x.sign;
      return *this;
    }
    // assignment - integer
    CBigInt operator = ( long long int x )
    {
      this->numro = to_string(x);
      this->numro.erase(0, min(this->numro.find_first_not_of('0'), this->numro.size()-1));
      if( isNegative(this->numro) )
      {
        this->sign = 1;
        this->numro.erase(0,1);
      }
      else
      { this->sign = 0; }
      return *this;
    }
    // assignment - string
    CBigInt operator = ( string x )
    {
      string tmp = x;
      int flag = 0;
      if( isNegative(x) )
      {
        tmp.erase(0,1);
        string::const_iterator it = tmp.begin();
        while ( (it != tmp.end() && isdigit(*it)) ) ++it;
        tmp.erase(it,tmp.end());
        if( tmp.empty() )
        {
          throw invalid_argument("INVALID NO.");
          flag = 1;
        }
      }
      if( !flag )
      {
        this->numro = x;
        this->numro.erase(0, min(this->numro.find_first_not_of('0'), this->numro.size()-1));
        if( isNegative(x) )
        {
          this->sign = 1;
          this->numro.erase(0,1);
        }
        else
        { this->sign = 0; }
      }
      return *this;
    }


    // comparison operators, any combination {CBigInt/int/string} {<,<=,>,>=,==,!=} {CBigInt/int/string}
    friend bool equality(const CBigInt & x , const CBigInt & y);
    friend bool operator == ( const CBigInt & x , const CBigInt & y )
    {
      bool res = equality(x,y);
      return res;
    }
    friend bool operator == ( const CBigInt & x , long long int no )
    {
      CBigInt y(no);
      bool res = equality(x,y);
      return res;
    }
    friend bool operator == ( long long int no , const CBigInt & x )
    {
      CBigInt y(no);
      bool res = equality(x,y);
      return res;
    }
    friend bool operator == ( const CBigInt & x , string no )
    {
      CBigInt y(no);
      bool res = equality(x,y);
      return res;
    }
    friend bool operator == ( string no , const CBigInt & x )
    {
      CBigInt y(no);
      bool res = equality(x,y);
      return res;
    }

    friend bool inequality(const CBigInt & x , const CBigInt & y);
    friend bool operator != ( const CBigInt & x , const CBigInt & y )
    {
      bool res = inequality(x,y);
      return res;
    }
    friend bool operator != ( const CBigInt & x , long long int no )
    {
      CBigInt y(no);
      bool res = inequality(x,y);
      return res;
    }
    friend bool operator != ( long long int no , const CBigInt & x )
    {
      CBigInt y(no);
      bool res = inequality(x,y);
      return res;
    }
    friend bool operator != ( const CBigInt & x , string no )
    {
      CBigInt y(no);
      bool res = inequality(x,y);
      return res;
    }
    friend bool operator != ( string no , const CBigInt & x )
    {
      CBigInt y(no);
      bool res = inequality(x,y);
      return res;
    }

    friend bool lessthan(const CBigInt & x , const CBigInt & y);
    friend bool operator < ( const CBigInt & x , const CBigInt & y )
    {
      bool res = lessthan(x,y);
      return res;
    }
    friend bool operator < ( const CBigInt & x , long long int no )
    {
      CBigInt y(no);
      bool res = lessthan(x,y);
      return res;
    }
    friend bool operator < ( long long int no , const CBigInt & y )
    {
      CBigInt x(no);
      bool res = lessthan(x,y);
      return res;
    }
    friend bool operator < ( const CBigInt & x , string no )
    {
      CBigInt y(no);
      bool res = lessthan(x,y);
      return res;
    }
    friend bool operator < ( string no , const CBigInt & y )
    {
      CBigInt x(no);
      bool res = lessthan(x,y);
      return res;
    }

    friend bool lessthaneq(const CBigInt & x , const CBigInt & y);
    friend bool operator <= ( const CBigInt & x , const CBigInt & y )
    {
      bool res = lessthaneq(x,y);
      return res;
    }
    friend bool operator <= ( const CBigInt & x , long long int no )
    {
      CBigInt y(no);
      bool res = lessthaneq(x,y);
      return res;
    }
    friend bool operator <= ( long long int no , const CBigInt & y )
    {
      CBigInt x(no);
      bool res = lessthaneq(x,y);
      return res;
    }
    friend bool operator <= ( const CBigInt & x , string no )
    {
      CBigInt y(no);
      bool res = lessthaneq(x,y);
      return res;
    }
    friend bool operator <= ( string no , const CBigInt & y )
    {
      CBigInt x(no);
      bool res = lessthaneq(x,y);
      return res;
    }

    friend bool greaterthan(const CBigInt & x , const CBigInt & y);
    friend bool operator > ( const CBigInt & x , const CBigInt & y )
    {
      bool res = greaterthan(x,y);
      return res;
    }
    friend bool operator > ( const CBigInt & x , long long int no )
    {
      CBigInt y(no);
      bool res = greaterthan(x,y);
      return res;
    }
    friend bool operator > ( long long int no , const CBigInt & y )
    {
      CBigInt x(no);
      bool res = greaterthan(x,y);
      return res;
    }
    friend bool operator > ( const CBigInt & x , string no )
    {
      CBigInt y(no);
      bool res = greaterthan(x,y);
      return res;
    }
    friend bool operator > ( string no , const CBigInt & y )
    {
      CBigInt x(no);
      bool res = greaterthan(x,y);
      return res;
    }

    friend bool greaterthaneq(const CBigInt & x , const CBigInt & y);
    friend bool operator >= ( const CBigInt & x , const CBigInt & y )
    {
      bool res = greaterthaneq(x,y);
      return res;
    }
    friend bool operator >= ( const CBigInt & x , long long int no )
    {
      CBigInt y(no);
      bool res = greaterthaneq(x,y);
      return res;
    }
    friend bool operator >= ( long long int no , const CBigInt & y )
    {
      CBigInt x(no);
      bool res = greaterthaneq(x,y);
      return res;
    }
    friend bool operator >= ( const CBigInt & x , string no )
    {
      CBigInt y(no);
      bool res = greaterthaneq(x,y);
      return res;
    }
    friend bool operator >= ( string no , const CBigInt & y )
    {
      CBigInt x(no);
      bool res = greaterthaneq(x,y);
      return res;
    }

    // operator +, any combination {CBigInt/int/string} + {CBigInt/int/string}
    friend CBigInt addting (const CBigInt & x , const CBigInt & y);
    friend CBigInt operator + ( const CBigInt & x , const CBigInt & y)
    {
      CBigInt result = addting(x,y);
      return result;
    }
    friend CBigInt operator + ( const CBigInt & x , long long int no )
    {
      CBigInt y(no);
      CBigInt result = addting(x,y);
      return result;
    }
    friend CBigInt operator + ( long long int no , const CBigInt & y )
    {
      CBigInt x(no);
      CBigInt result = addting(x,y);
      return result;
    }
    friend CBigInt operator + ( const CBigInt & x , string no )
    {
      CBigInt y(no);
      CBigInt result = addting(x,y);
      return result;
    }
    friend CBigInt operator + ( string no , const CBigInt & y )
    {
      CBigInt x(no);
      CBigInt result = addting(x,y);
      return result;
    }
    friend CBigInt operator + ( const string & no1 , const string & no2 );
    friend CBigInt operator + ( const long long int & no1 , const string & no2 );
    friend CBigInt operator + ( const string & no1 , const long long int & no2 );

    // operator +=, any of {CBigInt/int/string}
    CBigInt operator += ( string no )
    {
      CBigInt res(no);
      *this = *this + res;
      return *this;
    }
    CBigInt operator += ( long long int no )
    {
      CBigInt res(no);
      *this = *this + res;
      return *this;
    }
    CBigInt operator += ( const CBigInt & x )
    {
      *this = *this + x;
      return *this;
    }

    // operator *, any combination {CBigInt/int/string} * {CBigInt/int/string}
    friend CBigInt operator * ( const CBigInt & x , const CBigInt & y)
    {
      string no2 = x.numro;
      string no1 = y.numro;
      string result = multiply(no1,no2);
      CBigInt res(result);
      if( (x.sign == 1 && y.sign == 1) || (x.sign == 0 && y.sign == 0) )
      { res.sign = 0; }
      else
      { res.sign = 1; }
      return res;
    }
    friend CBigInt operator * ( const CBigInt & x , long long int no )
    {
      CBigInt y(no);
      string no2 = x.numro;
      string no1 = y.numro;
      string result = multiply(no1,no2);
      CBigInt res(result);
      if( (x.sign == 1 && y.sign == 1) || (x.sign == 0 && y.sign == 0) )
      { res.sign = 0; }
      else
      { res.sign = 1; }
      return res;
    }
    friend CBigInt operator * ( long long int no , const CBigInt & y )
    {
      CBigInt x(no);
      string no1 = x.numro;
      string no2 = y.numro;
      string result = multiply(no1,no2);
      CBigInt res(result);
      if( (x.sign == 1 && y.sign == 1) || (x.sign == 0 && y.sign == 0) )
      { res.sign = 0; }
      else
      { res.sign = 1; }
      return res;
    }
    friend CBigInt operator * ( const CBigInt & x , string no )
    {
      CBigInt y(no);
      string no2 = x.numro;
      string no1 = y.numro;
      string result = multiply(no1,no2);
      CBigInt res(result);
      if( (x.sign == 1 && y.sign == 1) || (x.sign == 0 && y.sign == 0) )
      { res.sign = 0; }
      else
      { res.sign = 1; }
      return res;
    }
    friend CBigInt operator * ( string no , const CBigInt & y )
    {
      CBigInt x(no);
      string no1 = x.numro;
      string no2 = y.numro;
      string result = multiply(no1,no2);
      CBigInt res(result);
      if( (x.sign == 1 && y.sign == 1) || (x.sign == 0 && y.sign == 0) )
      { res.sign = 0; }
      else
      { res.sign = 1; }
      return res;
    }
    friend CBigInt operator * ( const string & no1 , const string & no2 );
    friend CBigInt operator * ( const long long int & no1 , const string & no2 );
    friend CBigInt operator * ( const string & no1 , const long long int & no2 );

    // operator *=, any of {CBigInt/int/string}
    CBigInt operator *= ( string no )
    {
      CBigInt x(no);
      *this = *this * x;
      return * this;
    }
    CBigInt operator *= ( long long int no )
    {
      CBigInt x(no);
      *this = *this * x;
      return * this;
    }
    CBigInt operator *= ( const CBigInt & x )
    {
      *this = *this * x;
      return * this;
    }

    // output operator <<
    friend ostringstream & operator << ( ostringstream & os , const CBigInt & x )
    {
      if( x.sign == 1 && x.numro[0] != '0' )
      { os << "-"; }
      string ye = x.numro;
      ye.erase(0, min(ye.find_first_not_of('0'), ye.size()-1));
      os << ye;
      return os;
    }
    // input operator >>
    friend istringstream & operator >> (istringstream & is , CBigInt & x )
    {
      string input;
      is >> input;
      string::const_iterator it = input.begin();
      while (it != input.end() && isdigit(*it)) ++it;
      input.erase(it,input.end());
      if( input.empty() )
      { is.setstate(ios::failbit); }
      else
      {
        input.erase(0, min(input.find_first_not_of('0'), input.size()-1));
        x.numro = input;
      }
      return is;
    }
    void printnumro()
    {
      numro.erase(0, min(numro.find_first_not_of('0'), numro.size()-1));
      cout << "== ";
      if( sign == 1 && numro[0] != '0' )
      { cout << "-"; }
      cout << numro << " ==" << endl;
    }
};

bool equality(const CBigInt & x , const CBigInt & y)
{
  if (x.sign != y.sign)
  { return false; }
  else
  {
    if (x.numro.length() != y.numro.length())
    { return false; }
    else
    {
      for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
      {
        if( x.numro[i] != y.numro[i] )
        { return false; }
      }
    }
  }
  return true;
}
bool inequality(const CBigInt & x , const CBigInt & y)
{
  if (x.sign != y.sign)
  { return true; }
  else
  {
    if (x.numro.length() != y.numro.length())
    { return true; }
    else
    {
      for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
      {
        if( x.numro[i] != y.numro[i] )
        { return true; }
      }
    }
  }
  return false;
}
bool lessthan(const CBigInt & x , const CBigInt & y)
{
  if (x.sign != y.sign)
  { return x.sign > y.sign; }
  else
  {
    if (x.numro.length() != y.numro.length())
    { return x.numro.length() < y.numro.length(); }
    else
    {
      if( x.sign == 1 && y.sign == 1 )
      {
        for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
        {
          if( x.numro[i] != y.numro[i] )
          { return x.numro[i] > y.numro[i]; }
        }
      }
      else
      {
        for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
        {
          if( x.numro[i] != y.numro[i] )
          { return x.numro[i] < y.numro[i]; }
        }
      }
    }
  }
  return false;
}
bool greaterthan(const CBigInt & x , const CBigInt & y)
{
  if (x.sign != y.sign)
  { return x.sign < y.sign; }
  else
  {
    if (x.numro.length() != y.numro.length())
    { return x.numro.length() > y.numro.length(); }
    else
    {
      if( x.sign == 1 && y.sign == 1 )
      {
        for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
        {
          if( x.numro[i] != y.numro[i] )
          { return x.numro[i] < y.numro[i]; }
        }
      }
      else
      {
        for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
        {
          if( x.numro[i] != y.numro[i] )
          { return x.numro[i] > y.numro[i]; }
        }
      }
    }
  }
  return false;
}
bool lessthaneq(const CBigInt & x , const CBigInt & y)
{
  if (x.sign != y.sign)
  { return x.sign > y.sign; }
  else
  {
    if (x.numro.length() != y.numro.length())
    { return x.numro.length() < y.numro.length(); }
    else
    {
      if( x.sign == 1 && y.sign == 1 )
      {
        for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
        {
          if( x.numro[i] != y.numro[i] )
          { return x.numro[i] > y.numro[i]; }
        }
      }
      else
      {
        for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
        {
          if( x.numro[i] != y.numro[i] )
          { return x.numro[i] < y.numro[i]; }
        }
      }
    }
  }
  return true;
}
bool greaterthaneq(const CBigInt & x , const CBigInt & y)
{
  if (x.sign != y.sign)
  { return x.sign < y.sign; }
  else
  {
    if (x.numro.length() != y.numro.length())
    { return x.numro.length() > y.numro.length(); }
    else
    {
      if( x.sign == 1 && y.sign == 1 )
      {
        for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
        {
          if( x.numro[i] != y.numro[i] )
          { return x.numro[i] < y.numro[i]; }
        }
      }
      else
      {
        for( long long int i = x.numro.length() - 1 ; i >= 0 ; i-- )
        {
          if( x.numro[i] != y.numro[i] )
          { return x.numro[i] > y.numro[i]; }
        }
      }
    }
  }
  return true;
}
CBigInt addting (const CBigInt & x , const CBigInt & y)
{
  string no1 = x.numro;
  string no2 = y.numro;
  CBigInt res;
  if(x.sign == 1 && y.sign == 1)
  {
    string result = sum(no1,no2);
    res = result;
    res.sign = 1;
    return res;
  }
  else
  {
    if(x.sign == 0 && y.sign == 0)
    {
      string result = sum(no1,no2);
      res = result;
      return res;
    }
    else
    {
      if( x.numro == y.numro )
      {
        res = 0;
        res.sign = 0;
        return res;
      }
      if( x > y.numro )
      {
        string result = subtract(no1,no2);
        res = result;
        res.sign = x.sign;
        return res;
      }
      else if( x.numro < y )
      {
        string result = subtract(no2,no1);
        res = result;
        res.sign = y.sign;
        return res;
      }
      if( x.numro > y )
      {
        string result = subtract(no1,no2);
        res = result;
        res.sign = y.sign;
        return res;
      }
      else if( x < y.numro )
      {
        string result = subtract(no2,no1);
        res = result;
        res.sign = x.sign;
        return res;
      }
    }
  }
  return res;
}

CBigInt operator + ( const string & no1 , const string & no2 )
{
  CBigInt x(no1);
  CBigInt y(no2);
  CBigInt result = addting(x,y);
  return result;
}
CBigInt operator + ( const long long int & no1 , const string & no2 )
{
  CBigInt x(no1);
  CBigInt y(no2);
  CBigInt result = addting(x,y);
  return result;
}
CBigInt operator + ( const string & no1 , const long long int & no2 )
{
  CBigInt x(no1);
  CBigInt y(no2);
  CBigInt result = addting(x,y);
  return result;
}
CBigInt operator * ( const string & n1 , const string & n2 )
{
  CBigInt x(n1);
  CBigInt y(n2);
  string no1 = x.numro;
  string no2 = y.numro;
  string result = multiply(no1,no2);
  CBigInt res(result);
  if( (x.sign == 1 && y.sign == 1) || (x.sign == 0 && y.sign == 0) )
  { res.sign = 0; }
  else
  { res.sign = 1; }
  return res;
}
CBigInt operator * ( const long long int & n1 , const string & n2 )
{
  CBigInt x(n1);
  CBigInt y(n2);
  string no1 = x.numro;
  string no2 = y.numro;
  string result = multiply(no1,no2);
  CBigInt res(result);
  if( (x.sign == 1 && y.sign == 1) || (x.sign == 0 && y.sign == 0) )
  { res.sign = 0; }
  else
  { res.sign = 1; }
  return res;
}
CBigInt operator * ( const string & n1 , const long long int & n2 )
{
  CBigInt x(n1);
  CBigInt y(n2);
  string no1 = x.numro;
  string no2 = y.numro;
  string result = multiply(no1,no2);
  CBigInt res(result);
  if( (x.sign == 1 && y.sign == 1) || (x.sign == 0 && y.sign == 0) )
  { res.sign = 0; }
  else
  { res.sign = 1; }
  return res;
}

#ifndef __PROGTEST__
static bool equal ( const CBigInt & x, const char * val )
{
  ostringstream oss;
  oss << x;
  return oss . str () == val;
}

int main ( void )
{
  CBigInt a, b;
  istringstream is;
  a = 10;
  a += 20;
  assert ( equal ( a, "30" ) );
  a *= 5;
  assert ( equal ( a, "150" ) );
  b = a + 3;
  assert ( equal ( b, "153" ) );
  b = a * 7;
  assert ( equal ( b, "1050" ) );
  assert ( equal ( a, "150" ) );

  a = 10;
  a += -20;
  assert ( equal ( a, "-10" ) );
  a *= 5;
  assert ( equal ( a, "-50" ) );
  b = a + 73;
  assert ( equal ( b, "23" ) );
  b = a * -7;
  assert ( equal ( b, "350" ) );
  assert ( equal ( a, "-50" ) );

  a = "12345678901234567890";
  a += "-99999999999999999999";
  assert ( equal ( a, "-87654321098765432109" ) );
  a *= "54321987654321987654";
  assert ( equal ( a, "-4761556948575111126880627366067073182286" ) );
  a *= 0;
  assert ( equal ( a, "0" ) );
  a = 10;
  b = a + "400";
  assert ( equal ( b, "410" ) );
  b = a * "15";
  assert ( equal ( b, "150" ) );
  assert ( equal ( a, "10" ) );

  is . clear ();
  is . str ( " 1234" );
  assert ( is >> b );
  assert ( equal ( b, "1234" ) );
  is . clear ();
  is . str ( " 12 34" );
  assert ( is >> b );
  assert ( equal ( b, "12" ) );
  is . clear ();
  is . str ( "999z" );
  assert ( is >> b );
  assert ( equal ( b, "999" ) );
  is . clear ();
  is . str ( "abcd" );
  assert ( ! ( is >> b ) );
  is . clear ();
  is . str ( "- 758" );
  assert ( ! ( is >> b ) );
  a = 42;
  try
  {
    a = "-xyz";
    assert ( "missing an exception" == NULL );
  }
  catch ( const invalid_argument & e )
  {
    assert ( equal ( a, "42" ) );
  }

  a = "73786976294838206464";
  assert ( a < "1361129467683753853853498429727072845824" );
  assert ( a <= "1361129467683753853853498429727072845824" );
  assert ( ! ( a > "1361129467683753853853498429727072845824" ) );
  assert ( ! ( a >= "1361129467683753853853498429727072845824" ) );
  assert ( ! ( a == "1361129467683753853853498429727072845824" ) );
  assert ( a != "1361129467683753853853498429727072845824" );
  assert ( ! ( a < "73786976294838206464" ) );
  assert ( a <= "73786976294838206464" );
  assert ( ! ( a > "73786976294838206464" ) );
  assert ( a >= "73786976294838206464" );
  assert ( a == "73786976294838206464" );
  assert ( ! ( a != "73786976294838206464" ) );
  assert ( a < "73786976294838206465" );
  assert ( a <= "73786976294838206465" );
  assert ( ! ( a > "73786976294838206465" ) );
  assert ( ! ( a >= "73786976294838206465" ) );
  assert ( ! ( a == "73786976294838206465" ) );
  assert ( a != "73786976294838206465" );
  a = "2147483648";
  assert ( ! ( a < -2147483648 ) );
  assert ( ! ( a <= -2147483648 ) );
  assert ( a > -2147483648 );
  assert ( a >= -2147483648 );
  assert ( ! ( a == -2147483648 ) );
  assert ( a != -2147483648 );

  return 0;
}
#endif /* __PROGTEST__ */
