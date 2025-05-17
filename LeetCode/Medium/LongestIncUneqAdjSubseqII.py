class Solution(object):
    def getWordsInLongestSubsequence(self, words, groups):
        """
        :type words: List[str]
        :type groups: List[int]
        :rtype: List[str]
        """
        def hamming_dist(str1, str2):
            dist = 0
            l1 = list(str1)
            l2 = list(str2)
            for i in range(len(str1)):
                dist += 1 if l1[i] != l2[i] else 0
            return dist

        n = len(words)
        lis = [1] * n
        longest_len = 1
        longest_end = -1
        parent = [-1] * n

        for i in range(n - 1):
            for j in range(i + 1, n):
                if groups[i] != groups[j] and len(words[i]) == len(words[j]) and hamming_dist(words[i], words[j]) == 1:
                    if lis[j] < 1 + lis[i]:
                        lis[j] = 1 + lis[i]
                        parent[j] = i
                        if lis[j] > longest_len:
                            longest_len = lis[j]
                            longest_end = j

        ans = []
        curr = longest_end
        while parent[curr] != -1:
            ans.append(words[curr])
            curr = parent[curr]
        ans.append(words[curr])
        ans.reverse()

        return ans