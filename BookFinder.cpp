#include<iostream>
#include<vector>
#include <cctype> 

using namespace std;

void merge(vector<string> &v, vector<string> &left, vector<string> &right);

// Binary Search
int binary_search(const vector<string> &books, const string &target) {
    string targetLower = target;
    transform(targetLower.begin(), targetLower.end(), targetLower.begin(), ::tolower);

    int left = 0, mid, right = books.size() - 1;
    while (left <= right) {
        mid = left + (right - left) / 2;

        string currentBookLower = books[mid];
        transform(currentBookLower.begin(), currentBookLower.end(), currentBookLower.begin(), ::tolower);

        if (currentBookLower == targetLower) {
            return mid;
        } else if (currentBookLower < targetLower) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Merge Sort
void merge_sort(vector<string> &v){
    
    int n = v.size();
    if(n <= 1) return;

    vector<string> left;
    vector<string> right;

    for(int i = 0; i < n; i++){
        if(i < n/2){
            left.push_back(v[i]);
        } else {
            right.push_back(v[i]);
        }
    }

    merge_sort(left);
    merge_sort(right);

    v.clear();
    
    merge(v, left, right);
}

void merge(vector<string> &v, vector<string> &left, vector<string> &right){
    
    int n1 = left.size();
    int n2 = right.size();

    int p1 = 0;
    int p2 = 0;

    while(p1 < n1 && p2 < n2){
        if(left[p1] <= right[p2]){
            v.push_back(left[p1]);
            p1++;
        } else {
            v.push_back(right[p2]);
            p2++;
        }
    }

    while(p1 < n1){
        v.push_back(left[p1]);
        p1++;
    }

    while(p2 < n2){
        v.push_back(right[p2]);
        p2++;
    }
}

void print_sorted_list(vector<string> &books){
    for(int i = 0; i < books.size(); i++){
        cout<<i+1<<". "<<books[i]<<endl;
    }
}

int main(){
    vector<string> books = {"1984", "A Brief History of Time", "Animal Farm", 
    "Brave New World", "Catch 22", "Crime and Punishment", 
    "Don Quixote", "Fahrenheit 451", "Great Expectations", "Moby Dick", 
    "Pride and Prejudice", "The Catcher in the Rye", "The Great Gatsby", 
    "To Kill a Mockingbird", "War and Peace", "12/80 Pareto rule"};

    merge_sort(books);

    cout<<"Sorted list of books: "<<endl;
    print_sorted_list(books);

    string input;
    cout << "Enter book title: " << endl;
    getline(cin, input);

    int position = binary_search(books, input);
    if (position != -1) {
        cout << "Book found at position: " << position + 1 << endl;
    } else {
        cout << "Book not found in the list." << endl;
    }

    return 0;
}