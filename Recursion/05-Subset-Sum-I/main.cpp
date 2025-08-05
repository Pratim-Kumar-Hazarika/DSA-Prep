#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

void func(int ind, int sum, vector<int>& arr, int N, vector<int>& subSet) {
    if (ind == N) {
        subSet.push_back(sum);
        return;
    }
    // pick
    func(ind + 1, sum + arr[ind], arr, N, subSet);

    // not pick
    func(ind + 1, sum, arr, N, subSet);
}

vector<int> subSetSum(vector<int> arr, int N) {
    vector<int> subSet;
    func(0, 0, arr, N, subSet);
    sort(subSet.begin(), subSet.end());
    return subSet;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int N = arr.size();

    vector<int> result = subSetSum(arr, N);

    cout << "Subset sums: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
