//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // int searchInsertK(vector<int>Arr, int N, int k)
    // {
    //     int start = 0;
    //     int end = N-1;
        
    //     int mid = start + (end-start)/2;
        
    //     int ans = N;
        
    //     while(start <= end)
    //     {   
    //         if(Arr[mid] >= k)
    //         {
    //             ans = mid;
    //             end = mid-1;
    //         }
    //         else
    //         {
    //             start = mid+1;
    //         }
    //         mid = start + (end-start)/2;
    //     }
    //     return ans;
    // }
    
    int search(vector<int>Arr, int N, int k,int start,int end)
    {
        if(start > end) return N;
        
        int mid = start + (end-start)/2;
        
        if(Arr[mid] >= k) return min(mid , search(Arr,N,k,start ,mid-1));
        else return search(Arr,N,k,mid+1,end);
    }
    
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int start = 0;
        int end = N-1;
        
        return search(Arr,N,k,start,end);;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends