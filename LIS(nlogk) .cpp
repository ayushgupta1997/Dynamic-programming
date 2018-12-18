#include <bits/stdc++.h>

using namespace std;

int inf = 10000000;
// Complete the longestIncreasingSubsequence function below.
int longestIncreasingSubsequence(vector<int> arr) {
    int len = arr.size();
    int I[len+1];
    int L[len];
    I[0] = -inf;
    for (int i = 1; i <= len; i++) {
        I[i] = inf;
    }
    int lislen = 0;
    for (int i = 0; i <len; i++) {
        int low = 0, high = lislen;
        while(low <= high) {
            int mid = (low+high)/2;
            if(I[mid] < arr[i]) low = mid+1;
            else high = mid-1;
        }
        //cout << low << " ";
        I[low] = arr[i];
        L[i] = low;
        if(low > lislen) {
            lislen = low;
        }
    }
    int pos;
    int max = -1;
    for (int i = 0; i < len; i++) {
        if(L[i] > max) {
            max=L[i];
            pos = i;
        }
    }
    // printing of the LIS takes place here : )
    vector<int> ans(lislen);
    ans.push_back(max);
    bool vis[lislen+1] = {0};
    vis[max] = 1;
    max--;
    for (int i = pos-1; i >= 0; i++) {
        if(L[i] == max && !vis[max]) {
            vis[max] = 1;
            ans.push_back(max);
            max--;
        }
    }
    for (int i = lislen-1; i >=0; i--) {
        cout << ans[i] << " ";
    }
    
    return lislen;

}

int main()
{
   int n;
   cin >> n;
   vector<int> arr(n);
   for (int i = 0; i < n; i++) {
    cin >> arr[i];
   }

    int result = longestIncreasingSubsequence(arr);

    cout  << result << "\n";

    //fout.close();

    return 0;
}
