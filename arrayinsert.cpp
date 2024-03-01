#include<iostream>
using namespace std;
int main(){
   
    int val,pos,i;
int arr[10]={0};
 while(1){
cout<<"insert the value nad position";
cin>>val>>pos;
for(i=10;i<pos;i--){
    arr[i+1]=arr[i];

}
arr[pos]=val;
for(i=0;i<10;i++){
    cout<<arr[i]<<" ";
}

    }

    return 0;
}