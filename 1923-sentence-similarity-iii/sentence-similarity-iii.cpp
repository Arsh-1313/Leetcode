class Solution {
public:
    vector<string> split(string line,char delimiter){
        vector<string> result;
        string word;
        stringstream ss(line);
        while(getline(ss,word,delimiter)){
            result.push_back(word);
        }
        return result;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1=split(sentence1,' ');
        vector<string> words2=split(sentence2,' ');

        int n=words1.size();
        int m=words2.size();
        if(n<m){
            swap(words1,words2);
            swap(n,m);
        }
        

        int i=0;
        while(i<m && words1[i]==words2[i]){
            i++;
        }
        int j=0;
        while(j<m && words1[n-1-j]==words2[m-1-j]){
            j++;
        }

        return i+j>=m;
    }
};