class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0; // No prices means no profit
        }

        int n = prices.length;

        // Initialize variables for first and second transactions
        int firstBuy = Integer.MIN_VALUE; // The maximum profit after first buy
        int firstSell = 0; // The maximum profit after first sell
        int secondBuy = Integer.MIN_VALUE; // The maximum profit after second buy
        int secondSell = 0; // The maximum profit after second sell

        for (int i = 0; i < n; i++) {
            // Update the first buy
            firstBuy = Math.max(firstBuy, -prices[i]);
            // Update the first sell
            firstSell = Math.max(firstSell, firstBuy + prices[i]);
            // Update the second buy
            secondBuy = Math.max(secondBuy, firstSell - prices[i]);
            // Update the second sell
            secondSell = Math.max(secondSell, secondBuy + prices[i]);
        }

        // The maximum profit after two transactions
        return secondSell;
    }
}