#include <algorithm>
#include <iostream>
#include <vector>
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
    srand(time(0)); // seed random number generator

    vector<int> sizes = {100, 200, 400, 800, 1600, 3200, 6400}; // you can stop early if it's too slow

    for (int n : sizes) {
        vector<int> nums;

        // Add random numbers
        for (int i = 0; i < n - 3; ++i) {
            nums.push_back(rand() % 200001 - 100000); // Range: -100000 to 100000
        }

        // Ensure one valid triplet: -a, -b, a + b
        int a = rand() % 1000 + 1;
        int b = rand() % 1000 + 1;
        nums.push_back(-a);
        nums.push_back(-b);
        nums.push_back(a + b);

        // Shuffle to randomize positions
        random_shuffle(nums.begin(), nums.end());

        // Time the function
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = threeSum(nums);
        auto end = chrono::high_resolution_clock::now();

        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

        cout << "Input size: " << n << " -> Time: " << time_ms << " ms, Found triplets: " << result.size() << endl;
    }

    return 0;
}
