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
    void traverse_layer(vector<vector<int>>& matrix, int r1, int c1, int r2, int c2, vector<int>& res)
    {
        for(int i=c1;i<=c2;++i) // top row
            res.push_back(matrix[r1][i]);
        for(int i=r1+1;i<=r2;++i) // right column
            res.push_back(matrix[i][c2]);

        if (r1 < r2 && c1 < c2)  // Special case: 4x3, 3x4
        {
            for(int i=c2-1;i>=c1;--i) // bottom row
                res.push_back(matrix[r2][i]);
            for(int i=r2-1;i>r1;--i) // left column
                res.push_back(matrix[i][c1]);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int rs=matrix.size(), cs=matrix[0].size(), r1=0, c1=0, r2=rs-1, c2=cs-1;
        while(r1 <= r2 && c1 <= c2)
        {
            traverse_layer(matrix, r1, c1, r2, c2, res);
            ++r1; ++c1; --r2; --c2;
        }
        return res;
    }
};

int main()
{
    Solution so;
    vector<vector<int>> matrix;
    vector<int> res;
    matrix.push_back(vector<int>{1, 2, 3});
    matrix.push_back(vector<int>{4, 5, 6});
    matrix.push_back(vector<int>{7, 8, 9});

    res = so.spiralOrder(matrix);
    for (int i =0;i<res.size();++i)
        cout << res[i] << " ";
    cout << endl;


    vector<vector<int>> matrix1;
    matrix1.push_back(vector<int>{1, 2, 3, 4});
    matrix1.push_back(vector<int>{5, 6, 7, 8});
    matrix1.push_back(vector<int>{9, 10, 11, 12});
//    matrix1.push_back(vector<int>{13, 14, 15, 16});


    res = so.spiralOrder(matrix1);
    for (int i =0;i<res.size();++i)
        cout << res[i] << " ";
    cout << endl;
}
