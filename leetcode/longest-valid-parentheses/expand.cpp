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
    int longestValidParentheses(string s) {
        if (s.length() == 0)
            return 0;
        int max_length = 0, count, left, right, l, r, old_left, old_right;
        for (int i =0;i<s.length() - 1;++i)
        {
            left = i;
            right = i + 1;
            // focus on i & i+1
            if (s[left] == '(' && s[right] ==')')
            {
                // default: expand to left
                while (left > 0 || right + 1 < s.length()) // while the substring can move to left & right
                {
                    //cout << "left: "<<left<<" right: " <<right<<endl;
                    old_left = left;
                    old_right = right;
                    // 1st: try to move to left
                    if (left > 0)
                    {

                        l = left - 1;
                        r = right;
                        if (s[l] == '(' && right + 1 < s.length())
                        {
                            count = 0;
                            // move to right
                            do{
                                r += 1;
                                if (s[r] == '(') 
                                    count += 1;
                                else
                                    count -= 1;
                            }while(r + 1 < s.length() && count != -1);
                            if (count == -1) // ok
                            {
                                left = l;
                                right = r;
                            }
                            // if not ok, we do nothing
                        }
                        else if(s[l] == ')' && left - 2 >= 0) // s[l] == ')'
                        {
                            count = 0;
                            do{
                                l -= 1;
                                if (s[l] == ')')
                                    count += 1;
                                else
                                    count -= 1;
                            
                            }while(l > 0 && count != -1);
                        
                            if (count == -1)
                            {
                                left = l;
                                right = r;
                            }
                        }


                    }

                    //cout << "SECOND  || left: "<<left<<" right: " <<right<<endl;
                    // 2nd: try to move to right
                    if (right + 2 < s.length() && s[right + 1] == '(') // since we have checked the left '(' case which is the same as this case, there is no need to handle this
                    {
                        r = right + 1;
                        count = 0; 
                        do{
                            r += 1;
                            if (s[r] == '(')
                                count += 1;
                            else
                                count -= 1;
                        
                        }while(r + 1 < s.length() && count != -1);
                        if (count == -1)
                            right = r;
                    }

                    if (old_left == left && old_right == right) // no update
                        break;
                }
                max_length = max(max_length, right - left + 1);
                
            }
            else
                continue;
                 
        
        }
        return max_length;
            
    }
};

int main()
{
    Solution so = Solution();
    string s;
    cin >> s;
    cout << so.longestValidParentheses(s) << endl;
    

}


