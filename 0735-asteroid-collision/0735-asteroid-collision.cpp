class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        int curr = asteroids[i];
        bool alive = true;
        while (alive && curr < 0 && !st.empty() && st.top() > 0) {
            if (st.top() < -curr) {
                st.pop();
                continue;
            } else if (st.top() == -curr) {
                st.pop();
                alive = false;
            } else {
                alive = false;
            }
        }
        if (alive) st.push(curr);
    }
    vector<int> res(st.size());
    for (int i = (int)st.size() - 1; i >= 0; --i) {
        res[i] = st.top();
        st.pop();
    }
    return res;
    }
};