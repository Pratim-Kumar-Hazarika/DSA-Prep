#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool isPossible(int day, vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    int cnt = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (bloomDay[i] <= day) {
            cnt++;
        } else {
            total += cnt / k;
            cnt = 0;
        }
    }
    total += cnt / k;

    return total >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long val = 1LL * m * k;
    int n = bloomDay.size();
    if (n < val) return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    int low = mini, high = maxi;
    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (isPossible(mid, bloomDay, m, k)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << "Minimum days = " << minDays(bloomDay, m, k) << endl;
    // Expected output: 3

    return 0;
}
