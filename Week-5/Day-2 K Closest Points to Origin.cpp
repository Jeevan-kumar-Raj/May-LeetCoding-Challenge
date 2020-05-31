Day-2 K Closest Points to Origin.cpp

/*

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

*/

// Time:  O(nlogk)
// Space: O(k)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        static const auto& dist = [](const vector<int>& v) {
            return v[0] * v[0] + v[1] * v[1];
        };
        
        struct Compare {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return dist(a) < dist(b);
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Compare> max_heap;
        for (const auto& point : points) {
            max_heap.emplace(point);
            if (max_heap.size() > K) {
                max_heap.pop();
            }
        }
        vector<vector<int>> result;
        while (!max_heap.empty()) {
            result.emplace_back(max_heap.top()), max_heap.pop();
        }
        return result;
    }
};