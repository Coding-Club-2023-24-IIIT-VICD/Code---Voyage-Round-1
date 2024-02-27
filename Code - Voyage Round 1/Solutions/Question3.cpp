#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 1; len <= n; ++len) {
        for (int start = 1; start <= n - len + 1; ++start) {
            int end = start + len - 1;

            for (int burst = start; burst <= end; ++burst) {
                int energy = nums[start - 1] * nums[burst] * nums[end + 1] + dp[start][burst - 1] + dp[burst + 1][end];
                dp[start][end] = max(dp[start][end], energy);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
