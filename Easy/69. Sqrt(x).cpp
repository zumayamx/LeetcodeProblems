class Solution {
public:
    int mySqrt(int x) {
        // If the number is less than 2, return the same
        // number
        if (x < 2) return x;

        // Define the number to compare against to x
        long num;

        // Define the boundary of the binary search
        int pivot, left = 2, right = x / 2;

        while (left <= right)
        {
            pivot = left + (right - left) / 2;
            num = (long)pivot * pivot;
            if (num > x) right = pivot - 1;
            else if (num < x) left = pivot + 1;
            else return pivot;
        }
        return right;
    }
};
