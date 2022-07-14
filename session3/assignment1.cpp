#include <iostream>


using namespace std;

class Child
{
private:
    int num;
public:
    //friend class MyQueue;
    Child(int number =0):num(number)
    {
    }
    int getNum()
    {
        return num;
    }
    void setNum(int N)
    {
        num=N;
    }
    bool operator !=(const Child& other)
    {
       return num!=other.num;
    }
    int operator *=(const int Number)
    {
       return num*=Number;
    }
    int operator +=(const int Number)
    {
       return num+=Number;
    }
    Child& operator +=(Child& s)
    {
        num+=s.getNum();
        return *this;

    }
    friend ostream & operator << (ostream &out, const Child &c)
    {
        out <<c.num<<" ,";
        //cout<<endl;
        return out;
    }

};


class MyQueue
{
private:
    Child *arr;
    int size_arr;
    int index;

public:
    MyQueue(const int size_A) :arr(new Child[size_A]),size_arr(size_A),index(0)
    {

    }
    int getSize()
    {
        return size_arr;
    }
    MyQueue& operator<<(int Number)
    {
        arr[index].setNum(Number);
        index++;
        return *this;
    }
    MyQueue& operator<<(const Child &s)
    {
        arr[index]=s;
        index++;
        return *this;
    }
    MyQueue& operator<<(const MyQueue &c )
    {
        size_arr+=c.size_arr;
        for (int i=0;i<c.index;i++)
        {
            arr[index].setNum(c.arr[i].getNum());
            index++;
        }

        return *this;
    }

    MyQueue& operator=(const MyQueue &c )
    {
        MyQueue Q(c.size_arr);
        for (int i=0;i<c.index;i++)
        {
            arr[index].setNum(c.arr[i].getNum());
            index++;
        }
        return Q;
    }

    Child& operator[](int NDEX)
    {
        return arr[NDEX];
    }

    bool operator==(const MyQueue &c)
    {
        bool ret;
        if (size_arr==c.size_arr)
        {
            ret=true;
        }
        else
        {
            ret=false;
        }
        return ret;
    }
    
    ~MyQueue()
    {
        delete[] arr;
    }

    friend ostream & operator << (ostream &out, const MyQueue &c)
    {
        for (int i=0;i<c.index;i++)
        {
           out <<c.arr[i].Child::getNum()<<" ,";
        }
        cout<<endl;
        return out;
    }


};

int main ()
{
    MyQueue q0(20);
    q0 <<1<< Child() << Child(2) << Child(3);
    cout << q0;

    MyQueue q1(3);
    q1 << 30 << 20 << 50;
    q1 << q0; // Appending two queues
    cout << q1;
    MyQueue q4=q1;
    cout<<q4;
    MyQueue q2(q0); // 1, 0, 2, 3
    q2 == q0 ? cout<<"equal\n": cout<<"not equal\n"; // equal // 1, 0, 2, 3
    cout<<q2;

    MyQueue q3(q0.getSize());
    q3<<1<< Child(2) << Child(7);
    q3[2] += q1[1];
    cout<<q3;
    cout<<q3[2];




    return 0;

}
