#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        string result = "";
        
        // Generate all possible ways to select (n-numFriends) characters
        vector<bool> combination(n, true);
        // Mark numFriends positions as false
        for(int i = 0; i < numFriends; i++) {
            combination[n-1-i] = false;
        }
        
        // Try all possible combinations
        do {
            string current = "";
            for(int i = 0; i < n; i++) {
                if(combination[i]) {
                    current += word[i];
                }
            }
            result = max(result, current);
        } while(prev_permutation(combination.begin(), combination.end()));
        
        return result;
    }
};


int main() {
    // Custom inputs
    string word;
    int numFriends;

    cout << "Enter the word: ";
    cin >> word;

    cout << "Enter the number of friends: ";
    cin >> numFriends;

    // Create an instance of Solution and calculate the result
    Solution solution;
    string result = solution.answerString(word, numFriends);

    // Output the result
    cout << "Lexicographically largest string: " << result << endl;

    return 0;
}
