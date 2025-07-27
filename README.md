# Nonsense Sentence Generator (C++20)

A simple C++20 command-line program that generates random nonsense sentences using word lists and sentence templates. It demonstrates the use of STL containers, functions, and modern C++ random generation.

## ✅ Features

- Generates sentences using random parts of speech:
  - Nouns, Verbs, Adjectives, Adverbs, Articles, Prepositions
- Supports 5 sentence templates for variety
- Modern C++20 randomness using `std::mt19937` and `std::uniform_int_distribution`
- Option to save generated sentences to a file
- Clean and modular code

## 📂 Files

- `main.cpp` – Core logic and entry point

## 🛠️ Requirements

- C++20 compatible compiler (e.g., `clang++` or `g++` with `-std=c++20`)
- MacOS or Linux terminal

### Compile

```bash
clang++ -std=c++20 main.cpp -o main
```
