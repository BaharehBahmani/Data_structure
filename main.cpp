#include <iostream>     // I/O
#include <fstream>      // file I/O
#include <string>       // string
#include <cctype>       // std::ispunct
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"


int greet();
void fromConsole();
void fromFile();
void parse(std::string& str);
bool isPalindrome(const std::string& str);
void save(const LinkedList& palindromes, const LinkedList& nonPalindromes);


int main() {
    if (greet()) return 0;
    std::cout << "\nDo you want to enter phrases or read from file? (phrase or file) ";
    std::string answer;
    std::cin >> answer;
    if (answer == "file" || answer == "f") fromFile();
    else if (answer == "phrase" || answer == "p" || answer == "phrases") fromConsole();
    else std::cout << "Sorry, I didn't get it. Please run the program again!\n";
}


int greet() {
    std::cout << "-- Hello!\n";
    std::cout << "-- Behjat Bahmani\n";
    std::cout << "-- A simple program to check palindromes\n";
    std::cout << "-- Do you want to try it? (yes to continue) ";
    std::string answer;
    std::cin >> answer;
    if (answer == "yes" || answer == "y") return 0;
    return 1;
}

void fromConsole() {
    LinkedList palindromes;
    LinkedList nonPalindromes;
    std::cout << "\nOkay! Please Enter your phrases and i'll tell you if they're palindromes or not...\n";
    std::cout << "if you decided to quit just type 'quit' or 'exit'\n";
    std::string input;
    std::cout << "---> ";
    // since i'm going to use std::getline(), i have to ignore the last newline in buffer
    std::cin.ignore(1024, '\n');
    while (std::getline(std::cin, input)) {
        std::string tmp = input;
        if (input == "quit" || input == "exit") break;
        parse(input);
        if (isPalindrome(input)) {
            std::cout << "# Your phrase is palindrome!\n";
            palindromes.push_in_order(tmp);
        }
        else {
            std::cout << "# It's not palindrome\n";
            nonPalindromes.push_in_order(tmp);
        }
        std::cout << "---> ";
    }
    std::cout << "-- Do you want to save in file? (yes to save) ";
    std::string answer;
    std::cin >> answer;
    if (answer == "yes" || answer == "y") save(palindromes, nonPalindromes);
}

void parse(std::string& str) {
    for (std::size_t i{}; i < str.size(); ++i) {
        str[i] = std::tolower(str[i]);
        if (std::ispunct(str[i]) || std::isblank(str[i])) {
            str.erase(str.begin() + i);
            --i;
        }
    }
}

bool isPalindrome(const std::string& str) {
    Stack s;
    Queue q;
    for (char c : str) {
        s.push(c);
        q.push(c);
    }
    std::size_t size = s.size();
    for (std::size_t i{}; i < size; ++i) if (s.pop() != q.pop()) return false;
    return true;
}

void fromFile() {
    LinkedList palindromes;
    LinkedList nonPalindromes;
    std::cout << "\nYou decided to read from file...";
    std::cout << "\nPlease give me path to your file: ";
    std::string file;
    std::cin >> file;
    std::ifstream inputFile { file };
    if (!inputFile) {
        std::cerr << "Can't open the file!\n";
        exit(1);
    }
    std::string input;
    // since i'm going to use std::getline() i have to ignore the last newline in buffer
    std::cin.ignore(1024, '\n');
    while (std::getline(inputFile, input)) {
        std::string tmp = input;
        parse(input);
        std::cout << "---> " << tmp << '\n';
        if (isPalindrome(input)) {
            std::cout << "# Your phrase is palindrome!\n";
            palindromes.push_in_order(tmp);
        }
        else {
            std::cout << "# It's not palindrome\n";
            nonPalindromes.push_in_order(tmp);
        }
    }
    std::cout << "-- Do you want to save in file? (yes to save) ";
    std::string answer;
    std::cin >> answer;
    if (answer == "yes" || answer == "y") save(palindromes, nonPalindromes);
}

void save(const LinkedList& palindromes, const LinkedList& nonPalindromes) {
    std::cout << "Okay!, Please Enter filename or full path of the file you want to save data in: ";
    std::string fileName;
    std::cin >> fileName;
    std::ofstream outputFile { fileName + ".txt" };
    if (!outputFile) {
        std::cerr << "Can't open the file!\n";
        exit(1);
    }
    outputFile << "List of Palindromes:\n";
    std::size_t size = palindromes.size();
    auto iter = palindromes.begin();
    for (std::size_t i{}; i < size; ++i) {
        outputFile << i + 1 << ": " << iter->value << '\n';
        iter = iter->next;
    }

    outputFile << "\n-----------------------------------------------------------------------\n\n";

    iter = nonPalindromes.begin();
    size = nonPalindromes.size();
    outputFile << "List of Non-Palindromes:\n";
    for (std::size_t i{}; i < size; ++i) {
        outputFile << i + 1 << ": " << iter->value << '\n';
        iter = iter->next;
    }
}
