#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// https://leetcode.com/problems/can-place-flowers/

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int fs = flowerbed.size();
        if (fs == 0) return false;
        if (fs == 1) {
            if (flowerbed[0] == 1) return false;
            return n == 1;
        }
        if (fs == 2) {
            if (flowerbed[0] == 1 || flowerbed[1] == 1) return false;
            return n == 1;
        }
        // at beginning
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            --n;
        }
        for (int i = 1; i < fs - 1 && n > 0; ++i) {
            if (flowerbed[i] == 0 &&
                flowerbed[i - 1] == 0 &&
                flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        if (n > 0 && flowerbed[fs - 1] == 0 && flowerbed[fs - 2] == 0) {
            // flowerbed[fs - 1] = 1;
            --n;
        }
        return n == 0;
    }
};

void test1() {
    vector<int> v1{1,0,0,0,1};

    cout << "1 ? " << Solution().canPlaceFlowers(v1, 1) << endl;
    cout << "0 ? " << Solution().canPlaceFlowers(v1, 2) << endl;

    vector<int> v2{1,0,0,0,1,0,0};
    cout << "1 ? " << Solution().canPlaceFlowers(v2, 2) << endl;


}

void test2() {

}

void test3() {

}