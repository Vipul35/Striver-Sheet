class Solution {
public:
    int maxProfit(vector<int>& a )
                  {
        int buy=a[0];
        int profit=0;
        for(int i=1;i<a.size();i++)
        {
           int sell=a[i]-buy;
            profit=max(sell,profit);
            buy=min(buy,a[i]);
        }
        return profit;
    }
};