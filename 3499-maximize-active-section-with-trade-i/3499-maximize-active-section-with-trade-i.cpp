class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        int n = s.length();
        int totalOnes = 0;           // Total count of '1' segments
        int currentIndex = 0;        // Current position in string
        int previousZeroSegment = INT_MIN;  // Length of previous '0' segment
        int maxZeroWindow = 0;       // Maximum sum of consecutive zero segments
      
        // Process the string by grouping consecutive identical characters
        while (currentIndex < n) {
            // Find the end of current segment of identical characters
            int segmentEnd = currentIndex + 1;
            while (segmentEnd < n && s[segmentEnd] == s[currentIndex]) {
                segmentEnd++;
            }
          
            // Calculate the length of current segment
            int segmentLength = segmentEnd - currentIndex;
          
            if (s[currentIndex] == '1') {
                // If current segment is '1's, add to total count
                totalOnes += segmentLength;
            } else {
                // If current segment is '0's, update maximum window
                // Window represents adjacent zero segments that could be flipped
                maxZeroWindow = std::max(maxZeroWindow, previousZeroSegment + segmentLength);
                previousZeroSegment = segmentLength;
            }
          
            // Move to the next segment
            currentIndex = segmentEnd;
        }
      
        // Return total ones plus the maximum gain from flipping zeros
        return totalOnes + maxZeroWindow;
    }
};
