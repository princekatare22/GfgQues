//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int findLeftElement(int arr[], int n, int x,int start ,int end)
	{
	    if(start > end) return -1;
	    
	    int mid = start + (end-start)/2;
	    
	    if(arr[mid] == x)
	    {
	        if(findLeftElement(arr,n,x,start,mid-1) != -1)
	            return findLeftElement(arr,n,x,start,mid-1);
	        else
	           return mid;
	    }
	    else if(arr[mid] < x)
	    {
	        return findLeftElement(arr,n,x,mid+1,end);
	    }
	    else
	    {
	        return findLeftElement(arr,n,x,start,mid-1);
	    }
	}
	
	int findRightElement(int arr[], int n, int x,int start ,int end)
	{
	    if(start > end) return -1;
	    
	    int mid = start + (end-start)/2;
	    
	    if(arr[mid] == x)
	    {
	        if(findRightElement(arr,n,x,mid+1,end) != -1)
	            return findRightElement(arr,n,x,mid+1,end);
	        else
	           return mid;
	    }
	    else if(arr[mid] < x)
	    {
	        return findRightElement(arr,n,x,mid+1,end);
	    }
	    else
	    {
	        return findRightElement(arr,n,x,start,mid-1);
	    }
	}
	
	int count(int arr[], int n, int x) {
	    int left = findLeftElement(arr,n,x,0,n-1);
	    int right = findRightElement(arr,n,x,0,n-1);
	    
	    if(left == -1 && right == -1)
	        return 0;
	        
	    return  right-left+1;
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends