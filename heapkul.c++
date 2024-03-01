#include<iostream>
using namespace std;
#define MAX_SIZE 50

class Heap
{
  int heapMAX[MAX_SIZE];
  int sizeMAX;
  public:
  Heap()
  {
    sizeMAX = 0;
  }
  void insertMAX(int data)
  {
    sizeMAX = sizeMAX+1;
    heapMAX[sizeMAX] = data;
    int i = sizeMAX;
    while(i>1)
    {
      int parent = i/2;
      if(heapMAX[parent]<heapMAX[i])
      {
        swap(heapMAX[parent],heapMAX[i]);
        i = parent;
      }
      else return;
    }
  }
  void display()
  {
    cout<<sizeMAX<<endl;
    for(int i=1;i<=sizeMAX;++i)
    {
      cout<<heapMAX[i]<<" ";
    }
    cout<<endl;
  }
  void deleteMAX()
  {
    if(sizeMAX==0)
    {
      cout<<"Heap is empty"<<endl;
      return;
    }
    heapMAX[1] = heapMAX[sizeMAX];
    sizeMAX = sizeMAX-1;
    int i=1;
    while(i<sizeMAX)
    {
      int left = heapMAX[2*i];
      int right = heapMAX[2*i+1];
      int larger = left>right?2*i:2*i+1;
      if(heapMAX[i]<heapMAX[larger] && larger < sizeMAX)
      {
        swap(heapMAX[i],heapMAX[larger]);
        i = larger;
      }
      else return;
    }
  }
  void heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;

    int r=2*i+2;
  int largest=l>r?2*i+1:2*i+2;
  if(largest!=i){
    swap(a[i],a[largest]);
    heapify(a,n,largest);
  }
  }
  int check()
  {
    if(sizeMAX==0)return -1;
    else return 0;
  }
  void heapsort(){
    for(int i=sizeMAX/2-1;i>=0;i--){
      deleteMAX();

    }
    for(int i=sizeMAX-1;i>0;i--){
      swap(heapMAX[0],heapMAX[i]);
      deleteMAX();

    }
  }
};
int main()
{
  Heap h1;
  int data;
  cout<<"Welcome to Heap program!!"<<endl;
  while(true)
  {
    cout<<"Enter-->Create(1), Insert(2), Delete(3), Display(4), Terminate(5)"<<endl;
    int choice;
    cin>>choice;
    if(choice == 1)
    {
      if(h1.check()==-1)
      {
      int n;
      cout<<"Enter the number of elements you want to insert"<<endl;
      cin>>n;
      cout<<"Enter elements:-"<<endl;
      while(n>0)
      {
        cin>>data;
        h1.insertMAX(data);
        n--;
      }
      }
      else cout<<"Heap is already created"<<endl;
    }
      else if(choice == 2)
      {
        cout<<"Enter the elements you want to insert"<<endl;
        cin>>data;
        h1.insertMAX(data);
      }
      else if(choice == 3)
      {
        h1.deleteMAX();
      }
      else if(choice == 4)
      {
        h1.display();
      }
      else if(choice == 5)
      {
        h1.heapsort();
         h1.display();

      }

    }

  }