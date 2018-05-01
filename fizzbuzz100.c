#include <stdio.h>
int main(void) {
    char line[101][9] = {0};
    for (int i = 0, col = 3, row = 42; i < 909; i ++, col = (col + 5) % 9, row = 1 + ((row-1) + 17) % 100) {
        switch (col) {
            case 0:
                if (row % 3 == 0) {
                    line[row][col] = 'F';
                }
                else if (row % 5 == 0) {
                    line[row][col] = 'B';
                }
                else if (row < 10) {
                    line[row][col] = '0' + row;
                }
                else {
                    line[row][col] = '0' + row / 10;
                }
                break;
            case 1:
                if (row % 3 == 0) {
                    line[row][col] = 'i';
                }
                else if (row % 5 == 0) {
                    line[row][col] = 'u';
                }
                else if (row >= 10) {
                    line[row][col] = '0' + row % 10;
                }
                break;
            case 2:
            case 3:
                if (row % 3 == 0 || row % 5 == 0) {
                    line[row][col] = 'z';
                }
                break;
            case 4:
                if (row % 15 == 0) {
                    line[row][col] = 'B';
                }
                break;
            case 5:
                if (row % 15 == 0) {
                    line[row][col] = 'u';
                }
                break;
            case 6:
            case 7:
                if (row % 15 == 0) {
                    line[row][col] = 'z';
                }
                break;
        }
    }
    for (int i = 1; i <= 100; i ++) {
        puts(line[i]);
    }
}
