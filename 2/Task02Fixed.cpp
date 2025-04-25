//FIXME Некорректный формат формулировки задания

/*Хромой король.На квадратной доске расставлены монеты, достоинством от 1 до
* 100. Хромой король, находящийся в правом нижнем углу, мечтает попасть в левый верхний.
* При этом он может передвигаться только в клетку слева или сверху и хочет, чтобы сумма всех
* монет, оказавшихся у него на пути, была бы максимальной.Определить эту сумму и путь, каким
* образом должен двигаться король, чтобы ее собрать.Ввод и вывод организовать при помощи
* текстовых файлов.Формат входных данных : в первой строке входного файла записано число n
* - размер доски(1 < n < 80).Далее следует n строк, каждая из которых содержит n целых чисел,
* представляющих доску.В первую строку выходного файл нужно вывести единственное число :
* максимальную сумму, а во второй строке вывести путь в виде строки символов, обозначив символом L
* движение влево, а символом U - движение вверх.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> MatrixInput(string input_file_name, int& n) {
    ifstream input(input_file_name);
    input >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> board[i][j];
        }
    }
    input.close();
    return board;
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

void MatixOutput(string output_file_name, vector<vector<int>> dp) {
    ofstream output(output_file_name); //"b.txt"
    int maxSum = dp[0][0];
    output << maxSum << endl;
}

int main() {
    //FIXME Чтение из файла вынесено в отдельную процедуру.
    //ifstream input("a.txt");
    //FIXME Вывод в файл вынесен в отдельную функцию
    //ofstream output("b.txt");

    //FIXME Переменная не инициализирована; некорректный стиль названия переменной.
    //int N;
    int n = 0;
    //FIXME Чтение из файла вынесено в отдельную процедуру.
    //input >> n;

    // Используем вектор векторов для представления доски
    //FIXME Сомнительное название переменной
    //vector<vector<int>> docka(n, vector<int>(n));
    vector<vector<int>> board(n, vector<int>(n));

    // Чтение доски из файла
    //FIXME Чтение из файла вынесено в отдельную процедуру
    //for (int i = 0; i < n; ++i) {
    //    for (int j = 0; j < n; ++j) {
    //        input >> board[i][j];
    //    }
    //}
    board = MatrixInput("a.txt", n);

    // Вектор для хранения максимальных сумм
    vector< vector<int>> dp(n, vector<int>(n, 0));

    // Начальная позиция (правый нижний угол)
    //FIXME Вынесено в отдельную процедуру
    //dp[n - 1][n - 1] = board[n - 1][n - 1];

    // Заполнение таблицы максимальных сумм
    //FIXME Вынесено в отдельную процедуру
    //for (int i = n - 1; i >= 0; --i) {
    //    for (int j = n - 1; j >= 0; --j) {
    //        if (i < n - 1) {
    //            dp[i][j] = max(dp[i][j], dp[i + 1][j] + board[i][j]);
    //        }
    //        if (j < n - 1) {
    //            dp[i][j] = max(dp[i][j], dp[i][j + 1] + board[i][j]);
    //        }
    //    }
    //}
    dp = MaxSumMatrixFill(board, n);

    // Максимальная сумма монет
    //FIXME Вывод в файл вынесен в отдельную функцию
    //int maxSum = dp[0][0];
    //output << maxSum << endl;

    // Восстановление пути
    vector<char> path;
    int x = 0, y = 0;

    while (x < n - 1 || y < n - 1) {
        if (x == n - 1) { // можем двигаться только вверх
            path.push_back('L');
            y++;
        }
        else if (y == n - 1) { // можем двигаться только влево
            path.push_back('U');
            x++;
        }
        else if (dp[x + 1][y] > dp[x][y + 1]) { // двигаться вверх
            path.push_back('L');
            y++;
        }
        else {
            path.push_back('U'); // двигаться влево
            x++;
        }
    }

    // Вывод пути
    for (char move : path) {
        output << move;
    }
    output << endl;

    //FIXME Чтение из файла вынесено в отдельную процедуру
    //input.close();
    output.close();

    return 0;
}