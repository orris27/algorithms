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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, int> dict2index;
        vector<vector<string>> res;

        for (int i=0; i< strs.size();++i)
        {
            // compute the dict of character frequency
            map<char, int> dict;
            for (int j=0;j<strs[i].size();++j)
            {
                if (dict.find(strs[i][j]) == dict.end()) // not found
                    dict.insert(pair<char, int>(strs[i][j], 1));
                else
                    ++dict[strs[i][j]];
            }

            //cout <<"string="<<strs[i]<<" total="<<total << endl;
            map<map<char, int>, int>::iterator it = dict2index.find(dict);

            if (it == dict2index.end()) // not found
            {
                res.push_back(vector<string>{strs[i]});
                dict2index.insert(pair<map<char, int>, int>{dict, res.size() - 1});
            }
            else
            {
                res[it->second].push_back(strs[i]);
            }
        }
        return res;
    }
};
void print(vector<vector<string>> vvs){
    for(auto vs: vvs)
    {
        for (auto s: vs)
            cout << s << " ";
        cout << endl;
    }
}


int main()
{
    Solution so;
    vector<string> vs{"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> res = so.groupAnagrams(vs);
    print(res);

    vs = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
    res = so.groupAnagrams(vs);
    print(res);
    
}
