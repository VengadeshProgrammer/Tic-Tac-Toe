#include <stdio.h>
#include <stdlib.h> // Header Files
#include <time.h>
#define ROW 3                              // ROW = 3
#define COL 3                              // COL = 3
char map[ROW][COL];                        // Define a MAP ARRAY of ROW x COL
char player;                               // declare player
char PPLAYER;                              // declare progam player
unsigned short int turn = 1;               // declare and initialize program player turn
unsigned short int POSROW = 0, POSCOL = 0; // declare and (initialize for to overcome garbage value)  for POSITION of user input
const char *BlockHorizontalMatch(void);    // declare the functions
const char *BlockVerticalMatch(void);
const char *BlockSideMatchL(void);
const char *BlockSideMatchR(void);
const char *PlacePlayer(int POSROW, int POSCOL);
const char *BlockHorizontalViseVersaMatch(void);
const char *BlockHorizontalCenterMatch(void);
const char *BlockVerticalViseVersaMatch(void);
const char *BlockVerticalCenterMatch(void);
const char *BlockSideMatchLViseVersa(void);
const char *BlockSideMatchRCenter(void);
const char *BlockSideMatchLCenter(void);
const char *BlockSideMatchRViseVersa(void);
void DisplayGrid(int POSROW, int POSCOL)
{
    // Function to PrintBoard
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (i == 0)
            {
                printf("\n _____________");
            }
            printf("\n | %c | %c | %c |", map[i][j], map[i][j + 1], map[i][j + 2]);
            if (i == 3)
            {
                printf("\n _____________ \n\n");
            }
            else
            {
                printf("\n _____________");
                break;
            }
        };
    };
};

