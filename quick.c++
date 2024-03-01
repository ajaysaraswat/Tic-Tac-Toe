// //C++ program for Quick Sort Algorithm
// #include <iostream>
// #include <stdbool.h>
// #define MAX 7
// int intArray[MAX] = {4,6,3,2,1,9,7};
// void printline(int count) {
//    int i;	
//    for(i = 0;i < count-1;i++) {
//       std::cout << "=";
//    }
//    std::cout << "=\n";
// }
// void display() {
//    int i;
//    std::cout << "[";
//    // navigate through all items 
//    for(i = 0;i < MAX;i++) {
//       std::cout << intArray[i] << " ";
//    }
//    std::cout << "]\n";
// }
// void swap(int num1, int num2) {
//    int temp = intArray[num1];
//    intArray[num1] = intArray[num2];
//    intArray[num2] = temp;
// }
// int partition(int left, int right, int pivot) {
//    int leftPointer = left -1;
//    int rightPointer = right;
//    while(true) {
//       while(intArray[++leftPointer] < pivot) {
//          //do nothing
//       }	
//       while(rightPointer > 0 && intArray[--rightPointer] > pivot) {
//          //do nothing
//       }
//       if(leftPointer >= rightPointer) {
//          break;
//       } else {
//          std::cout << " item swapped :" << intArray[leftPointer] << "," << intArray[rightPointer] << "\n";
//          swap(leftPointer,rightPointer);
//       }
//    }
//    std::cout << " pivot swapped :" << intArray[leftPointer] << "," << intArray[right] << "\n";
//    swap(leftPointer,right);
//    std::cout << "Updated Array: "; 
//    display();
//    return leftPointer;
// }
// void quickSort(int left, int right) {
//      if(right-left <= 0) {
//       return;   
//    } else {
//       int pivot = intArray[right];
//       int partitionPoint = partition(left, right, pivot);
//       quickSort(left,partitionPoint-1);
//       quickSort(partitionPoint+1,right);
//    }        
// }
// int main() {
//    std::cout << "Input Array: ";
//    display();
//    printline(50);
//    quickSort(0, MAX-1);
//    std::cout << "Output Array: ";
//    display();
//    printline(50);
//    return 1;
// }

#include<iostream>
using namespace std;
int a[10]={1,9,8,7,5,6,4,3,2,12};

class quick{
   public:
   void display(){
      for(int i=0;i<10;i++){
         cout<<a[i]<<" ";
      }

   }
   void swap(int num1,int num2){
      int temp=a[num1];
      a[num1]=a[num2];
      a[num2]=temp;
   }

   int partition(int left,int right,int pivot){
      int leftpointer=left-1;
     int  rightpointer=right;
     while(true){
      while(a[++leftpointer]<pivot){

      }
      while(a[--rightpointer]>pivot&&rightpointer>0){

      }
      if(leftpointer>=rightpointer){
         break;
      }
      else{
         swap(leftpointer,rightpointer);
      }
     }
     swap(leftpointer,right);
     return leftpointer;
   }
   void quicksort(int left,int right){
   if(right-left<=0){
      return;
   }  
   else{
      int pivot=a[right];
      int partionpoint=partition(left,right,pivot);
      quicksort(left,partionpoint-1);
      quicksort(partionpoint+1,right);

   }    
   }
};
int main(){
   quick* q;
   q->display();
   q->quicksort(0,10);
   cout<<endl;
  q-> display();
  return 0;
   
}