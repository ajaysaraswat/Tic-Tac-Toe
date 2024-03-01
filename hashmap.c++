#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;



int main(){
    //creation
    unordered_map<string,int> m;

    //insertion
    //firstway is
    pair<string,int> p= make_pair("ajay",3);
    m.insert(p);

    //second way
    pair<string, int> pair2("love",2);
    m.insert(pair2);
    //3
    m["mera"]=1;

    //search
    cout<<m["ajay"]<<endl;
    cout<<m.at("ajay")<<endl;

    //size
    cout<<m.size();

    //erase
    m.erase("love");
    cout<<m.size();
    // for(auto it:m){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    unordered_map<string,int>:: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}