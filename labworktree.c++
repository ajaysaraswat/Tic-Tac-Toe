#include<iostream>
#include<queue>
using namespace std;
class node
{
    int data;
    node *left;
    node *right;
    public:
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node *createNode(int data)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    node *insert(node *root, int data)
    {
        if (root == NULL)
        {
            return createNode(data);
        }

        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }

        return root;
    }

    node *findMin(node *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    node *deletion(node *root, int data)
    {
        if (root == NULL)
        {
            cout<<"Tree is empty"<<endl;
            return root;
        }

        if (data < root->data)
        {
            root->left = deletion(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = deletion(root->right, data);
        }
        else
        {
            if (root->left == NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
        return root;
    }
    void inorder(node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }

    void preorder(node *root)
    {
        if (root == NULL)
            return;
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node *root)
    {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
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
};

int main()
{
    node *root = NULL;
    int choice, data;

    while (1)
    {
        cout<<"Insert(1), Delete(2), Inorder(3), Preorder(4), Postorder(5),lavel order traversal(6) Exit(7)"<<endl;
        cin>>choice;

        if (choice == 1)
        {
            cout<<"Enter data (node number) to insert: "<<endl;
            cin>>data;
            root = root->insert(root, data);
        }
        else if (choice == 2)
        {
            cout<<"Enter data to delete: "<<endl;
            cin>>data;
            root = root->deletion(root, data);
        }
        else if (choice == 3)
        {
            cout<<"Inorder Traversal: "<<endl;
            root->inorder(root);
            cout<<endl;
        }
        else if (choice == 4)
        {
            cout<<"Preorder Traversal: "<<endl;
            root->preorder(root);
            cout<<endl;
        }
        else if (choice == 5)
        {
            cout<<"Postorder Traversal: "<<endl;
            root->postorder(root);
            cout<<endl;
        }
        else if (choice == 7)
        {
            exit(0);
        }
      
        else if(choice==6){
            root-> levelordertraversal( root);
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }

    }
    return 0;
}