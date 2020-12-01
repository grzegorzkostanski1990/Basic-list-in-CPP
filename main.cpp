#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
};
void push(node*&H, int x)
{
    node* tmp = new node;
    tmp -> val =x;

    tmp ->next = H;
    H = tmp;
}

void pushlast(node*&H, int x)//last element
{
    node* tmp = new node;
    tmp -> val =x;

    node*p = H;
    while(p->next !=NULL)
        p=p->next;
        p->next =tmp;
        tmp->next =NULL;
}

void pushx(node*&H, int x, int afterwith)
    {
        node* tmp = new node;
        tmp -> val =x;
        node* p =H;
        while(p->val  != afterwith)
            p=p->next;
        tmp->next =p->next;
        p->next = tmp;

    }

void pop(node*&H)
{
    node* p =H;
    if(p == NULL)
        cout<<"list is empty"<<endl;
    else if(p->next ==NULL)
    {
        H=NULL;
        delete p;
    }
    else
    {
        while(p->next !=NULL)
        {
            p= p->next;
        }
        node*s = H;
            while(s->next !=p)
            {
                s= s->next;
            }
            s->next= p ->next;
            delete p;
    }
}

void popbeg(node*&H)
    {
    node*p=H;
    H = H->next;
    delete p;
    }

void show(node* H)
{
    node*p=H;
    while(p!=NULL)
    {
        cout<<p->val<<"->";
        p= p->next;
    }
    cout<<"NULL"<<endl;
}


int main()
{
    node* H =NULL;
    push(H,1);
    push(H,2);
    push(H,3);
    show(H);
    pushx(H,4,2);
    show(H);

    return 0;
}
