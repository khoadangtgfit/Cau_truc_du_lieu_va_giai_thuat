#include<iostream>
using namespace std;
void push(int a[],int &n,int x)
{
    a[n]=x;
    n++;
}
int pop(int a[],int &n)
{
    if(n==0)
        return -1;
    int x = a[n-1];
    n--;
    return x;
}
void popall(int a[],int &n)
{
    while (n>0)
    {
        int x=pop(a,n);
        cout<<x<<endl;
    }
}
void Enqueue(int a[],int &n,int x)
{
    a[n]=x;
    n++;
}
int Dequeue(int a[],int &n)
{
    if(n==0)
        return -1;
    int x=a[0];
    for(int i=0;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    return x;
}
void DequeueALL(int a[],int &n)
{
    while (n>0)
    {
        int x=Dequeue(a,n);
        cout<<x<<endl;
    }
}
void ChuyenDoi(int a[],int &n,int t)
{
    while (t>0)
    {
        int b=t%2;
        push(a,n,b);
        int t=t/2;
    }
    
}
int main()
{
    int a[100];
    int n=0;
    cout<<"STACK:"<<endl;
    push(a,n,17);
    push(a,n,23);
    push(a,n,97);
    push(a,n,44);
    // ChuyenDoi(a,n,20);
    popall(a,n);
    popall(a,n);
    // cout<<"\nQUEUE"<<endl;
    // Enqueue(a,n,17);
    // Enqueue(a,n,23);
    // Enqueue(a,n,97);
    // Enqueue(a,n,44);
    // DequeueALL(a,n);
}