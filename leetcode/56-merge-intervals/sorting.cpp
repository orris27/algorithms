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

void print_v(vector<int> v)
{
    for(int i =0;i<v.size();++i)
        cout << v[i] <<" ";
    cout << endl;
}


void print(const vector<vector<int>>& vv)
{
    vector<int> v;
    for (int i =0; i<vv.size();++i)
    {
        v = vv[i];
        for (int j =0 ;j<v.size();++j)
            cout << v[j] << " ";
        cout << endl;
    }
}






/*
 * My approach
 *
int cmp(const vector<int>& a, const vector<int>& b) // "vector<int>" is time-consuming
{
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res; // handle empty case
        if (intervals.size() == 1)
        {
            res.push_back(vector<int>{intervals[0][0], intervals[0][1]});
            return res;
        }
        sort(intervals.begin(), intervals.end(), cmp);  // sort based on the first element
        int left=intervals[0][0], right=intervals[0][1];
        for (int i = 1;i<intervals.size();++i)
        {
            if (i == intervals.size() - 1) 
            {
                if (right >= intervals[i][0]) // current interval needs to be merged into previous interval
                {
                    right = max(right, intervals[i][1]);
                    res.push_back(vector<int>{left, right});
                }
                else // independent internal
                {
                    res.push_back(vector<int>{left, right});
                    res.push_back(vector<int>{intervals[i][0], intervals[i][1]});
                }
            }
            else
            {
                if(right >= intervals[i][0])
                {
                    right = max(right, intervals[i][1]);
                }
                else
                {
                    res.push_back(vector<int>{left, right});
                    left = intervals[i][0];
                    right = intervals[i][1];
                }
            }
        }

            
        return res;
    }
};

*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return vector<vector<int>>{}; // handle empty case
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});  // sort based on the first element
        vector<vector<int>> res{vector<int>{intervals[0][0], intervals[0][1]}};
        for(int i=1;i<intervals.size();++i)
        {
            if (res.back()[1] >= intervals[i][0]) // if we can merge the last element in res and new interval 
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else res.push_back(vector<int>{ intervals[i][0], intervals[i][1]}); // if we cannot merge, then push the new interval
        }
        return res;
    }
};



int main()
{
    Solution so;
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "intervals:" << endl;
    print(intervals);
    cout << "solution:" << endl;
    vector<vector<int>> res = so.merge(intervals);
    print(res);
    cout << endl;

    intervals = {{1, 4}, {4, 5}};
    cout << "intervals:" << endl;
    print(intervals);
    cout << "solution:" << endl;
    res = so.merge(intervals);
    print(res);
    cout << endl;

    intervals = {{1, 3}};
    cout << "intervals:" << endl;
    print(intervals);
    cout << "solution:" << endl;
    res = so.merge(intervals);
    print(res);
    cout << endl;

    intervals = {{1, 4}, {0, 4}};
    cout << "intervals:" << endl;
    print(intervals);
    cout << "solution:" << endl;
    res = so.merge(intervals);
    print(res);
    cout << endl;

    intervals = {{1, 4}, {0, 1}};
    cout << "intervals:" << endl;
    print(intervals);
    cout << "solution:" << endl;
    res = so.merge(intervals);
    print(res);
    cout << endl;


    intervals = {{1, 4}, {0, 0}};
    cout << "intervals:" << endl;
    print(intervals);
    cout << "solution:" << endl;
    res = so.merge(intervals);
    print(res);
    cout << endl;



    intervals = {{4, 5}, {1, 4}, {0, 1}};
    cout << "intervals:" << endl;
    print(intervals);
    cout << "solution:" << endl;
    res = so.merge(intervals);
    print(res);
    cout << endl;

}

