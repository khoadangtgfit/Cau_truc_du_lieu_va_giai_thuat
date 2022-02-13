#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *pright;
    Node *pleft;
};
typedef struct Node NODE;
typedef NODE* TREE;
void KhoiTaoCay(TREE &t)
{
    t=NULL;
}
void ThemVaoCay(TREE &t,int x)
{
    NODE *p=new NODE;
    if(t==NULL)
    {
        p->data=x;
        p->pright=NULL;
        p->pleft=NULL;
        t=p;
    }
    else
    {
        if(t->data>x)
            ThemVaoCay(t->pleft,x);
        else if(t->data<x)
        {
            ThemVaoCay(t->pright,x);
        }
        
    }
}
NODE *TimKiemNode(TREE t,int x)
{
    if(t==NULL)
        return NULL;
    else
    {
        if(x<t->data)
            TimKiemNode(t->pleft,x);
        else if(x>t->data)
            TimKiemNode(t->pright,x);
        else
        {
            return t;
        }
    }
    
}
void XoaNode(TREE &t,int x)
{
    if(t==NULL)
        return;
    else
    {
        if(t->data>x)
            XoaNode(t->pleft,x);
        else if(t->data<x)
            XoaNode(t->pright,x);
        else
        {
            NODE *X=t;
            if(t->pleft==NULL)
                t=t->pright;
            else if(t->pright=NULL)
                t=t->pleft;
            delete(X);
        }
        
    }
    
}
void XuatCay(TREE t)
{
    if(t!=NULL)
    {
        cout<<t->data<<"\t";
        XuatCay(t->pleft);
        XuatCay(t->pright);
    }
}
int TongNode(TREE t)
{
    if(t!=NULL)
    {
        int right=(TongNode(t->pright));
        int left=TongNode(t->pleft);
        return t->data+left+right;
    }
    else
    {
        return 0;
    }
}
int Max(TREE t)
{
	if(t->pright==NULL)
	{
		return (t->data);
	}
	else
	{
		return Max(t->pright);
	}
}
int Min(TREE t)
{
    if(t->pleft==NULL)
    {
        return t->data;
    }
    else
    {
        Min(t->pleft);
    }
    
}
int DemNode(TREE t)
{
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        int left=DemNode(t->pleft);
        int right=DemNode(t->pright);
        return 1+right+left;
    }
    
}
NODE *XoayCay(TREE t)
{
    TREE p;
    p=t;
    if(t==NULL)
        cout<<"\nKhong the xoay vi cay rong!";
    else{
        if(t->pright==NULL)
            cout<<"\nKhong the xoay trai vi khong co cay con ben phai!"<<endl;
        else
        {
            p=t->pright;
            t->pright=p->pleft;
            p->pleft=t;
        }
        
    }
}
int main()
{
    TREE t;
    KhoiTaoCay(t);
    ThemVaoCay(t,5);
    ThemVaoCay(t,1);
    ThemVaoCay(t,2);
    ThemVaoCay(t,-2);
    ThemVaoCay(t,6);
    ThemVaoCay(t,1);
    // XoaNode(t,7);
    // NODE *p=TimKiemNode(t,-2);
    // if(p==NULL)
    //     cout<<"Khong tim thay!";
    // else
    // {
    //     cout<<"Tim thay!";
    // }
    XuatCay(t);
    cout<<"\nTong="<<TongNode(t);
    cout<<"\nMAX="<<Max(t);
    cout<<"\nMin="<<Min(t);
    cout<<"\nSL Node="<<DemNode(t);
    
}