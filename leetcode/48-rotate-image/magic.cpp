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

void print(vector<vector<int>> matrix)
{
    for (auto v: matrix)
    {
        for (int elm : v)
          cout << elm << " ";
        cout << endl;
    }

}



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // clockwise: reverse up to down + then swap the symmetry
        reverse(matrix.begin(), matrix.end());
        for (int i=0;i<matrix.size();++i)
            for (int j=0;j<i;++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main()
{
    Solution so;
    vector<vector<int>> matrix = {
      {1,2,3},
      {4,5,6},
      {7,8,9}
    };
    so.rotate(matrix);
    print(matrix);

    matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    so.rotate(matrix);
    print(matrix);
}
