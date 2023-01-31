//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int findFirstOccur(int arr[], int n , int x)
{
    int start = 0;
    int end = n-1;
    
    int mid = start + (end-start)/2;
    
    int ans = -1;
    
    while(start <= end)
    {
        if(arr[mid] == x)
        {
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid] > x)
        {
            end = mid-1;
        }
        else
        {
            start  = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int findLastOccur(int arr[], int n , int x)
{
    int start = 0;
    int end = n-1;
    
    int mid = start + (end-start)/2;
    
    int ans = -1;
    
    while(start <= end)
    {
        if(arr[mid] == x)
        {
            ans = mid;
            start  = mid+1;
        }
        else if(arr[mid] > x)
        {
            end = mid-1;
        }
        else
        {
            start  = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    vector <int> ans;
    ans.push_back(findFirstOccur(arr,n,x));
    ans.push_back(findLastOccur(arr,n,x));
    
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends