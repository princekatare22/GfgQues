//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    if(N < M)
	    {
	        for(int i=0;i<N;i++)
	        {
	            int start = 0;
	            int end = M-1;
	            int mid = start + (end-start)/2;
	            
	            while(start <= end)
	            {
	                if(mat[i][mid] == X) return 1;
	                else if(mat[i][mid] < X) start = mid+1;
	                else end = mid-1;
	                
	                mid = start + (end-start)/2;
	            }
	        }
	    }
	    else
	    {
	        for(int i=0 ; i<M ; i++)
	        {
	            int start = 0;
	            int end = N-1;
	            int mid = start + (end-start)/2;
	            
	            while(start <= end)
	            {
	                if(mat[mid][i] == X) return 1;
	                else if(mat[mid][i] < X) start = mid+1;
	                else end = mid-1;
	                
	                mid = start + (end-start)/2;
	            }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends