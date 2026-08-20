class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        vector<bool> result;
        for(int i=0; i < candies.size(); i++){
            maxi = max(candies[i], maxi);
        }
        for( int j=0; j < candies.size(); j++){
            if(candies[j] + extraCandies >= maxi){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};