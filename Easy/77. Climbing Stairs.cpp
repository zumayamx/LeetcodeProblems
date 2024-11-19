class Solution {
public:
    int climbStairs(int n) {
        // If there is only one step, there is only one way to reach it: take a step of size 1.
        if (n == 1) {
            return 1;
        }

        // Create a `dp` array where `dp[i]` will represent the number of ways
        // to reach step `i` following the problem's constraints
        // (steps of size 1 or 2). We include `n + 1` positions because
        // we need to consider up to step `n`.
        int dp[n + 1];

        // BASE CASES:
        // Step 1: There is only one way to reach it: take a step of size 1.
        dp[1] = 1;

        // Step 2: There are two ways to reach it:
        // 1. Take two steps of size 1: [1, 1].
        // 2. Take one step of size 2: [2].
        dp[2] = 2;

        // Recurrence relation:
        // For steps greater than or equal to 3, calculate the total number of ways to reach them
        // by summing the possible combinations from the previous step (`dp[i-1]`)
        // and the step before the previous one (`dp[i-2]`).
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // EXAMPLE WITH dp[3]:
        // We want to calculate `dp[3]`:
        // 1. Combinations from `dp[2]` (step 2):
        //    - Combinations in `dp[2]`: [1, 1], [2].
        //    - Add a step of size 1 to reach step 3:
        //      - [1, 1] + 1 = [1, 1, 1].
        //      - [2] + 1 = [2, 1].
        // 2. Combinations from `dp[1]` (step 1):
        //    - Combination in `dp[1]`: [1].
        //    - Add a step of size 2 to reach step 3:
        //      - [1] + 2 = [1, 2].
        //
        // Total combinations for `dp[3]`: [1, 1, 1], [2, 1], [1, 2].
        // Therefore, `dp[3] = 3`.
        // A general property observed here is that combinations from [i - 1]
        // always end with a step of size 1, while combinations from [i - 2]
        // always end with a step of size 2. These are independent but
        // are summed to give the total combinations to reach a step.

        // Return the total number of ways to reach step `n`.
        return dp[n];
    }
};
