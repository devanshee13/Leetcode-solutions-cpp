class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustedBy(n + 1, 0);
        vector<int> trusts(n + 1, 0);
        for (auto t : trust) {

            int a = t[0];
            int b = t[1];

            trusts[a]++;
            trustedBy[b]++;
        }
        for (int i = 1; i <= n; i++) {
             if (trustedBy[i] == n - 1 && trusts[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};