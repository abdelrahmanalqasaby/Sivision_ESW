#include <iostream>

using namespace std;

class Member
{
    private:
    string firstName;
    string LastName;
    int age;
public:
    Member():firstName(""),LastName(""),age(0)
    {
    }
    virtual void getData()
    {
        cout<<"insert first name \n";
        cin>>firstName;
        cout<<"\ninsert Last name \n";
        cin>>LastName;
        cout<<"\ninsert age\n";
        cin>>age;
    }
    virtual void putData()
    {
        cout<< "\nFirst name:"<<firstName<<"\nLast name:"<<LastName<<"\n Age:"<<age;
    }
};
class Professor :public Member
{
private:
    int publications;
    int cur_id;

public:
    Professor() : publications(0),cur_id(0)
    {
    }
    void getData() // insert the data
    {
        Member::getData();
        cout<<"insert number of Publications\n";
        cin>>publications;
        cout<<"\ninsert current ID\n";
        cin>>cur_id;
    }
    void putData() // print the data
    {
        Member::putData();
        cout<< "\nnumber of Publications:"<<publications<<"\ncurrent ID:"<<cur_id<<endl;

    }

};

class Assistant :public Member
{
private:
    string Department;
    string researchName;

public:
    Assistant() :Department(""),researchName("")
    {
    }
    void getData() // insert the data
    {
        Member::getData();
        cout<<"insert the Department\n";
        cin>>Department;
        cout<<"\ninsert Research Name\n";
        cin>>researchName;

    }
    void putData() // print the data
    {
        Member::putData();
        cout<< "\nthe Department:"<<Department<<"\nResearch Name:"<<researchName<<endl;

    }

};

class College
{
private:
    Member **Array;
    int Size;
    int empty_loc;

public:
    College(const int size_A) :Array(new Member*[size_A]),Size(size_A),empty_loc(0)
    {

    }
    void addStuffMember(Member *element)
    {
        if (empty_loc==Size)
        {
            return;
        }
        Array[empty_loc]=element;
        empty_loc++;
    }
    void getData()
    {
        for (int i=0;i<empty_loc;i++)
        {
            Array[i]->getData();
        }
    }
    void putData()
    {
        for (int i=0;i<empty_loc;i++)
        {
            Array[i]->putData();
        }
    }

};


int main()
{
    College college(20);
    Professor* professor_1 = new Professor(); //Create a professor object
    Assistant* assistant_1 = new Assistant(); // Create an assistant object.
    college.addStuffMember(professor_1 );
    college.addStuffMember(assistant_1 );
    college.getData();
    college.putData();
    delete professor_1 ;
    delete assistant_1 ;




    return 0;

}
