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
    int dfs(int row, int column, vector<vector<int>> &paths){ // return the number of unique paths
        // call this method if and only the element is not visited
        if (paths[row][column] != - 1) // visited before
            return paths[row][column];

        // reach the destination
        if (row == paths.size() - 1 && column == paths[0].size() - 1)
        {
            return paths[row][column] = 1;
        }
        
        int res = 0;
       
        // move to the right
        if (column + 1 < paths[0].size())
            res += dfs(row, column + 1, paths);

        if(row + 1 < paths.size())
            res += dfs(row+1, column, paths);

        return paths[row][column] = res;
    }
    int uniquePaths(int m, int n) {
        // m: number of columns, n: number of rows
        vector<vector<int>> paths(n, vector<int>(m, -1));
        return dfs(0, 0, paths);
    }
};



int main()
{
    Solution so;
    cout << so.uniquePaths(3, 2) << endl;

    cout << so.uniquePaths(7, 3) << endl;

}
