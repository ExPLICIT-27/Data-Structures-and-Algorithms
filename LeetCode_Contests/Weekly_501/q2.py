class Solution(object):
    def countWordOccurrences(self, chunks, queries):
        """
        :type chunks: List[str]
        :type queries: List[str]
        :rtype: List[int]
        """
        S = "".join(chunks)

        valid_cnts = {}
        
        curr = ""
        for i in range(len(S)):
            if S[i].islower():
                curr += S[i]
            else:
                if S[i] == "-":
                    if i - 1 >= 0 and i + 1 < len(S) and S[i - 1].islower() and S[i + 1].islower():
                        curr += S[i]
                    else:
                        if curr:
                            valid_cnts[curr] = valid_cnts.get(curr, 0) + 1
                            curr = ""
                else:
                    if curr:
                        valid_cnts[curr] = valid_cnts.get(curr, 0) + 1
                        curr = ""

        if curr:
            valid_cnts[curr] = valid_cnts.get(curr, 0) + 1
        ans = []

        for s in queries:
            if s in valid_cnts:
                ans.append(valid_cnts[s])
            else:
                ans.append(0)

        return ans
            