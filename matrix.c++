#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

node(int d){
    this->data=d;
    this->next=NULL;
    }
    void insertionathead(node* &head,int d){
        node *temp=new node(d);
        temp->next=head;
        head=temp;

    }
    void insertionattail(node* &tail,int d){
        node* temp=new node(d);
        tail->next=temp;
        tail=temp;
    }

    void insertion(node* &head,node* &tail,int d,int pos){
        if(pos==1){
            insertionathead(head,d);
            return ;
        }
        node* temp=head;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
            count++;

        }
        if(temp->next==NULL){
            insertionattail(tail,d);
            return ;
        }
        else{
            node* nodetoinsert=new node(d);
            nodetoinsert->next=temp->next;
            temp->next=nodetoinsert;
        }
    }
    void print(node* &head){
        if(head==NULL){
            cout<<"list is empty";
        }
        node* temp=head;
        while(temp!=NULL){
            cout<< temp->data<<" ";
            temp=temp->next;
        }
    }
    void deletion(node* &head,int pos){
        if(pos==1){
            node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            node* curr=head;
            node* prev=NULL;
            int count=1;
            while(count<pos){
                prev=curr;
                curr=curr->next;
                count++;
            }
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;

            }
        }
    

};

int main(){
    node* node1;
    node* head=NULL;
    node* tail=NULL;
    node1->insertionathead(head,2);
    node1->insertionathead(head,6);
    node1->insertion(head,tail,3,1);
    node1->insertion(head,tail,8,2);
    node1->insertion(head,tail,7,3);
    node1->print(head);
    node1->deletion(head,3);
    cout<<endl;
    node1->print(head);

}