#include<iostream>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node* link;
    node(int d){
        this->data=d;
        this->link=NULL;
    }
};
void insertAtHead(node* &head,int d){
    node* temp=new node(d);
    temp->link=head;
    head=temp;
}
void insertAtTail(node* &tail,int d){
    node* temp=new node(d);
    tail->link=temp;
    tail=temp;
}/*
bool  Iscircular(node* head){
    //empty list
    if(head==NULL){
        return true;
    }
    node* temp=head->link;
    while(temp!=NULL && temp!=head){
        temp=temp->link;
    }
    if(temp==head){
        return true;
    }return false;
}*/
bool detectloop(node* head){
    if (head==NULL){
        return false;
    }
    map<node*,bool>visited;
    node* temp=head;
    while(temp!=NULL){
        //cycle present
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->link;
    }return false;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}
int main(){node* tail;
    node* head=tail=new node(20);
    insertAtHead(head,50);
    insertAtTail(tail,10);
    display(head);
    //bool Iscircular(head);
    if(detectloop){
        cout<<endl<<"is circular";
    }else{
        cout<<endl<<"no loop";
    }
    return 0;
}