#include<iostream>
using namespace std;
void Swap(int &a,int &b)
{
    int t=a; a=b; b=t;
}
void SelectionSort(int a[],int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i)
            Swap(a[i],a[min]);
    }
}
void Xuat(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
int main()
{
    int a[]={1,3,4,2,5};
    int n=5;
    SelectionSort(a,n);
    Xuat(a,n);
}