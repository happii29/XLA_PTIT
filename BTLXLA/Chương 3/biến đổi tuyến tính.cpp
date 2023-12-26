#include<iostream>
#include<vector>
using namespace std;
int main(){
    float a,b;
    int n;
    cin>>a>>b>>n;
    vector<vector<int>>m(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
            int tmp=a*m[i][j]+b;
            if(tmp>255) tmp=255;
            cout<<tmp<<" ";
        }
        cout<<endl;
    }
}