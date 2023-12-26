#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void medianFilter(std::vector<std::vector<int>>& image){
    int height=image.size();
    int width=image[0].size();
    std::vector<std::vector<int>>result(height,std::vector<int>(width));
    for(int y=1;y<height-1;y++){
        for(int x=1;x<width-1;x++){
            std::vector<int>neighbors;
            for(int dy=-1;dy<=1;dy++){
                for(int dx=-1;dx<=1;dx++){
                    neighbors.push_back(image[y+dy][x+dx]);
                }
            }
            std::sort(neighbors.begin(),neighbors.end());
            result[y][x]=neighbors[4];
        }
    }
    image=result;
}
int main(){
    int size;
    cin>>size;
    std::vector<std::vector<int>>image(size,std::vector<int>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>image[i][j];
        }
    }
    medianFilter(image);
    for(int y=1;y<image.size()-1;y++){
        for(int x=1;x<image[y].size()-1;x++){
            cout<<image[y][x]<<" ";
        }
        cout<<endl;
    }
}