class Solution {
public:
    int twoEggDrop(int n) {
        int k = 0;
        int sum = 0;

        while (sum < n) {
            k++;
            sum += k;
        }

        return k;
    }
};
