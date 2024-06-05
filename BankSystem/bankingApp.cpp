#include<iostream>
#include <vector>
#include "clint.cpp"
#include "bankAccount.cpp"
#include "savingBankAccount.cpp"

using namespace std;
int bankAccount::id = 20230000;
class bankingApp
{
    int counterAccounts = 0;
    vector <bankAccount> accounts;
public:
    int choice;
    int choice1;
    bankingApp()
    {
    }
    int getCounterAccounts(){
        return this->counterAccounts;
    }
    void app()
    {
        cout<<"Welcome to CIB Banking Application\n"<<
            "1. Create a New Account\n"<<
            "2. List Clients and Accounts\n"<<
            "3. Withdraw Money\n"<<
            "4. Deposit Money\n"<<
            "0. Exit App \n"<<
            "Please Enter Your Choice ";
        bool b=1;
        while (b)
        {
            cin>>choice ;
            switch (choice)
            {
            case 0:
                b=0;
                cout<<"Thank You For Usig CIB \n";
                break;
            case 1:
                 creatAccount();
                break;
            case 2:
                 listAccounts();
                break;
            case 3:
                 withdrawMoney();
                break;
            case 4:
                 depositMoney();
                break;
            default:
                cout<<"Please Enter Your Choice Again \n";
                cout<<"Welcome to FCAI Banking Application\n"<<
                    "1. Create a New Account\n"<<
                    "2. List Clients and Accounts\n"<<
                    "3. Withdraw Money\n"<<
                    "4. Deposit Money\n"<<
                    "0. Exit App";
                break;
            }
        }
    }
    void creatAccount()

    {
        string n,p,d;
        float balance;
        float balance1;
        //cout<<"Please Enter Choice =========> " ;
        //cin>>choice;
        cout<<"Please Enter Client Name =========> ";
        cin>>n;
        cout<<"Please Enter Client phone =========> ";
        cin>>p;
        cout<<"Please Enter Client address =========> ";
        cin>>d;
        client newClient = client(n,p,d);
        cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
        cin>>choice1;
        while(choice1 !=1 && choice1 != 2)
            {
                cout<<"Please Re Enter Account Type ";
                cin>>choice1;
            }
        cout<<"Please Enter the Starting Balance =========> ";
        cin>>balance;
        if(choice1==1)
        {
            bankAccount::id++;
            bankAccount newAccount = bankAccount(balance);
            newAccount.setID(bankAccount::id);
            newAccount.setClient(newClient);
            cout<<"An account was created with ID " << newAccount.getID() << " and Starting Balance " <<newAccount.getBalance() <<" L.E. ";
            accounts.push_back(newAccount),counterAccounts++;
            cout<<"Welcome to CIB Banking Application\n"<<
            "1. Create a New Account\n"<<
            "2. List Clients and Accounts\n"<<
            "3. Withdraw Money\n"<<
            "4. Deposit Money\n"<<
            "0. Exit App \n"<<
            "Please Enter Your Choice ";
        }
        else if(choice1==2)
        {
            bankAccount::id++;
            float minmumBalance = 1000;
            cout<<"Please Enter Minmum Balance ";
            cin>>minmumBalance;
            savingBankAccount newSavingAccount =savingBankAccount(minmumBalance,balance,"(Saving)");
            newSavingAccount.setID(bankAccount::id);
            newSavingAccount.setClient(newClient);
            cout<<"An account was created with ID "<< newSavingAccount.getID() <<" , Starting Balance " <<newSavingAccount.getBalance() <<" L.E. and minimum Balance "<<newSavingAccount.getMinimummBalance();
            accounts.push_back(newSavingAccount),counterAccounts++;
           cout<<"Welcome to CIB Banking Application\n"<<
            "1. Create a New Account\n"<<
            "2. List Clients and Accounts\n"<<
            "3. Withdraw Money\n"<<
            "4. Deposit Money\n"<<
            "0. Exit App \n"<<
            "Please Enter Your Choice "; 
        }
    }
    void listAccounts()
    {
        int i=0;
        while (counterAccounts>i)
        {
            cout<<"----------------------------"<<accounts[i].getClient().getName()<<"---------\n"
            <<"Address: "<<accounts[i].getClient().getAddress()<<"., Phone: "<<accounts[i].getClient().getPhNum()<<'\n'
            <<"Account Id: "<<accounts[i].getID()<<"  ";
                cout<<accounts[i].type<<'\n';
            cout<<"Balance: "<<accounts[i].getBalance()<<'\n';
            i++;
        }
        
        

    }
    void withdrawMoney()
    {
        int i=0;
        while (counterAccounts>i)
        {
            int id1;
            bool r=0;
            cout<<"Please Enter Account ID ";
            bool t=1;
            while (!r)
            {
                while (t)
                {
                    int id2;
                    cin>>id1;
                    t=0;   
                }
                if(id1==accounts[i].getID())
                {
                    r=1;
                    cout<<"Account ID: "<<accounts[i].getID();
                    cout<<"\nAccount Type: "<<accounts[i].getType()
                    <<" Balance: "<<accounts[i].getBalance()<<
                    "\nPlease Enter The Amount To withdraw =========>  ";
                    float amount;
                    bool b = 0;
                    while (!b)
                    {
                        cin>>amount;
                        if (amount < 0)
                            cout << "Sorry. This is more than what you can withdraw."<<'\n'<<"Please Enter The Amount To withdraw =========>  ";
                        else if (amount > accounts[i].getBalance())
                            cout << "Sorry. This is more than what you can withdraw."<<'\n'<<"Please Enter The Amount To withdraw =========>  ";
                        else
                        {
                            accounts[i].setBalance(accounts[i].getBalance()-amount),b=1;
                            cout<<"Thank you.\n"<<"Account ID: "<<accounts[i].getID()<<
                            "\nNew Balance: "<<accounts[i].getBalance();
                            cout<<"\n------------------------------------------------------------------\n";
                            i++;
                        }
                    }
                    
                }
                else 
                    r=0,i++;
            }
            
            
        }
        
        
    }
    void depositMoney()
    {
      int i=0;
        while (counterAccounts>i)
        {
            int id1;
            bool r=0;
            cout<<"Please Enter Account ID ";
            bool t=1;
            while (!r)
            {
                while (t)
                {
                    int id2;
                    cin>>id1;
                    t=0;   
                }
                if(id1==accounts[i].getID())
                {
                    r=1;
                    cout<<"Account ID: "<<accounts[i].getID();
                    cout<<"\nAccount Type: "<<accounts[i].getType()
                    <<" Balance: "<<accounts[i].getBalance()<<
                    "\nPlease Enter The Amount To Deposit =========>  ";
                    float amount;
                    bool b = 0;
                    while (!b)
                    {
                        cin>>amount;
                        if (amount < 0)
                            cout << "Sorry. This is more than what you can withdraw."<<'\n'<<"Please Enter The Amount To withdraw =========>  ";
                        else
                        {
                            accounts[i].setBalance(accounts[i].getBalance()+amount),b=1;
                            cout<<"Thank you.\n"<<"Account ID: "<<accounts[i].getID()<<
                            "\nNew Balance: "<<accounts[i].getBalance();
                            cout<<"------------------------------------------------------------------\n";
                            i++;
                        }
                    }
                    
                }
                else 
                    r=0,i++;
            }
            
            
        }  
    }

};
