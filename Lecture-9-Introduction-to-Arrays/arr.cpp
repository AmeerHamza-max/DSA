// #include<iostream>
// using namespace std;
// void printArray(int arr[],int size){
//     cout<<"Printing the array"<<endl;

    
//     for (int i = 0 ; i < size; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<"Printing done"<<endl;
// }
// void charprintArray(char arr[],int size){
//     cout<<"Printing the array"<<endl;

    
//     for (int i = 0 ; i < size; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<"Printing done"<<endl;
// }
// int main(){
//     int number[15];
//     cout<<"Value at 0 index "<<number[0]<<endl;//garbage value
//     cout<<"Value at 25 index "<<number[25]<<endl;//garbage value

//     //initialzing an array
//     int second[3]={5,7,11};
//     cout<<"Value at second index "<<second[2]<<endl;
//     int third[15]={2,7};
//     cout<<endl<<" Everything is fine"<<endl<<endl;
//     int n=3;
//     cout<<"Printing the array"<<endl;

//     for (int i = 0 ; i < n; i++){
//         cout<<third[i]<<" ";
//     }
//     n=4;
//      cout<<"Printing the array"<<endl;

//     int fourth[10]={0};
//     for (int i = 0 ; i < n; i++){
//         cout<<fourth[i]<<" ";
//     }

//     int fifth[10]={1};
//     int fifthSize=sizeof(fifth)/sizeof(int);

//     for(int i =0 ; i < n; i++){
//         cout<<fifth[i]<<endl;
//     }
//     printArray(third,n);








//     char ch[5]={'a','b','c','d','e'};
//     int size=sizeof(ch)/sizeof(char);
//     charprintArray(ch,size);

//     double firstDouble(5);
//     float firstFloat(6);
//     bool firstBool(9);

//     return 0;


// }


#include<iostream>
using namespace std;
int calculateSum(){
    int arr[5]={2,7,1,-4,11};
    int size = sizeof(arr)/sizeof(int);
    int sum = 0;
    for(int i = 0 ; i < size; i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int sumOfArr=calculateSum();
    cout<<"Sum of the Array = "<<sumOfArr<<endl;
}


