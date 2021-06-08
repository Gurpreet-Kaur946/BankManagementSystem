#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Bank
{
    int total;
    string id;
    struct person
    {
        string name, Id, Address;
        int ContactNo, cash;
    }person[100];

public:
    Bank()
    {
        total=0;
    }
    void menu();
    void newAcc();
    void DisplayDet();
    void updateInfo();
    void Search();
    void transactions();
    void removeAcc();
};

int main()
{
    Bank bObj;
    bObj.menu();
    return 0;
}
void Bank::menu()
{
    char ch;
    do
    {
        cout<<"\n******MENU******";
        cout<<"\n1. Create a new account";
        cout<<"\n2. Display details of customers";
        cout<<"\n3. Update details of existing customer";
        cout<<"\n4. Check details of existing customer";
        cout<<"\n5. Perform transactions";
        cout<<"\n6. Delete existing account";
        cout<<"\n7. Exit\n";
        ch=getch();
        switch(ch){
        case '1':
            Bank::newAcc();
            break;
        case '2':
            Bank::DisplayDet();
            break;
        case '3':
            Bank::updateInfo();
            break;
        case '4':
            Bank::Search();
            break;
        case '5':
            Bank::transactions();
            break;
        case '6':
            Bank::removeAcc();
            break;
        case '7':
            exit(0);
            break;
        default:
            cout<<"\nInvalid Input";
        }
    }while(ch!=7);
}

void Bank::newAcc()
{
        cout<<"\nEnter details of customer:"<<total+1;
        cout<<"\nEnter name:";
        cin>>person[total].name;
        cout<<"\nEnter customer ID:";
        cin>>person[total].Id;
        cout<<"\nEnter address of the customer:";
        cin>>person[total].Address;
        cout<<"\nEnter contact no:";
        cin>>person[total].ContactNo;
        cout<<"\nTotal cash amount:";
        cin>>person[total].cash;
        total++;
}
void Bank::DisplayDet()
{
    for(int i=0; i<total; i++)
    {
        cout<<"\nDetails of the customer"<<i+1;
        cout<<"\nName:"<<person[i].name;
        cout<<"\nId:"<<person[i].Id;
        cout<<"\nAddress:"<<person[i].Address;
        cout<<"\nContact No:"<<person[i].ContactNo;
        cout<<"\nCash"<<person[i].cash;
    }
}
void Bank::updateInfo()
{
    cout<<"\nEnter ID of the customer you want to update the details:";
    cin>>id;
    for(int i=0;i<total;i++)
    {
        if(id==person[i].Id)
        {
            cout<<"\nPrevious details of the customer:";
            cout<<"\nName:"<<person[i].name;
            cout<<"\nId:"<<person[i].Id;
            cout<<"\nAddress:"<<person[i].Address;
            cout<<"\nContact No:"<<person[i].ContactNo;
            cout<<"\nCash"<<person[i].cash;
            cout<<"\nEnter new details of the customer";
            cout<<"\nEnter name:";
            cin>>person[i].name;
            cout<<"\nEnter customer ID:";
            cin>>person[i].Id;
            cout<<"\nEnter address of the customer";
            cin>>person[i].Address;
            cout<<"\nEnter contact no:";
            cin>>person[i].ContactNo;
            cout<<"\nTotal cash amount";
            cin>>person[i].cash;
            break;
        }
        if(i==total-1)
         {
             cout<<"\nNo such record found";
         }
    }
}
void Bank::Search()
{
    cout<<"\nEnter ID of the customer you want to search the details:";
    cin>>id;
    for(int i=0;i<total;i++)
    {
         if(id==person[i].Id)
         {
            cout<<"\nDetails of the customer"<<i+1;
            cout<<"\nName:"<<person[i].name;
            cout<<"\nId:"<<person[i].Id;
            cout<<"\nAddress:"<<person[i].Address;
            cout<<"\nContact No:"<<person[i].ContactNo;
            cout<<"\nCash"<<person[i].cash;
            break;
         }
         if(i==total-1)
         {
             cout<<"\nNo such record found";
         }
    }
}
void Bank::transactions()
{
    char ch;
    int cash;
    cout<<"\nEnter the customer ID:";
    cin>>id;
    for(int i=0;i<total;i++)
    {
         if(id==person[i].Id)
         {
            cout<<"\nName:"<<person[i].name;
            cout<<"\nAddress:"<<person[i].Address;
            cout<<"\nContact No:"<<person[i].ContactNo;
            cout<<"\nExisting cash amount:"<<person[i].cash;
            cout<<"\nPress 1 to deposit the cash";
            cout<<"\nPress 2 to withdraw the cash";
            ch=getch();
            switch(ch)
            {
            case '1':
                cout<<"\nEnter the amount you want to deposit";
                cin>>cash;
                person[i].cash=+cash;
                cout<<"\nAfter depositing, your new amount is:"<<person[i].cash;
                break;
            case '2':
                back:
                cout<<"\nEnter the amount you want to withdraw:";
                cin>>cash;
                if(cash>person[i].cash)
                {
                    cout<<"\nNot enough cash. You can't withdraw!\nCurrent cash available:"<<person[i].cash;
                    Sleep(3000);
                    goto back;
                }
                person[i].cash-=cash;
                cout<<"\nYour new amount is:"<<person[i].cash;
                break;
            default:
                cout<<"\nInvalid output!";
                break;
            }
            break;
         }
         if(i==total-1)
         {
             cout<<"\nNo such record found";
         }
    }
}
void Bank::removeAcc()
{
    char ch;
    cout<<"\nPress 1 to remove a specific record";
    cout<<"\nPress 2 to remove full record";
    ch=getch();
    switch(ch)
    {
    case '1':
        cout<<"\nEnter the id of the customer you want to delete the record:";
        cin>>id;
        for(int i=0;i<total;i++)
        {
            if(id==person[i].Id)
            {
                for(int j=i;j<total;j++)
                {
                    person[j].name=person[j+1].name;
                    person[j].Id=person[j+1].Id;
                    person[j].Address=person[j+1].Address;
                    person[j].Address=person[j+1].ContactNo;
                    person[j].cash=person[j+1].cash;
                    total--;
                    break;
                }
            }
            if(i==total-1)
             {
                 cout<<"\nNo such record found";
             }
        }
    break;
    case '2':
        total=0;
        cout<<"\nAll record is deleted";
    break;
    default:
        cout<<"\nInvalid output!";
        break;
    }
}
