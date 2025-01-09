# Word Frequency Analyzer

## Overview
The **Word Frequency Analyzer** is a C++ program that processes one or more text files to compute word frequencies. The program filters out stop words, cleans the text, and generates a frequency report. It also visualizes the most frequent words using a simple bar chart.

---

## Features

1. **Stop Words Filtering**:
   - The program removes common stop words (e.g., "the", "and", "is") using a customizable stop words file.

2. **Word Frequency Analysis**:
   - Computes the frequency of each unique word in the provided text files, ignoring case and punctuation.

3. **Frequency Report**:
   - Displays a detailed table of word frequencies, sorted in descending order of occurrence.

4. **Bar Chart Visualization**:
   - Visualizes the top N most frequent words using a simple bar chart.

---

## How to Use

### Prerequisites:
- A C++ compiler (e.g., `g++`).
- A file named `stop_words.txt` containing common stop words, one word per line.
- One or more text files to analyze.

### Steps:
1. Clone the repository or copy the source code into a file named `WordFrequencyAnalyzer.cpp`.
2. Compile the program:
   ```bash
   g++ -o WordFrequencyAnalyzer WordFrequencyAnalyzer.cpp
