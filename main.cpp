// Nonsense Sentence Generator in C++
// Description: Generates random nonsense sentences using word lists

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>

using namespace std; 

// Word lists
vector<string> nouns = {"cat", "dog", "robot", "banana", "alien"};
vector<string> verbs = {"eats", "jumps", "builds", "destroys", "admires"};
vector<string> adjectives = {"tiny", "fluffy", "invisible", "strange", "angry"};
vector<string> adverbs = {"quickly", "loudly", "awkwardly", "gracefully", "silently"};
vector<string> articles = {"the", "a"};
vector<string> prepositions = {"on", "under", "beside", "with", "without"};

// Function to get a random element from a list
string randomWord(const vector<string>& list, mt19937& randomNumber) {
    uniform_int_distribution<int> dist(0, list.size() - 1);
    return list[dist(randomNumber)];
}

// Sentence template 1: article + adjective + noun + verb + adverb
string template1(mt19937& randomNumber) {
    return randomWord(articles, randomNumber) + " " + randomWord(adjectives, randomNumber) + " " + randomWord(nouns, randomNumber) + " " +
           randomWord(verbs, randomNumber) + " " + randomWord(adverbs, randomNumber) + ".";
}

// Sentence template 2: noun + verb + preposition + article + noun
string template2(mt19937& randomNumber) {
    return randomWord(nouns, randomNumber) + " " + randomWord(verbs, randomNumber) + " " + randomWord(prepositions, randomNumber) +
           " " + randomWord(articles, randomNumber) + " " + randomWord(nouns, randomNumber) + ".";
}

// Sentence template 3: article + noun + verb
string template3(mt19937& randomNumber) {
    return randomWord(articles, randomNumber) + " " + randomWord(nouns, randomNumber) + " " + randomWord(verbs, randomNumber) + ".";
}

// Sentence template 4: noun + adverb + verb + adjective + noun
string template4(mt19937& randomNumber) {
    return randomWord(nouns, randomNumber) + " " + randomWord(adverbs, randomNumber) + " " + randomWord(verbs, randomNumber) + " " +
           randomWord(adjectives, randomNumber) + " " + randomWord(nouns, randomNumber) + ".";
}

// Sentence template 5: adjective + noun + verb + article + noun
string template5(mt19937& randomNumber) {
    return randomWord(adjectives, randomNumber) + " " + randomWord(nouns, randomNumber) + " " + randomWord(verbs, randomNumber) + " " +
           randomWord(articles, randomNumber) + " " + randomWord(nouns, randomNumber) + ".";
}

// Generate a sentence using a random template
string generateSentence(mt19937& randomNumber) {
    int choice = rand() % 5;
    switch (choice) {
        case 0: return template1(randomNumber);
        case 1: return template2(randomNumber);
        case 2: return template3(randomNumber);
        case 3: return template4(randomNumber);
        case 4: return template5(randomNumber);
        default: return template1(randomNumber);
    }
}

int main() {
    random_device rd;
    mt19937 randomNumber(rd());

    int count;
    char saveOption;
    string filename;

    cout << "How many nonsense sentences do you want to generate? ";
    cin >> count;

    vector<string> sentences;
    for (int i = 0; i < count; ++i) {
        string sentence = generateSentence(randomNumber);
        sentences.push_back(sentence);
        cout << sentence << "\n";
    }

    cout << "Do you want to save the sentences to a file? (y/n): ";
    cin >> saveOption;

    if (saveOption == 'y' || saveOption == 'Y') {
        cout << "Enter filename: ";
        cin >> filename;
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& s : sentences) {
                outFile << s << "\n";
            }
            outFile.close();
            cout << "Sentences saved to " << filename << endl;
        } else {
            cerr << "Failed to open file." << endl;
        }
    }

    return 0;
}
