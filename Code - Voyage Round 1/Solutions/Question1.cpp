#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> inp;
    inp.reserve(n);

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        inp.push_back(a);
        if (a % 2 == 1) {
            res += a;
        }
        cout << res << " ";
    }

    return 0;
}