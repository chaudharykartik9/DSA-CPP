
class Solution {
   private:
    void backtract(int o,int c,int n,string s , vector<string> &ans){
        if(o == c && (o+c) == 2*n){
           ans.push_back(s) ;
           return ; 
        }

        if(o < n ){
            backtract(o+1 , c ,n ,s + '(' , ans );
        }
        if(c < o ){
            backtract(o , c+1 ,n , s+ ")" , ans );
        }
    }
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtract(0, 0, n, "", ans);
        return ans;
    }
};