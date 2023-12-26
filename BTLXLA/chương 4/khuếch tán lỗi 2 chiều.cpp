#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int nguong=127;
    int du=0;
    int b=0;
    int a[n+1][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nguong>=a[i][j]){
                b=0;
            }
            else{
                b=255;
            }
            a[i][j]=b;
            int e=b-a[i][j];
            a[i][j+1]=a[i][j+1]-e*(7/16);
            a[i+1][j-1]=a[i+1][j-1]-e*(3/16);
            a[i+1][j]=a[i+1][j]-e*(5/16);
            a[i+1][j+1]=a[i+1][j+1]-e*(1/16);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}