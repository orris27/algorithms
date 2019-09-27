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
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h == 0)
            return vector<vector<int>>();
        int w = matrix[0].size();
        pair<int, int> cur, next;
        vector<vector<int>> dist(h, vector<int>(w, INT32_MAX));
        queue<pair<int, int>> q;
        for (int i =0;i<h;++i)
            for(int j =0 ;j<w;++j)
            {
                if (matrix[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push(pair<int, int>(i, j));
                }
            }

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            for (int i =0;i<4;++i)
            {
                next.first = cur.first + dirs[i][0];
                next.second = cur.second + dirs[i][1];
                if (next.first >= 0 && next.first < h && next.second >= 0 && next.second < w)
                {
                    // If the next point can be updated, it can be used to update points around it as well
                    //if (dist[next.first][next.second] == INT32_MAX)
                    if(dist[next.first][next.second] > dist[cur.first][cur.second])
                    {
                        dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
                        //printf("dist[%d, %d] = %d\n", cur.first, cur.second, dist[next.first][next.second]);
                        //q.push(next);
                        q.push(pair<int, int>(next.first, next.second));

                    }
                }
            }
        }

        return dist;
    }
};


void print(const vector<vector<int>>& m)
{
    for(auto& v: m)
    {
        for(int elm:v)
        {
            printf("%d ", elm);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    vector<vector<int>> matrix = {{0,0,0},
                                  {0,1,0},
                                  {1,1,1}};
    Solution so;
    vector<vector<int>> res = so.updateMatrix(matrix);
    print(res);


    matrix = {{0},{0},{0},{0},{0}};
    res = so.updateMatrix(matrix);
    print(res);
}
