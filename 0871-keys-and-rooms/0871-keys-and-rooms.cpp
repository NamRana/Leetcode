class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size(); //total no of rooms
        vector<bool> visited(n,false); //visited array

        stack<int> st; //using stack for DFS
        st.push(0);//starting from room 0

        while(!st.empty()){
            int room=st.top();//taking one from stack
            st.pop();

            if(!visited[room]){ //if this room is not visited before, mark it is as visited now
                visited[room]=true;
            

            //collect all keys from this room
            for(int key:rooms[room]){
                if(!visited[key]){
                    st.push(key);//push key (room index) into stack
                }
            }
        }

        }
        for(bool v: visited){
            if(!v) return false;
        }
        return true;
    }
};