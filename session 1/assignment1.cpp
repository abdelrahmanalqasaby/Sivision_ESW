#include<iostream>
#include<string.h>

using namespace std;

class complex_t
{
private:
int real;//Real number
int img;// imaginary number


public:
    complex_t()  // the default constructor
    {
       real=0;
       img=0;
    }
    complex_t(int realNumber) // the parameterized constructor with only the real part & the img is 0
    {
        real=realNumber;
        img=0;
    }
    complex_t(int realNumber,int imgNumber) // the second parameterized constructor with both real & img
    {
        real=realNumber;
        img=imgNumber;
    }
    void set() //the setter for the complex number
    {
        cout<<"enter real part ";
        cin>>real;
        cout<<"enter imaginary part ";
        cin>>img;
    }
    void get() //the getter for the complex number
    {
        cout<< "the complex number is "<<real <<" + "<<img<<"i"<<endl;
    }

    complex_t add(const complex_t object) // add function
    {
        complex_t result;
        result.real =real+ object.real;
        result.img =img+ object.img;
        return result;

    }

    complex_t sub(const complex_t object) // sub function
    {
        complex_t result;
        result.real =-real+ object.real;
        result.img =-img+object.img;
        return result;

    }

    complex_t multiply(const complex_t object) // multiply function
    {
        complex_t result;
        result.real =(real*object.real)-(img*object.img);
        result.img =(real*object.img)+(img*object.real);
        return result;

    }

    void print()
    {
        if (img>=0)
        {
            cout<<endl<< real<<"+"<<img<<"i"<<endl;

        }
        else
        {
            cout<<endl<< real<<img<<"i"<<endl;

        }

    }

};



int main(void)
{
    complex_t object;
    complex_t c1(10,6);
    complex_t c2(8,7);
    complex_t c5=c2.add(c1);
    c5.print();
    complex_t c6=c2.sub(c1);
    c6.print();
    complex_t c7=c2.multiply(c1);
    c7.print();




    return 0;
}
