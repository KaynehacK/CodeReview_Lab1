#ifndef LAB1_TASK02_H
#define LAB1_TASK02_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int ReadInput(const string& input_file_name,
                vector<vector<int>>& board
                );

vector<vector<int>> MaxSumMatrixFill(vector<vector<int>> board, int n);

string StringSolution(vector<vector<int>> dp, const int& n);

bool WriteOutput(const string& output_file_name,
                 const string& solution,
                 const int& maxSum
                 );

#endif //LAB1_TASK02_H
