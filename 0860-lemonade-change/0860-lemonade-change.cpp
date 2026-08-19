class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five=0;
        int ten=0;
        int twenty=0;
        if(bills[0] != 5){
            return false;
        }
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five>=1){
                five--;
                }
                else{
                    return false;
                }
                ten++;
            }
            else if(bills[i]==20){
                if((five>=1 && ten>=1)||(five>=3)){
                    if((five>=1 && ten>=1)&&(five>=3)){
                        ten--;
                        five--;
                    }
                    else if(five>=3){
                        five-=3;
                    }
                    else{
                        five--;
                        ten--;
                    }
                }
                else{
                    return false;
                }
                twenty++;
            }

           
        }
        return true;
    
    }
};