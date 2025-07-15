class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3)return false;
        int v=0,c=0;
        bool has_vowel=false,has_consonant=false;
        for(char c:word){
            if(isalpha(c)){
                c=tolower(c);
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                    has_vowel=true;
                }else{
                    has_consonant=true;
                }
            }else if(!isdigit(c)){
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};