// https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
using namespace std;

#include <vector>
#include <limits>
#include <cassert>

namespace ctciarrayleftrotation
{
vector<int> rotLeft(vector<int> a, int d) // std::rotate(a.begin(), a.end(), d)
{
    int n = a.size();
    d = d % n; // simplify input
    vector<int> b(n, 0);

    for (int i = 0; i < n; i++)
    {
        int rotIndex = (i - d) < 0 ? n + (i - d) : i - d;
        b[rotIndex] = a[i];
    }

    return b;
}

void test()
{
    vector<int> actual_ans = rotLeft({1, 2, 3, 4, 5}, 4);
    vector<int> expected_ans = {5, 1, 2, 3, 4};

    for (int i = 0; i < 5; i++)
    {
        assert(actual_ans[i] == expected_ans[i]);
    }
}
} // namespace ctciarrayleftrotation