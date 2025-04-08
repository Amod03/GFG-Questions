//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int low=0;
        sort(arr.begin(),arr.end());
        int high=arr.size()-1;
        int floor=-1;
        int ceil=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<=x){
                low=mid+1;
                floor=mid;
            }else{
                high=mid-1;
            }
        }
        low=0;high=arr.size()-1;
         while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<x){
                low=mid+1;
            }else{
                high=mid-1;
                ceil=mid;
            }
        }
        if(floor<0)
        floor=-1;
        else
        floor=arr[floor];
        
        if(ceil>arr.size()-1){
            ceil=-1;
        }else{
            ceil=arr[ceil];
        }
        return {floor,ceil};
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