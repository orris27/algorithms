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

void print(vector<vector<bool>> vv)
{
    for (auto v: vv)
    {
        for (bool elm: v)
            cout << elm << " ";
        cout << endl;
    }
}

class Solution {
public:
    void reset(vector<vector<bool>>& path) {
        if (path.size() == 0) return;
        for (int i =0;i<path.size();++i)
            for (int j=0;j<path[0].size();++j)
                path[i][j] = false;
    }

    bool dfs(const vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>>& path, int index) {
        // make sure path[i][j] is false before this function is called
        //debug("index: %d, (i, j): (%d, %d)\n", index, i, j);
        path[i][j] = true;
        //if (index == 1 && i == 1 && j == 1) 
        //    debug("debug position\n");
        if (index + 1 > word.size()) // finish all the characters 
            return true;
        //print(path);

        // move up
        //debug("move up\n");
        if (i - 1 >= 0 && board[i-1][j] == word[index] && path[i - 1][j] == false && dfs(board, word, i-1, j, path, index + 1))
            return true;

        // move down
        //debug("move down\n");
        if (i + 1 < board.size() && board[i+1][j] == word[index] && path[i + 1][j] == false && dfs(board, word, i+1, j, path, index + 1))
            return true;

        // move to left
        //debug("move to left\n");
        if (j - 1 >= 0 && board[i][j-1] == word[index] && path[i][j-1] == false && dfs(board, word, i, j-1, path, index + 1))
            return true;
            
        // move to right
        //debug("move to right\n");
        if (j + 1 < board[0].size() && board[i][j+1] == word[index] && path[i][j+1] == false && dfs(board, word, i, j+1, path, index + 1))
            return true;

        path[i][j] = false; // current point cannot form final path, remove it
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        vector<vector<bool>> path(board.size(), vector<bool>(board[0].size(), false));
        
        //reset(path);

        // Find the starting point
        for (int i=0;i<board.size();++i)
        {
            for (int j=0;j<board[0].size();++j)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, i, j, path, 1) == true)
                        return true;
                    else reset(path);
                }
            }
        }
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
    cout << so.exist(board, "SEE") << endl;
    cout << so.exist(board, "ABCB") << endl;


    board = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    cout << so.exist(board, "AAB") << endl;;

    board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    cout << so.exist(board, "ABCESEEEFS") << endl;
}
