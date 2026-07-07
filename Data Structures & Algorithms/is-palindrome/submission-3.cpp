class Solution {
public:

        //check for alphanumeric characters 
        //convert uppercase to lowercase
        //2 pointers

        bool isAlphaNum(char ch){

            if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
                 return true;
               }

               return false;
        }


        bool isPalindrome(string s){

            int lp = 0, rp = s.size() - 1;

            while(lp < rp){

                if(!isAlphaNum(s[lp])){
                    lp++; 
                }

                else if(!isAlphaNum(s[rp])){
                    rp--; 
                }

                else {
                    
                    if (tolower(s[lp]) != tolower(s[rp])) {
                    return false;
                }
                lp++;
                rp--;
            }
        }
        return true;
       }

};
