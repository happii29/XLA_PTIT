#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    int threshold=127;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int currError=0;
        for(int j=0;j<n;j++){
            int u=a[i][j]-currError;
            int newPixel=u<threshold?0:255;
            cout<<newPixel<<" ";
            currError=newPixel-u;
        }
        cout<<endl;
    }
}