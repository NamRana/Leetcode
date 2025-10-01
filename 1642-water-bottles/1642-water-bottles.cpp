class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=numBottles; //total bottles we can drink
        int empty=numBottles; //initally all will become empty after drinking

        while(empty>=numExchange){
            int newBottles=empty/numExchange;
            total+=newBottles;
            empty=empty%numExchange+newBottles;
        }
        return total;
    }
};