#include <bits/stdc++.h>
using namespace std;

int main (){
    int n; 
    int index = -1;
    int target;
    cin>>n;
     int arr[n];
    for (int i =0 ; i<n; i++){
        cin>>arr[i];
    }
    cin>>target;
    for (int j =0 ; j<n ;j++){
        if (arr[j]==target){
          index = j;
          break;
        } 
    }
       cout<<index;
    return 0;
}