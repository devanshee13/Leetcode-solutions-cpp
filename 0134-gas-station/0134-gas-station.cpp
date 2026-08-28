class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank =0;
        int start =0;
        int total=0;
        int n = gas.size();
        for(int i =0; i < n; i++){
            tank = tank -cost[i] +gas[i];
            total = total -cost[i] +gas[i];
            if(tank < 0){
                start = i+1;
                tank =0;
            }

            
        }
        if(total<0){
            return -1;
        }
        return start;
    }
};