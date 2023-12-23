# BookFinder C++
BookFinder program implemented in C++

This C++ program sorts a list of book titles and allows the user to search for a book in the sorted list.

# Dependencies:
The program uses the following C++ libraries:
- iostream
- vector
- cctype

# Functions
The program consists of the following functions:

- `binary_search(const vector<string> &books, const string &target)`: This function performs a binary search on the vector `books` for the string `target`. The function is case-insensitive.

-  `merge(vector<string> &v, vector<string> &left, vector<string> &right)`: This function merges two sorted vectors, `left` and `right`, into a single sorted vector `v`.

- `merge_sort(vector<string> &v)`: This function sorts the vector `v` using the merge sort algorithm.

- `print_sorted_list(vector<string> &books)`: This function prints the sorted list of books.

- `main()`: This is the main function where the program execution begins. It initializes a vector with book titles, sorts the vector, prints the sorted list, and prompts the user to enter a book title to search for in the list.

# Usage
Compile and run the program. When prompted, enter the title of the book you want to search for.

# bash
g++ -std=c++11 BookFinder.cpp
./Bookfinder
