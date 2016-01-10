#include <iostream>

using namespace std;

const int board_size = 8;
bool board[board_size][board_size];
int results_count = 0;

void printBoard()
{
    for(int i = 0; i < board_size; i++)
    {
        for(int j = 0; j < board_size; j++)
            cout<<(board[i][j] ? "*" : "-");
        cout<<endl;
    }
}


bool check(int a, int b)
{
    for(int i = 0; i < a; i++)
        if(board[i][b])
            return false;

    for(int i = 1; i <= a && b-i >= 0; i++)
        if(board[a-i][b-i])
            return false;

    for(int i = 1; i <= a && b+i < board_size; i++)
        if(board[a-i][b+i])
            return false;

    return true;
}


void setQueen(int a)
{
    if(a == board_size)
    {
        printBoard();
        std::cout << "Result #" << ++results_count << endl << endl;
        return;
    }

    for(int i = 0; i < board_size; i++)
    {
        if(check(a, i))
        {
            board[a][i] = 1;
            setQueen(a+1);
            board[a][i] = 0;
        }
    }

}

int main()
{
    setQueen(0);

    return 0;
}
