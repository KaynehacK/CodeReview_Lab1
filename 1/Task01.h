#ifndef LAB1_TASK01_H
#define LAB1_TASK01_H

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

struct Solution {
    vector<int> selected_items;
    int total_weight;
    int total_tax;
};

Solution  KnapSackSolution(int min_weight, vector<int>& weights, vector<int>& taxes);

void PrintSolution(const Solution& solution);

bool ReadInputData(const string& filename, int& Z, vector<int>& weights, vector<int>& taxes);

#endif //LAB1_TASK01_H
