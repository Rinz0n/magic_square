#include "magic_square.h"

int main() {
    setlocale(LC_ALL, "RU");
    int number;
    int size;
    int sum;
    int width = 0;
    vector<int> sum_rows;
    vector<int> sum_diagonals;
    vector<int> sum_columns;
    do {
        menu();

        // Данное условие помогает избежать бесконечного цикла в случае, если пользователь ввел не число
        if (!(cin >> number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите 1 или 2" << endl;
            continue;
        }

        switch (number) {
        case 1: {
            cout << endl << "Введите размер магического квадрата нечётного порядка (нечётное число > или = 3):"
                << endl;
            input_correct_size(size);
            sum = size * (size * size + 1) / 2;
            vector<vector<int>> magic_square(size, vector<int>(size, 0));

            fillMagicsquare(magic_square, size);
            outputMagicsquare(magic_square, size, width);
            sumMagsquare(magic_square, size, sum_rows, sum_columns, sum_diagonals);
            correct(size, sum, sum_rows, sum_columns, sum_diagonals);
            uniqueNumber(magic_square, size);
            addFile(magic_square, size, width);

            sum_rows.clear();
            sum_columns.clear();
            sum_diagonals.clear();
            width = 0;
            break;
        }
        case 2:
            cout << "Выход из программы";
            break;
        default:
            cout << "Ошибка! Введите 1 или 2";
        }
    } while (number != 2);

    return 0;

}
