class Solution {
public:
    bool isPalindrome(int x) {
        int c=x;
        double s=0;
        if((x<0)&&(x-x)==0)
        {
            return false;
        }
        else
        {
        while(x!=0)
        {
            int d=x%10;
            s=(s*10)+d;
            x=x/10;
        }
        }
        if(s==c)
        return true;
        else
        return false;
    }
};