#include"HugeInt.h"
#include<iostream>
#include<iomanip>

ostream &operator<<(ostream &out,const HugeInt &obj)
{
 if(obj.sign=='-')
  out<<obj.sign;
 int total=0;
 for(int i=99;i>=0;i--)
  if(obj.num[i]!=0)
  {
   total=i;
   break;
  }
 for(int i=total;i>=0;i--)
  out<<obj.num[i];
 return out;
}

istream &operator>>(istream &in,HugeInt &obj)
{
 char b;
 int total=0,temp[100];
 string s;
 for(int i=0;i<100;i++)
  temp[i]=0;
 in>>s;
 if(s[0]=='-')
 {
  obj.sign='-';
  for(int i=0;i<s.size()-1;i++)
   temp[i]=s[i+1]-48;
  for(int i=0;i<s.size()-1;i++)
   obj.num[i]=temp[s.size()-2-i];
 }
 else
 {
  for(int i=1;i<s.size();i++)
   temp[i]=s[i]-48;
  for(int i=0;i<s.size()-1;i++)
   obj.num[i]=temp[s.size()-1-i];
  obj.num[s.size()-1]=s[0]-48;
 }
 return in;
}

HugeInt HugeInt::operator+(HugeInt &a)//若兩數異號 視為相減 去比大小決定用哪個減哪個 再判斷正負  若同號 則直接相加 正負號不變
{
 HugeInt sum,obj;
 for(int i=0;i<100;i++)
 {
  sum.num[i]=num[i];
  obj.num[i]=a.num[i];
 }
 sum.sign=sign;
 obj.sign=a.sign;
 int count=0,count_obj=0;
 for(int i=99;i>=0;i--)
  if(sum.num[i]!=0)
  {
   count=i;
   break;
  }
 for(int i=99;i>=0;i--)
  if(obj.num[i]!=0)
  {
   count_obj=i;
   break;
  }
 if(sum.sign!=obj.sign)
 {
  if(count>count_obj)
  {
   for(int i=0;i<count;i++)
   {
    if(sum.num[i]<obj.num[i])
    {
     sum.num[i]+=10;
     sum.num[i+1]-=1;
    }
    sum.num[i]-=obj.num[i];
   }
  }
  else if(count==count_obj)
  {
   int a=0;
   for(int i=count;;i--)
   {
    if(sum.num[i]!=obj.num[i])
    {
     if(sum.num[i]>=obj.num[i])
      a=0;
     else
      a=1;
     break;
    }
   }
   if(a==0)
   {
    for(int i=0;i<=count;i++)
    {
     if(sum.num[i]<obj.num[i])
     {
      sum.num[i]+=10;
      sum.num[i+1]-=1;
     }
     sum.num[i]-=obj.num[i];
    }
   }
   else
   {
    for(int i=0;i<=count_obj;i++)
    {
     if(obj.num[i]<sum.num[i])
     {
      obj.num[i]+=10;
      obj.num[i+1]-=1;
     }
     sum.num[i]=obj.num[i]-sum.num[i];
    }
    if(sum.sign=='+')
     sum.sign='-';
    else
     sum.sign='+';
   }
  }
  else
  {  
   for(int i=0;i<=count_obj;i++)
   {
    if(obj.num[i]<sum.num[i])
    {
     obj.num[i]+=10;
     obj.num[i+1]-=1;
    }
    sum.num[i]=obj.num[i]-sum.num[i];
   }
   if(sum.sign=='-')
    sum.sign='+';
   else
    sum.sign='-';
  }
 }
 else
 {
  if(count>=count_obj)
   for(int i=0;i<=count+1;i++)
   {
    sum.num[i]+=obj.num[i];
    if(sum.num[i]>9)
    {
     sum.num[i+1]+=1;
     sum.num[i]-=10;
    }
   }
  else
  {
   for(int i=0;i<=count_obj+1;i++)
   {
    sum.num[i]+=obj.num[i];
    if(sum.num[i]>9)
    {
     sum.num[i+1]+=1;
     sum.num[i]-=10;
    }
   }
  }
 }
 return sum;
}

HugeInt HugeInt::operator-(HugeInt &a)//若兩數異號 視為相加 正負號不變 若兩數同號 判斷大小後用大的減小的 再判斷正負
{
 HugeInt sum,obj;
 for(int i=0;i<100;i++)
 {
  sum.num[i]=num[i];
  obj.num[i]=a.num[i];
 }
 sum.sign=sign;
 obj.sign=a.sign;
 int count=0,count_obj=0;
 for(int i=99;i>=0;i--)
  if(sum.num[i]!=0)
  {
   count=i;
   break;
  }
 for(int i=99;i>=0;i--)
  if(obj.num[i]!=0)
  {
   count_obj=i;
   break;
  }
 if(sum.sign!=obj.sign)
 {
  if(count>=count_obj)
   for(int i=0;i<=count+1;i++)
   {
    sum.num[i]+=obj.num[i];
    if(sum.num[i]>9)
    {
     sum.num[i+1]+=1;
     sum.num[i]-=10;
    }
   }
  else
  {
   for(int i=0;i<=count_obj+1;i++)
   {
    sum.num[i]+=obj.num[i];
    if(sum.num[i]>9)
    {
     sum.num[i+1]+=1;
     sum.num[i]-=10;
    }
   }
  }
 }
 else
 {
  if(count>count_obj)
  {
   for(int i=0;i<count;i++)
   {
    if(sum.num[i]<obj.num[i])
    {
     sum.num[i]+=10;
     sum.num[i+1]-=1;
    }
    sum.num[i]-=obj.num[i];
   }
  }
  else if(count==count_obj)
  {
   int a=0;
   for(int i=count;;i--)
   {
    if(sum.num[i]!=obj.num[i])
    {
     if(sum.num[i]>=obj.num[i])
      a=0;
     else
      a=1;
     break;
    }
   }
   if(a==0)
   {
    for(int i=0;i<=count;i++)
    {
     if(sum.num[i]<obj.num[i])
     {
      sum.num[i]+=10;
      sum.num[i+1]-=1;
     }
     sum.num[i]-=obj.num[i];
    }
   }
   else
   {
    for(int i=0;i<=count_obj;i++)
    {
     if(obj.num[i]<sum.num[i])
     {
      obj.num[i]+=10;
      obj.num[i+1]-=1;
     }
     sum.num[i]=obj.num[i]-sum.num[i];
    }
    if(sum.sign=='+')
     sum.sign='-';
    else
     sum.sign='+';
   }
  }
  else
  {  
   for(int i=0;i<=count_obj;i++)
   {
    if(obj.num[i]<sum.num[i])
    {
     obj.num[i]+=10;
     obj.num[i+1]-=1;
    }
    sum.num[i]=obj.num[i]-sum.num[i];
   }
   if(sum.sign=='+')
    sum.sign='-';
   else
    sum.sign='+';
  }
 }
 return sum;
} 

const HugeInt &HugeInt::operator=(const HugeInt &obj)
{
 for(int i=0;i<100;i++)
  num[i]=obj.num[i];
 sign=obj.sign;
 return *this;
}
