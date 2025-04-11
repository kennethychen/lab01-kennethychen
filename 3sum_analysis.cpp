#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <random>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> trips;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                for (int k = 0; k < nums.size(); ++k) {
                    if (i != j && i != k && j != k) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> curr = {nums[i], nums[j], nums[k]};
                            sort(curr.begin(), curr.end());
                            bool isDuplicate = false;
                            for (int l = 0; l < trips.size(); l++) {
                                if (trips[l] == curr) {
                                    isDuplicate = true;
                                    break;
                                }
                            }
                            if (!isDuplicate) {
                                trips.push_back(curr);
                            }
                        }
                    }
                }
            }
        }
        return trips;
    }
};

int main() {
    srand(time(0));
    vector<int> sizes = {100, 200, 400, 800, 1600, 3200, 6400};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> big(-100000, 100000);
    uniform_int_distribution<> small(1, 1000);
    for (int n : sizes) {
        vector<int> nums;
        for (int i = 0; i < n - 3; ++i) {
            nums.push_back(big(gen));
        }
        int a = small(gen);
        int b = small(gen);
        nums.push_back(-a);
        nums.push_back(-b);
        nums.push_back(a + b);
        shuffle(nums.begin(), nums.end(), gen);
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = threeSum(nums);
        auto end = chrono::high_resolution_clock::now();
        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
        cout << "n = " << n << " - time = " << time_ms << " ms, triplets: " << result.size() << endl;
    }
    return 0;
}
