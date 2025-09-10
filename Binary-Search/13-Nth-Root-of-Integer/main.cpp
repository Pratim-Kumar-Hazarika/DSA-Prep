#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * mid;
        if (ans > m) return 2; // mid^n > m
    }
    if (ans == m) return 1;   // mid^n == m
    else return 0;            // mid^n < m
}

int NthRoot(int n, int m) {
    int low = 1, high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int root = func(mid, n, m);

        if (root == 1) return mid;     // found exact nth root
        if (root == 2) high = mid - 1; // mid^n > m
        else low = mid + 1;            // mid^n < m
    }
    return -1; // not a perfect nth root
}

int main() {
    int N = 3;
    int M = 27;

    int ans = NthRoot(N, M);
    if (ans == -1)
        cout << M << " is not a perfect " << N << "th root" << endl;
    else
        cout << "The " << N << "th root of " << M << " is: " << ans << endl;

    return 0;
}
