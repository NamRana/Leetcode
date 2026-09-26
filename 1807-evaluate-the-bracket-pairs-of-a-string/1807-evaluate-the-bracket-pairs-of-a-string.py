class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        
        #stroing knowledge in a dictionary
        mp={}

        for key, value in knowledge:
            mp[key]=value

        ans=[]
        i=0

        #traverse the string
        while i<len(s):

            #found opening bracket
            if s[i]=='(':

                #found closing bracket
                j=i+1

                while s[j] !=')':
                    j+=1

                #extract the keys
                key =s[i+1:j]

                #get value from dictionary
                if key in mp:
                    ans.append(mp[key])
                
                else:
                    ans.append("?")

                #move after ')'
                i=j+1

            else:
                ans.append(s[i])
                i+=1

        return ''.join(ans)