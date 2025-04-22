//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

    int minRow(vector<vector<int>> &matrix) {
        // code here
          int cnt_max = INT_MAX;
    int index = 1;
    int n=matrix.size();
    int m=matrix[0].size();
    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        sort(matrix[i].begin(),matrix[i].end());
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones < cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index+1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> mat(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(mat) << "\n";
        cout << "~\n";
    }
}
// } Driver Code Ends