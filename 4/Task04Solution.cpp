#include "Task04.h"

using namespace std;

//FIXME Названия всех функций и переменных неясно отражают их назначения
// Множественная ошибка с лишним переносом строки перед фигурной скобкой
//int calc(string str);
//int element(string str)
//{
int EvaluateElement(const string& element) {
    //FIXME Добавлена проверка на пустую строку
    if (element.empty()) {
        throw invalid_argument("Пустое выражение");
    }

    if (element[0] == '(' && element[element.size() - 1] == ')') {
        return EvaluateExpression(element.substr(1, element.size() - 2));
    }

    //FIXME Добавлена проверка, что элемент - число
    for (char c : element) {
        if (!isdigit(c)) {
            throw invalid_argument("Недопустимый символ в числе: " +
                                   string(1, c)
            );
        }
    }

    return stoi(element);
}
//int term(string str)
//{
int EvaluateTerm(const string& term) {
    //FIXME Переменная удалена для оптимизации логики
    //int i = term.size() - 1;
    int level = 0;
    //FIXME Переменная удалена для оптимизации логики
    //int pos = -1;
    //FIXME Тип цикла изменён для оптимизации логики
    //while (i >= 0) {
    for (int i = term.size() - 1; i >= 0; --i) {
        if (term[i] == ')') {
            //FIXME Нужна префиксная инкрементация
            //level++;
            --level;
        }
        if (term[i] == '(') {
            //FIXME Нужна префиксная декрементация
            //level--;
            --level;
        }

        if (level == 0 && term[i] == '*') {
            //FIXME Удалено для оптимизации логики
            //pos = i;
            //break;
            return EvaluateTerm(term.substr(0, i)) *
                   EvaluateElement(term.substr(i + 1));
        }
        //FIXME Удалено для оптимизации логики
        //i--;
    }

    //FIXME Условие удалено для оптимизации логики
    //if (pos == -1) {
    //    return EvaluateElement(term);
    //}
    //FIXME Перемещено для оптимизации логики
    //return EvaluateTerm(term.substr(0, pos)) *
    //       EvaluateElement(term.substr(pos + 1));

    return EvaluateElement(term);
}

//int calc(string str)
//{
int EvaluateExpression(const string& expression) {
    //FIXME Переменная удалена для оптимизации логики
    //int i = expression.size() - 1;
    int level = 0;
    //FIXME Переменная удалена для оптимизации логики
    //int pos = -1;
    //FIXME Тип цикла изменён для оптимизации логики
    //while (i >= 0)
    //{
    for (int i = expression.size() - 1; i >= 0; --i) {
        if (expression[i] == ')') {
            //FIXME Нужна префиксная инкрементация
            //level++;
            --level;
        }
        if (expression[i] == '(') {
            //FIXME Нужна префиксная декрементация
            //level--;
            --level;
        }
        if (level == 0 && (expression[i] == '-' || expression[i] == '+')) {
            //FIXME Удалено для оптимизации логики
            //pos = i;
            //break;
            if (level == 0 && (expression[i] == '+' || expression[i] == '-')) {
                int left = EvaluateExpression(expression.substr(0, i));
                int right = EvaluateTerm(expression.substr(i + 1));
                return (expression[i] == '+') ? left + right : left - right;
            }
        }
        //FIXME Удалено для оптимизации логики
        //i--;
    }

    //FIXME Условие удалено для оптимизации логики
    //if (pos == -1) {
    //    return EvaluateTerm(expression);
    //}

    //FIXME Условия удалены для оптимизации логики
    //char ch = expression[pos];
    //if (ch == '+') {
    //      //FIXME Устранено превышение максимально допустимой длины строки
    //      return EvaluateExpression(expression.substr(0, pos)) +
    //             EvaluateTerm(expression.substr(pos + 1));
    //  }
    //if (ch == '-') {
    //      //FIXME Устранено превышение максимально допустимой длины строки
    //      return EvaluateExpression(expression.substr(0, pos)) -
    //             EvaluateTerm(expression.substr(pos + 1));
    //  }
    //return 0;
    return EvaluateTerm(expression);
}