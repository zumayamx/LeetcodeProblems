#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Return the number of maximum bouquets that can be made on day mid.
    int getNumOfBouquets(vector<int>& bloomDay, int mid, int k) {
        int numOfBouquets = 0;
        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            // If the flower is bloomed, add to the set. Else reset the count.
            if (bloomDay[i] <= mid) {
                count++;
            } else {
                count = 0;
            }

            if (count == k) {
                numOfBouquets++;
                count = 0;
            }
        }
        cout << "NUM_B: " << numOfBouquets << endl;
        return numOfBouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = 0;
        for (int day : bloomDay) {
            end = max(end, day);
        }

        int minDays = -1;
        while (start <= end) {
            cout << "START: " << start << endl;
            cout << "END: " << end << endl;
            int mid = (start + end) / 2;
            cout << "MID: " << mid << endl;
            if (getNumOfBouquets(bloomDay, mid, k) >= m) {
                minDays = mid;
                end = mid - 1;
                cout << "END: " << end << endl;
            } else {
                start = mid + 1;
            }
        }

        return minDays;
    }
};

int main() {
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;

    Solution n;
    cout << n.minDays(bloomDay, m, k) << endl;
    return 0;
}