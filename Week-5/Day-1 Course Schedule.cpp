Day-1 Course Schedule.cpp

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

*/

// Time:  O(|V| + |E|)
// Space: O(|E|)

// Topological sort solution.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Store courses with in-degree zero.
        queue<int> zeroInDegree;
        
        // in-degree, out-degree
        unordered_map<int, unordered_set<int>> inDegree;
        unordered_map<int, unordered_set<int>> outDegree;
        for (int i = 0; i < prerequisites.size(); ++i) {
            inDegree[prerequisites[i][0]].insert(prerequisites[i][1]);
            outDegree[prerequisites[i][1]].insert(prerequisites[i][0]);
        }
        
        // Put all the courses with in-degree zero into queue.
        for(int i = 0; i < numCourses; ++i) {
            if(inDegree.find(i) == inDegree.end()) {
                zeroInDegree.push(i);
            }
        }
        
        // V+E
        while(!zeroInDegree.empty()) {
            // Take the course which prerequisites are all taken.
            int prerequisite = zeroInDegree.front();
            zeroInDegree.pop();
            for (const auto & course: outDegree[prerequisite]) {
                // Update info of all the courses with the taken prerequisite.
                inDegree[course].erase(prerequisite);
                // If all the prerequisites are taken, add the course to the queue.
                if (inDegree[course].empty()) {
                    zeroInDegree.push(course);
                }
            }
            // Mark the course as taken.
            outDegree.erase(prerequisite);
        }
        
        // All of the courses have been taken.
        if (!outDegree.empty()) {
            return false;
        }
        
        return true;
    }
};
