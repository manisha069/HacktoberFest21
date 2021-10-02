""" The longest common subsequence problem is finding the longest sequence which exists in both the given strings """

def longest_common_subsequence(s1, s2):
    """
    :param s1: string
    :param s2: string
    :return: int
    """
    m = len(s1)
    n = len(s2)

    dp = [[0] * (n + 1) for i in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]
