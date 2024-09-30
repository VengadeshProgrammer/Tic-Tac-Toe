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
unsigned short int already = 0;
const char *BlockHorizontalMatch(int CheckPplayerWin); // declare the functions
const char *BlockVerticalMatch(int CheckPplayerWin);
const char *BlockSideMatchL(int CheckPplayerWin);
const char *BlockSideMatchR(int CheckPplayerWin);
const char *PlacePlayer(int POSROW, int POSCOL);
const char *BlockHorizontalViseVersaMatch(void);
const char *BlockHorizontalCenterMatch(void);
const char *BlockVerticalViseVersaMatch(void);
const char *BlockVerticalCenterMatch(void);
const char *BlockSideMatchLViseVersa(void);
const char *BlockSideMatchRCenter(void);
const char *BlockSideMatchLCenter(void);
const char *BlockSideMatchRViseVersa(void);
void WinningTechinques(void);
void DisplayGrid()
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

const char *BlockHorizontalMatch(int CheckPplayerWin)
{
    // Function to BlockHorizontalMatch By Player
    if (CheckPplayerWin == 1)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL - 2; j++)
            {
                if ((map[i][j] == PPLAYER) && (map[i][j + 1] == PPLAYER) && (map[i][j + 2] == PPLAYER) && map[i][j] != '\0' && map[i][j + 1] != '\0' && map[i][j + 2] != '\0')
                {
                    return "Winner!";
                }
            }
        }
    }
    else if (CheckPplayerWin == 0)
    {
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
    WinningTechinques();
    // if (BlockHorizontalMatch() == "Horizontal" || BlockVerticalMatch() == "Vertical" || BlockSideMatchL() == "Side" || BlockSideMatchR() == "Side" || BlockHorizontalViseVersaMatch() == "HorViseVersa" || BlockHorizontalCenterMatch() == "HorCenter" || BlockVerticalViseVersaMatch() == "VerViseVersa" || BlockVerticalCenterMatch() == "VerCenter" || BlockSideMatchLViseVersa() == "SideLViseVersa" || BlockSideMatchRViseVersa() == "SideRViseVersa" || BlockSideMatchRCenter() == "SideRCenter" || BlockSideMatchLCenter() == "SideLCenter")
    // {
    //     // Checks if anyone of the functions blocks the player charcter
    // }
};
const char *BlockVerticalMatch(int CheckPplayerWin)
{
    // Function to BlockVerticalMatch
    if (CheckPplayerWin == 1)
    {
        for (int i = 0; i < ROW - 2; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if ((map[i][j] == PPLAYER) && (map[i + 1][j] == PPLAYER) && (map[i + 2][j] == PPLAYER) && map[i][j] != '\0' && map[i + 1][j] != '\0' && map[i + 2][j] != '\0')
                {
                    return "Winner!";
                }
            }
        }
    }
    else if (CheckPplayerWin == 0)
    {
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
    }
};
const char *BlockSideMatchL(int CheckPplayerWin)
{
    // Function to BlockLeftSideMatch
    if (CheckPplayerWin == 1)
    {
        for (int i = 0; i < ROW - 2; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if ((map[ROW - 1][COL - 3] == PPLAYER) && (map[ROW - 2][COL - 2] == PPLAYER) && (map[ROW - 3][COL - 1] == PPLAYER) && map[ROW - 1][COL - 3] != '\0' && map[ROW - 2][COL - 2] != '\0' && map[ROW - 3][COL - 1] != '\0')
                {
                    return "Winner!";
                }
            }
        }
    }
    else if (CheckPplayerWin == 0)
    {
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
    }
};
const char *BlockSideMatchR(int CheckPplayerWin)
{
    // Function to BlockRightSideMatch
    if (CheckPplayerWin == 1)
    {
        for (int i = 0; i < ROW - 2; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if ((map[ROW - 1][COL - 1] == PPLAYER) && (map[ROW - 2][COL - 2] == PPLAYER) && (map[ROW - 3][COL - 3] == PPLAYER) && map[ROW - 1][COL - 1] != '\0' && map[ROW - 2][COL - 2] != '\0' && map[ROW - 3][COL - 3] != '\0')
                {
                    return "Winner!";
                }
            }
        }
    }
    else if (CheckPplayerWin == 0)
    {
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
void WinningTechinques()
{
    if (already == 0)
    {

        int corners[4][2] =
            {
                {0, 0},
                {0, 2},
                {2, 0},
                {2, 2}

            };
        int randomIndex = rand() % 4;

        if (map[1][1] != player)
        {
            map[1][1] = PPLAYER;
            randomIndex = 0;
            already = 1;
        }
        else
        {
            if (map[corners[randomIndex][0]][corners[randomIndex][1]] == player)
                WinningTechinques();
            else
            {
                map[corners[randomIndex][0]][corners[randomIndex][1]] = PPLAYER;
                randomIndex = 0;
                already = 1;
            }
        }
    }
    else
    {
        // If Blocks, checks if BOT WON
        if (BlockHorizontalMatch(0) == "Horizontal" || BlockVerticalMatch(0) == "Vertical" || BlockSideMatchL(0) == "Side" || BlockSideMatchR(0) == "Side" || BlockHorizontalViseVersaMatch() == "HorViseVersa" || BlockHorizontalCenterMatch() == "HorCenter" || BlockVerticalViseVersaMatch() == "VerViseVersa" || BlockVerticalCenterMatch() == "VerCenter" || BlockSideMatchLViseVersa() == "SideLViseVersa" || BlockSideMatchRViseVersa() == "SideRViseVersa" || BlockSideMatchRCenter() == "SideRCenter" || BlockSideMatchLCenter() == "SideLCenter")
        {
            // Checks if anyone of the functions blocks the player charcter
            if (BlockSideMatchL(1) == "Winner!" || BlockSideMatchR(1) == "Winner!" || BlockHorizontalMatch(1) == "Winner!" || BlockVerticalMatch(1) == "Winner!")
            {
                DisplayGrid();
                printf("\n You LOSE !! \n");
                exit(1);
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
