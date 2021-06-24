#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
using namespace std;
const int nMax = 10001;
const int oo = 2000000000;
int n, m, a[1001][1001], meme[1001][1001], kq[1001][1001], sl, vt[1001][1001] ;
bool ok = true;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1 , 0, -1};
bool vst[1001][1001];

void enter() {
    cin >> n >> m;
    for (int i =1; i <= n; i++)
    for (int j =1; j <= m ;j++) {
        cin >> a[i][j];
        meme[i][j] = a[i][j];
    }

}
void Intalize() {
    for (int i = 1; i <= n; i++)
            for (int j =1; j <= m; j++) {
                vt[i][j] = -1;
            }
    sl = m*n;

    kq[1][1] = kq[n][m] = kq[1][m] = kq[n][1] = 2;
    for (int i = 2; i <= m -1; i++) {
        kq[1][i] = kq[n][i] =  3;
    }
    for (int i = 2; i <= n - 1; i++) {
        kq[i][1] = kq[i][n] = 3;
    }
    for (int i = 1; i <= n; i++) {
        for (int j =1; j <= m; j++) if (!kq[i][j]) kq[i][j] = 4;
    }
}

bool Check(int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void update (int i, int j, int t) {
    if (vt[i][j]>0) return;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (Check(x, y)) {
            kq[x][y]--;
            a[x][y] -= t;
        }

    }
    vt[i][j] = t;
    sl--;
}
void updatexd(int i ,int j, int t) {
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k] ;
        if (Check(x, y))
        update(x, y, t);
    }
}
void Solve()
{
    ok = true;
    while (ok )
     {
        ok = false;
        for (int i = 1 ; i <= n ; i++)
            for (int j = 1; j <= m ; j++)
                if (kq[i][j] > 0 && a[i][j] == kq[i][j])
                    {
                        ok = true;
                        updatexd(i, j , 1);
                    }

         for (int i = 1; i <= n; i++)
            for (int j =1; j <= m; j++)
                if (a[i][j] == 0 && kq[i][j] > 0)
                {
                    ok = true;
                    updatexd(i, j, 0);
                }

     }
}
void Result() {

    if (sl >= 0 ) cout << "NO"<<'\n';
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m ;j++) {
                int tmp = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (Check(x, y))
                    tmp += vt[x][y];
                }
                if (tmp != meme[i][j]) {
                    cout << "NO\n";
                    return;
                }

            }
        }
        cout <<"YES\n";

    }
}

int main() {
    freopen("CANSU.INP" , "r", stdin);
    freopen("CANSU.OUT" , "w", stdout);
  //  int tc;
  //  cin >> tc;

    enter();
    Intalize();
    Solve();
    Result();





}
