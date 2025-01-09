#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>

using namespace std;

// Function to load stop words
set<string> loadStopWords(const string& filename) {
    set<string> stopWords;
    ifstream file(filename);
    string word;
    if (file.is_open()) {
        while (file >> word) {
            stopWords.insert(word);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open stop words file." << endl;
    }
    return stopWords;
}

// Function to clean and standardize a word
string cleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

// Function to analyze word frequencies
unordered_map<string, int> analyzeFrequency(const vector<string>& files, const set<string>& stopWords) {
    unordered_map<string, int> wordFrequency;
    for (const string& file : files) {
        ifstream inFile(file);
        if (!inFile.is_open()) {
            cerr << "Error: Unable to open file " << file << endl;
            continue;
        }
        string word;
        while (inFile >> word) {
            word = cleanWord(word);
            if (!word.empty() && stopWords.find(word) == stopWords.end()) {
                wordFrequency[word]++;
            }
        }
        inFile.close();
    }
    return wordFrequency;
}

// Function to display word frequencies
void displayWordFrequencies(const unordered_map<string, int>& wordFrequency) {
    cout << "\nWord Frequency Report:\n";
    cout << setw(20) << left << "Word" << setw(10) << "Frequency" << endl;
    cout << string(30, '-') << endl;

    vector<pair<string, int>> sortedWords(wordFrequency.begin(), wordFrequency.end());
    sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return b.second < a.second; // Sort by frequency (descending)
    });

    for (const auto& entry : sortedWords) {
        cout << setw(20) << left << entry.first << setw(10) << entry.second << endl;
    }
}

// Function to generate a basic bar chart visualization
void visualizeWordFrequencies(const unordered_map<string, int>& wordFrequency, int limit = 10) {
    cout << "\nWord Frequency Bar Chart (Top " << limit << "):\n";
    vector<pair<string, int>> sortedWords(wordFrequency.begin(), wordFrequency.end());
    sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return b.second > a.second; // Sort by frequency (descending)
    });

    for (int i = 0; i < min(limit, (int)sortedWords.size()); ++i) {
        cout << setw(15) << left << sortedWords[i].first << " | ";
        int barLength = sortedWords[i].second;
        for (int j = 0; j < barLength; ++j) cout << "*";
        cout << " (" << sortedWords[i].second << ")\n";
    }
}

int main() {
    cout << "Welcome to the Word Frequency Analyzer!\n";

    // Load stop words
    string stopWordsFile = "stop_words.txt";
    set<string> stopWords = loadStopWords(stopWordsFile);

    // Get file names from the user
    vector<string> files;
    string fileName;
    char choice;
    cout << "Enter the text files to analyze (type 'done' when finished):\n";
    while (true) {
        cout << "Enter file name: ";
        cin >> fileName;
        if (fileName == "done") break;
        files.push_back(fileName);
    }

    if (files.empty()) {
        cerr << "No files provided. Exiting program." << endl;
        return 1;
    }

    // Analyze word frequencies
    unordered_map<string, int> wordFrequency = analyzeFrequency(files, stopWords);

    // Display word frequency report
    displayWordFrequencies(wordFrequency);

    // Visualize top word frequencies
    visualizeWordFrequencies(wordFrequency);

    return 0;
}
