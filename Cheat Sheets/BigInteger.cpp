#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigInteger
{
private:
    string Number;
public:
    BigInteger(){
        Number="0";
    }
    
    BigInteger(const int & Number);
    BigInteger(const string & Numeber);
    BigInteger(const BigInteger & Number);
    bool operator ==(const BigInteger & OtherNumber);
    bool operator > (const BigInteger & OtherNumber);
    bool operator >=(const BigInteger & OtherNumber);
    bool operator < (const BigInteger & OtherNumber);
    bool operator <=(const BigInteger & OtherNumber);
    bool operator !=(const BigInteger & OtherNumber);
    BigInteger operator = (const BigInteger & OtherNumber);
    BigInteger operator = (const int & OtherNumber);
    BigInteger operator + (const BigInteger & OtherNumber);
    BigInteger operator + (const int & OtherNumber);
    BigInteger operator - (const BigInteger & OtherNumber);
    BigInteger operator - (const int & OtherNumber);
    BigInteger operator * (const BigInteger & OtherNumber);
    BigInteger operator * (const int & OtherNumber);
    BigInteger operator / (const BigInteger & OtherNumber);
    BigInteger operator / (const int & OtherNumber);
    BigInteger operator +=(const BigInteger & OtherNumber);
    BigInteger operator +=(const int & OtherNumber);
    BigInteger operator -=(const BigInteger & OtherNumber);
    BigInteger operator -=(const int & OtherNumber);
    BigInteger operator *=(const BigInteger & OtherNumber);
    BigInteger operator *=(const int & OtherNumber);
    BigInteger operator /=(const BigInteger & OtherNumber);
    BigInteger operator /=(const int & OtherNumber);
    friend ostream & operator <<(ostream & out,const BigInteger & num);
    friend istream & operator >>(istream & in, BigInteger & num);
};

BigInteger::BigInteger(const int &Number)
{
    this->Number=to_string(Number);
}

BigInteger::BigInteger(const BigInteger &Number)
{
    this->Number=Number.Number;
}

BigInteger::BigInteger(const string& Numeber)
{
    this->Number=Numeber;

    while(this->Number[0]=='0')
        this->Number.erase(0,1);
    if(this->Number=="")
        this->Number="0";
}

bool BigInteger::operator ==(const BigInteger &OtherNumber)
{
    if(Number==OtherNumber.Number)
        return true;
    return false;
}

bool BigInteger::operator >(const BigInteger &OtherNumber)
{
    if(Number.size()>OtherNumber.Number.size())
        return true;
    else if(Number.size()<OtherNumber.Number.size())
        return false;
    for(int i=0;i<Number.size();i++)
    {
        if(Number[i]>OtherNumber.Number[i])
            return true;
        else if(Number[i]<OtherNumber.Number[i])
            return false;
    }
    return false;
}

bool BigInteger::operator >=(const BigInteger &OtherNumber)
{
    if(*this>OtherNumber || *this==OtherNumber)
        return true;
    return false;
}

bool BigInteger::operator <(const BigInteger &OtherNumber)
{
    if(Number.size()<OtherNumber.Number.size())
        return true;
    else if(Number.size()>OtherNumber.Number.size())
        return false;
    for(int i=0;i<Number.size();i++)
    {
        if(Number[i]<OtherNumber.Number[i])
            return true;
        else if(Number[i]>OtherNumber.Number[i])
            return false;
    }
    return false;
}

bool BigInteger::operator <=(const BigInteger &OtherNumber)
{
    if(*this<OtherNumber || *this==OtherNumber)
        return true;
    return false;
}

bool BigInteger::operator !=(const BigInteger &OtherNumber)
{
    if(Number!=OtherNumber.Number)
        return true;
    return false;
}

BigInteger BigInteger::operator =(const BigInteger OtherNumber)
{
    Number=OtherNumber.Number;
    return *this;
}

BigInteger BigInteger::operator =(const int OtherNumber)
{
    this->Number=to_string(OtherNumber);
    return *this;
}

BigInteger BigInteger::operator +(const BigInteger &OtherNumber)
{
    int a=0,b=0;
    string str1,str2;
    str1.resize(max(0,(int)(OtherNumber.Number.size()-Number.size()))+1,'0');
    str2.resize(max(0,(int)(Number.size()-OtherNumber.Number.size()))+1,'0');
    str1.resize((int)(str1.size()+10-(int)(Number.size()+str1.size())%5),'0');
    str2.resize((int)(str2.size()+10-(int)(OtherNumber.Number.size()+str2.size())%5),'0');
    str1+=Number;
    str2+=OtherNumber.Number;
    string result="";
    int cary=0;
    for(int i=0;i<str1.size()/5;i++)
    {

        int a=stoi(str1.substr(str1.size()-i*5-5,5));
        int b=stoi(str2.substr(str2.size()-i*5-5,5));
        int x=a+b+cary;
        string rx=to_string(x%100000);
        for(int i=rx.size();i<5;i++)
            rx="0"+rx;
        result=rx+result;
        cary=x/100000;
    }
    while(result[0]=='0')
        result.erase(0,1);
    return BigInteger(result);
}

