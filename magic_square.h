#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void menu();

void input_correct_size(int& size);

void correct(int size, int sum, vector<int> row, vector<int> col, vector<int> diag);

void fillMagicsquare(vector<vector<int>>& magicsquare, int size);

void outputMagicsquare(const vector<vector<int>>& magicsquare, int size, int& width);

void sumMagsquare(const vector<vector<int>>& magicsquare, int size,
    vector<int>& rows, vector<int>& columns,
    vector<int>& diagonals);

void uniqueNumber(const vector<vector<int>>& magicsquare, int size);

void addFile(const vector<vector<int>>& magicsquare, int size, const int width);

#endif