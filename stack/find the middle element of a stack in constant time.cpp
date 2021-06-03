#include<iostream>
using namespace std;

int count = 0;
class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void  insertAttail(node* &head, node* &temp, node* &middle, int val){

    node* n = new node(val);
     if(head == NULL){
        head = n;
        temp = head;
        middle = temp;
        count = count+1;
        return;
    }
    temp->next = n;
    n->prev = temp;
    temp = n;
    count = count+1;
    if(count%2!=0){
        middle = middle->next;
    }
    
}

void Delete(node *&head, node* &middle, node *&temp){
    if(head==NULL){
        cout<<"stack is empty"<<endl;
        //return;
    }
    else if(head->next==NULL){
        head = NULL;
        middle = NULL;
        //cout<<"NOW stack is empty"<<endl;
        //return;

    }
    else{
        node *t = temp;
    temp = temp->prev;
    temp->next = NULL;
    delete(t);
    count--;
    //cout<<"count = "<<count<<endl;
    if(count%2==0)
    middle = middle->prev;

    }
    
}

void display(node* head){
    if(head==NULL){
        cout<<"stack is empty"<<endl;
    }
    node *p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    node* head = NULL;
    node *temp = head;
    node *middle;
    insertAttail(head,temp,middle,1);
    insertAttail(head,temp,middle,2);
    insertAttail(head,temp,middle,3);
    insertAttail(head,temp,middle,4);
    insertAttail(head,temp,middle,5);
    insertAttail(head,temp,middle,6);
    
    display(head);
    cout<<"middle element is: "<<middle->data<<endl;
    Delete(head,middle,temp);
    
    display(head);
    cout<<"middle element is: "<<middle->data<<endl;
    Delete(head,middle,temp);
    
    
    
    return 0;
}
