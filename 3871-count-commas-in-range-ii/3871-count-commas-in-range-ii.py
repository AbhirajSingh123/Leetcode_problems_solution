class Solution:

  def countCommas(self, n: int) -> int:
    total_commas = 0
    start = 1000
    while start <= n:
      total_commas += n - start + 1
      start *= 1000
    return total_commas
