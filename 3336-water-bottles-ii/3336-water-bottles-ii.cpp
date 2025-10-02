class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total=numBottles; //total bottles drunk
        int empty=numBottles; //empty bottles after drinking

        while(empty>=numExchange){
            //exchange "numExchange" empty bottles for 1 full bottles
            empty-=numExchange;
            numExchange++; //next exchange cost more
            total+=1;
            empty+=1;
        }

        return total;
    }
};