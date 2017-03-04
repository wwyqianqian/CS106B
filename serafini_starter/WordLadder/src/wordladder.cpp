// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header


  #include <cctype>
	#include <cmath>
	#include <fstream>
	#include <iostream>
	#include <string>
	#include "console.h"
	#include "strlib.h"
	#include "stack.h"
	#include "lexicon.h"
	#include "simpio.h"
	#include "queue.h"
	#include "filelib.h"
	#include "set.h"


	using namespace std;


	void runWordLadder();
	string getWord();
	Lexicon openDictionary();
	bool wordsAreValid(string w1, string w2, Lexicon &dic);
	void returnSolution(Stack<string> &solution, string w1, string w2);
	void findShortestWordLadder(string w1, string w2, Lexicon &dic);


	int main() {
	    cout << "Welcome to Word Ladder." << endl;
	    runWordLadder();
	    cout << "Have a nice day." << endl;
	    return 0;
	}


	// Runs Word Ladder program
	void runWordLadder() {
	    cout << "Please give me two English words, and I will change the first into the second by changing one letter at a time." << endl;
	    Lexicon dictionary = openDictionary(); // Initializes a new lexicon containing words from a dictionary txt file
	    while (true) {
	        string word1 = getWord();
	        if (word1 == "") { // If empty string is entered, quits program.
	            return;
	        }
	        string word2 = getWord();
	        if (word2 == "") { // If empty string is entered, quits program.
	            return;
	        }
	        if (wordsAreValid(word1, word2, dictionary)) {
	            findShortestWordLadder(word1, word2, dictionary);
	        }
	    }
	}


	// Opens dictionary file, if valid. Stores contents in Lexicon data structure.
	Lexicon openDictionary() {
	    ifstream input;
	    Lexicon lex;
	    while (true) {
	        string filename = getLine("Dictionary file name? ");
	        openFile(input, filename);
	        if (input.is_open()) {
	            lex.addWordsFromFile(filename); // reads in the contents from the data file. Must be text file containing 1 word per line.
	            break;
	        } else {
	            cout << "File does not exist. Try again." << endl;
	        }
	    }

	    return lex;
	}


	// Asks user to input a word. Returns string in lower case.
	string getWord() {
	    string w1 = getLine("Word #1 (or Enter to quit): ");
	    return toLowerCase(w1);
	}


	// Returns true if the two words are valid
	bool wordsAreValid(string w1, string w2, Lexicon &dic) {
	    if (w1 == w2) {
	        cout << "The two words must be different." << endl;
	        return false;
	    }
	    if (!dic.contains(w1) || !dic.contains(w2)) {
	        cout << "The two words must be found in the dictionary." << endl;
	        return false;
	    }
	    if (w1.length() != w2.length()) {
	        cout << "The two words must be the same length." << endl;
	        return false;
	    }
	    return true;
	}


	// Find the shortest word ladder between strings w1 and w2
	void findShortestWordLadder(string w1, string w2, Lexicon &dic) {


	    Queue<Stack<string> > wordLadders; // Create an empty queue of stacks


	    Stack<string> start; // Create and add a stack containing w1 to the queue
	    start.push(w1);
	    wordLadders.enqueue(start);

	    Set<string> usedWords; // Keeps track of used words so that they are not re-used in mult ladders
	    usedWords.add(w1);

	    while (!wordLadders.isEmpty()) {


	        Stack<string> partialLadder = wordLadders.dequeue(); // Dequeue the partial-ladder stack from the front of the queue


	        string topWord = partialLadder.peek(); // Retrieve the word on top of the stack



	        for (int i = 0; i < topWord.length(); i++) { // Iterate through each letter of the word


	            string alphabet = "abcdefghijklmnopqrstuvwxyz";


	            string copyTWord = topWord; // Create copy of the top word to manipulate


	            for (int j = 0; j < alphabet.length(); j++) { // Iterate through alphabet

	                if (topWord[i] != alphabet[j]) {
	                    copyTWord[i] = alphabet[j]; // if the letter varies from original letter, replace it;

	                    if (copyTWord == w2) { // If we found the solution, print out the stack and return to main
	                        partialLadder.push(copyTWord);
	                        returnSolution(partialLadder, w1, w2);
	                        usedWords.clear();
	                        return;
	                    }
	                    if (dic.contains(copyTWord) && !usedWords.contains(copyTWord)) { // If modified string is valid and not used before...
	                        Stack<string> copyStack = partialLadder; // Create a copy of partialLadder
	                        copyStack.push(copyTWord); // Add copyTWord to partialLadder
	                        wordLadders.enqueue(copyStack); // Add partialLadder to queue
	                        usedWords.add(copyTWord);
	                    }
	                }
	            }
	        }
	    }
	    cout << "There is no word ladder between these two words. Sorry!" << endl;
	}

	void returnSolution(Stack<string> &solution, string w1, string w2) {
	    cout << "A ladder from " << w2 << " back to " << w1 << ":" << endl;
	    while (!solution.isEmpty()) {
	        cout << solution.pop() << " ";
	    }
	    cout << "\n" << endl;
	}
