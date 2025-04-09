//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    int n = arr.size();
      int fl = -1;
      int ce = INT_MAX;
      for(int i = 0; i<n; i++){
          if(arr[i] ==x){
              return {x,x};
          }else{
             if(arr[i] < x && fl <arr[i] ){
                  fl = arr[i];
              }
              if(arr[i]>x && ce > arr[i]){
                  ce = arr[i];
              }
          }

      }
      if(ce == INT_MAX){
          ce = -1;
      }
      return {fl,ce};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends