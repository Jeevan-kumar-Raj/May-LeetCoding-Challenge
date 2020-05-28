Day-6 Possible Bipartition.cpp

/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

*/

// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(N);
        for (const auto& dislike : dislikes) {
            int u = dislike[0] - 1, v = dislike[1] - 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        
        vector<int> color(N);
        color[0] = 1;
        queue<int> q({0});
        while (!q.empty()) {
            const auto cur = q.front(); q.pop();
            for (const auto& nei : adj[cur]) {
                if (color[nei] == color[cur]) {
                    return false;
                } else if (color[nei] == -color[cur]) {
                    continue;

                }
                
                color[nei] = -color[cur];
                q.emplace(nei);
            }
        }
        return true;
    }
};



// Second methods

class Solution {
    bool isBipartite(vector<vector<int>>& adj,int N,int node,vector<int>& color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        //Process current graph component using BFS
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int ele: adj[curr])
            {
                if(color[ele]==color[curr]) //Odd-cycle
                    return false;
                if(color[ele]==-1)  //Unvisited node
                {
                    color[ele] = 1-color[curr];
                    q.push(ele);
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> adj(N+1);
        for(int i=0;i<dislikes.size();++i)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> color(N+1,-1);
        for(int i=1;i<=N;++i)
            if(color[i]==-1)
                if(!isBipartite(adj,N,i,color))
                    return false;
        return true;
    }
};