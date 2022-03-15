//
// Created by seed on 3/6/22.
//

#include "mat.hpp"
#include "stdexcept"
#include <vector>

using namespace ariel;
int const low = 33;
int const high = 126;

string ariel::mat(int columns, int row, char s, char bet) {

//    if (columns % 2 == 0 || row % 2 == 0 || columns < 0 || row < 0) {
//        throw invalid_argument("Mat size is always odd and positive");
//    }
//    if (s < low || s > high || bet < low || bet > high) {
//        throw invalid_argument("Not a valid symbols");
//    }
    vector <vector<char>> matrix(row, vector<char>(columns));
    int i = 0;
    string spiri = string("");
    if (columns % 2 != 0 && row % 2 != 0 && columns > 0 && row > 0) {
        if (s >= low && s <= high && bet >= low && bet <= high) {
            char sym = s;
            int haf = min(columns, row) / 2;
            while (i <= haf) {
                /* Print the first and last row from the remaining rows */
                for (int k = i; k < columns - i; k++) {
                    matrix[i][k] = sym;
                    matrix[row - 1 - i][k] = sym;
                }
                /* Print the first and last columns from the remaining columns */
                for (int l = i; l < row - i; l++) {
                    matrix[l][i] = sym;
                    matrix[l][columns - 1 - i] = sym;
                }
                if (sym == s) {
                    sym = bet;
                } else {
                    sym = s;
                }
                i++;
            }
        } else {
            throw invalid_argument("Not a valid symbols");
        }
    } else {
        throw invalid_argument("columns and rows should always be odd and positive");
    }
    for (i = 0; i < row; i++) {
        for (int l = 0; l < columns; l++) {
            spiri += matrix[i][l];
        }
        spiri += '\n';
    }
    return spiri;
}