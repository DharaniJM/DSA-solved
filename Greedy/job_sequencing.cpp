

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &dl, vector<int> &pt) {
        
        int n= dl.size();
        vector<pair<int,int>> jobs;
        
        for(int i=0; i<n; i++) {
            jobs.push_back({dl[i],pt[i]});
        }
        sort(jobs.begin(),jobs.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto x :jobs) {
            if(x.first > pq.size()) {
                pq.push(x.second);
            }else if(!pq.empty()  && pq.top() < x.second){
                pq.pop();
                pq.push(x.second);
            }
        }
        
        vector<int> ans ={0,0};
        while(!pq.empty()) {
            ans[1]+=pq.top();
            pq.pop();
            ans[0]++;
        }
        return ans;
    }
};