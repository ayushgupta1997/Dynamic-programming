#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define rep(i, a, b)             for(int i = a; i < b; i++)
#define REP(i, a, b)             for(int i = a; i <= b; i++)
#define sc(n)                    scanf("%d",&n)
#define sc2(a,b)                 scanf("%d%d", &a, &b) 
#define pb                       push_back
#define ff                       first
#define ss                       second
#define mp                       make_pair
#define mt                       make_tuple
#define SET(a, b)                memset(a,b,sizeof(a)) 
#define all(v)                   (v).begin(),(v).end()
#define rall(v)                  (v).rbegin(),(v),rend()
#define MAX 200005
#define MOD 1000000007

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef double ld;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        string a, b;
        cin >> n >> m;
        cin >> a >> b;
        int dp[n+1][m+1];
        int ans=0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if(i==0 || j==0) {
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1]) {   // when this condition holds true we get the substrings
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(dp[i][j],ans);
                }
                else { 
                    dp[i][j]=0;
                }
            }
        }
        cout <<  ans;
        cout << endl;
    }

return 0;
}
