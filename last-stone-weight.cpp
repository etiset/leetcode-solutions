class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> qu;

        for(int st: stones){
            qu.push(st);
        }

        while(qu.size() > 1){
            int a = qu.top();
            qu.pop();
            int b = qu.top();
            qu.pop();

            if(a != b){
                qu.push(a - b);
            }
        }

        return qu.size() ? qu.top() : 0;
    }
};