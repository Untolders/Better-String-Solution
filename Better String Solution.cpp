*******************************************************************************  Question  ***********************************************************************************************************************


Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

Example 1:

Input:
str1 = "gfg", str2 = "ggg"
Output: "gfg"
Explanation: "gfg" have 7 distinct subsequences whereas "ggg" have 4 distinct subsequences. 
Example 2:

Input: str1 = "a", str2 = "b"
Output: "a"
Explanation: Both the strings have only 1 distinct subsequence. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function betterString() which takes str1 and str2 as input parameters and returns the better string.

Expected Time Complexity: O( max( str1.length, str2.length ) )

Expected Auxiliary Space: O( max( str1.length, str2.length ) )

Constraints:
1 <= str1.length , str2.length <= 30



********************************************************************************  solution  **********************************************************************************************************************

  //{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string betterString(string str1, string str2) {
        // code here
           return uniqueSubsequences(str1) >= uniqueSubsequences(str2) ? str1 : str2 ;
    }
    int uniqueSubsequences(string &s){
        int n = s.size() ; 
        vector<int> dp(n+1,0) ;
        unordered_map<char,int> mp ;
        dp[0] = 1 ;
        for(int i = 1 ; i <= n ; i++){
            dp[i] = 2 * dp[i-1] ;
            if(mp.find(s[i-1]) != mp.end()){
                int index = mp[s[i-1]] ;
                dp[i] -= dp[index-1] ;
            }
            mp[s[i-1]] = i ;
        }
        return dp[n] ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
