class Solution:
    def uniquePaths(self, grid: list[list[int]]) -> int:
        MOD = 10**9 + 7
        m = len(grid)
        n = len(grid[0])
        
        # dp[c] स्टोर करता है: [down_paths, right_paths] जो वर्तमान रो (row) के c-वें कॉलम में आ रहे हैं
        dp = [[0, 0] for _ in range(n + 1)]
        
        # बेस केस: (0, 0) पर पहुँचने का 1 तरीका (शुरुआत के लिए दोनों दिशाओं को 1 पर सेट करते हैं)
        dp[1] = [1, 1]
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    # दर्पण होने पर:
                    # जो रास्ता ऊपर से आ रहा था (dp[c+1][0]) वह अब दाएँ जाएगा -> dp[c+1][1]
                    # जो रास्ता बाईं ओर से आ रहा था (dp[c][1]) वह अब नीचे जाएगा -> dp[c+1][0]
                    dp[c + 1] = [dp[c + 1][1], dp[c][0]]
                else:
                    # खाली सेल होने पर दोनों रास्तों का योग होता है
                    total = (dp[c + 1][1] + dp[c][0]) % MOD
                    dp[c + 1] = [total, total]
                    
        # अंतिम सेल (m-1, n-1) पर पहुँचने वाले कुल रास्तों को रिटर्न करें
        return dp[n][0]
