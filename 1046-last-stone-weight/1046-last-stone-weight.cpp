class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //we will use max heap as it will stores all stones and give us the heaviest one
        priority_queue<int> pq;

        //pushing all stones into a queue
        for(int s:stones){
            pq.push(s);
        }

        //continue until we have 0 or 1 stone left
        while(pq.size()>1){
            //picking the heaviest stone from top

            int y=pq.top();
            pq.pop();

            //picking second heaviest stone
            int x=pq.top();
            pq.pop();

            //if they are equal ->both will be destroyed
            if(x!=y){
                pq.push(y-x);
            }

        }
        if(pq.empty())return 0;

        return pq.top();
    }
};