class Solution:
    def shortestDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        seen = {}
        
        for i in range(len(wordsDict)):
            if wordsDict[i] in seen:
                seen[wordsDict[i]].append(i)
            else:
                seen[wordsDict[i]] = [i]
        
        smallest = math.inf
        for i in seen[word1]:
            for j in seen[word2]:
                if abs(i - j) < smallest:
                    smallest = abs(i - j)
        
        return smallest