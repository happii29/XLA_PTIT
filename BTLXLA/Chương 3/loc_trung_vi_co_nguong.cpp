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
    int n,m,phi;
    cin >> n >> m >> phi;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            b[i][j] = 0;
        }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i <= n - 2 && j <= m - 2){
                int tmp = loctrungvi(i,j);
                // b[i + 1][j + 1] = tmp;
                b[i + 1][j + 1] = (abs(tmp - a[i + 1][j + 1]) <= phi ? a[i + 1][j + 1] : tmp);
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
	freopen("loctrungviconguong.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
