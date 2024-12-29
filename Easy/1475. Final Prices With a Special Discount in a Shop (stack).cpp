class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Get the length of the prices array
        int n = prices.size();

        // Declare a stack to save the indices of the
        // elements that don't have a discount yet
        stack<int> index;

        // Copy the prices array into a result vector.
        // This helps to preserve the original values for
        // elements that don't have a discount available
        vector<int> result = prices;

        // Iterate over the prices array
        for (int i = 0; i < n; i++) {
            // While the current price can serve as a discount
            // for the element at the top of the stack,
            // calculate and save the modified price in the result vector
            while (!index.empty() && prices[index.top()] >= prices[i]) {
                result[index.top()] = prices[index.top()] - prices[i];

                // Remove the top element from the stack since we found its discount
                index.pop();
            }
            // Push the current index onto the stack
            index.push(i);
        }
        return result;
    }
};
