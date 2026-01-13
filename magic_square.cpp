#include "magic_square.h"

void menu() {
    cout << endl << "╔═══════════════════════════════════════╗" << endl;
    cout << "║   Выберите действие (введите цифру)   ║" << endl;
    cout << "╚═══════════════════════════════════════╝" << endl;
    cout << "1. сгенерировать магический квадрат" << endl;
    cout << "2. выйти из программы" << endl;
}

void input_correct_size(int& size) {
    if (!(cin >> size)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите число" << endl;
        input_correct_size(size);
    }
    if (size % 2 == 0 || size <= 1) {
        cout << endl << "Введён неверный размер магического квадрата" << endl;
        cout << "Пожалуйста, введите новый размер:" << endl;
        input_correct_size(size);
    }
}

void correct(int size, int sum, vector<int> row, vector<int> col,
    vector<int> diag) {
    for (int i = 0; i < size; i++) {
        if (row[i] != sum) {
            cout << "Сумма чисел в строке " << i + 1
                << " отличается, квадрат составлен неверно!" << endl;
            break;
        }
        if (col[i] != sum) {
            cout << "Сумма чисел в столбце " << i + 1
                << " отличается, квадрат составлен неверно!" << endl;
            break;
        }
        if (diag[0] != sum) {
            cout << "Сумма чисел главной диагонали отличается, "
                << "квадрат составлен неверно!" << endl;
            break;
        }
        if (diag[1] != sum) {
            cout << "Сумма чисел побочной диагонали отличается, "
                << "квадрат составлен неверно!" << endl;
            break;
        }
    }
}

void fillMagicsquare(vector<vector<int>>& magicsquare, int size) {
    int i = 0;
    int j = size / 2; // Начальная позиция для 1 (середина первой строки)
    int num = 1;

    while (num <= size * size) {
        magicsquare[i][j] = num;
        int next_i = i - 1;
        if (next_i < 0) {
            next_i = size - 1;
        }
        int next_j = j + 1;
        if (next_j == size) {
            next_j = 0;
        }
        if (magicsquare[next_i][next_j] == 0) {
            i = next_i;
            j = next_j;
        }
        else {
            i++;
        }
        num++;
    }
}

void outputMagicsquare(const vector<vector<int>>& magicsquare, int size, int& width) {
    cout << endl << "╔════════════════════════════════════════════╗" << endl;
    cout << "║        МАГИЧЕСКИЙ КВАДРАТ " << setw(5) << size << setw(2) << "x"
        << setw(2) << size << "        ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl << endl;

    // Определяем ширину для выравнивания чисел
    int max_num = size * size;
    while (max_num > 0) {
        max_num /= 10;
        width++;
    }
    if (width == 0) {
        width = 1;
    }

    // Заполняем верхнюю границу квадрата
    cout << "   ┌";
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < width + 2; k++) {
            cout << "─";
        }
        if (j < size - 1) cout << "┬";
    }
    cout << "┐" << endl;

    // Заполняем середину
    for (int i = 0; i < size; i++) {
        cout << "   │";
        for (int j = 0; j < size; j++) {
            cout << " " << setw(width) << magicsquare[i][j] << " ";
            if (j < size - 1) cout << "│";
        }
        cout << "│" << endl;

        if (i < size - 1) {
            cout << "   ├";
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < width + 2; k++) {
                    cout << "─";
                }
                if (j < size - 1) cout << "┼";
            }
            cout << "┤" << endl;
        }
    }

    // Заполняем нижнюю границу квадрата
    cout << "   └";
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < width + 2; k++) {
            cout << "─";
        }
        if (j < size - 1) cout << "┴";
    }
    cout << "┘" << endl;
}

void sumMagsquare(const vector<vector<int>>& magicsquare, int size,
    vector<int>& rows, vector<int>& columns,
    vector<int>& diagonals) {
    int sum_rows = 0;
    int sum_col = 0;
    int sum_diag = 0;

    cout << endl << "Суммы всех строк магического квадрата:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum_rows += magicsquare[i][j];
        }
        cout << i + 1 << " строка: " << sum_rows << endl;
        rows.push_back(sum_rows);
        sum_rows = 0;
    }

    cout << "Суммы всех столбцов магического квадрата:" << endl;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            sum_col += magicsquare[i][j];
        }
        cout << j + 1 << " столбец: " << sum_col << endl;
        columns.push_back(sum_col);
        sum_col = 0;
    }

    cout << "Сумма главной диагонали: ";
    for (int i = 0; i < size; i++) {
        sum_diag += magicsquare[i][i];
    }
    cout << sum_diag << endl;
    diagonals.push_back(sum_diag);
    sum_diag = 0;

    cout << "Сумма побочной диагонали: ";
    for (int i = 0; i < size; i++) {
        int j = size - 1 - i;
        sum_diag += magicsquare[i][j];
    }
    cout << sum_diag << endl;
    diagonals.push_back(sum_diag);
}

void uniqueNumber(const vector<vector<int>>& magicsquare, int size) {
    int cnt = 0;
    vector<int> numbers;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            numbers.push_back(magicsquare[i][j]);
        }
    }

    for (int i = 0; i < size * size; i++) {
        for (int j = 0; j < size * size; j++) {
            if (numbers[i] == numbers[j]) {
                cnt++;
            }
        }
        if (cnt > 1) {
            cout << endl << "Квадрат составлен неверно, число "
                << numbers[i] << " повторяется несколько раз" << endl;
        }
        cnt = 0;
    }
}

void addFile(const vector<vector<int>>& magicsquare, int size, const int width) {
    ofstream ofile("magic_square.txt");
    if (ofile.is_open()) {
        ofile << "   ┌";
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < width + 2; k++) {
                ofile << "─";
            }
            if (j < size - 1) ofile << "┬";
        }
        ofile << "┐" << endl;

        for (int i = 0; i < size; i++) {
            ofile << "   │";
            for (int j = 0; j < size; j++) {
                ofile << " " << setw(width) << magicsquare[i][j] << " ";
                if (j < size - 1) ofile << "│";
            }
            ofile << "│" << endl;

            if (i < size - 1) {
                ofile << "   ├";
                for (int j = 0; j < size; j++) {
                    for (int k = 0; k < width + 2; k++) {
                        ofile << "─";
                    }
                    if (j < size - 1) ofile << "┼";
                }
                ofile << "┤" << endl;
            }
        }

        ofile << "   └";
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < width + 2; k++) {
                ofile << "─";
            }
            if (j < size - 1) ofile << "┴";
        }
        ofile << "┘" << endl;
        cout << endl << "Магический квадрат успешно добавлен в файл!" << endl;
    }
    else {
        cout << "Не получилось открыть файл!";
    }
    ofile.close();

}
