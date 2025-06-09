class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq(stones.begin(), stones.end());

        while(pq.size() > 1){
            int it1 = pq.top();
            pq.pop();

            int it2 = pq.top();
            pq.pop();

            printf("%d %d\n", it1, it2);

            if(it1 - it2 > 0){
                pq.push(it1 - it2);
            }
        }
        
        return (pq.empty()) ? 0 : pq.top();
    }
};