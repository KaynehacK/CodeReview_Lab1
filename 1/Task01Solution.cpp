#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

//FIXME Удалено чрезмерное количество поясняющих комментариев

//FIXME Структура добавлена для оптимизации вывода результата
struct Solution {
    vector<int> selected_items;
    int total_weight;
    int total_tax;
};

//FIXME Некорректный стиль названия процедуры;
// названия процедуры и аргументов неясно отражают их назначение;
// Процедура преобразована в функцию для оптимизации вывода результата
//void knapSack(int W, vector<int>& wt, vector<int>& val) {
Solution KnapSackSolution(int min_weight,
                          vector<int>& weights,
                          vector<int>& taxes) {
    int n = weights.size();
    //FIXME Названия переменных должны быть в стиле snake_case
    //int maxWeight = 0; // Максимально возможный вес всех предметов
    int max_weight = 0;
    for (int w : weights) max_weight += w;

    // Вектор dp, где dp[w] хранит минимальное налоговое бремя для веса w
    vector<int> dp(max_weight + 1, INT_MAX);
    dp[0] = 0; // Нулевой вес имеет нулевое налоговое бремя

    // FIXME Изменена логика алгоритма
    //vector<vector<bool>> selected(max_weight + 1, vector<bool>(n, false));
    vector<vector<int>> selected(max_weight + 1);

    // Заполняем dp и selected
    //FIXME Нужно использовать префиксную инкрементацию
    //for (int i = 0; i < n; i++) {
    for (int i = 0; i < n; ++i) {
        //FIXME Лишние переносы строки перед фигурной скобкой
        // Нужно использовать префиксную декрементацию
        //for (int w = max_weight; w >= weights[i]; w--) // Перебираем все возможные веса
        //{
        for (int w = max_weight; w >= weights[i]; --w) {
            //FIXME Лишние переносы строки перед фигурной скобкой
            // Превышение максимально допустимой длины строки
            //if (dp[w - weights[i]] != INT_MAX &&dp[w - weights[i]] + taxes[i] < dp[w])
            //{
            if (dp[w - weights[i]] != INT_MAX &&
                dp[w - weights[i]] + taxes[i] < dp[w]) {
                dp[w] = dp[w - weights[i]] + taxes[i];
                selected[w] = selected[w - weights[i]];
                selected[w].push_back(i + 1);
            }
        }
    }


    // Находим минимальное налоговое бремя для весов >= W
    //FIXME Некорректные названия переменных
    // Изменена логика алгоритма
    //int minVal = INT_MAX;
    //int bestWeight = 0; // Вес, соответствующий минимальному налоговому бремени
    //vector<bool> bestSelection(n, false); // Набор предметов, дающий минимальное налоговое бремя
    int min_tax = INT_MAX;
    int best_weight = 0;
    vector<int> best_selection;

    //FIXME лишний перенос строки перед фигурной скобкой
    // Нужно использовать префиксную инкрементацию
    //for (int w = min_weight; w <= max_weight; w++)
    //{
    for (int w = min_weight + 1; w <= max_weight; ++w) {
        //FIXME лишний перенос строки перед фигурной скобкой
        //if (dp[w] < min_tax) // Если найдено лучшее решение
        //{
        if (dp[w] < min_tax) {
            min_tax = dp[w]; // Обновляем минимальное налоговое бремя
            best_weight = w; // Запоминаем вес
            best_selection = selected[w]; // Запоминаем набор предметов
        }
    }

    // FIXME Вывод результата вынесен в отдельную процедуру
    // Вывод результата
//    if (min_tax == INT_MAX) // Если решение не найдено
//    {
//        cout << "Невозможно достичь минимального веса " << min_weight << endl;
//    }
//    else// Если решение найдено
//    {
//        cout << "Порядковые номера выбранных предметов: ";
//        for (int i = 0; i < n; i++)
//        {
//            if (best_selection[i])
//            {
//                cout << i + 1 << " ";
//            }
//        }
//        cout << endl;
//
//        // Выводим общий вес и итоговое налоговое бремя
//        cout << "Общий вес: " << best_weight << " кг" << endl;
//        cout << "Итоговое налогообложение: " << min_tax << endl;
//    }

    return {best_selection,
            best_weight,
            min_tax
    };
}

void PrintSolution(const Solution& solution) {
    if (solution.total_weight == 0) {
        cout << "Невозможно достичь требуемого веса" << endl;
        return;
    }

    cout << "Порядковые номера выбранных предметов: ";
    for (int item : solution.selected_items) {
        cout << item << " ";
    }
    cout << "\nОбщий вес: " << solution.total_weight << " кг\n";
    cout << "Итоговое налогообложение: " << solution.total_tax << endl;
}

bool ReadInputData(const string& filename,
                   int& Z,
                   vector<int>& weights,
                   vector<int>& taxes) {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return false;
    }

    int N;
    input >> N >> Z;
    weights.resize(N);
    taxes.resize(N);

    for (int i = 0; i < N; ++i) input >> weights[i];
    for (int i = 0; i < N; ++i) input >> taxes[i];

    return true;
}
