class Solution {
public:
    int maxProfit(vector<int>& a) {

        int minibuy = a[0], profit = 0;
        int n = a.size();

        for(int i = 1; i < n; i++){
            int currProfit = a[i] - minibuy;
            profit = max(profit, currProfit);
            minibuy = min(minibuy, a[i]);
        }
        return profit;

    }
};
