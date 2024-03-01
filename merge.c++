// //C++ program for Merge Sort Algorithm
// #include <iostream>
// #define max 10
// //navigate through all items
// //int a[11] ;

// int b[10]={0};


// //merge sorting
// void merging(int a[],int low, int mid, int high) {
//    int l1, l2, i;
//    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
//       if(a[l1] <= a[l2])
//          b[i] = a[l1++];
//       else
//          b[i] = a[l2++];
//    }
//     while(l1 <= mid)    
//       b[i++] = a[l1++];

//    while(l2 <= high)   
//       b[i++] = a[l2++];

//    for(i = low; i <= high; i++)
//       a[i] = b[i];
// }
// void sort(int a[],int low, int high) {
//    int mid;  
//    if(low < high) {
//       mid = (low + high) / 2;
//       sort(a,low, mid);
//       sort(a,mid+1, high);
//       merging(a,low, mid, high);
//    } else { 
//       return;
//    }   
// }
// int main() { 
//     int a[11];
//    int i;
//    int k=34;
//    for(int j=0;j<11;j++){
// a[j]=k;
// k=k-2;
//    }
   
//    //Before sorting
//    std::cout << "List before sorting\n";   
//    for(i = 0; i <= max; i++)
//       std::cout << a[i] << " ";
//    sort(a,0, max);
//    //After sorting
//    std::cout << "\nList after sorting\n";
//    for(i = 0; i <= max; i++)
//       std::cout << a[i] << " ";
// }

#include<iostream>
using namespace std;
int b[10];
class merge{
    public:
    void merging(int a[],int low,int mid,int high){
        int l1,l2,i;
        for(l1=low,l2=mid+1,i=low;l1<=mid&&l2<=high;i++){
            if(a[l1]<=a[l2]){
                b[i]=a[l1++];
            }
            else{
                b[i]=a[l2++];
            }
        }
        while(l1<=mid){
            b[i++]=a[l1++];
        }
        while(l2<=high){
            b[i++]=a[l2++];
        }
        for(int i=low;i<=high;i++){
            a[i]=b[i];
        }
    }
    void sort(int a[],int low,int high){
        int mid;
        if(low<high){
            mid=(low+high)/2;
            sort(a,low,mid);
            sort(a,mid+1,high);
            merging(a,low,mid,high);
        }
        else{
        return ;
        }
    }
};
int main(){
    merge* m1;
    int a[11]={9,8,7,6,5,4,3,2,1,0,12};
    m1->sort(a,0,10);
    for(int i=0;i<11;i++){
        cout<<a[i]<<" ";
    }


}