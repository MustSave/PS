class Solution:
    #init ver
    def lengthOfLongestSubstring(self, s: str) -> int:
        strl = len(s)
        res = 0
        hash = list(False for i in range(128)) #ASCII

        
        for i in range(strl): # i는 시작위치, j는 길이
            j = 0
            while not hash[ord(s[i+j])]: # 반복 없으면
                hash[ord(s[i+j])] = True
                j += 1
                if i+j > strl-1:
                    break
            if res < j : res = j
            
            hash = list(False for i in range(128))
        return res
    
    # Sliding Window Algorithm
    # max 함수 사용시 if문 비교보다 런타임 증가
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = right = 0
        hash = list(0 for i in range(128)) #ASCII
        res = 0

        while right < len(s):
            hash[ord(s[right])] += 1

            while hash[ord(s[right])] > 1:
                res = max(res, right-left)
                hash[ord(s[left])] -= 1
                left += 1

            right += 1

        return max(res, right-left)