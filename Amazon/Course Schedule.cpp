Question: https://leetcode.com/problems/course-schedule/

Input:
int V = 4; // Number of courses
vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
};

Output: true    // Or if you want, you can display topo sort vector

TC: O(v+e), SC: O(v+e)

Topo sort using BFS:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        queue<int> q;
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(int it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(int i : adj[node]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }

        return topo.size() == V;
    }
};

int main() {
    Solution sol;
    int V = 4; // Number of courses
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    if(sol.canFinish(V, prerequisites)) {
        cout << "It is possible to finish all courses." << endl;
    } else {
        cout << "It is NOT possible to finish all courses." << endl;
    }

    return 0;
}
