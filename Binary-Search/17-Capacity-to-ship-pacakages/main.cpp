#include <iostream>
#include <vector>
#include <numeric>  
#include <climits>
using namespace std;

int totalDays(int cap, vector<int>& weights) {
    int days = 1, load = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days++;
            load = weights[i];
        } else {
            load += weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int low = maxi, high = sum;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (totalDays(mid, weights) <= days) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    int result = shipWithinDays(weights, days);
    cout << "Minimum capacity required = " << result << endl;

    return 0;
}
