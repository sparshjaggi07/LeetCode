class Solution {
    public :
void reverse(string &s, int left, int right) {
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

string reverseWords(string s) {
    int n = s.length();
    int i = 0, j = 0;
    while (i < n && s[i] == ' ') i++;
    while (i < n) {
        if (s[i] != ' ') s[j++] = s[i++];
        else {
            s[j++] = ' ';
            while (i < n && s[i] == ' ') i++;
        }
    }
    if (j > 0 && s[j - 1] == ' ') j--;
    s.resize(j);  
    reverse(s, 0, s.size() - 1);
    int start = 0;
    for (int end = 0; end <= s.size(); ++end) {
        if (end == s.size() || s[end] == ' ') {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    }
    return s;
}
};