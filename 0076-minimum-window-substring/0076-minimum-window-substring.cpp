class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int>mp;
        int l=0,r=0,minlen=1e9,sindex=-1,cnt=0;
        for(int i=0;i<t.length();i++)mp[t[i]]++;
        while(r<s.size()){
            if(mp[s[r]]>0){
                cnt++;
            }
            mp[s[r]]--; 
            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minlen);
    }
};
