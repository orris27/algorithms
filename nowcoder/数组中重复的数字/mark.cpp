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
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int elm;
        for(int i =0;i<length;++i) // not "< length-1"
        {
            //debug("numbers[%d]=%d\n", elm, numbers[elm]);
            elm = numbers[i] % length; // get the real element
            //cout << i << " " << elm << " " << numbers[elm] << endl;
            //debug("i=%d || numbers[%d]=%d\n", i, elm, numbers[elm]);
            if(numbers[elm] > length)
            {
                *duplication = elm;
                return true;
            }
            //debug("numbers[%d]=%d\n", elm, numbers[elm]);
            numbers[elm] += length;
            //debug("numbers[%d]=%d\n", elm, numbers[elm]);
        }
        return false;
    }
};

int main()
{
    Solution so;
    int numbers[] = {2, 4, 3, 1, 4};
    int duplication;
    cout << so.duplicate(numbers, 5, &duplication) << " " << duplication << endl;

}
