class Solution {
public:

    string encode(vector<string>& strs) { 

        string res = "";

        for(string s : strs){

            res += to_string(s.size()) + '#' + s;
            //to_string(s.size()) s.size gives integer value and we have to convert to string for concatenation to be read like 4#sting
        }

        return res;

    }

    vector<string> decode(string s) { 

        vector<string> res;

        int i = 0;

        while(i < s.size()){

            int j = i;

            while(s[j] != '#'){
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            j++;

            string word = s.substr(j,len);

            res.push_back(word);

            i = j + len;
        }

        return res;

    }
};
