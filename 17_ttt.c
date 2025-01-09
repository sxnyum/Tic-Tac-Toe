#include <stdio.h>
#include <stdlib.h>

char empty[10] = {'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);

int main()
{
    int status_of_game;
    char mark;
    player = 1;
    do
    {
        displayBoard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter your Choice: ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        markBoard(mark);
        status_of_game = checkForWin();
        player++;

    } while (status_of_game == -1);
    displayBoard();

    if (status_of_game == 1)
        printf("==> Player %d wins!\n", --player);
    else
        printf("==> It's a draw!\n");

    return 0;
}

int checkForWin()
{
    if (empty[1] == empty[2] && empty[2] == empty[3] && empty[1] != ' ')
        return 1;
    if (empty[4] == empty[5] && empty[5] == empty[6] && empty[4] != ' ')
        return 1;
    if (empty[7] == empty[8] && empty[8] == empty[9] && empty[7] != ' ')
        return 1;
    if (empty[1] == empty[4] && empty[4] == empty[7] && empty[1] != ' ')
        return 1;
    if (empty[2] == empty[5] && empty[5] == empty[8] && empty[2] != ' ')
        return 1;
    if (empty[3] == empty[6] && empty[6] == empty[9] && empty[3] != ' ')
        return 1;
    if (empty[1] == empty[5] && empty[5] == empty[9] && empty[1] != ' ')
        return 1;
    if (empty[3] == empty[5] && empty[5] == empty[7] && empty[3] != ' ')
        return 1;

    for (int i = 1; i <= 9; i++)
    {
        if (empty[i] == ' ')
            return -1;
    }
    return 0;
}

void displayBoard()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 : (X) - Player 2 : (O)\n\n\n");

    printf("      |      |              |      |     \n");
    printf("  1   |  2   |  3       %c   |  %c   |  %c \n", empty[1], empty[2], empty[3]);
    printf("______|______|_____   ______|______|_____\n");
    printf("      |      |              |      |     \n");
    printf("  4   |  5   |  6       %c   |  %c   |  %c \n", empty[4], empty[5], empty[6]);
    printf("______|______|_____   ______|______|_____\n");
    printf("      |      |              |      |     \n");
    printf("  7   |  8   |  9       %c   |  %c   |  %c \n", empty[7], empty[8], empty[9]);
    printf("      |      |              |      |     \n");
}

void markBoard(char mark)
{
    if (choice >= 1 && choice <= 9 && empty[choice] == ' ')
        empty[choice] = mark;
    else
    {
        printf("Invalid Move. Try again.\n");
        player--;
        getchar();
    }
}
