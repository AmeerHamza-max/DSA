#include<iostream>
using namespace std;
#include<list>
int main(){
    // list<string> cars;
    list<string> cars={"BMW","Mehran","Audi","Range Rover"};
    for(string car:cars){
        cout<<car<<" ";
    }
    cout<<endl;
    cout<<cars.front()<<endl;
    cout<<cars.back()<<endl;
    cars.front()="Opel";
    cars.back()="Toyota";
    cout<<cars.back()<<endl;
    cout<<cars.front()<<endl;
    cars.push_front("VW");
    cars.push_back("Tesla");
    cout<<cars.front()<<endl;
    cout<<cars.back()<<endl;
    cars.pop_back();
    cars.pop_front();
    cout<<cars.front()<<endl;
    cout<<cars.back()<<endl;


    cout<<cars.size()<<endl;
    cout<<cars.empty()<<endl;



    // for(int i = 0 ; i < cars.size();i++){
    //     cout<<cars[i]<<"\n";
    // } this throws an error

    for (string car:cars){
        cout<<car<<" ";
    }
}
