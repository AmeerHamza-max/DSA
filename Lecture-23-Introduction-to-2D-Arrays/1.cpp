#include<iostream>
using namespace std;
#include<climits>
bool isPresent(int arr[][4],int target, int row, int col){
    for(int row = 0 ; row < 3; row++){
        for(int col=0;col<4;col++){
            if(arr[row][col]-=target){
                return 1;
            }
        }
    }
    return 0;
}
void rowWiseSum(int arr[][4],int rowSize,int colSize){
    
    for(int row=0; row < rowSize;row++){
        int sum = 0;
        for(int col=0; col < colSize;col++){
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }
}
int largestRowSUm(int arr[][4],int row, int col){
    int maxi = INT_MIN;
    int sum = 0;
    int rowIndex=-1;
    for(int row=0; row < 3;row++){
        int sum = 0 ; 
        for(int col = 0 ; col < 4; col++ ){
            sum += arr[row][col];

        }
        if(sum > maxi){
            maxi=sum;
            rowIndex=row;
        }
    

    }
    cout<<"the maximum sum is "<<maxi<<endl;
    return rowIndex;
}
void wavePrint(int arr[][4],int mrow, int ncol){
    for(int col = 0 ; col <ncol; col++){
        if(col & 1){
            for(int row = mrow-1;row>=0;row--){
                cout<<arr[row][col]<<" ";
            }
        }
        else{
            for(int row = 0 ; row < mrow;row++){
                cout<<arr[row][col]<<" ";
            }
        }
    }
}
void binarySearch(int arr[][4], int rows, int cols, int target)
{
    int start = 0;
    int end = rows * cols - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Convert 1D index to 2D index
        int element = arr[mid / cols][mid % cols];

        if (element == target)
        {
            cout << "Element Found at Index: ("
                 << mid / cols << ", " << mid % cols << ")" << endl;
            return;
        }
        else if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << "Element Not Found" << endl;
}
void spiralPrint(int arr[][4], int rows, int cols)
{
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    while (top <= bottom && left <= right)
    {
        // Top Row
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;

        // Right Column
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;

        // Bottom Row
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }

        // Left Column
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
}
int main(){
    int arr[3][4];
    // int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    cout<<"Enter the Elements "<<endl;
    for(int i = 0 ; i < 3; i++){
     for(int j = 0 ; j < 4; j++){
         cin >> arr[i][j];
         }
    }
    
    for(int i = 0 ; i < 3; i++){
        for(int j = 0 ; j < 4; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout<<"Enter teh element to search = ";
    // int target;
    // cin >> target;
    // if(isPresent(arr,target,3,4)){
    //     cout<<"Element Found"<<endl;
    // }
    // else{
    //     cout<<"Element not found"<<endl;
    // }
    // cout<<"Printing the sum of the rows of an Arrays "<<endl;
    // rowWiseSum(arr,3,4);

    // for(int i = 0 ; i < 3; i++){
    //     for(int j = 0 ; j < 4; j++){
    //         cout<<arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    
    int max = largestRowSUm(arr,3,4);
    cout<<"The maximum sum of row index is = "<<max;
    cout<<"The wave Print "<<endl;
    wavePrint(arr,3,4);
    cout<<"The spiral print "<<endl;
    spiralPrint(arr, 3, 4);



    return 0;
}