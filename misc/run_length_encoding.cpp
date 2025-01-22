#include<iostream>
#include<map>

using namespace std;

string runLengthEncodingUsingMap(string s)
{
    string encoded="";
    map<char, int> charMap;
    for (auto & c: s) {
        charMap[c] += 1;
    }

    for (auto pair: charMap) {
        encoded += pair.first;
        encoded += to_string(pair.second);
    }

    return encoded;
}


int main(int argc, char* argv[])
{
    string input = "abcabcd";
    cout << "Input: " << input << endl;
    cout << "output: "<< runLengthEncodingUsingMap(input) << endl;

    return 0;


}
