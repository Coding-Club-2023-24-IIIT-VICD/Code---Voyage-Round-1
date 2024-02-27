#include <iostream>
#include <vector>
#include <limits>
#include <climits>
using namespace std;

int main() {
    int n, target_sum;
    cin >> n >> target_sum;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = -1, r = -1;
    int curSize = INT_MAX;
    int start = 0, end = 0;
    int curSum = 0;

    while (end < n) {
        curSum += v[end];
        while (curSum > target_sum) {
            curSum -= v[start];
            start++;
        }
        if (curSum == target_sum && (end - start + 1) <= curSize) {
            curSize = end - start + 1;
            l = start;
            r = end;
        }
        end++;
    }

    if (l == -1 && r == -1) {
        cout << "";
        return 0;
    }

    for (int i = l; i <= r; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
