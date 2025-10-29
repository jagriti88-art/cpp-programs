#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> price(n), ans(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && price[s.top()] <= price[i]) s.pop();
        if (s.empty()) ans[i] = i + 1;
        else ans[i] = i - s.top();
        s.push(i);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
