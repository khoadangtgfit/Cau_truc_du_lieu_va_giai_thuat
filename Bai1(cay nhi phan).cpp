#include<iostream>
using namespace std;
typedef struct node
{   int info;
    struct node* left;
    struct node* right;
}Node;
Node* CreateNode(int d)
{
    Node *p=new Node;
    if(p!=NULL)
    {
        p->info=d;
        p->left=NULL;
        p->right=NULL;
    }
    return p;
}
void CreateTree(Node* &proot,int a[],int begin,int end)
{
    if(begin>end)   return;
    int i=(begin+end)/2;
    proot=CreateNode(a[i]);
    CreateTree(proot->left,a,begin,i-1);
    CreateTree(proot->right,a,i+1,end);
}
void NLR(Node *proot)
{
    if(proot!=NULL){
    cout<<"\t"<<proot->info;
    NLR(proot->left);
    NLR(proot->right);
}
}
void LNR(Node *proot)
{
    if(proot!=NULL){
    NLR(proot->left);
    cout<<"\t"<<proot->info;
    NLR(proot->right);
}
}
void LRN(Node *proot)
{
    if(proot!=NULL){
    NLR(proot->left);
    cout<<"\t"<<proot->info;
    NLR(proot->right);
}
}
int dem(Node *proot)
{
    if(proot==NULL)
        return 0;
    return dem(proot->left)+dem(proot->right)+1;

}
int demnutla(Node *proot)
{
    if(proot!=NULL)
    {
        if(proot->left==NULL&&proot->right==NULL)
        {
            return 1;
        }
        else
        {
            return demnutla(proot->left)+demnutla(proot->right);
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    int a[]={1,4,5,6,7,3,8,2};
    int n=8;
    Node* proot;
    CreateTree(proot,a,0,n-1);
    cout<<"\nXuat NLR:"<<endl;
    NLR(proot);
    cout<<"\nXuat LNR:"<<endl;
    LNR(proot);
    cout<<"\nXuat LRN:"<<endl;
    LRN(proot);
    cout<<"\nDem="<<dem(proot);
    cout<<"\nDem la="<<demnutla(proot);
    return 0;
}
