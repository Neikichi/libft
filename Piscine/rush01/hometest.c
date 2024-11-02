#include <stdio.h>

#define N 4

int square[N][N];
int count = 0;

void print_square() 
{
    int i = 0, j = 0;
    while (i < N) {
        j = 0;
        while (j < N) {
            printf("%d ", square[i][j] + 1);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

int is_valid(int row, int col, int num) {
    int i = 0;
    while (i < col) {
        if (square[row][i] == num) return 0;
        i++;
    }
    i = 0;
    while (i < row) {
        if (square[i][col] == num) return 0;
        i++;
    }
    return 1;
}

void generate_squares(int row, int col) {
    if (row == N) {
        // print_square();
        to_verify();
        count++;
        return;
    }
    if (col == N) {
        generate_squares(row + 1, 0);
        return;
    }
    int num = 0;
    while (num < N) {
        if (is_valid(row, col, num)) {
            square[row][col] = num;
            generate_squares(row, col + 1);
        }
        num++;
    }
    square[row][col] = 0;
}

void to_verify()
{
    char arr[N * N] = {'0'};

    int row = 0, col, lc, rc, ur, lr;
    while (row < N) {
        col = 0;
        lc = 1;
        rc = 1;
        ur = 1;
        lr = 1;
        while (col < N) {
            printf("%d ", square[row][col] + 1);

            if (col + 1 < N && square[row][col] != N && square[row][col] < square[row][col + 1])
            {
                lc++;
            }
            if (col > 0 && square[row][N - col] != N && square[row][N - col] < square[row][N - col - 1])
            {
                rc++;
            }
            if (row + 1 < N && square[row + col][col - col + row] != N && square[row + col][col - col + row] < square[row + col + 1][col - col + row])
            {
                ur++;
            }
            
            col++;
        }
        printf(" | Lc:%d Rc:%d Up:%d\n", lc, rc, ur);
        row++;
    }
    printf("\n");
}

int main() {

    char arr[] = "2 1 3 4 3 2 1 2 4 3 2 1 1 2 2 2";
    

    generate_squares(0, 0);
    printf("Total Latin Squares generated: %d\n", count);
    return 0;
}