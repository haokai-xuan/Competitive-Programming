class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        def at_least_k(k):
            vowel = defaultdict(int)
            consonants = 0
            left = 0

            ans = 0

            for right in range(len(word)):
                if word[right] in "aeiou":
                    vowel[word[right]] += 1
                else:
                    consonants += 1

                while len(vowel) == 5 and consonants >= k:
                    ans += len(word) - right

                    if word[left] in "aeiou":
                        vowel[word[left]] -= 1
                    else:
                        consonants -= 1

                    if vowel[word[left]] == 0:
                        vowel.pop(word[left])
                    left += 1

            return ans


        return at_least_k(k) - at_least_k(k + 1)