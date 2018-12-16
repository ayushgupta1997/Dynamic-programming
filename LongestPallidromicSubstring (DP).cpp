/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : [2018-12-16 11:54]	
  
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

int main()  {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int t;
    cin >> t;
    while(t--) {
    	string s;
    	cin >> s;
    	int  n = s.length();
        int dp[n+1][n+1];
        for (int i=0; i<=n ;i++) {
            for (int j=0; j<=n; j++) {
                dp[i][j]=false;
            }
        }
        int maxLength=1;
        int start = 0;
        rep(i,0,n) {
            dp[i][i]=true;
        }
        bool flag=0;
        rep(i,0,n-1) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                if(flag==0) {
                    maxLength = 2;
                    start = i;
                    flag=1;
                }
            }
        }
        for (int len=3; len<=n; len++) { // length
            for (int initial=0; initial < n-len+1; initial++) {
                int end = initial+len-1;
                if(s[initial] == s[end] && dp[initial+1][end-1]) {
                    dp[initial][end] = true;
                    if(len>maxLength) {
                        maxLength = len;
                        start = initial;
                    }    
                    
                }
            }
        }
        cout<<s.substr(start,maxLength)<<endl;
    }
	
	return 0;

}
