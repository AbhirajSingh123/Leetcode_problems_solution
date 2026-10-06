class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0; // Unmatched '('
        int r = 0; // Unmatched ')' needing '('
        for (const char c : s) {
            if (c == '(') {
                ++l;
            } else {
                if (l == 0) ++r;
                else --l;
            }
        }
        return l + r;
    }
};
