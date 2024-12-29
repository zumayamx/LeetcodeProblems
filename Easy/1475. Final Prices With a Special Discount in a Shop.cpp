class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        // This is a brute force solution that uses two nested loops to find the discount.

        // Get the length of the prices array
        int n = prices.size();

        // Copy the prices array to modify by applying the discounts.
        // This helps to preserve prices for cases where no valid discount exists.
        vector<int> final_prices = prices;

        // Iterate over the prices array to find the corresponding discount
        for (int i = 0; i < n; i++)
        {
            // Check the elements that come after the current price
            for (int j = i + 1; j < n; j++)
            {
                // If the price is less than or equal to the current price,
                // apply the discount by updating the final price
                if (prices[j] <= prices[i])
                {
                    final_prices[i] = prices[i] - prices[j];

                    // Break to avoid further unnecessary iterations
                    break;
                }
            }
        }
        return final_prices;
    }
};
