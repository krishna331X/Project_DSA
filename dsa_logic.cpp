#include<iostream>
using namespace std;

struct Customer
{
    string name;
    string service;
};

class Queue
{
    Customer arr[10];
    int front;
    int rear;

public:

    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(Customer c)
    {
        if(rear == 9)
        {
            cout<<"Queue Full"<<endl;
            return;
        }

        if(front == -1)
        front = 0;

        rear++;
        arr[rear] = c;
    }

    Customer dequeue()
    {
        Customer temp;

        if(front == -1 || front > rear)
        {
            cout<<"Queue Empty"<<endl;
            return temp;
        }

        temp = arr[front];
        front++;

        return temp;
    }

    void display()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i].name<<" - "<<arr[i].service<<endl;
        }
    }
};

class Stack
{
    Customer arr[10];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    void push(Customer c)
    {
        if(top == 9)
        {
            cout<<"Stack Full"<<endl;
            return;
        }

        top++;
        arr[top] = c;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Empty"<<endl;
            return;
        }

        cout<<"Undo Service: "<<arr[top].name<<endl;
        top--;
    }

    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i].name<<" - "<<arr[i].service<<endl;
        }
    }
};

int main()
{
    Queue bookingQueue;
    Stack serviceHistory;

    Customer c1 = {"Riya","Gel Nails"};
    Customer c2 = {"Anita","Nail Art"};

    bookingQueue.enqueue(c1);
    bookingQueue.enqueue(c2);

    cout<<"Booking Queue:"<<endl;
    bookingQueue.display();

    Customer served = bookingQueue.dequeue();

    serviceHistory.push(served);

    cout<<"\nService History:"<<endl;
    serviceHistory.display();

    serviceHistory.pop();

    return 0;
}