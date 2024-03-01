#include<iostream>
#include<math.h>
using namespace std;

int main(){
    float x;
    float R;
    cout<<"enter the value of R";
    cin>>R;
    cout<<"Enter the value of initial root";
    cin>>x;
    float a=0,b=0,c,d,y,prev=0;
    prev=0;
    int t=0;
   while(prev!=y){
    prev=y;
   a=(1/(pow(x,0.5)))+0.4-(4*log10(R*pow(x,0.5)));
   b=-(0.5/pow(x,1.5))-(0.8685/(R*pow(x,0.5)));
   y=x-(a/b);
   cout<<y<<endl;
   x=y;
   
    }
}

