class Solution(object):
    def getLongestSubsequence(self, words, groups):
        """
        :type words: List[str]
        :type groups: List[int]
        :rtype: List[str]
        """
        start0 = []
        start1 = []
        select0 = True
        for i in range(len(words)):
            if select0 and groups[i] == 0:
                select0 = False
                start0.append(words[i])
            elif not select0 and groups[i] == 1:
                select0 = True
                start0.append(words[i])
        
        select0 = False
        for i in range(len(words)):
            if select0 and groups[i] == 0:
                select0 = False
                start1.append(words[i])
            elif not select0 and groups[i] == 1:
                select0 = True
                start1.append(words[i])

        return start0 if len(start0) > len(start1) else start1