#include<iostream>
#include<queue>
using namespace std;

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

        
};

         node* buildtree( node* root){
                int data;
                cin>>data;
                root=new node(data);

                if(data==-1){
                    return NULL;
                }
            cout<<"enter the daat for inserting in left"<<endl;
            root->left=buildtree(root->left);
            cout<<"enter the data for inserting in right"<<endl;
            root->right=buildtree(root->right);
            return  root;
         }
         void levelordertraversal(node* root){
            queue<node*> q;
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                    node* temp=q.front();
                    q.pop();
                if(temp==NULL){
                    //purana level complete traverse ho chuka hai
                    cout<<endl;
                    if(!q.empty()){
                    //queue has some child nodes
                    q.push(NULL);
                    }
                }
                else{
                    cout<<temp->data<<" ";
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }

            }

         }
         void inorder(node* root){
//  base case
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        


         }

         void preorder(node* root){
if (root==NULL){
    return;
}

        


            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
            
         }

         void postorder(node* root){
            if (root==NULL){
    return;
}
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
         }
         int heighttree(node* root){
            if(root==NULL){
                return 0;
            }
            int left=heighttree(root->left);
            int right=heighttree(root->right);
            int ans=max(left,right)+1;
            return ans;
         }
int main(){
node* root=NULL;
//built a tree
root=buildtree(root);
levelordertraversal(root);
cout<<"inorder traversal=";
inorder(root);
cout<<endl;
cout<<"preorder traversal=";
preorder(root);cout<<endl;
cout<<"postorder traversal=";
postorder(root);cout<<endl;
cout<<"height="<<heighttree(root);
    return 0;
}