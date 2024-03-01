#include<iostream>
using namespace std;
class node {
 public:
 int data;
 node* left;
 node* right;

 node(int d){
    this->data= d;
    this->left=NULL;
    this->right=NULL;

 }
 node* inserttobst(node* root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        root->right=inserttobst(root->right,d);
    }
    else{
        root->left=inserttobst(root->left,d);
    }
 return root;
 }

 void takeinput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=inserttobst(root,data);
        cout<<"enetr the data";
        cin>>data;
    }

 }
 void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
 cout<< root->data <<" ";
    // printf("%d ",root->data);
   inorder(root->right);
 }
 void postorder(node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<" ";
 }
 node* findmin(node* &root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
 }
//2 3 9 5 6 51 7 98

node* deletion(node*root,int data){
if(root==NULL){
    cout<<"tree is empty";
    return root;
}
if(data>root->data){
  root->right=deletion(root->right,data);

}
else if(data<root->data){
   root->left= deletion(root->left,data);
}
else{
   if(root->left==NULL){
    node* temp=root->right;
    delete root;
    return temp;

   }
   if(root->right==NULL){
    node*temp=root->left;
    delete root;
    return temp;
   }
 node*temp=findmin(root->right);
 root->data=temp->data;
 root->right=deletion(root->right,temp->data);


   }
   return root;

}
void balanced(node*root){
    if(root==NULL){
        return ;
    }
    balanced(root->left);
    cout<<root->data<<" ";
    balanced(root->right);
}
};

int main(){
    node* root=NULL;
    int data;
    cout<<"enter data for creat bst"<<endl;
    root->takeinput(root);
   root->inorder(root);
   cout<<endl;
   root->postorder(root);
   cout<<" minimum is--->";
  cout<<  root->findmin(root)->data;
  cout<<"enter the value you deleted"<<endl;
  cin>>data;
 root-> deletion(root,data);
 cout<<endl;
  root->inorder(root);
  root->balanced(root);
    return 0;
}