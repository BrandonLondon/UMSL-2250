//============================================================================
// Name        : 2250.cpp
// Author      : Brandon London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Word {
	string english;
	string piglatin;
};

Word* splitSentence(const string words, int& size);
void convertToPigLatin(Word wordArr[], int size);
void displayPigLatin(const Word wordArr[], int size);
bool checkForVowel(char letter);

int main() {
	string englishSentence;
	int size;
	cout << "Hello! Please enter a sentence in English: ";
	getline(cin, englishSentence);
	Word* words = splitSentence(englishSentence, size);
	convertToPigLatin(words, size);
	displayPigLatin(words, size);
	delete[] words;
	words = NULL;
	return 0;
}
Word* splitSentence(const string words, int& size) {
	string wordsCopy = words;
	int numWords = 0;
	for (int i = wordsCopy.size() - 1; i >= 0; i--) {
		wordsCopy[i] = tolower(wordsCopy[i]);
		if (isspace(wordsCopy[i])
				&& ((i == wordsCopy.size() - 1) || (i == 0))) {
			wordsCopy = wordsCopy.erase(i, 1);
		} else if (isspace(wordsCopy[i])
				&& ((isspace(wordsCopy[i - 1])) || (isspace(wordsCopy[i + 1])))) {
			wordsCopy = wordsCopy.erase(i, 1);
		} else if ((!isalpha(wordsCopy[i])) && (!isspace(wordsCopy[i]))) {
			wordsCopy = wordsCopy.erase(i, 1);
		} else if (isalpha(wordsCopy[i])) {
			numWords++;
			do {
				i--;
			} while (isalpha(wordsCopy[i]) && i > 0);
			i++;
		}
	}
	size = numWords;
	Word* temp = new Word[size];
	for (int i = 0; i < size; i++) {
		temp[i].english = wordsCopy.substr(0, wordsCopy.find_first_of(' '));
		wordsCopy = wordsCopy.substr(wordsCopy.find_first_of(' ') + 1);
	}
	return temp;
}
void convertToPigLatin(Word wordArr[], int size) {
	for (int i = 0; i < size; i++) {
		if (checkForVowel(wordArr[i].english[0])) {
			wordArr[i].piglatin = (wordArr[i].english + "way");
		} else {
			for (int j = 1; j < wordArr[i].english.length(); j++) {
				wordArr[i].piglatin += wordArr[i].english[j];
			}
			wordArr[i].piglatin += wordArr[i].english[0];
			wordArr[i].piglatin += "ay";
		}
	}
	return;
}

void displayPigLatin(const Word wordArr[], int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << wordArr[i].piglatin + ' ';
	}
	cout << endl;
	return;
}
bool checkForVowel(char letter) {
	bool output = false;
	switch (letter) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		output = true;
		break;
	default:
		output = false;
	}
	return output;
}
