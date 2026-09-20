class Solution {
public:
    int reverseDegree(string s) {
        int stringLength = s.length();
        int totalReverseDegree = 0;
      
        // Iterate through each character position (1-indexed)
        for (int position = 1; position <= stringLength; ++position) {
            // Get the character at current position (0-indexed in string)
            char currentChar = s[position - 1];
          
            // Calculate reverse alphabetical value (distance from 'z')
            // 'a' -> 26, 'b' -> 25, ..., 'z' -> 1
            int reverseAlphabeticalValue = 26 - (currentChar - 'a');
          
            // Add weighted contribution: position * reverse value
            totalReverseDegree += position * reverseAlphabeticalValue;
        }
      
        return totalReverseDegree;
    }
};
