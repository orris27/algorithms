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
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        bool fr=false, fc=false; // indicate whether the 1st row or column should reset
        for (int i=0;i<matrix.size();++i)
            if (matrix[i][0] == 0)
                fc = true; // 1st column should be reset, since there is a zero element
        for (int i=0;i<matrix[0].size();++i)
            if (matrix[0][i] == 0)
                fr = true; // 1st row should be reset, since there is a zero element

        for (int i =1;i<matrix.size();++i) // If the iteration contains the first row or column, then it causes their row or column to be reset if they are set to 0
            for(int j=1;j<matrix[0].size();++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }

        // start reseting. Note that we reset all the elements after setting the indicators to avoid an indicator appears too late, such as "{1, 1, 0}"
        for (int i =1;i<matrix.size();++i)
            for(int j=1;j<matrix[0].size();++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;

        if (fr == true)
            for(int i =0;i<matrix[0].size();++i)
                matrix[0][i] = 0;

        if (fc == true)
            for(int i =0;i<matrix.size();++i)
                matrix[i][0] = 0;
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
    cout << endl;


    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    so.setZeroes(matrix);
    print(matrix);
    cout << endl;

    matrix = {{1,2,3,4},{5,0,5,2},{8,9,2,0},{5,7,2,1}};
    so.setZeroes(matrix);
    print(matrix);
    cout << endl;

}