BigInteger BigInteger::operator +(const int &OtherNumber)
{
    BigInteger oNumber(OtherNumber);
    return *this+oNumber;
}

BigInteger BigInteger::operator -(const BigInteger &OtherNumber)
{
    string sign="";
    string str1,str2;
    str1.resize(max(0,(int)(OtherNumber.Number.size()-Number.size()))+1,'0');
    str2.resize(max(0,(int)(Number.size()-OtherNumber.Number.size()))+1,'0');
    str1.resize((int)(str1.size()+10-(int)(Number.size()+str1.size())%5),'0');
    str2.resize((int)(str2.size()+10-(int)(OtherNumber.Number.size()+str2.size())%5),'0');
    str1+=Number;
    str2+=OtherNumber.Number;
    if(str1<str2)
    {
        string tmp=str1;
        str1=str2;
        str2=tmp;
        sign="-";
    }
    string result="";
    int cary=0;
    for(int i=0;i<str1.size()/5;i++)
    {
        int a=stoi(str1.substr(str1.size()-i*5-5,5));
        int b=stoi(str2.substr(str2.size()-i*5-5,5));
        a+=cary;
        if(a<b)
        {
            a+=100000;
            cary=-1;
        }
        else
            cary=0;
        int x=(a-b);
        if(x<0)
            x*=-1;
        string rx=to_string(x%100000);
        for(int i=rx.size();i<5;i++)
            rx="0"+rx;
        result=rx+result;
    }
    while(result[0]=='0')
        result.erase(0,1);
    result=sign+result;
    return BigInteger(result);
}

BigInteger BigInteger::operator -(const int &OtherNumber)
{
    BigInteger oNumber(OtherNumber);
    return *this-oNumber;
}

BigInteger BigInteger::operator *(const BigInteger &OtherNumber)
{

   BigInteger a=*this,b=OtherNumber,c(0), result(0);
   while(a>c)
   {
       BigInteger d=b,e(1);
       e.Number.resize(a.Number.size(),'0');
       d.Number.resize(b.Number.size()+a.Number.size(),'0');
       result+=d;
       a-=e;
   }
   result.Number.resize(result.Number.size()-1,'0');
   return result;
}

BigInteger BigInteger::operator *(const int &OtherNumber)
{
    BigInteger oNumber(OtherNumber);
    return *this*oNumber;
}

BigInteger BigInteger::operator /(const BigInteger &OtherNumber)
{
    BigInteger a=*this,b=OtherNumber, result(0);
    while(a>=b)
    {
        BigInteger c=b;
        BigInteger d=0;
        while(a>=c)
        {
            c.Number.resize(c.Number.size()+1,'0');
            d.Number.resize(d.Number.size()+1,'0');
        }
        c.Number.resize(c.Number.size()-1,'0');
        d.Number.resize(d.Number.size()-1,'0');
        d.Number[0]='1';
        result+=d;
        a-=c;
    }
    return result;

}

BigInteger BigInteger::operator /(const int &OtherNumber)
{
    BigInteger oNumber(OtherNumber);
    return *this/oNumber;
}

BigInteger BigInteger::operator +=(const BigInteger &OtherNumber)
{
    this->Number=(*this+OtherNumber).Number;
    return *this;
}

BigInteger BigInteger::operator +=(const int &OtherNumber)
{
    this->Number=(*this+OtherNumber).Number;
    return *this;
}

BigInteger BigInteger::operator -=(const BigInteger &OtherNumber)
{
    this->Number=(*this-OtherNumber).Number;
    return *this;
}

BigInteger BigInteger::operator -=(const int &OtherNumber)
{
    this->Number=(*this-OtherNumber).Number;
    return *this;
}

BigInteger BigInteger::operator *=(const BigInteger &OtherNumber)
{
    this->Number=(*this*OtherNumber).Number;
    return *this;
}

BigInteger BigInteger::operator *=(const int &OtherNumber)
{
    this->Number=(*this*OtherNumber).Number;
    return *this;
}

BigInteger BigInteger::operator /=(const BigInteger &OtherNumber)
{
    this->Number=(*this/OtherNumber).Number;
    return *this;
}

BigInteger BigInteger::operator /=(const int &OtherNumber)
{
    this->Number=(*this/OtherNumber).Number;
    return *this;
}

ostream & operator <<(ostream & out,const BigInteger & num)
{
    return out<<num.Number;
}

istream & operator >>(istream & in,BigInteger & num)
{
    return in>>num.Number;
}

int main()
{
    BigInteger a,b;
    string c;
    cin>>a>>c>>b;
    if(c=="+")
        cout<<a+b<<endl;
    if(c=="-")
        cout<<a-b<<endl;
    if(c=="*")
        cout<<a*b<<endl;
    if(c=="/")
        cout<<a/b<<endl;
}
