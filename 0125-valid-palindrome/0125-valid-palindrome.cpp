char tolower(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');  
    }
    return ch;  
}
string removecharacter(string s)
{
    string ss="";
    for(int i=0;i<s.size();i++)
    {
        if(isalnum(s[i])){
            ss+=tolower(s[i]);
        }
    }
    return ss;
}
class Solution {
public:
    bool isPalindrome(string s) {
    string copy=removecharacter(s);
    string r=copy;
    reverse(copy.begin(),copy.end());
    if(copy==r){
        return true;
    }
    return false;
    }
};