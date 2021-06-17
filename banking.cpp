#include <iostream>
#include<string>

using namespace std;

class Account

{
    private:
    string acc_holder_name;
    
    long int  phone;
public:
   void get_account_info()
   {
       cout<<"\n\nEnter Account holder name :- ";
       cin.ignore();
       getline(cin,acc_holder_name);
       cout<<"Enter phone number :- ";
       cin>>phone;
   }
   void display_account_info()
   {
       cout<<"\n\nCustomer Name :- "<<acc_holder_name;
       cout<<"\n Phone number :- "<<phone;

   }
};

class current_acct : public Account
{
  static double balance;
  public:
    void disp_current_bal()
    {
      cout<<"\nBalance :- "<<balance;
    }
    void deposit_current_bal()
    {
      double deposit;
      cout<<"\nEnter amount to Deposit :- ";
      cin>>deposit;
      balance = balance + deposit;
    }
    void withdraw_current_bal()
    {
      double penalty,withdraw;
      cout<<"\n\nBalance :- "<<balance;
      cout<<"\nEnter amount to be withdraw :-";
      cin>>withdraw;
      balance=balance-withdraw;
      if(balance < 500)
      {
      penalty=(500-balance)/10;
      balance=balance-penalty;
      cout<<"\nBalance after deducting penalty : "<<balance;
      }
      else if(withdraw > balance)
      {
      cout<<"\n Insufficient balance\n";
      balance=balance+withdraw;
      }
    else
      cout<<"\nAfter Withdrawl your Balance : "<<balance;
     }
};
double current_acct::balance=0;

class savings_acct : public Account
{
static double savings_bal;
  public:
     void disp_savings_bal()
    {
      cout<<"\nBalance :- "<<savings_bal;
    }
    void deposit_savings_bal()
    {
      float deposit,interest;
      cout<<"\nEnter amount to Deposit :- ";
      cin>>deposit;
      savings_bal = savings_bal + deposit;
      interest=(savings_bal*2)/100;
      savings_bal=savings_bal+interest;
    }
    void withdraw_savings_bal()
    {
      float withdraw;
      cout<<"\nBalance :- "<<savings_bal;
      cout<<"\nEnter amount to be withdraw :-";
      cin>>withdraw;
      savings_bal-=withdraw;
      if(withdraw > savings_bal)
      {
      cout<<"\n\n Insufficient balance \n";
      savings_bal+=withdraw;
      }

        else
      cout<<"\nAfter Withdrawl your Balance : "<<savings_bal;

     }
};
double savings_acct::savings_bal=0;

int main(){
  current_acct c[3];
  savings_acct s[3];
  int sa=0,cu=0;
  Q:
  cout<<"\n BANK MANAGEMENT SYSTEM \n WELCOME"<<endl;
  cout<<"Menu: \n 1. New Customer \n 2. Existing Customer \n 3.exit"<<endl;
  cout<<"Enter The Choice:";
  int choice1;
  cin>>choice1;
  if (choice1==1)
  {
    cout<<"\n Choose Account Type: \n 1.savings \n 2.current \n Enter your Choice:";
    int choice2;
    cin>>choice2;
    if(choice2==1)
    {
      if(sa<3)
      {
        s[sa].get_account_info();
        s[sa].deposit_savings_bal();
        cout<<"\n Savings Account created Successfully Account number:"<<sa+1<<endl;
        sa++;
        goto Q;
      }
      else
      {
        cout<<"Max number of accounts reached:";
        goto Q;
      }


    }
    else
    {
      if(cu<3)
      {
        c[cu].get_account_info();
        c[cu].deposit_current_bal() ;
        cout<<"Current Account created Successfully Account number:"<<cu+1<<endl;
        cu++;
        goto Q;
      }
      else
      {
        cout<<"Max number of accounts reached:";
        goto Q;
      }

    }
      }

  
  else if(choice1==2)
  {
    cout<<"\n Choose Account Type: \n 1.savings \n 2.current \n Enter your Choice:";
    int choice3,acct;
    cin>>choice3;
    if(choice3==1)
    {
      cout<<"\n Enter Account number: ";
      cin>>acct;
      if(acct<=3 && acct>0)
      {
        while(1)
        {
          cout<<"\n Menu \n 1.To deposit an amount \n 2.To withdraw an amount \n 3.To display balance \n 4.To display with full details \n 5.Exit \n Enter your choice \n";
          int choice4;
          cin>>choice4;
     switch(choice4)
      {
       case 1 : s[acct-1].deposit_savings_bal();

            break;
       case 2 : s[acct-1].withdraw_savings_bal();

            break;
       case 3 : s[acct-1].disp_savings_bal();

            break;
       case 4 : s[acct-1].display_account_info();
                s[acct-1].disp_savings_bal();
                break;
       case 5: goto Q;

            break;

        default:cout<<"Invalid Choice"<<endl;
      }

        }
    
  
    }
    else
      cout<<"\n Invalid account";

      

    }
    else if(choice3==2)
    {
      cout<<"\n Enter Account number: ";
      cin>>acct;
      if(acct<=3 && acct>0)
      {
        while(1)
        {
          cout<<"\n Menu \n 1.To deposit an amount \n 2.To withdraw an amount \n 3.To display balance \n 4.To display with full details \n 5.Exit \n Enter your choice \n";
          int choice4;
          cin>>choice4;
     switch(choice4)
      {
       case 1 : c[acct-1].deposit_current_bal();

            break;
       case 2 : c[acct-1].withdraw_current_bal();

            break;
       case 3 : c[acct-1].disp_current_bal();

            break;
       case 4 : c[acct-1].display_account_info();
                c[acct-1].disp_current_bal();
                break;
       case 5: goto Q;

            break;

        default:cout<<"Invalid Choice"<<endl;
      }

        }
    
  
    }
    else
      cout<<"\n Invalid account";

    }

  }
  return 0;

}
