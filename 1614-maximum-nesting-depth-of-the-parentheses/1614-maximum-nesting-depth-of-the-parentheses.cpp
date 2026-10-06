class Solution {
public:
    int maxDepth(string s) {
        int bal = 0 ;
        int ans = 0 ;
        for(char c: s){
            if(c =='('){
                bal++ ;
                ans = max(bal , ans ) ;
            }if(c == ')'){
                bal-- ;
            }
        }
        return ans ;
        
    }
};