const char *BlockHorizontalMatch()
{
    // Function to BlockHorizontalMatch By Player
    int turn = 1;
    for (int i = 0; i < ROW; i++)
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL - 2; j++) // Updated to COL - 2
        {
            // Ensure we check for only valid adjacent columns
            if (map[i][j] == map[i][j + 1] && map[i][j] != '\0' && map[i][j + 1] != '\0') // Check if there's a valid player character
            {
                if (map[i][j + 2] == '\0') // Check if the third spot is empty
                {
                    map[i][j + 2] = PPLAYER;
                    turn = 0;
                    return "Horizontal";
                }
            }
        }
    }
};
const char *PlacePlayer(int POSROW, int POSCOL)
{
    // Function to correctly place the player on the board
    if (map[POSROW][POSCOL] == PPLAYER || map[POSROW][POSCOL] == player)
    {
        printf("\n Enter Correct Position !");
        exit(1);
    }
    else
    {
        // if okay, initialize the map accoring to the position of user given is set to the player character;
        if (POSROW >= 3 || POSCOL >= 3)
        {
            printf("\n Enter Correct Position !");
            exit(1);
        }
        else
            map[POSROW][POSCOL] = player;
    }
    if (BlockHorizontalMatch() == "Horizontal" || BlockVerticalMatch() == "Vertical" || BlockSideMatchL() == "Side" || BlockSideMatchR() == "Side" || BlockHorizontalViseVersaMatch() == "HorViseVersa" || BlockHorizontalCenterMatch() == "HorCenter" || BlockVerticalViseVersaMatch() == "VerViseVersa" || BlockVerticalCenterMatch() == "VerCenter" || BlockSideMatchLViseVersa() == "SideLViseVersa" || BlockSideMatchRViseVersa() == "SideRViseVersa" || BlockSideMatchRCenter() == "SideRCenter" || BlockSideMatchLCenter() == "SideLCenter")
    {
        // Checks if anyone of the functions blocks the player charcter
    }
};
const char *BlockVerticalMatch()
{
    // Function to BlockVerticalMatch
    int turn = 1;
    for (int i = 0; i < ROW - 2; i++) // Updated to ROW - 2
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL; j++)
        {
            // Ensure we check for only valid adjacent columns
            if (map[i][j] == map[i + 1][j] && map[i][j] != '\0' && map[i + 1][j] != '\0') // Check if there's a valid player character
            {
                if (map[i + 2][j] == '\0') // Check if the third spot is empty
                {
                    map[i + 2][j] = PPLAYER;
                    turn = 0;
                    return "Vertical";
                }
            }
        }
    }
};
const char *BlockSideMatchL()
{
    // Function to BlockLeftSideMatch
    int turn = 1;
    for (int i = 0; i < ROW - 2; i++)
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL; j++)
        {
            if (map[ROW - 1][COL - 3] == map[ROW - 2][COL - 2] && map[ROW - 1][COL - 3] != '\0' && map[ROW - 2][COL - 2] != '\0')
            {
                if (map[ROW - 3][COL - 1] == '\0')
                {
                    map[ROW - 3][COL - 1] = PPLAYER;
                    turn = 0;
                    return "Side";
                }
            }
        }
    }
};
const char *BlockSideMatchR()
{
    // Function to BlockRightSideMatch
    int turn = 1;
    for (int i = 0; i < ROW - 2; i++)
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL; j++)
        {
            if (map[ROW - 1][COL - 1] == map[ROW - 2][COL - 2] && map[ROW - 1][COL - 1] != '\0' && map[ROW - 2][COL - 2] != '\0')
            {
                if (map[ROW - 3][COL - 3] == '\0')
                {
                    map[ROW - 3][COL - 3] = PPLAYER;
                    turn = 0;
                    return "Side";
                }
            }
        }
    }
};
const char *BlockHorizontalViseVersaMatch()
{
    int turn = 1;
    for (int i = 0; i < ROW; i++)
    {
        if (map[i][2] == map[i][1] && map[i][2] != '\0' && map[i][1] != '\0')
        {
            if (map[i][0] == '\0')
            {
                map[i][0] = PPLAYER;
                turn = 0;
                return "HorViseVersa";
            }
        }
    }
};
const char *BlockHorizontalCenterMatch()
{
    int turn = 0;
    for (int i = 0; i < ROW; i++)
    {
        if (map[i][0] == map[i][2] && map[i][0] != '\0' && map[i][2] != '\0')
        {
            if (map[i][1] == '\0')
            {
                map[i][1] = PPLAYER;
                turn = 0;
                return "HorCenter";
            }
        }
    }
};
const char *BlockVerticalViseVersaMatch()
{
    int turn = 1;
    for (int i = 0; i < ROW; i++)
    {
        if (map[2][i] == map[1][i] && map[2][i] != '\0' && map[1][i] != '\0')
        {
            if (map[0][i] == '\0')
            {
                map[0][i] = PPLAYER;
                turn = 1;
                return "VerViseVersa";
            }
        }
    }
};
const char *BlockVerticalCenterMatch()
{
    int turn = 1;
    for (int i = 0; i < ROW - 2; i++) // Updated to ROW - 2
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL; j++)
        {
            // Ensure we check for only valid adjacent columns
            if (map[0][j] == map[2][j] && map[0][j] != '\0' && map[2][j] != '\0') // Check if there's a valid player character
            {
                if (map[1][j] == '\0') // Check if the third spot is empty
                {
                    map[1][j] = PPLAYER;
                    turn = 0;
                    return "VerCenter";
                }
            }
        }
    }
};
const char *BlockSideMatchRViseVersa()
{
    int turn = 1;
    for (int i = 0; i < ROW - 2; i++)
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL; j++)
        {
            if (map[ROW - 3][COL - 3] == map[ROW - 2][COL - 2] && map[ROW - 3][COL - 3] != '\0' && map[ROW - 2][COL - 2] != '\0')
            {
                if (map[ROW - 1][COL - 1] == '\0')
                {
                    map[ROW - 1][COL - 1] = PPLAYER;
                    turn = 0;
                    return "SideRViseVersa";
                }
            }
        }
    }
};
const char *BlockSideMatchRCenter()
{
    int turn = 1;
    for (int i = 0; i < ROW - 2; i++)
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL; j++)
        {
            if (map[ROW - 3][COL - 3] == map[ROW - 1][COL - 1] && map[ROW - 3][COL - 3] != '\0' && map[ROW - 1][COL - 1] != '\0')
            {
                if (map[ROW - 2][COL - 2] == '\0')
                {
                    map[ROW - 2][COL - 2] = PPLAYER;
                    turn = 0;
                    return "SideRCenter";
                }
            }
        }
    }
};
const char *BlockSideMatchLViseVersa()
{
    int turn = 1;
    for (int i = 0; i < ROW - 2; i++)
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL; j++)
        {
            if (map[ROW - 3][COL - 3] == map[ROW - 2][COL - 2] && map[ROW - 3][COL - 3] != '\0' && map[ROW - 2][COL - 2] != '\0')
            {
                if (map[ROW - 3][COL - 3] == '\0')
                {
                    map[ROW - 1][COL - 1] = PPLAYER;
                    turn = 0;
                    return "SideLViseVersa";
                }
            }
        }
    }
};
const char *BlockSideMatchLCenter()
{
    int turn = 1;
    for (int i = 0; i < ROW - 2; i++)
    {
        if (turn == 0)
            break;
        for (int j = 0; j < COL; j++)
        {
            if (map[ROW - 1][COL - 3] == map[ROW - 3][COL - 1] && map[ROW - 1][COL - 3] != '\0' && map[ROW - 3][COL - 1] != '\0')
            {
                if (map[ROW - 2][COL - 2] == '\0')
                {
                    map[ROW - 2][COL - 2] = PPLAYER;
                    turn = 0;
                    return "SideLCenter";
                }
            }
        }
    }
};
int main()
{

    // main function to assemble all functions with algorithms
    srand(time(0));
    if (POSROW == 0 && POSCOL == 0)
    {
        // saves the player character
        printf("\n Enter Your Player As X or O: ");
        scanf("%c", &player);
        // gets a program player (opponent character);
        if (player == 'X')
            PPLAYER = 'O';
        else if (player == 'x')
            PPLAYER = 'o';
        else if (player == 'O')
            PPLAYER = 'X';
        else if (player == 'o')
            PPLAYER = 'x';
        else // if player enters other characters , exit the game;
            exit(1);
        while (1)
        {
            // game loop
            // gets position by user
            printf("\n Enter The ROW Position : ");
            scanf("%hu", &POSROW);
            printf("\n Enter The COL Position : ");
            scanf("%hu", &POSCOL);
            PlacePlayer(POSROW, POSCOL);
            DisplayGrid(POSROW, POSCOL);
        }
    }
    else
    {
        POSCOL = 0;
        POSROW = 0;
    }
    return 0;
    // Game end
};
