#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

using namespace std;
//typedef long long int int64;
typedef struct tagNode
{
    int num;
    struct tagNode *pNext;
}Node;

Node *pQueue=NULL;

void setupQueue()
{
    //3 5 7 9
    Node *p=new Node;
    assert(p);
    pQueue=p;  //head
    p->num=3;
    p->pNext=NULL;
    while(p->num<1e6)
    {
        Node *p2=new Node;
        assert(p2);
        p2->num=p->num+2;
        p2->pNext=NULL;
        p->pNext=p2;
        p=p2;
    }
    
}

void clearQueue()
{
    while(pQueue)
    {
        Node *p=pQueue;
        pQueue=pQueue->pNext;
        delete p;
    }
}

void printQueue()
{
    Node *p=pQueue;
    while(p)
    {
        cout<<p->num<<" ";
        p=p->pNext;
    }
}

void shiftQueue()
{
    if(!pQueue)
    {
        cout<<"shift error: queue is empty."<<endl;
        return;
    }
    int n = pQueue->num;
    Node *p=pQueue;
    int i=1;
    while(p->pNext)
    {
        if(i%n==0)
        {
            Node *pTmp=p->pNext;
            p->pNext=pTmp->pNext;
            //cout<<"delete "<<pTmp->num<<endl;
            delete pTmp;
        }
        else
        {
            p=p->pNext;
        }
        i++;
    }

    p=pQueue;
    pQueue=pQueue->pNext;
    delete p;
}

//1<= n <=3000
int luckyNumber(int n)
{
    if(n==1)
    {
        return 2;
    }
    n-=2;
    Node *ptr;
    while(n--)
    {
        shiftQueue();
    }
    if(!pQueue)
    {
        cout<<"queue is empty."<<endl;
        return 0;
    }
    return pQueue->num;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        setupQueue();
        //printQueue();
        //shiftQueue();
        //cout<<"shift ok"<<endl;
        //printQueue();
        cout<<luckyNumber(n)<<endl;
        //cout<<"ok"<<endl;
        clearQueue();
        //cout<<"clear ok"<<endl;
        //printQueue();
    }
}
