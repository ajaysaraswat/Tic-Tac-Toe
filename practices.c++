#include<iostream>
using namespace std;
 int count=0;
class node{
public:
int data;
node* left;
node* right;
 node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;
}
node* insertion(node* &root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(root->data>d){
        root->left=insertion(root->left,d);
    }
    else {
        root->right=insertion(root->right,d);
    }
     
        return root;
    
}
void inorder(node* root){
  
    if(root==NULL){
        return ;
    }    
    inorder(root->left);
    cout<< root->data <<" ";
    count++;
    inorder(root->right);
 
}
   
 void takeinput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertion(root,data);
        cout<<"enetr the data";
        cin>>data;
    }

 }
node* findmin(node* root){
    while(root->left!=NULL){
        root=root->left;

    }
    return root;
}
node* deletion(node*root,int data){
    if(root==NULL){
        cout<<"tree is empty";
        return root;
    }
    if(data<root->data){
        root->left=deletion(root->left,data);
    }
    else if(data>root->data){
        root->right=deletion(root->right,data);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }
    }


}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left= height(root->left);
    int right= height(root->right);
    int ans=max(left,right)+1;
    return ans;
    }

};
int main(){
    node* root=NULL;
    cout<<"hii";
    root->takeinput(root);

//    root->insertion(root,28);
  
   root->inorder(root);
   cout<<"hii  "<<count;
   root->deletion(root,6);
   cout<<endl;
    root->inorder(root);
    cout<<"height";
   cout<< root->height(root);
   return 0;
}