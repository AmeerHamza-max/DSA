#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<int> v;
    cout<<"Capcity -> "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Capcity -> "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Capcity -> "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"Capcity -> "<<v.capacity()<<endl;
    cout<<"Size -> "<<v.size()<<endl;
    for(int i = 0; i < v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    cout<<"Before Pop Back "<<endl;
    v.pop_back();
    for(int i = 0; i < v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    cout<<"After Pop Back "<<endl;
     cout<<"Size before clear ="<<v.size()<<endl;
    v.clear();
   
    cout<<"Size After clear = "<<v.size()<<endl;

    vector<int> a(5,1);
    cout<<"Printing A = ";
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> last(a);
    cout<<"Printing last = ";
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;

   


    
}