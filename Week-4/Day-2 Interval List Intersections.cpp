Day-2 Interval List Intersections.cpp

/*

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> res;
        int Aptr=0,Bptr=0;
        int sizeA = A.size();
        int sizeB = B.size();
        vector<int> temp(2);    //To push elements to res vector
        //Iterate over all intervals and store answer
        while(Aptr<sizeA && Bptr<sizeB)
        {
            if(B[Bptr][0]<=A[Aptr][1] && A[Aptr][0]<=B[Bptr][1])
            {
                temp[0] = max(A[Aptr][0],B[Bptr][0]);
                temp[1] = min(A[Aptr][1],B[Bptr][1]);
                res.push_back(temp);
            }
            //Now increment either Aptr or Bptr conditionally
            if(A[Aptr][1]>B[Bptr][1])
                Bptr+=1;
            else
                Aptr+=1;
        }
        return res;
    }
};
