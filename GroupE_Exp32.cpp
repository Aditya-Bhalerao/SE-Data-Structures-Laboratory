// Pizza parlor accepting maximum M orders. Orders are served in first come first served
// basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
// using circular queue using array.

#include <iostream>

using namespace std;
#define size 11
class pizza
{
    int porder[size];
    int front,rear;
public:
    pizza()
    {
        front=rear=-1;
    }
    int qfull()
    {
        if((front==0)&&(rear==(size-1))||(front==(rear+1)%size))
            return 1;
        else
            return 0;
    }
    int qempty()
    {
        if(front==-1)
            return 1;
        else
            return 0;
    }
    void accept_order(int);
    void make_payment(int);
    void order_in_queue();
};
void pizza::accept_order(int item)
{
    if(qfull())
        cout<<"\nNo more orders for today.\n";
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%size;
        }
        porder[rear]=item;
    }
}

void pizza::make_payment(int n)
{
    int item;
    char ans;
    if(qempty())
        cout<<"\nSorry !!! order not recieved yet...\n";
    else
    {
        cout<<"\nDelivered orders as follows...\n";
        for(int i=0; i<n; i++)
        {
            item=porder[front];
            if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front=(front+1)%size;
            }
            cout<<"\t"<<item;
        }
        cout<<"\nTotal amount to pay: Rs. "<<n*100;
        cout<<"\nThank you\n";
    }
}

void pizza::order_in_queue()
{
    int temp;
    if(qempty())
    {
        cout<<"\nThere are no pending orders...\n";
    }
    else
    {
        temp=front;
        cout<<"\nPending Order as follows...\n";
        while(temp!=rear)
        {
            cout<<"\t"<<porder[temp];
            temp=(temp+1)%size;
        }
        cout<<"\t"<<porder[temp];
    }
}
int main()
{
    pizza p1;
    int ch,k,n;
    do
    {
        cout<<"\n\t***** Welcome To Pizza Parlor *******\n";
        cout << "\n1.Accept order\n2.Make_payment\n3.Pending Orders\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nPizza menu\n";
            cout<<"\n1.Veg Pizza\n2.Veg cheese Pizza\n3.Veg Extravaganza Pizza";
            cout<<"\nPlease enter your order: ";
            cin>>k;
            p1.accept_order(k);
            break;
        case 2:
            cout<<"\nEnter Quantity(1-10): ";
            cin>>n;
            p1.make_payment(n);
            break;
        case 3:
            cout<<"\nFollowing orders are in queue to deliver\n";
            p1.order_in_queue();
            break;
        }
    }
    while(ch!=4);

    return 0;
}
