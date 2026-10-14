class Solution {
    public String maxSumOfSquares(int num, int sum) {
        // A digit can contribute at most 9.
        if (sum > 9 * num) {
            return "";
        }

        int nines = sum / 9;
        int remainder = sum % 9;

        StringBuilder ans = new StringBuilder(num);

        // Add as many nines as possible.
        for (int i = 0; i < nines; i++) {
            ans.append('9');
        }

        // Add the remaining digit, if any.
        if (remainder > 0) {
            ans.append((char) ('0' + remainder));
        }

        // Pad the remaining positions with zeros.
        while (ans.length() < num) {
            ans.append('0');
        }

        return ans.toString();
    }
}