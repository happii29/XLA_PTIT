#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int img[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>img[i][j];
        }
    }
    float mask[3][3]={{1.0/9,1.0/9,1.0/9},{1.0/9,1.0/9,1.0/9},{1.0/9,1.0/9,1.0/9}};
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            float temp=img[i-1][j-1]*mask[0][0]+img[i-1][j]*mask[0][1]+img[i-1][j+1]*mask[0][2]+img[i][j-1]*mask[1][0]+img[i][j]*mask[1][1]+img[i][j+1]*mask[1][2]+img[i+1][j-1]*mask[2][0]+img[i+1][j]*mask[2][1]+img[i+1][j+1]*mask[2][2];
            cout<<(int)round(temp)<<" ";
        }
        cout<<endl;
    }
}