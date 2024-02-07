
	class Solution {
    public:
    int dp[21][21];
    bool solve(int i,int j,string &s,string &p){
        if(j == p.size())return (i == s.size());
        
        if(dp[i][j] != -1)return dp[i][j];
        bool ans = 0;
        auto match = [&](int idx1,int idx2){
          return (p[idx2] == '.' ? idx1 < s.size() : (s[idx1] == p[idx2]));
        };
        
        if(j + 1 < p.size() && p[j + 1] == '*'){
            ans = solve(i,j + 2, s, p);
            ans |= (match(i,j) && solve(i + 1, j, s, p));
        
        }
        else if(match(i,j)){
            ans = solve(i + 1, j + 1, s, p);
        }
        return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {  
        memset(dp,-1,sizeof dp);
        return solve(0,0,s,p);
    }
};

