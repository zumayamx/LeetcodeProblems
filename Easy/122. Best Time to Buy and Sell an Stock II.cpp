class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // This problem can be confusing, as it was for me.
        // The key to solving it is to focus only on "up" differences.
        // That means we need to sum all the "ups" in the prices to maximize the profit.
        // With this idea in mind:

        // Define a variable for the total profit.
        int total = 0;

        // Iterate over the prices, starting from the second element
        // to avoid out-of-bounds memory access, since
        // we need to find moments when the prices "go up".
        // Compare the current price with the previous price.
        for (int i = 1; i < prices.size(); i++) {
            // If the current price is greater than the previous price,
            // it indicates an "up". In this case, we add the difference 
            // (also referred to as profit) to the total profit.
            // Otherwise, we do nothing.
            if (prices[i] > prices[i - 1]) {
                total += prices[i] - prices[i - 1];
            }
        }
        
        return total;
    }
};
