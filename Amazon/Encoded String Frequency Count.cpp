Question:
I was given an encoded string where each letter corresponds to a number, and in some cases, the frequency of the character was mentioned in parentheses.
For example, the string "1226#24#(2)" translates to "abzxx".
The encoding works like this: 'a' is 1, 'b' is 2, and so on. Characters like 'j' are encoded as 10#, 'k' as 11#, etc.
If a character appears more than once, its frequency is appended next to it.The task was to calculate the frequency of each character in the string.

Input: "1226#24#(2)"      // translates to "abzxx"
Output: [1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1]

Time Complexity : O(N)
Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> func(string s){
        vector<int> freq(26, 0);
        int i=0, n= s.size();
        while(i<n){
            int num=0;
            if(i+2<n && s[i+2]=='#'){
                num= stoi(s.substr(i,2));
                i+=3;
            }
            else{
                num= s[i]-'0';
                i++;
            }
            
            
            int cnt=1;
            if(i<n && s[i]=='('){
                i++;
                int j=i+1;
                while(j<n && s[j]!=')') j++;
                cnt= stoi(s.substr(i,j-i));
                i=j+1;
            }
            
            
            freq[num-1]=cnt;
        }
        return freq;
    }
};

int main(){
    string s="1226#24#(2)";
    
    Solution sol;
    vector<int> res= sol.func(s);
    for(int i: res){
        cout<<i<<" ";
    }

    return 0;
}
