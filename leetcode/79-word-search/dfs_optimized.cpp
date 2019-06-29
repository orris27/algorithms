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

void print(vector<vector<char>> vv)
{
    for (auto v: vv)
    {
        for (auto elm: v)
            cout << elm << " ";
        cout << endl;
    }
}

class Solution {
public:
    bool dfs(vector<vector<char>>& board, const char* w, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != *w) return false; // return false if current index is out of bounds or current content is not equal to the required value
        if (*(w+1) == '\0') // reach the end
            return true;

        char curr = board[i][j];
        board[i][j] = '*';
        bool flag =  dfs(board, w+1, i-1, j)  // up
            || dfs(board, w+1, i+1, j) // down
            || dfs(board, w+1, i, j-1) // left
            || dfs(board, w+1, i, j+1); // right
        
        if (flag == false) board[i][j] = curr; // restore
        return flag;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;

        for (int i=0;i<board.size();++i)
            for (int j=0;j<board[0].size();++j)
                if (dfs(board, word.c_str(), i, j) == true) // if current point can the starting point
                    return true;
        return false;
    }


};

int main()
{
    set<vector<char>> s;
    s.insert(vector<char>{'a', 'b'});
    map<vector<char>, int> m;
    vector<char> vc = vector<char>{'c', 'd'};
    m.insert(pair<vector<char>, int>{vc, 5});
    Solution so;

    vector<vector<char>> board = {
                                      {'A','B','C','E'},
                                      {'S','F','C','S'},
                                      {'A','D','E','E'}
                                    };


    cout << so.exist(board, "ABCCED") << endl;;
    //cout << so.exist(board, "SEE") << endl; // LeetCode problem
    //cout << so.exist(board, "ABCB") << endl;


    board = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    cout << so.exist(board, "AAB") << endl;;

    board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    cout << so.exist(board, "ABCESEEEFS") << endl;
}
