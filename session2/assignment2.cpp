#include<iostream>
//#include "RationalNum.h"

using namespace std;

class RationalNum
{

private:
    int numerator;
    int denominator;
public:
    friend ostream & operator << (ostream &out, const RationalNum &c);
    RationalNum (int n=1,int d=1):numerator(n),denominator(d){}

    RationalNum operator+(RationalNum num2)
    {
        RationalNum Result;
        Result.denominator=denominator*num2.denominator;
        Result.numerator=(denominator*num2.numerator)+(num2.denominator*numerator);
        return Result;

    }
    RationalNum operator-(RationalNum num2)
    {
        RationalNum Result;
        Result.denominator=denominator*num2.denominator;
        Result.numerator=-(denominator*num2.numerator)+(num2.denominator*numerator);
        return Result;

    }
    RationalNum operator*(RationalNum num2)
    {
        RationalNum Result;
        Result.denominator=denominator*num2.denominator;
        Result.numerator=numerator*num2.numerator;
        return Result;

    }

    RationalNum operator*(int num2)
    {
        RationalNum num_2(num2,1);
        RationalNum Result;
        Result=(*this)*num_2;
        return Result;
    }

    RationalNum operator+(int num2)
    {
        RationalNum num_2(num2,1);
        RationalNum Result;
        Result=*this+num_2;
        return Result;
    }

    void operator--(int)
    {
        numerator-=denominator;

    }
    /*void print()
    {
        cout<<numerator<<"/"<<denominator<<endl;
    }*/
};
    ostream & operator << (ostream &out, const RationalNum &c)
    {
        out << c.numerator;
        out << "/" << c.denominator << endl;
        return out;
    }


int main()
{

    RationalNum number1(3,7);
    RationalNum number2(2,9);
    RationalNum number3=number1+5+10;
    cout<<number2;
    number2--;
    cout<<number2;

    //number3.print();
    RationalNum number4=RationalNum(10)*number3;
    //number4.print();
    cout<<number4;




    return 0;
}
