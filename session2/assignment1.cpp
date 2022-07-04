#include<iostream>
#include<string>
#include<map>
using namespace std;

class Account
{
private:
    std::string firstName;
    std::string lastName;
    int accountNum;
    int balance;

public:
    friend class Bank;
    static int nextAccountNum;

    friend ostream & operator << (ostream &out, const Account &c);

    Account(std::string s="mohamed",std::string v="alqasaby",int bal=0):firstName(s),lastName(v),balance(bal)
    {
        accountNum=nextAccountNum;
        nextAccountNum++;
    }
    void Deposit(float amount)
    {
        (*this).balance+=amount;
    }
    void withdraw(float amount)
    {
        (*this).balance-=amount;
    }
    int getAccountNumber()
    {
        return (*this).accountNum;
    }


};

class Bank
{
private:
    map<int ,Account> DB_bank;
public:
    static Bank& creatObject() //singleton object
    {
        static Bank object;
        return object;
    }

    Bank()
    {
    }
    void OpenAccount(std::string firstname, std::string lastname, float balance)
    {
        Account object(firstname,lastname,balance);
        cout<<"your Account Number is : "<<object.getAccountNumber()<<"\nyou should remember it";
        DB_bank.insert(pair<int ,Account>(object.accountNum,object));


    }

    int BalanceEnquiry(long accountNumber)
    {
        return DB_bank[accountNumber].balance;

    }

    void Deposit(long accountNumber, float amount)
    {
        DB_bank[accountNumber].Deposit(amount);
    }

    void Withdraw(long accountNumber, float amount)
    {
        DB_bank[accountNumber].withdraw(amount);
    }

    void CloseAccount(long accountNumber)
    {
        DB_bank.erase(accountNumber);
    }





};

int Account::nextAccountNum=0;
ostream & operator << (ostream &out, const Account &c)
    {
        out << c.firstName<<" "<<c.lastName<<endl;
        out << c.accountNum << endl;
        out << c.balance<<endl;
        return out;
    }

enum user_transaction
{
    OPEN_ACCOUNT=1,
    BALANCE_ENQUIRY,
    DEPOSIT,
    WITHDRAW,
    CLOSE_ACCOUNT,
    QUIT
};
int main()
{
    int userTransaction;
    Bank &CIB=Bank::creatObject();
    cout<<"enter your transaction please"<<endl;
    do
    {
        cout<<"\npress \n1 to open account \n2 for Balance \n3 to Deposit \n4 to withdraw\n5 to close account \n6 to QUIT\n";
        cin>>userTransaction;
        if (userTransaction == OPEN_ACCOUNT)
        {
            cout<<"please enter your first name ,last name & balance\n";
            std::string first_name;
            std::string last_name;
            int balance;
            cin>>first_name>>last_name>>balance;
            CIB.OpenAccount(first_name,last_name,balance);


        }
        else if(userTransaction==BALANCE_ENQUIRY)
        {
            int accNum;
            cout<<"enter your account number\n";
            cin>>accNum;
            cout<<endl<<CIB.BalanceEnquiry(accNum);

        }
        else if (userTransaction==DEPOSIT)
        {
            int accNum,amount;
            cout<<"enter your account number & the amount\n";
            cin>>accNum>>amount;
            CIB.Deposit(accNum,amount);

        }

        else if (userTransaction==WITHDRAW)
        {
            int accNum,amount;
            cout<<"enter your account number & the amount\n";
            cin>>accNum>>amount;
            CIB.Withdraw(accNum,amount);

        }
        else if (userTransaction==CLOSE_ACCOUNT)
        {
            int accNum;
            cout<<"enter your account number\n";
            cin>>accNum;
            CIB.CloseAccount(accNum);
        }

    }while(userTransaction!=QUIT);

    /*CIB.OpenAccount("alq","qla",9000);
    int bal=CIB.BalanceEnquiry(0);
    cout<<"the balance for account 1="<<bal<<endl;
    CIB.Deposit(0,5000);
    cout<<"the balance for account 1="<<CIB.BalanceEnquiry(0)<<endl;*/
    return 0;
}
