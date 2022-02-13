#include<iostream>
using namespace std;
int BinarySearch(int a[],int n,int x)
{
    int left=0,right=n-1,mid;
    do
    {
        mid=(right+left)/2;
        if(x==a[mid])
            return mid;
        else if(x<a[mid])
            right=mid-1;
        else 
            left=mid+1;

    } while (left<=right);
    return -1;
    
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8},n=8;
    int k=BinarySearch(a,n,4);
    if(k==-1)
        cout<<"\nKhong tim thay gia tri !";
    else
    {
        cout<<"\nTim thay gia tri o vi tri "<<k;
    }
    
}