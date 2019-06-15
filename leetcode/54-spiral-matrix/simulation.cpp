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
    int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    //3, 2, 2, 1, 1
    // 4, 2, 3, 1, 2
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int nums_x = matrix[0].size() - 1, nums_y = matrix.size() - 1;
        for (int i =0;i<matrix[0].size();++i)
            res.push_back(matrix[0][i]);
        int count =matrix[0].size(), size = matrix.size() * matrix[0].size();
        for(int x=0, y=matrix[0].size()-1, k=0;count<size;++k)
        {
//            debug("k=%d\n", k);
//            debug("(x, y) = (%d, %d)\n", x, y);
//            debug("count=%d\n", count);
//            if (count == 7)
//                break;
            if (k%2 == 0) // x
            {
                for (int i=0;i<nums_y;++i, ++count)
                {
                    x = x+dirs[k%4][0];
                    y = y+dirs[k%4][1];
                    res.push_back(matrix[x][y]);
                }
                --nums_y;
            }
            else // y
            {
                for(int i=0;i<nums_x;++i, ++count)
                {
                    x = x+dirs[k%4][0];
                    y = y+dirs[k%4][1];
                    res.push_back(matrix[x][y]);
                }
                --nums_x;
            }
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
