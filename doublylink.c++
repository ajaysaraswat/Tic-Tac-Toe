/*#include<iostream>
using namespace std;
class node{
    public:
int data;
node* next;
node* prev;


node(int d){
    this->data=d;
    this->next=NULL;
    this->prev-NULL;
}

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp=temp->next; 
    }
}

int getlength(node* head){
    int sum=0;
    node* temp=head;
    while(temp!=NULL){
    sum=sum+1;
    temp=temp->next;
    }
    cout<<" sum is"<<sum;
    return sum;
}
void insertionathead(node* &head,node* &tail,int d){
    if(head==NULL){
        node*temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
        node* temp=new node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertionattail(node* &head,node* &tail,int d){
if(tail==NULL){
    node* temp=new node(d);
    tail=temp;
    head=temp;
}
else{
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}
}
void insertionatloc(node* &head,node* &tail,int pos,int d){
    //insertion at start
    if(pos==1){
        insertionathead(head,tail,d);
        return; 
    }
    
        node* temp=head;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
            count++;

        }
        if(temp->next==NULL){
            insertionattail(head,tail,d);
            return ;
        }
    node* nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}

void deletion(node* &head,int pos){
    //deletion first or starting node
    if(pos==1){
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;


    }
    else{
        //deleting any middle and last node
        node* curr=head;
        node* prev=NULL;

        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        curr->next=NULL;
    }
}

};

int main(){
    
  node* node1;
    
  //  node1=new node(10);
    node* head=NULL;
    node* tail=NULL;
    
   node1->print(head);
   cout<<endl;
   node1->getlength(head);
  node1->insertionathead(head,tail,12);
  node1->insertionathead(head,tail,13);
 node1->print(head); 
  node1->getlength(head);
  node1->insertionattail(head,tail,56);
node1->print(head); 
  node1->getlength(head);
  node1->insertionatloc(head,tail,2,20);
  cout<<endl;
  node1->print(head); 
}
*/
// practice
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    void insertionathead(node* &head,node* &tail,int d){
        if(head==NULL){
            node* temp=new node(d);
            head=temp;
            tail=temp;

        }
        node* temp=new node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
}
    void insertionattail(node* &head,node* &tail,int d){
        if(tail==NULL){
            node* temp=new node(d);
            tail=temp;
            head=temp;
        }
        else{
            node* temp=new node(d);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;

            
        }
    }
    void insertion(node* &head,node* &tail,int pos,int d){
        if(pos==1){
            insertionathead(head,tail,d);
            return ;
        }
        node* temp=head;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
            count++;

        }
        if(temp->next==NULL){
            insertionattail(head,tail,d);
            return ;

        }
        else{
            node* nodetoinsert=new node(d);
               nodetoinsert->next=temp->next;
             temp->next->prev=nodetoinsert;
            temp->next=nodetoinsert;
            nodetoinsert->prev=temp;
         
           
        }
    }
    void print(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void deletion(node* &head,node* &tail,int pos){
       
        if(pos==1){
            node* temp=head;
            head=temp->next;
              temp->next->prev=NULL;
            temp->next=NULL;
           
            delete temp;
        }
        else{
            int count=1;
            node* curr=head;
            node* prev=NULL;
            while(count<pos){
                prev=curr;
                curr=curr->next;
                count++;

            }
           
           curr->prev=NULL;
           curr=curr->next;
           curr->next=NULL;
           delete curr;
        }
    }
};
int main(){
    node* node1;
    node* head=NULL;
    node* tail=NULL;
    node1->print(head);  
  node1->insertionathead(head,tail,4); 
 node1->insertionathead(head,tail,7);
   node1->insertionattail(head,tail,8);
   node1->insertionattail(head,tail,19);
   node1->insertion(head,tail,2 ,25);
      node1->insertion(head,tail,1 ,15);
//       node1->print(head);
     node1-> deletion(head,tail,3);
    cout<<endl;
   node1->print(head);  
}

