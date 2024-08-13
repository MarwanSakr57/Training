#include <bits/stdc++.h>
using namespace std;

int main (){
    int n; 
    cin>>n;
    int arr[n];
     for (int i =0 ; i<n; i++){
        cin>>arr[i];
     }
    int MAX = arr[0];
    for (int i = 0; i<n; i++)
    {
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    cout<<MAX;

    return 0;
}