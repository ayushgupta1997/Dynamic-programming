/*

  author      : (ayushgupta1997)
  Modified On : [2018-12-14 12:15]	
  
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

int count(string s, int n) {
	bool dp[n][n];
	SET(dp,0);
	int ans = 0;
	for(int i = 0; i < n; i++) dp[i][i]=1;
	for (int i = 0; i < n-1; i++) {
		if(s[i]==s[i+1]) {
			ans++;
			dp[i][i+1]=1;
		}
	}
	for (int gap = 2; gap < n; gap++) {
		for (int i = 0; i < n-gap; i++) {
			int j = i+gap;
			if((s[i]==s[j]) && (dp[i+1][j-1])) {
				dp[i][j]=1;
				ans++;
			}
		}
	}		
	return ans;
}
int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    int n = s.size();
    //of length greater than 2;
    cout << count(s, n);
    
	return 0;

}
