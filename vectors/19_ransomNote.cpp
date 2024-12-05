/*
 * Given two strings `ransomNote` and `magazine`, return true if you can construct
 * the ransomNote from the letters in magazine and false otherwise.
 *
 * Each letter in the magazine string can only be used once in the ransomNote.
 * 
 * Key Requirements:
 *  - Check if all characters in ransomNote can be found in magazine.
 *  - A character can only be used as many times as it appears in magazine.
 *    == That means, each letter in magazine can only be used once in ransomNote. ==
 *
 * Example:
 *  ransomNote = "aabb"
 *  magazine = "abbab"
 *
 *  Output: True
*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;

bool checkRandomNote(string magazine, string ransomNote)
{
    unordered_map<char, int> magazineCharMap;

    for (auto &e : magazine) {
        magazineCharMap[e]++;
    }
    // check if each char of magazie is present in ransomNote
    for (auto &c: ransomNote) {
        if (magazineCharMap[c] > 0) {
            magazineCharMap[c]--;
        } else {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    string magazine = "abbab";
    string ransomNote = "abbab";

    cout << "Is a RandomNote: " << checkRandomNote(magazine, ransomNote) << endl;

    return 0;
}
