//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        int start = 0;
        int end = n-1;
        int mid = start + (end-start)/2;
        
        while(start < end)
        {
            if(arr[mid] >= arr[0])
                start = mid +1;
            else
                end = mid;
                
            mid = start + (end-start)/2;
        }
        if(arr[0] < arr[mid]) return arr[0];
        return arr[mid];
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends