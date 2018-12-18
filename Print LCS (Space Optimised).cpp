/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : 18/12/18
  
 */

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

void lcs(string a, string b, int n, int m) {
	int dp[2][m+1];
	SET(dp,0);
	int mx=0, end=0;
	for (int i = 1; i <= n; i++) {
		int q = i&1;
		for (int j = 1; j<=m; j++) {
			if(a[i-1] == b[j-1]) {
				dp[q][j] = dp[1-q][j-1]+1;
				if(dp[q][j] > mx) {
					mx = dp[q][j];
					end = i;
				} 
			}
		}
	}
	cout << a.substr(end-mx,mx);
}

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string a,b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    lcs(a, b, n, m);
	  return 0;

}
