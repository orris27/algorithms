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



const int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), tmp;
        if (n == 0) return;
        int points[4][2];
        int start_points[][2] = {{0, 0}, {0, n-1}, {n-1,n-1}, {n-1,0}};

        for (int k=0;k<n/2;++k)
        {
            for (int i=0;i<4;++i)
                for(int j=0;j<2;++j)
                    points[i][j] = start_points[i][j];

            for(int i=0;i<n - k*2-1;++i)
            {
                tmp = matrix[points[0][0]][points[0][1]];
                matrix[points[0][0]][points[0][1]] = matrix[points[3][0]][points[3][1]];
                matrix[points[3][0]][points[3][1]] = matrix[points[2][0]][points[2][1]];
                matrix[points[2][0]][points[2][1]] = matrix[points[1][0]][points[1][1]];
                matrix[points[1][0]][points[1][1]] = tmp;

                // move points
                for(int j=0;j<4;++j)
                { 
                    points[j][0] += dirs[j][0];
                    points[j][1] += dirs[j][1];
                }
            }
            start_points[0][0] += 1; start_points[0][1] += 1;
            start_points[1][0] += 1; start_points[1][1] -= 1;
            start_points[2][0] -= 1; start_points[2][1] -= 1;
            start_points[3][0] -= 1; start_points[3][1] += 1;
        
        }
        
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
    //so.rotate(matrix);
    //print(matrix);

    matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    so.rotate(matrix);
    print(matrix);
}
