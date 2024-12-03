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

long Part2(const string& filename) {
    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    // Match mul(x,y), do(), and don't()
    regex instructionRegex("mul\\((\\d{1,3}),(\\d{1,3})\\)|do\\(\\)|don't\\(\\)");

    long totalSum = 0;
    bool isEnabled = true; // mul instructions start as enabled

    sregex_iterator iter(content.begin(), content.end(), instructionRegex);
    sregex_iterator end;

    while (iter != end) {
        string match = (*iter).str();

        if (match == "do()") {
            isEnabled = true; // Enable mul instructions
        } else if (match == "don't()") {
            isEnabled = false; // Disable mul instructions
        } else {
            // Extract numbers from mul(x,y) if enabled
            if (isEnabled) {
                long a = stol((*iter)[1].str());
                long b = stol((*iter)[2].str());
                totalSum += a * b;
            }
        }
        ++iter;
    }

    return totalSum;
}

long Part1(const string& filename)
{
	ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    regex mulRegex("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    long totalSum = 0;
    
    sregex_iterator iter(content.begin(), content.end(), mulRegex);
    sregex_iterator end;

    while (iter != end) {
        long a = stol((*iter)[1].str());
        long b = stol((*iter)[2].str());
        totalSum += a * b;
        ++iter;
    }

    return totalSum;
}

int main(){
	long result1 = Part1("input.txt");
	long result2 = Part2("input.txt");

	cout<<"Part1: "<<result1<<endl;
	cout<<"Part2: "<<result2<<endl;
}
