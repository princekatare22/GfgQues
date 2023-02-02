//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int getPivot(int A[], int l, int h)
    {
        int mid = l + (h-l)/2;
        while(l < h)
        {
            if(A[mid] >= A[0])
            {
                l = mid +1;
            }
            else h = mid;
            
            mid = l +(h-l)/2; 
        }
        return mid;
    }
    
    int binarySearch(int A[], int l, int h, int key)
    {
        int mid = l + (h-l)/2;
        
        while(l <= h)
        {
            if(A[mid] == key) return mid;
            else if(A[mid] < key) l = mid+1;
            else h = mid-1;
            
             mid = l + (h-l)/2;
        }
        return -1;
    }
    
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int pivot = getPivot(A, l, h);
        if(A[pivot] <= key && A[h-1] >= key)
            return binarySearch(A,pivot,h,key);
        else return binarySearch(A,l,pivot-1,key);
    };
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends