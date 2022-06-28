#include<iostream>
#include<string.h>

using namespace std;

class matrix_t
{
private:
int RowsNumber; //number of rows for the matrix
int ColumnNumbers; //number of columns for the matrix
int ** arr;


public:
    matrix_t() // the default constructor rows & columns are 1
    {
       RowsNumber=1;
       ColumnNumbers=1;
        arr = new int * [1] ; // allocate an array of 10 int pointers — these are our rows
       for (int count = 0; count < 1; count++)
       {
           arr[count] = new int[1]; // these are our columns
       }
       **arr=0;
    }

    matrix_t(int rows) // the parameterized constructor with only number of rows & columns is 1
    {
        RowsNumber=rows;
       ColumnNumbers=1;

        arr = new int*[rows] ; // allocate an array of 10 int pointers — these are our rows
       for (int count = 0; count < rows; count++)
       {
           arr[count] = new int[1]; // these are our columns
       }
       for (int c=0;c<rows;c++)
       {
           arr[c][ColumnNumbers]=0;
       }
    }

    matrix_t(int rows,int col)// the parameterized constructor with both number of rows & columns
    {
        RowsNumber=rows;
        ColumnNumbers=col;
        arr= new int*[rows] ; // allocate an array of 10 int pointers — these are our rows
       for (int counter2 = 0; counter2 < rows; counter2++)
       {
           arr[counter2] = new int[col]; // these are our columns
       }
       for (int r=0;r<rows;r++)
       {
           for (int c=0;c<col;c++)
           {
               arr[r][c]=0;
           }
           cout<<endl;
       }
    }

    matrix_t( const matrix_t& object)// the parameterized constructor coping an old matrix
    {
        RowsNumber=object.RowsNumber;
        ColumnNumbers=object.ColumnNumbers;
        arr= new int*[RowsNumber] ; // allocate an array of 10 int pointers — these are our rows
       for (int counter2 = 0; counter2 < RowsNumber; counter2++)
       {
           arr[counter2] = new int[ColumnNumbers]; // these are our columns
       }
        for (int r=0;r<RowsNumber;r++)
       {
           for (int c=0;c<ColumnNumbers;c++)
           {
               arr[r][c]=object.arr[r][c];
           }
        }
    }

     void getElement(int ro,int co)//the setter for the matrix
    {
        cout<<arr[ro][co]<<endl;
    }

    void setElement(int r,int c,int element) //the getter for the matrix
    {
        if ((r<RowsNumber)&&(c<ColumnNumbers))
        {
            arr[r][c]=element;
        }

    }

    void print()
    {
         for (int r=0;r<RowsNumber;r++)
       {
           for (int c=0;c<ColumnNumbers;c++)
           {
               cout<<*(*(arr+r)+c)<<" ";
           }
           cout<<endl;
       }
    }


    ~matrix_t()
    {
        for(int i=0;i<RowsNumber;i++)    //To delete the inner arrays
        {
            delete [] arr[i];
        }
        delete [] arr;

    }
};



int main(void)
{
   matrix_t obj;
   //cout<<endl<<"object print"<<endl;
   obj.print();
   matrix_t c(3);
   //cout<<endl<<"C print"<<endl;
   c.print();
   matrix_t m(3,3);
   //cout<<endl<<"m print"<<endl;
   m.print();
   m.setElement(0,0,4);
   m.setElement(0,1,5);
   m.setElement(1,0,6);
   m.setElement(1,1,7);
   m.print();
   matrix_t m1(m);
  // cout<<endl<<"the second array"<<endl;
   m1.print();



    return 0;
}
