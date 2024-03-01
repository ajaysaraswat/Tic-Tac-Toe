#include<iostream>
using namespace std;
class heap{
    public:

void heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;

    int r=2*i+2;
   largest=arr[l]>arr[r]?2*i+1:2*i+2;
  if(largest!=i){
    swap(a[i],a[largest]);
    heapify(a,n,largest);
  }
  }
  void heapsort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
  }
  void printarray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
       
    }
     cout<<"\n";
  }
};
int main()
{
    heap* h1;
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    h1->heapsort(arr, N);
 
    cout << "Sorted array is \n";
   h1->printarray(arr, N);
}
