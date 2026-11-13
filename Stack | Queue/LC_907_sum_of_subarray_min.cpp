class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        const int mod = 1e9 + 7;

        vector<int> pse(n), nse(n);
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        long long sum = 0; 

        for(int i = 0; i < n; i++)
        {
            long long l = i - pse[i];
            long long r = nse[i] - i;

            long long contri = arr[i] * l * r;

            sum = (sum + contri) % mod;
        }

        return sum;
    }
};
