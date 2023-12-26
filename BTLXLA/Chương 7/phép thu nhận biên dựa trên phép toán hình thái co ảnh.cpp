#include <iostream>
#include <vector>
using namespace std;
int main(){
    int seSize;
    cin>>seSize;
    int structuringElement[seSize][seSize]={0};
    for(int i=0;i<seSize;i++){
        for(int j=0;j<seSize;j++){
            cin>>structuringElement[i][j];
        }
    }
    int imageSize;
    cin>>imageSize;
    int image[imageSize][imageSize]={0};
    int result[imageSize][imageSize];
    for(int i=0;i<imageSize;i++){
        for(int j=0;j<imageSize;j++){
            cin>>image[i][j];
            result[i][j]=0;
        }
    }
    int d=imageSize-seSize+1;
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
        	int flag=0;
            for(int k=0;k<seSize;k++){
                for(int l=0;l<seSize;l++){
                	if(structuringElement[k][l]==1&&image[i+k][j+l]==0) flag=1;
                }
            }
            if(flag==0) result[i+seSize/2][j+seSize/2]=1;
            else result[i+seSize/2][j+seSize/2]=0;
        }
    }
    for(int i=0;i<imageSize;i++){
        for(int j=0;j<imageSize;j++){
        	cout<<image[i][j]-result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}