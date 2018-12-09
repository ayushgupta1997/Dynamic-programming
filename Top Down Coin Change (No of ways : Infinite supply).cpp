/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : [2018-12-09 11:59]	
  
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

int dp[100][100]; // assuming max size of [ 100 X 100 ] 

int  Solve(int coins[], int n, int m) {
	if(n == 0) dp[n][m] = 1; // take no coins as such
	if(n<0) return 0;
	if(m == 0) dp[n][m] = 0;
	if(dp[n][m] != -1) return dp[n][m];
	int res = Solve(coins, n-coins[m-1],m) + Solve(coins,n,m-1);
	return dp[n][m]=res;
}

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin >> n >> m;
    //change for n cents and infinite supply of m coins of particular value
    int coins[m];
    rep(i,0,m) cin >> coins[i];
    SET(dp,-1);
    cout << Solve(coins, n, m);
    return 0;

}
