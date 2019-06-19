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






int cmp(const vector<int>& a, const vector<int>& b) // "vector<int>" is time-consuming
{
    return a[0] < b[0];
}

class Node{
public:
    int curr_idx;
    vector<int> children;
};
class Solution {
public:
    bool overlap(vector<int> a, vector<int> b)
    {
        return max(a[0], b[0]) <= min(a[1], b[1]);
    }
    vector<vector<int>> build_graph(const vector<vector<int>>& intervals)
    {
        // build the graph that connects their index
        vector<vector<int>> graph(intervals.size(), vector<int>{});
        for(int i=0;i<intervals.size();++i)
        {
            for(int j =i+1;j<intervals.size();++j)
            {
                if (overlap(intervals[i], intervals[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        return graph;
    }
    void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int index, set<int>& s){
        // make sure that visited[index] == false before revoking this method
        visited[index] = true;
        s.insert(index);
        for(int i=0;i<graph[index].size(); ++i)
        {
            if(visited[graph[index][i]] == false)
                dfs(graph, visited, graph[index][i], s);
        }
    
    }
    vector<int> merge_intervals(const vector<vector<int>>& intervals, set<int> s)
    {
        vector<int> big_interval;
        for (set<int>::iterator it=s.begin();it!=s.end();++it)
        {
            if(it == s.begin())
            {
                big_interval.push_back(intervals[*it][0]);
                big_interval.push_back(intervals[*it][1]);
            }

            else
            {
                // merge the big_interval and intervals[i]
                big_interval[0] = min(big_interval[0], intervals[*it][0]);
                big_interval[1] = max(big_interval[1], intervals[*it][1]);
            }
        }
        return big_interval;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        cout <<"hello world"<< endl;
        vector<vector<int>> graph = build_graph(intervals); // graph[i] might be empty if intervals[i] is independent
        // add the connected index to one set using dfs
        vector<set<int>> components;
        vector<bool> visited(intervals.size(), false);

        for(int i =0;i<intervals.size();++i)
        {
            if (visited[i] == false) // apply dfs to new interval 
            {
                set<int> s;
                dfs(graph, visited, i, s);
                components.push_back(s);
            }
        }
            
        vector<vector<int>> res;
        // merge the interval for each component
        for (int i=0;i<components.size();++i)
            res.push_back(merge_intervals(intervals, components[i]));

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



