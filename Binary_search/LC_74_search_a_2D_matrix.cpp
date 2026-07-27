class Solution {
public:
    bool lowerBound(vector<int>&matrix, int n, int k)   
    {
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high)
        {
            int mid = (low + high)/2;

            if(matrix[mid] == k) return true;

            else if(matrix[mid] > k) high = mid-1;

            else low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();

        for(int i = 0; i < matrix.size(); i++)
        {
            if(lowerBound(matrix[i], n, target)) return true;
        }
        return false;;
    }
};
