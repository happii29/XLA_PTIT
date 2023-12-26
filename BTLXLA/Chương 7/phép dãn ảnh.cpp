#include <iostream>
#include <vector>
using namespace std;
int main(){
    int seSize,x;
    cin>>seSize;
    int se[seSize][seSize];
    for(int i=0;i<seSize;i++){
    	for(int j=0;j<seSize;j++){
    		cin>>se[i][j];
		}
	}
    int imageSize;
    cin>>imageSize;
    int image[imageSize+2][imageSize+2];
    int result[imageSize][imageSize];
    for(int i=0;i<imageSize+2;i++){
    	for(int j=0;j<imageSize+2;j++){
    		image[i][j]=0;
		}
	}
	for(int i=1;i<=imageSize;i++){
		for(int j=1;j<=imageSize;j++){
			cin>>x;
			image[i][j]=x;
			result[i-1][j-1]=0;
		}
	}
    int d=imageSize-seSize+3;
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
        	int flag=0;
            for(int k=0;k<seSize;k++){
                for(int l=0;l<seSize;l++){
                	if(se[k][l]==1&&image[i+k][j+l]==1) flag=1;
                }
            }
            if(flag==1) result[i+seSize/2-1][j+seSize/2-1]=1;
        }
    }
    for(int i=0;i<imageSize;i++){
        for(int j=0;j<imageSize;j++){
        	cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;