#include "Task03.h"
//FIXME Некоторые из импортированных библиотек не были использованы
#include <iostream>
//#include <fstream>
#include <vector>
#include <cmath>
//#include <iomanip>
//#include <climits>
#include <stdint.h>

using namespace std;

double Count(int N, int K) {
    //FIXME Добавлена валидация
    if (!ValidateInput(N, K)) {
        throw invalid_argument("Invalid input parameters");
    }

    // dp[i][j] — количество чисел длины i, заканчивающихся на j подряд идущих нулей
    // dp[i][4] — количество чисел, где уже было 4+ подряд идущих нулей
    //FIXME Использование целочисленных типов кроме int не приветствуется.
    //vector<vector<long long>> dp(N + 1, vector<long long>(5, 0));
    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(5, 0));

    dp[1][0] = K - 1;  // Любая цифра кроме нуля
    dp[1][1] = 1;      // Только ноль

    //FIXME Необходимо использовать префиксную инкрементацию.
    //for (int i = 2; i <= N; i++) {
    //    for (int j = 0; j < 4; j++) {
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < 4; ++j) {
            dp[i][0] += dp[i - 1][j] * (K - 1);
        }
        dp[i][1] += dp[i - 1][0];
        dp[i][2] += dp[i - 1][1];
        dp[i][3] += dp[i - 1][2];

        dp[i][4] += dp[i - 1][3];

        dp[i][4] += dp[i - 1][4] * K;
    }
    //FIXME Два оператора написаны в одну строку.
    // Превышение максимально допустимой длины строки.
    // Вывод результата на должен находиться в этой функции.
    //double count = dp[N][4]; cout <<"Количество чисел, содержащих болше 3 нулей подряд: "<< count << endl;
    //FIXME Создания отдельной переменной можно избежать.
    //double count = dp[N][4];
    //return count;
    return dp[N][4];
}

bool ValidateInput(int N, int K) {
    return (K >= 2 && K <= 10) &&
           (N > 1 && N < 20) &&
           (N + K < 26);
}

//FIXME Невнятное название процедуры
//void HomeDyn16() {
void Solution() {
    int N, K;

    //FIXME Два оператора написаны в одну строку
    //cout<<"Система счисления: ";cin >> K;
    //cout<<"Количество разрядов: ";cin >> N;
    cout<<"Система счисления: ";
    cin >> K;
    cout<<"Количество разрядов: ";
    cin >> N;

    //FIXME Неправильный расчёт всех N-разрядных чисел K-ичной системы счисления
    //double all = pow(K, N);
    double all = pow(K,N) - pow(K,N-1);
    cout<<"Общее количество: "<<all<<endl;
    //FIXME Неясно назначение данной переменной и смысл её вывода.
    //double result = Count(N, K) / all;
    //cout  << result << endl;
    cout << "Количество чисел, содержащих болше 3 нулей подряд: " << Count(N,K);
}
