#include<iostream>
#include<string.h>
using namespace std;
struct BenhNhan
{
	int STT;
	char hoten[30];
	int tuoi;
};
struct Node
{
	BenhNhan data;
	Node* pNext;
};
struct Queue
{
	Node* pHead;
	Node* pTail;
};
void Nhap(BenhNhan &bn)
{
	fflush(stdin);
	cout<<"\nNhap ho ten:";
	gets(bn.hoten);
	fflush(stdin);
	cout<<"\nNhap tuoi:";
	cin>>bn.tuoi;
}
void Xuat(BenhNhan bn)
{
	cout<<bn.STT<<"\t"<<bn.hoten<<"\t"<<bn.tuoi<<endl;
}
void Init(Queue &q)
{
	q.pHead=NULL;
	q.pTail=NULL;
}
bool IsEmpty(Queue &q)
{
	if(q.pHead==NULL)
		return true;
	return false;
}
Node* CreateNode(BenhNhan bn)
{
	Node *p=new Node;
	if(p==NULL)
	{
		return NULL;
	}
	else
	{
		p->data=bn;
		p->pNext=NULL;
	}
	return p;
}
void EnQueue(Queue &q,BenhNhan bn)
{
	Node *p=CreateNode(bn);
	if(IsEmpty(q)==true)
	{
		q.pHead=q.pTail=p;
	}
	else
	{
		q.pTail->pNext=p;
		q.pTail=p;
	}
}
void DeQueue(Queue &q,BenhNhan &bn)
{
	if(IsEmpty(q)==true)
	{
		cout<<"Danh sach rong!";
	}
	else
	{
		Node *p=q.pHead;
		bn=p->data;
		q.pHead=q.pHead->pNext;
		delete(p);
	}
}
void InPut(Queue &q,int n)
{
	BenhNhan bn;
	for(int i=0;i<n;i++)
	{
		Nhap(bn);
		EnQueue(q,bn);
	}
}
void OutPut(Queue q)
{
	BenhNhan bn;
	cout<<"STT\tHoTen\tTuoi"<<endl;
	while (IsEmpty(q)==false)
	{
		DeQueue(q,bn);
		Xuat(bn);
	}
}
int SizeOfList(Queue q)
{
	int d=0;
	Node *p=q.pHead;
	while (p!=NULL)
	{
		d++;
		p=p->pNext;
	}
	return d;
}
void InsertMid(Queue &q,BenhNhan khoa,int pos)
{
	if(pos<0||pos>SizeOfList(q)-1)
		cout<<"\nNhap vi tri sai"<<endl;
	else
	{
		Node *p=CreateNode(khoa);
		int d=0;
		Node *t=q.pHead;
		Node *del=new Node;
		while (pos!=d)
		{
			d++;
			t=t->pNext;
			del=t->pNext;
		}
		t->pNext=p;
		p->pNext=del;
	}
	
}
void UpDateSTT(Queue &q)
{
	int i=0;
	Node*p=q.pHead;
	while (p!=NULL)
	{
		p->data.STT=i++;
		p=p->pNext;
	}
	
}
void Menu()
{
	cout<<"===========Menu==========="<<endl;
	cout<<"1.Nhap thong tin cac benh nhan"<<endl;
	cout<<"2.Xuat thong tin cac benh nhan"<<endl;
	cout<<"3.Them 1 benh nhan vao vi tri"<<endl;
	cout<<"0.Thoat"<<endl;
	cout<<"===========End==========="<<endl;
}
int main()
{
	Queue q;
	BenhNhan khoa;
	int n,pos,chon;
	Init(q);
	do
	{
		Menu();
		cout<<"Moi Chon:";
		cin>>chon;
		if(chon==1)
		{
			cout<<"Nhap so luong benh nhan:";
			cin>>n;
			InPut(q,n);
		}
		else if(chon==2)
		{
			OutPut(q);
		}
		else if(chon==3)
		{
			cout<<"\nNhap thong tin benh nhan can them:";
			Nhap(khoa);
			cout<<"\nNhap vi tri :";
			cin>>pos;
			InsertMid(q,khoa,pos);
		}
		else
		{
			chon=0;
		}
		
	} while (chon!=0);
}



