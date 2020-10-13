#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int *operate(vector<int> x, int m) {
    int *res = new int[m];
    stack<int> mstack;
    for (int i = m - 1; i >= 0; i--) {
        while (!mstack.empty() && x[i] >= x[mstack.top()]) {
            mstack.pop();
        }
        if (mstack.empty()) {
            mstack.push(i);
            res[i] = 0;
        } else {
            res[i] = mstack.top() - i;
            mstack.push(i);
        }
    }
    return res;
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int x;
    int count = 0;
    while (ss >> x) {
        nums.push_back(x);
        count++;
    }
    int *res;
    res = operate(nums, count);
    for (int i = 0; i < count; i++) {
        if (i != 0) cout << '\t';
        cout << *(res + i);
    }
}