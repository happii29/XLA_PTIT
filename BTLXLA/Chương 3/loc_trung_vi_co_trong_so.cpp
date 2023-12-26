/**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector
#define ii pair<int, int>
#define all(x) (x).begin(), (x).end()
const int N = 2e5 + 5;

int n,m;
int a[105][105];
int mask[3][3];
void loctrungvi(int x,int y){
    int tm[1000],k = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int l = 0; l < mask[i][j]; l++){
                tm[k++] = a[i + x][j + y];
            }
            
        }
    }
    sort(tm,tm + k);
    for(int i = 0; i < k; i++)
        cout << tm[i] << " ";
    // return (tm[k / 2]);
}

void solve(){
    
    printf("nhap hang n: " );
    cin >> n; 
    printf("nhap hang m: " );
    cin >> m;
    
    printf("Nhap mang: \n");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    printf("Nhap mask \n");
    for(int i = 0; i < 3; i++)  
        for(int j = 0; j < 3; j++){
            cin >> mask[i][j];
        }
    int x,y;
    printf("nhap diem \n");
    cin >> x >> y;
    printf("%d\n",a[x - 1][y]);
    printf("%d\n",a[x][y]);
    printf("%d\n",a[x + 1][y]);
    loctrungvi(x,y);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
