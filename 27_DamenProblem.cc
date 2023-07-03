#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

const int N = 8;
bool print_each_try = false;
int solution_number = 0;

void print_chess_board(int chess_board[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << chess_board[i] << " ";
    }
    cout << "\n\n";
}

void print_graphic_chess_board(int chess_board[], int N)
{
    for (int i = N - 1; i >= 0; i--)
    {
        cout << i + 1 << " |  ";
        for (int n = 0; n < N; n++)
        {
            if (chess_board[n] == i + 1)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << "    ";
    for (int i = 1; i <= N; i++)
    {
        cout << " -";
    }
    cout << endl
         << "     ";
    for (int i = 1; i <= N; i++)
    {
        cout << i << " ";
    }
    cout << "\n\n";
}

bool check_position(int chess_board[], int new_column)
{
    for (int i = 0; i < new_column; i++)
    {
        if (chess_board[new_column] == chess_board[i] or abs(chess_board[new_column] - chess_board[i]) == abs(new_column - i))
        {
            return false;
        }
    }
    return true;
}

void next_column(int chess_board[], int N, int new_column)
{
    if (chess_board[new_column] == N)
    {
        if (new_column == 0)
        {
            cout << "All combinations have been tried. Number of solutions for N=" << N << ": " << solution_number << "\n\n\n";
            exit(0);
        }
        chess_board[new_column] = 0;
        next_column(chess_board, N, new_column - 1);
    }
    for (int i = chess_board[new_column]; i < N; i++)
    {
        chess_board[new_column]++;
        if (print_each_try){
            print_chess_board(chess_board, N);
            print_graphic_chess_board(chess_board, N);
        }
        if (check_position(chess_board, new_column))
        {
            if (new_column == N - 1)
            {
                solution_number++;
                cout << "Solution " << solution_number << " found!" << endl;
                print_chess_board(chess_board, N);
                cout << "\n";
                print_graphic_chess_board(chess_board, N);
                cout << endl;
                chess_board[new_column] = 0;
                next_column(chess_board, N, new_column - 1);
            }
            else
            {
                next_column(chess_board, N, new_column + 1);
            }
        }
        else if (chess_board[new_column] == N)
        {
            chess_board[new_column] = 0;
            next_column(chess_board, N, new_column - 1);
        }
    }
}

int main()
{
    int chess_board[N];

    next_column(chess_board, N, 0);


    cout << "\n\n";
    return 0;
}