#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<string> cars={"Mehran","Ferari","BMW","Bugati"};
  cout<<cars[0]<<endl;
  cout<<cars[1]<<endl;
  cout<<cars[2]<<endl;
  cout<<cars[3]<<endl;
  //cout<<cars[4]<<endl;
  cout<<cars.front()<<endl;
  cout<<cars.back()<<endl;
  cout<<cars.at(1);
  cars.push_back("TESLA");
  cars.pop_back("Mehran");
  cars.size();
  cars.empty();
  for(int i = 0 ; i < cars.size();i++){
  	cout<<cars[i]<<" ";
  }
  for (string car : cars) {
  cout << car << "\n";
}
  


 // for(string ch:cars){
  	//cout<<ch<<endl;
  //}
  return 0;
}
