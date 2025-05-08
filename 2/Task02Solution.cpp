/*
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int ReadInput(const string& input_file_name,
                vector<vector<int>>& board
                ) {
    ifstream input(input_file_name);
    int n = 0;
    if (!input.is_open()) {
        cerr << "Cannot open input file: " << input_file_name << endl;
        return -1;
    }
    if (!(input >> n)) {
        cerr << "Cannot read from input file: " << input_file_name << endl;
        return -1;
    }
    board.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> board[i][j];
        }
    }
    input.close();
    return n;
}

vector<vector<int>> MaxSumMatrixFill(vector<vector<int>> board, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n - 1][n - 1] = board[n - 1][n - 1];
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i < n - 1) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j] + board[i][j]);
            }
            if (j < n - 1) {
                dp[i][j] = max(dp[i][j], dp[i][j + 1] + board[i][j]);
            }
        }
    }
    return dp;
}

string StringSolution(vector<vector<int>> dp, const int& n) {
    string solution = "";
    int x = 0, y = 0;
    while (x < n - 1 || y < n - 1) {
        if (x == n - 1) { // можем двигаться только вверх
            solution += 'U';
            ++y;
        } else if (y == n - 1) { // можем двигаться только влево
            solution += 'L';
            ++x;
        } else if (dp[x + 1][y] < dp[x][y + 1]) { // двигаться вверх
            solution += 'U';
            ++y;
        } else {
            solution += 'L'; // двигаться влево
            ++x;
        }
    }
    return solution;
}

bool WriteOutput(const string& output_file_name,
                 const string& solution,
                 const int& maxSum) {
    ofstream output(output_file_name); //"b.txt"
    if (!output.is_open()) {
        cerr << "Cannot open output file: " << output_file_name << endl;
        return false;
    }
    output << maxSum << endl << solution;
    output.close();
    return true;
}
*/
