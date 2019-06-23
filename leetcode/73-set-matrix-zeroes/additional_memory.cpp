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
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        for (int i =0;i<matrix.size();++i)
            for(int j=0;j<matrix[0].size();++j)
            {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        // reset the row
        //for(int i=0;i<rows.size();++i)
        for (int r: rows)
            for(int j=0;j<matrix[0].size();++j)
                matrix[r][j] = 0;
        for (int c: cols)
            for (int i=0;i<matrix.size();++i)
                matrix[i][c] = 0;
            
    }
};

void print(vector<vector<int>> matrix)
{
    for (auto v: matrix)
    {
        for(int elm: v)
            cout << elm << " ";
        cout << endl;
    }
}

int main()
{
    Solution so;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    
    so.setZeroes(matrix);
    print(matrix);


    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    so.setZeroes(matrix);
    print(matrix);

}
