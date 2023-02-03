//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    pair <int,int> ans = make_pair(-1,-1);
    sort(arr,arr+n);
    
    int start = 0;
    int end = n-1;
    int mid = start +(end-start)/2;
    
    while(start <= end)
    {
        if(arr[mid] <= x)
        {
            ans.first = arr[mid];
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    
    start = 0;
    end = n-1;
    mid = start +(end-start)/2;
    
    while(start <= end)
    {
        if(arr[mid] >= x)
        {
            ans.second = arr[mid];
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}