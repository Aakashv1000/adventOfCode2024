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

void parseInput(string filename, vector<int> &x, vector<int> &y){
	ifstream file(filename);
    string line;
    while (getline(file, line)) {
    	stringstream ss(line);
    	int right, left;
    	ss >> left >> right;
    	x.push_back(left);
    	y.push_back(right);
    }

}

int main(){
	vector<int> x, y;
	parseInput("input.txt", x, y);
	

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int sum = 0, similar = 0;

    for(int i =0; i<x.size(); i++)
    {
    	sum += abs(x[i] - y[i]);
    	similar += (x[i] * count(y.begin(), y.end(), x[i]));
    }

    cout<<"Part 1: "<<sum<<endl<<"Part 2: "<<similar;

	
}