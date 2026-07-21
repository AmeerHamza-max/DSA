// #include<iostream>
// using namespace std;
// #include<algorithm>
// void printArray(int arr[],int n){
//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// void sortOne(int arr[],int n){
//     int left = 0,right=n-1;
//     while(left < right){
//         while(arr[left] == 0  && left < right){
//             left++;
//         }
//         while(arr[right]==1 && left < right){
//             right--;
//         }
//         if( left < right){
//             swap(arr[left],arr[right]);
//             left++;
//             right--;
//         }
        
//     }

// }
// int main(){
//     int arr[8]={1,1,0,0,0,0,1,0};
//     sortOne(arr,8);
//     printArray(arr,8);

// }

#include<iostream>
using namespace std;
#include<algorithm>
void printArray(int arr[],int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sortOne(int arr[],int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;

while(mid <= high){
    if(arr[mid] == 0){
        swap(arr[low], arr[mid]);
        low++;
        mid++;
    }
    else if(arr[mid] == 1){
        mid++;
    }
    else{
        swap(arr[mid], arr[high]);
        high--;
    }
}

}
int main(){
    int arr[9]={0,0,2,1,0,1,1,0,2};
    sortOne(arr,9);
    printArray(arr,9);

}