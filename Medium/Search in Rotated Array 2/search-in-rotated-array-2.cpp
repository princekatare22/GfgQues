//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int getPivot(vector<int>& A)
    {
        int start = 0;
        int end = A.size()-1;
        int mid = start + (end-start)/2;
        
        while(start < end)
        {
            if(A[mid] >= A[0]) 
                start = mid+1;
            else end = mid;
            
             mid = start + (end-start)/2;
        }
        return mid;
    }
    
    bool binarySearch(vector<int>& A, int start, int end, int key)
    {
        int mid = start + (end-start)/2;
        
        while(start <= end)
        {
            if(A[mid] == key) return true;
            else if(A[mid] < key) start = mid+1;
            else end = mid-1;
            
             mid = start + (end-start)/2;
        }
        return false;
    }
    
    bool Search(int N, vector<int>& A, int Key) {
        // Code here
        int pivot = getPivot(A);
        if(A[pivot] <= Key && A[N-1] >= Key) return binarySearch(A,pivot,N-1,Key);
        else return binarySearch(A,0,pivot-1,Key);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends