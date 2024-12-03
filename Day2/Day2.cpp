#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <functional>
#include <numeric>
#include <list>
#include <regex>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <set>
#include <tuple>
#include <stack>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}


bool adjacent_diff(const vector<int>& num) {
    for (size_t i = 1; i < num.size(); ++i) {
        int diff = abs(num[i] - num[i - 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}


bool is_safe(const vector<int>& numbers) {
    bool isIncreasing = is_sorted(numbers.begin(), numbers.end());
    bool isDecreasing = is_sorted(numbers.begin(), numbers.end(), comp);
    bool hasValidDiffs = adjacent_diff(numbers);

    return (isIncreasing || isDecreasing) && hasValidDiffs;
}

bool can_be_safe_by_removal(const vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        vector<int> modified = numbers;
        modified.erase(modified.begin() + i);  

        if (is_safe(modified)) {
            return true;
        }
    }
    return false;
}

int Part1(const string& filename) {
    ifstream file(filename);
    string line;

    int count = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> numbers;
        int num;
        while (iss >> num) {
            numbers.push_back(num);
        }

        if (is_safe(numbers)) {
            count++;
        }
    }

    return count;
}

int Part2(const string& filename) {
    ifstream file(filename);
    string line;

    int count = 0;

    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> numbers;
        int num;
        while (iss >> num) {
            numbers.push_back(num);
        }

        bool isIncreasing = is_sorted(numbers.begin(), numbers.end());
        bool isDecreasing = is_sorted(numbers.begin(), numbers.end(), comp);
        bool hasValidDiffs = adjacent_diff(numbers);

        if (((isIncreasing || isDecreasing) && hasValidDiffs) || can_be_safe_by_removal(numbers)) {
            count++;
        }
    }

    return count;
}





int main(){
	cout<<Part1("input.txt")<<endl;
	cout<<Part2("input.txt")<<endl;
}