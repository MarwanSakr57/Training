#include <bits/stdc++.h>
using namespace std;

int main (){
    int r; 
    int c;
    int just=0;
    int vill=0;
    cin>>r>>c;
    int Justice_League[r][c];
    int Villains[r][c];
     for (int i =0 ; i<r; i++){
        for(int j =0; j<c; j++){
        cin>>Justice_League[i][j]; 
        }
     }
       for (int i =0 ; i<r; i++){
        for(int j =0; j<c; j++){
        cin>>Villains[i][j]; 
        }
     }
     for(int k =0;k<r;k++){
        for (int l = 0; l < c; l++)
        {
            if(Justice_League[k][l]>Villains[k][l]){
                just++;
            }
            else if (Justice_League[k][l]<Villains[k][l])
            {
                vill++;
            }
            
        }
        
     }
  if(just>vill){
    cout<<"Justice League";

  }else if (vill>just)
  {
    cout<<"Villains";
  }else{
    cout<<"Tie";
  }

  
    return 0;
}