//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int>& nums, int K,int mid)
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + ceil(float(nums[i])/mid);
            if(sum > K) return false;
        }
        return true;
    }
  
  
    int smallestDivisor(vector<int>& nums, int K) {
        int start = 1;
        int end = K;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            end = max(nums[i],end);
        }
        
        int mid = start + (end-start)/2;
        
        int ans = -1;
        
        while(start <= end)
        {
            if(isPossible(nums,K,mid))
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
            
            mid = start + (end-start)/2;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends