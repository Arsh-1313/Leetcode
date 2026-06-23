class Solution {
public:
    string largestMerge(string word1, string word2) {
        int low=0;
        int high=0;

        int n=word1.length();
        int m=word2.length();

        string result;
        while(low<n && high<m){
            if((word1.substr(low))<(word2.substr(high))){
                result.push_back(word2[high]);
                high++;
            }else{
                result.push_back(word1[low]);
                low++;
            }
        }
        while(low<n){
            result.push_back(word1[low]);
            low++;
        }
        while(high<m){
            result.push_back(word2[high]);
            high++;
        }
        return result;
    }
};