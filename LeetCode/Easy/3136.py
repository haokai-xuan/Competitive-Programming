class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        vowels = ['a', 'e', 'i', 'o', 'u']

        has_vowel = False
        has_cons = False

        for c in word:
            if ('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z'):
                if c.lower() in vowels:
                    has_vowel = True
                else:
                    has_cons = True
            elif '0' <= c and c <= '9':
                continue
            else:
                return False

        return has_vowel and has_cons