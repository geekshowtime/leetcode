#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        vector<int> pilesCopy(piles);
        sort(pilesCopy.begin(), pilesCopy.end());
        int right = pilesCopy[pilesCopy.size() - 1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (possible(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool possible(vector<int>& piles, int mid, int h) {
        int time = 0;
        int ii = 0;
        int j = 0;
        for (auto i : piles) {
            ii = ceil(i / double(mid));
            time += ii;
        }
        if (time <= h) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    vector<int> nums{30, 11, 23, 4, 20};
    int h = 5;
    Solution soultion;
    int result = soultion.minEatingSpeed(nums, h);
    cout << "result is: " << result << endl;
    return 0;
}