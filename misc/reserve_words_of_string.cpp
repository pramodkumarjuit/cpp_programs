#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>    

using namespace std;

string reverseWords(string s)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    ostringstream oss;

    while (ss >> word) {
        words.push_back(word);
    }
    
    reverse(words.begin(), words.end());

    bool isFirst = true;
    for (auto &w: words) {
        if (!isFirst)
            oss << " ";
        oss << w;
        isFirst = false;
    }

    return oss.str();
}

int main (int argc, char *argv[])
{
    string S = "The quick brown fox jumps over the lazy dog";
    cout << "Input: " << S << endl;
    string SR = reverseWords(S);
    cout << "Output: " << SR << endl;

    return 0;
}
