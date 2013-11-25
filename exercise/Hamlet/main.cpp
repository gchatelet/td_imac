#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>
#include <vector>

#include <cstdlib>

using namespace std;

bool isWithin(char value, char first, char end) {
    return value >= first && value <= end;
}

string sanitize(const string& word) {
    string sanitizedWord;
    for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        const bool numeric = isWithin(c, '0', '9');
        const bool lowercase = isWithin(c, 'a', 'z');
        const bool uppercase = isWithin(c, 'A', 'Z');
        const bool valid = numeric || lowercase || uppercase;
        if (!valid) continue;
        if (uppercase) c = c - 'A' + 'a';
        sanitizedWord.push_back(c);
    }
    return sanitizedWord;
}

int main(int argc, char **argv) {
    if (argc != 2) throw runtime_error("You must give a filename");

    ifstream file(argv[1]);
    if (!file) throw ios::failure("Unable to open filename");

    // reading all words
    vector<string> allWords;
    string word;
    while (file >> word)
        allWords.push_back(sanitize(word));
    cout << "file counts " << allWords.size() << " words" << endl;

    // no statistic to compute for empty file
    if (allWords.empty()) return EXIT_SUCCESS;

    // putting all the words in a set
    set<string> allUniqueWords;
    for (vector<string>::const_iterator itr = allWords.begin();
                    itr != allWords.end(); ++itr) {
        allUniqueWords.insert(*itr);
    }
    cout << "file counts " << allUniqueWords.size() << " unique words" << endl;

    // counting frequency for each word
    map<string, size_t> wordFrequencyMap;
    for (vector<string>::const_iterator itr = allWords.begin();
                    itr != allWords.end(); ++itr) {
        ++wordFrequencyMap[*itr];
    }

    // reversing map with correct handling of similar frequencies
    multimap<size_t, string> frequencyWordMap;
    for (map<string, size_t>::const_iterator itr = wordFrequencyMap.begin();
                    itr != wordFrequencyMap.end(); ++itr) {
        frequencyWordMap.insert(make_pair(itr->second, itr->first));
    }

    int i = 0;
    // displaying 10 less frequent words
    cout << "10 less frequent words" << endl;
    i = 0;
    for (multimap<size_t, string>::const_iterator itr =
                    frequencyWordMap.begin();
                    i < 10 && itr != frequencyWordMap.end(); ++itr, ++i) {
        cout << '\t' << itr->first << '\t' << itr->second << endl;
    }

    // displaying 10 most frequent words
    cout << "10 most frequent words" << endl;
    i = 0;
    for (multimap<size_t, string>::const_reverse_iterator itr =
                    frequencyWordMap.rbegin();
                    i < 10 && itr != frequencyWordMap.rend(); ++itr, ++i) {
        cout << '\t' << itr->first << '\t' << itr->second << endl;
    }

    return EXIT_SUCCESS;
}
