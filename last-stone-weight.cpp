class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(!pq.empty()){
            int u = pq.top();
            pq.pop();

            if(pq.empty()){
                return u;
            }

            int v = pq.top();
            pq.pop();

            if(u > v){
                pq.push(u - v);
            }
        }

        return 0;
    }
};