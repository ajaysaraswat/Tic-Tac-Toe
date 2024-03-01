#include<iostream>
using namespace std;
class item{
    public:
int value;
int pri;
};
item pr[100];

int size=-1;
void enqueue(int value,int priority){
    size++;
    pr[size].value=value;
    pr[size].pri=priority;
}
int peek(){
    int highpriority=-1;
    int ind=-1;
    for(int i=0;i<=size;i++){
        if(highpriority==pr[i].pri&&ind>-1&&pr[ind].value<pr[i].value){
            highpriority=pr[i].pri;
            ind=i;
        }
        else if(highpriority<pr[i].pri){
            highpriority=pr[i].pri;
            ind=i;

        }
    }
    return ind;
}
    void dequeue(){
        int ind=peek();
        for(int i=ind;i<size;i++){
            pr[i]=pr[i+1];
           
        }
         size--;
    }
    int main(){
        item* t;
        enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);
           int ind=peek();
           cout<<pr[ind].value<<endl;
           dequeue();
           ind=peek();
         cout<<pr[ind].value<<endl;
         dequeue();
         ind = peek();
    cout << pr[ind].value << endl;
 
           return 0;
    }

