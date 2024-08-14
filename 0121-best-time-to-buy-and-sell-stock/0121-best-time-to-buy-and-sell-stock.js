/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let start = 0;
    let end = 1;
    let profit = 0;
    
    if (prices.length < 2 || prices == null) {
        return 0;
    }
    
    while (end < prices.length) {
        if (prices[end] < prices[start]) {
            start++;
        } else {
            if (prices[end] - prices[start] > profit) {
                profit = prices[end] - prices[start];
            }
            end++;
        }
    }
    
    return profit;
};