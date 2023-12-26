/**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector
#define ii pair<int, int>
#define all(x) (x).begin(), (x).end()
const int N = 2e3 + 5;


int a[N][N],b[N][N];
int loctrungvi(int x,int y){
    int tm[10];
    int k = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            tm[k++] = a[x + i][j + y];
    
    sort(tm,tm + k);
    return tm[k / 2];
}

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            b[i][j] = 0;
        }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i > 0 && i <= n - 2 && j > 0 && j <= m - 2){
                b[i + 1][j + 1] = loctrungvi(i,j);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << b[i][j] << " \n"[j == m];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("in.txt","r",stdin);

    
    int t = 1;

    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
