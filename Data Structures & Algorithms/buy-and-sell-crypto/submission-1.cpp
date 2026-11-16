class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int min_price_idx = 0, next_max_price_idx = 0;
        for (int i=1;i<prices.size();i++) {
            cout << "min_price_idx: " << min_price_idx << ',' << 
            "next_max_price_idx: " << next_max_price_idx << '\n';
            cout << prices[min_price_idx] << ' ' << prices[i] << '\n';
            if (prices[min_price_idx] > prices[i]) {
                min_price_idx = i;
                continue;
            }
            next_max_price_idx = i;
            for (int j=i;j<prices.size();j++) {
                if (prices[min_price_idx] > prices[j]) {
                    i = j-1;
                    cout << "i: " << i << '\n';
                    break;
                }
                if (prices[j] > prices[next_max_price_idx])
                    next_max_price_idx = j;
            }
            profit = max(profit, prices[next_max_price_idx] - prices[min_price_idx]);
            cout << "profit: " << profit << '\n';
        }

        return profit;
    }
};
