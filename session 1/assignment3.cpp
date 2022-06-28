#include<iostream>
#include<string.h>

using namespace std;

class point
{
private:
int x_access; //number of rows for the matrix
int y_access; //number of columns for the matrix
friend class line;

public:
    point(int x,int y) // the default constructor rows & columns are 1
    {
        x_access=x;
        y_access=y;
    }

};

class line
{
private:
    float slope;
    float y_intersection;

public:
    line(point z,point q)
    {
        slope=(static_cast<float>((z.y_access-q.y_access))/(z.x_access-q.x_access));
        y_intersection=(z.y_access-static_cast<float>(slope*z.x_access));
    }
    line(line a,int number)
    {
        y_intersection=a.y_intersection+number;
        slope=a.slope;
    }
    void print()
    {
        cout<<"[y="<<slope<<"x+"<<y_intersection<<"]"<<endl;
    }
};



int main(void)
{

    point p1(7,12);
    point p2(5,13);


    line eq1(p1,p2);
    eq1.print();

    line eq2(eq1,30);
    eq2.print();


    return 0;
}
