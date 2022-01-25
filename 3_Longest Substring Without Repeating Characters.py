class Solution:
    #init ver
    def lengthOfLongestSubstring(self, s: str) -> int:
        strl = len(s)
        max = 0
        hash = list(False for i in range(128)) #ASCII

        
        for i in range(strl): # i는 시작위치, j는 길이
            j = 0
            while not hash[ord(s[i+j])]: # 반복 없으면
                hash[ord(s[i+j])] = True
                j += 1
                if i+j > strl-1:
                    break
            if max < j : max = j
            
            hash = list(False for i in range(128))
        return max
    
    # Sliding Window Algorithm
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = right = 0
        hash = list(0 for i in range(128)) #ASCII
        max = 0

        while right < len(s):
            hash[ord(s[right])] += 1

            while hash[ord(s[right])] > 1:
                if max < right-left:
                    max = right-left

                hash[ord(s[left])] -= 1
                left += 1

            right += 1


        if max < right-left:
            max = right-left
        return max