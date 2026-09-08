class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        set<char> array;
        for(char c: jewels){
            array.insert(c);
        }
        for(char c: stones){

            if(array.count(c)){
                count++;
            }
        }
        return count;
    }
};