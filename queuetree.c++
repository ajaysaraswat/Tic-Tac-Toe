#include<iostream>
using namespace std;

void linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"serch successfull and present at "<<i<<" location";
            return ;
        }
       
    }

            cout<<"not found";
        


}
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_ele=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ele]){
                min_ele=j;
            }
        }
            int temp=arr[min_ele];
            arr[min_ele]=arr[i];
            arr[i]=temp;

        
    }
}

int binarysearch(int arr[],int n,int key){
int s=0,e=n-1,mid;
mid=(s+e)/2;
while(s<e){
if(arr[mid]==key){
return mid;
}
else if(arr[mid]<key){
    s=mid+1;

}
else{
    e=mid-1;
}
mid=(s+e)/2;
}
return mid;

}
int main(){
    int arr[10]={0};
    int k,key;
    cout<<"enter the size of array";
    cin>>k;
    cout<<"enter the elements";
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    cout<<"enter the key ";
    cin>>key;
    cout<<"element in sorted array is  " ;
     selectionsort(arr,k);
      for(int i=0;i<k;i++){
        cout<<" "<<arr[i];
    }
   /* linearsearch(arr,k,key);*/
   
    cout<<"element in binary serach is "<< binarysearch(arr,k,key);
    return 0;
}