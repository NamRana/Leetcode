class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result=[]

        def backtrack(start, path, remaining):
            #vaild combination found
            if len(path)==k and remaining==0:
                result.append(path[:])
                return
            
            #stop exploring if condition invalid
            if remaining<0 or len(path)>=k:
                return

            for i in range(start,10):
                path.append(i)
                backtrack(i+1,path,remaining-i);
                path.pop()

        backtrack(1,[],n)
        return result