class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for(string email:emails){
            string local="";
            string domain="";

            //splitting into local and domain
            int atPos=email.find('@');
            local=email.substr(0,atPos);
            domain=email.substr(atPos);


            //Rule1: ignore after '+'
            int plusPos=local.find('+');
            if(plusPos!=string::npos){
                local=local.substr(0,plusPos);
            }

            //Rule2: remove all '.'
            string cleanedLocal="";
            for(char c: local){
                if(c!='.')cleanedLocal+=c;
            }

            //final normaized string
            string normalized=cleanedLocal+domain;
            uniqueEmails.insert(normalized);
        }

        return uniqueEmails.size();
    }
};