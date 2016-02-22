#include <stdio.h>

#define M 4
#define N 5

int move = 0;

void DisplayBoard(int Board[M][N])
{
    int i, j;
    printf("\n-------------\n");
    for(i = 1; i < 4; i ++) {
        for(j = 1; j < 4; j++) {
            if(Board[i][j] == -1) {
                printf("| X ");
            } else if(Board[i][j] == 1) {
                printf("| O ");
            } else {
                printf("|   ");
            }
        }
        printf("|\n-------------\n");
    }
}

int Move(int Board[M][N])
{
    int x, y, X, i;
    X = (move%2) ? 1 : -1;
    printf("Player %d: ", (move%2)+1);
    scanf(" %d %d", &x, &y);
    Board[x][y] = X;
    Board[x][0] = Board[x][0] + X;
    Board[0][y] = Board[0][y] + X;
    if(x == y && x != 0) 
        Board[0][0] =  Board[0][0] + X;
    if( x == y + 2 || y == x + 2 || (x == 2) && (y ==2)) {
        Board[0][N-1] = Board[0][N-1] + X;
    }
    DisplayBoard(Board);
    move++;
    for(i = 0; i < M; i++) {
        if(Board[i][0] == 3 || Board[0][i] == 3) {
            printf("Winner is O\n");
            return 1;
        }
        if(Board[i][0] == -3 || Board[0][i] == -3) {
            printf("Winner is X\n");
            return 1;
        }
    }
    if(Board[0][N-1] == 3) {
        printf("Winner is O\n");
        return 1;
    } else if (Board[0][N-1] == -3) {
        printf("Winner is X\n");
        return 1;
    }
    Move(Board);
}

int main()
{
    int i, j;
    int Board[M][N];
    for(i = 0; i < M; i++)
        for(j=0; j < N; j++)
            Board[i][j] = 0;
    DisplayBoard(Board);
    Move(Board);
}