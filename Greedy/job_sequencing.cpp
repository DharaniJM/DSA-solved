/*
Problem Summary: Job Scheduling for Max Profit
You are given:

Two arrays:
deadline[]: Deadline by which each job must be completed.
profit[]: Profit earned if that job is completed on or before its deadline.
Each job takes 1 unit of time.
Only one job can be scheduled at a time (no parallel jobs).

Objective
Schedule jobs in such a way that:
No job misses its deadline.
Total profit is maximized.

Return:
The number of jobs successfully scheduled.
The maximum profit earned from those jobs.
*/
//+++++++++++++++  Solution ++++++++++++

/*
Greedy Algorithms

Job Sequencing Problem
- [Problem Link](https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)
- Approach: Sort by deadline, use Min-Heap to track top profits within allowed deadlines.
- Time Complexity: O(n log n)
*/


class Solution {
  public:
    vector<int> jobSequencing(vector<int> &dl, vector<int> &pt) {
        
        int n= dl.size();
        vector<pair<int,int>> jobs;
        
        //Pushing the deadline and profit as pair for easy sorting and handling
        for(int i=0; i<n; i++) {
            jobs.push_back({dl[i],pt[i]});
        }
        // Sort By deadLines asscending..=>O(nlogn)
        sort(jobs.begin(),jobs.end());
        
        //Min heap Implementation for picking top profitable Jobs
        //here insertion takes O(logn) and picking first small elements O(1).
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto x :jobs) {
            // check for deadline by pq size..
            if(x.first > pq.size()) {
                pq.push(x.second);


             // if the top profit is mall then curr profit then we do following instruction    
            }else if(!pq.empty()  && pq.top() < x.second){
                pq.pop();
                pq.push(x.second);
            }
        }
        // storing in ans vector for returing
        vector<int> ans ={0,0};
        while(!pq.empty()) {
            ans[1]+=pq.top();
            pq.pop();
            ans[0]++;
        }
        return ans;
    }
};



