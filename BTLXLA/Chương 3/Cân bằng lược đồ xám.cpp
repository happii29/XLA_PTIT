#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int m,n,level;
    cin>>m>>n>>level;
    int img[m][n];
    int px[level]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>img[i][j];
            px[img[i][j]]++;
        }
    }
    int CDF[level]={0};
    int accumulation=0;
    for(int i=0;i<level;i++){
        accumulation+=px[i];
        CDF[i]=accumulation;
    }
    for(int i=0;i<level;i++){
        CDF[i]=max(0,(int)round((level-1)*CDF[i]/(float)(m*n)));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<CDF[img[i][j]]<<" ";
        }
        cout<<endl;
    }
}