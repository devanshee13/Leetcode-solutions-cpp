class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int sum =0;
        for(int i =0; i < n; i++){
            int t = timeSeries[i];
            int s = t + duration -1;
           int poisonTime;
           if(i == 0) {
             poisonTime = duration;
            }
            else if(timeSeries[i] - timeSeries[i-1] < duration) {
             poisonTime = timeSeries[i] - timeSeries[i-1];
            }
            else {
            poisonTime = duration;
            }
            sum += poisonTime;
            
        }
        return sum;
    }
};