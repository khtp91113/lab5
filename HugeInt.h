#include<iostream>
#include<string>
using namespace std;
class HugeInt//把每個數字拆開存進num陣列 然後sign用來存正負號
{
 friend ostream &operator<<(ostream&,const HugeInt&);
 friend istream &operator>>(istream&,HugeInt&);
 public:
 HugeInt operator+(HugeInt &obj);
 HugeInt operator-(HugeInt &obj);
 const HugeInt &operator=(const HugeInt &obj);
 HugeInt()
 {
  for(int i=0;i<100;i++)
   num[i]=0;
  sign='+';
 }
 HugeInt(long long int a)
 {
  if(a<0)
  {
   sign='-';
   a=a*(-1);
  }
  else
   sign='+';
  for(int i=0;i<100;i++)
   num[i]=0;
  for(int i=0;i<100&&a>=0;i++)
  {
   num[i]=a%10;
   a/=10;
  }
 }
 HugeInt(string s)
 {
  if(s[0]=='-')
   sign='-';
  else
   sign='+';
  int temp[100];
  for(int i=0;i<100;i++)
   num[i]=0;
  for(int i=0;i<100;i++)
   temp[i]=0;
  if(s[0]=='-')
  {
   for(int i=0;i<s.size()-1;i++)
   {
    temp[i]=s[i+1]-48;
   }
   for(int i=0;i<s.size()-1;i++)
    num[i]=temp[s.size()-2-i];
  }
  else
  {
   for(int i=0;i<s.size();i++)
    temp[i]=s[i]-48;
   for(int i=0;i<s.size();i++)
    num[i]=temp[s.size()-1-i];
  }
 }  
 private:
 int num[100];
 char sign;
};
