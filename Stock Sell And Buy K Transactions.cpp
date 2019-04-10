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
        int n, k;
        cin >> k >> n;
        int price[n];
        for (int i = 0; i < n; i++) {
            cin >> price[i];
        }
        
        int profit[k+1][n+1]; // profit with atmost k transactions till ith day
        for (int i=0; i<=k; i++) {
            profit[i][0] = 0;
        }
         for (int i=0; i<=n; i++) {
            profit[0][i] = 0;
        }

        for(int i=1; i<=k ;i++) {
            for (int j=1; j<n; j++) {
                int temp = INT_MIN;
                for (int day = 0; day<j; day++) {
                    temp = max(temp, price[j]-price[day]+profit[i-1][day]);
                }
                profit[i][j] = max(profit[i][j-1], temp);
            }
        }
        cout << profit[k][n-1]<<endl;
    }

return 0;
}
