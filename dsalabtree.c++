#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int id){
       this->data=id;
       this->left=NULL;
       this->right=NULL;

    }
};

    Node*buildtree(Node*root){
        int data;
     
        cin>>data;
        root=new Node(data);
        if(data==-1){
            return NULL;
        }
        cout<<"enter the data for inserting in left of  " <<root->data<<endl;
        root->left=buildtree(root->left);
        cout<<"enter the data for inserting in right "<<root->data<<endl;
        root->right=buildtree(root->right);
    return root;
}

void levelordertraversal(Node* root){
            queue<Node*> q;
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                    Node* temp=q.front();
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

    void inorder(Node* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }
    int main(){
        Node*root=NULL;
        cout<<"plese enter -1 if element is null"<<endl;
        cout<<"enter the root"<<endl;
        root=buildtree(root);
        levelordertraversal(root);
        cout<<"inordertraversal===>";
        inorder(root);
        return 0;
    }