#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int left = 0, right = 0;
            int maxLength = 0;
            std::unordered_map<char, int> charMap;

            for (right = 0; right < s.length(); right++) {
                char currentChar = s[right];
                if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >=left) {
                    left = charMap[currentChar] + 1;
                }
                charMap[currentChar] = right;
                maxLength = std::max(maxLength, right-left+1);
            }
            return maxLength;
        }
};

//int main(int argc, char *arv[])
int main()
{
    class Solution solution;
    std::string str = "abcabcabb";

    std::cout << "Length of longest sub str without repeating char: " << solution.lengthOfLongestSubstring(str) << std::endl;

    return 0;
}
