#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]>m) a[i][j]=255;
            else a[i][j]=0;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
