#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;


class Solution {
public:
    void solveNQueens1(vector<vector<int>>& res, vector<int> vec, int index)
    {
        if (index == vec.size()) // exit function
            res.push_back(vec);
        for (int i= index;i<vec.size();++i) // traverse the remaing nums
        {
            // check if vec[i] is valid
            bool flag = true;
            for (int j = 0; j < index;++j)
            {
                int delta = index - j; // deal with diagonal case
                if (vec[j] + delta == vec[i] || vec[j] - delta == vec[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                swap(vec[index], vec[i]);
                solveNQueens1(res, vec, index+1);
                swap(vec[index], vec[i]); // return back
            }
        }
        
    }
    string gen(int n, int curr){
        string res;
        for (int i =0;i<n;++i)
            res += (i == curr)?'Q' :'.';
        return res;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> nums;
        for (int i =0;i<n;++i)
            nums.push_back(i); // constuct the function of (0, 1, 2, ..., n) to represent the position of queen in each row
        vector<vector<int>> res;
        solveNQueens1(res, nums, 0); // get the final result in the format of integer
        
        vector<vector<string>> graphs;
        for (int i=0;i<res.size();++i)
        {
            vector<string> graph;
            for(int j=0;j<res[i].size();++j)
                graph.push_back(gen(n, res[i][j])); // translate the integer to graph
            graphs.push_back(graph);
        }
        return graphs;
    }
};


int main()
{
    vector<vector<string>> here;
    cout <<"here ok!" << endl;
    Solution so;
    vector<vector<string>> res;
    
    res = so.solveNQueens(4);
    for (int i =0;i<res.size();++i)
    {
        vector<string> vs = res[i];
        for(int j =0;j<vs.size();++j)
        {
            cout << vs[j] << endl;
        }
        cout << endl;

    }
}
