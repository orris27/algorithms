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

// IOU
// (x, y) is the coordinates of the rectangle, while (h, w) represents its height and width
// Note that x increases topdown, while y increases from the right to the left
double iou(double x1, double y1, double w1, double h1, double x2, double y2, double w2, double h2)
{
   double S1 = w1 * h1;
   double S2 = w2 * h2;
   
   double w = (x1 > x2)? min(x2 + h2 - x1, h1):min(x1 + h1 - x2, h2);
   double h = (y1 > y2)? min(y2 + w2 - y1, w1):min(y1 + w1 - y2, w2);
   
   w = max(w, 0.0);
   h = max(h, 0.0);
   return (w * h) / (S1 +S2 - w*h);
}

int main()
{
    cout << iou(3, 4, 3, 8, 5, 6, 6, 10) << endl;
}
