class Solution {
public:
    int countVowelStrings(int n) {
        // C(n+4, 4) = (n+4)(n+3)(n+2)(n+1) / 24
        long long res = 1;
        for (int i = 1; i <= 4; i++) {
            res = res * (n + i) / i;
        }
        return res;
    }
};
