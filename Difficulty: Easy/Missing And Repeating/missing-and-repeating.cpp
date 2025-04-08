//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        int x=0;
        for(int i=0;i<n;i++)
        {
            x=x^arr[i];
            x=x^(i+1);
        }
        int setbit=x&(~(x-1));
        vector<int> ans(2);
        ans[0]=0;  //repeating
        ans[1]=0;  //missing
        for(int i=0;i<n;i++)
        {
            if(arr[i] & setbit)
            ans[0]=ans[0]^arr[i];
            else
            ans[1]=ans[1]^arr[i];
            
            if((i+1) & setbit)
            ans[0]=ans[0]^(i+1);
            else
            ans[1]=ans[1]^(i+1);
            
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==ans[0])
            count++;
        }
        if(count==2){
            return ans;
        }else{
            return {ans[1],ans[0]};
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends