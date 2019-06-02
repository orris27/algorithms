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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i, j;
        // make sure nums1.size() < nums2.size()
        vector<int> tmp;
        if (nums1.size() > nums2.size()) // time complexity of size() is O(1)
        {
            tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }
        int m = nums1.size();
        int n = nums2.size();
        bool b1, b2;
        int lm, rm; // left max, right min
        
        int left, right;
        left = 0;
        right = m;
        i = (left + right) / 2;

        // binary search
        while(true)
        {

            j = (m + n) / 2 - i;
            b1 = (i - 1 >= 0 && j < n)?(nums1[i - 1] <= nums2[j]):true;
            b2 = (j - 1 >= 0 && i < m)?(nums2[j - 1] <= nums1[i]):true; // b1 and b2 cannot be false at the same time
            

            if (b1 && b2)
            {
                if (i - 1 >= 0 && j - 1 >= 0) 
                    lm = max(nums1[i - 1], nums2[j - 1]);
                else if (i - 1 < 0 && j - 1 >= 0) // !!! i & j can both be 0
                    lm = nums2[j - 1];
                else if (i - 1 >= 0 && j - 1 < 0)
                    lm = nums1[i - 1];

                if (i < m && j < n)
                    rm = min(nums1[i], nums2[j]);
                else if (i >= m && j < n)
                    rm = nums2[j];
                else if (i < m && j >= n)
                    rm = nums1[i];

                if ((m + n) % 2 == 0) // even
                {
                    return (double(lm + rm)) / 2;
                }
                else // odd
                {
                    if (i + j < (m + n - i - j)) // if the right side has more elements, pick up the minimal one on the right side
                        return double(rm);

                    else
                        return double(lm);
                }
            }
            
            else if (!b1) // i too large, reduce i
            {
                right = i;
                i = (left + right) / 2;
            }
            else // b2 is false, which means i too small, increase i
            {
                left = i;
                i = (left + 1 == right)?right:(left + right) / 2;
            }
        
        }
        return 0;
        
    }


};

int main()
{
    Solution so;
    vector<int> a1{1, 3};
    vector<int> b1{2};
    cout << so.findMedianSortedArrays(a1, b1) << endl;

    
    vector<int> a2{1, 2};
    vector<int> b2{3, 4};
    cout << so.findMedianSortedArrays(a2, b2) << endl;

    vector<int> a3{};
    vector<int> b3{1};
    cout << so.findMedianSortedArrays(a3, b3) << endl;

}
