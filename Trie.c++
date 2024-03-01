#include<iostream>
using namespace std;

class Trienode{
    public:
    int data;
    Trienode* children[26];
    bool terminal;

    Trienode(char c){
        data=c;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        terminal=false;
    }
};

class Trie{
public:

Trienode* root;

Trie(){
    root=new Trienode('\0');
}

 
    
    void insertutil(Trienode* root,string word){
        //base condition
        if(word.length()==0){
            root->terminal=true;
            return ;
        }

        int index=word[0]-'a';
        Trienode* child;

        //present

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new Trienode(word[0]);
            root->children[index]=child;

        }
        insertutil(child,word.substr(1));
    }
    void insertion(string word){
        insertutil(root,word);
    }
    bool searchutil(Trienode* root,string word){
        //base case
        if(word.length()==0){
            return root->terminal;
        }
        int index=word[0]-'a';
        Trienode* child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];

        }else{
            return false;
        }
        return searchutil(child,word.substr(1));
    }
    bool search(string word){
        return searchutil(root,word);
    }

};

int main(){
    Trie t;
    t.insertion("abcd");
    t.insertion("ab");
    t.insertion("abc");
    

    cout<<"present  "<<t.search("a");
    return 0;
    
}