#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaximumLength(vector<int>& nums) {
    const long long INF = 1e16 + 7; 
    vector<pair<int, long long> > dp(nums.size(), {0, INF});
    vector<long long> pref(nums.size(), 0);
    pref[0] = nums[0]; 
    for (int i = 1; i < nums.size(); i++) {
        pref[i] = pref[i - 1] + nums[i]; 
    }
    dp[0].first = 1;
    dp[0].second = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] >= dp[i - 1].second) {
            dp[i].first = max(dp[i - 1].first + 1, dp[i].first); 
            if (dp[i - 1].first + 1 == dp[i].first) {
                dp[i].second = min(dp[i].second, (long long)nums[i]);
            }
        } else {
            dp[i].first = max(dp[i].first, dp[i - 1].first); 
            if (dp[i].first == dp[i - 1].first) {
                dp[i].second = min(dp[i].second, dp[i - 1].second + (long long)nums[i]);    
            }
        }
        int lo = i; int hi = nums.size() - 1, idx = -1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2; 
            if (pref[mi] - pref[i - 1] >= dp[i - 1].second) {
                idx = mi;
                hi = mi - 1; 
            } else {
                lo = mi + 1; 
            }
        }
        if (idx != -1) {
            dp[idx].first = max(dp[idx].first, dp[i - 1].first + 1);
            if (dp[idx].first == dp[i - 1].first + 1) {
                dp[idx].second = min(dp[idx].second, pref[idx] - pref[i - 1]);
            }
        }
    }
    return dp.back().first;
}

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = findMaximumLength(nums);
    cout << ans;
}