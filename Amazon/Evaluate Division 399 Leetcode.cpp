Sample input (for example 1):
2
a b
b c
2.0 3.0
5
a c
b a
a e
a a
x x

Output will be:
6.00000
0.50000
-1.00000
1.00000
-1.00000


📊 Time and space complexity analysis:
Let:
n = number of equations
q = number of queries
V = number of unique variables (at most 2*n)

✅ buildGraph:
For each of n equations, adds two edges:
Time: O(n)
Space: O(V^2) in worst case (dense graph), practically O(n)

✅ calcEquation:
For each of q queries: runs DFS
DFS could visit all nodes (V) and edges (E) in worst case
Time: O(q * (V + E))
Since V and E ≤ 2*n, roughly O(q * n)

✅ Overall:
Time complexity: O(n + q * n) ≈ O(q * n)
Space complexity: O(V^2) for graph + O(V) for visited set ≈ O(n)



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string node, string &dest, unordered_map<string, unordered_map<string, double>> &gr, unordered_set<string> &vis, double &ans, double temp){
        if(vis.find(node) != vis.end()) return;

        vis.insert(node);
        if(node==dest){
            ans= temp;
            return;
        }

        for(auto ne : gr[node]){
            dfs(ne.first, dest, gr, vis, ans, temp*ne.second);
        }
    }

    unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>>& equations, const vector<double>& values){
        unordered_map<string, unordered_map<string, double>> gr;
        for(int i=0;i<equations.size();i++){
            string dividend= equations[i][0];
            string divisor= equations[i][1];
            double value= values[i];

            gr[dividend][divisor]= value;
            gr[divisor][dividend]= 1.0/value;
        }
        return gr;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> gr= buildGraph(equations, values);
        vector<double> finalAns;
        for(auto query: queries){
            string dividend = query[0];
            string divisor = query[1];

            if(gr.find(dividend)==gr.end() || gr.find(divisor)==gr.end()) finalAns.push_back(-1.0);
            else{
                unordered_set<string> vis;
                double ans= -1, temp = 1.0;
                dfs(dividend, divisor, gr, vis, ans, temp);
                finalAns.push_back(ans);
            }
        }

        return finalAns;
    }
};

int main() {
    int n;
    cin >> n; // number of equations
    vector<vector<string>> equations(n, vector<string>(2));
    for(int i=0; i<n; i++){
        cin >> equations[i][0] >> equations[i][1];
    }

    vector<double> values(n);
    for(int i=0; i<n; i++){
        cin >> values[i];
    }

    int q;
    cin >> q; // number of queries
    vector<vector<string>> queries(q, vector<string>(2));
    for(int i=0; i<q; i++){
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution sol;
    vector<double> res = sol.calcEquation(equations, values, queries);
    cout << fixed << setprecision(5);
    for(double num : res){
        cout << num << endl;
    }

    return 0;
}
