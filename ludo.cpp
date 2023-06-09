#include <iostream>
#include "fstream"
#include <conio.h> //headerfiles
#include <cstdlib>
#include <windows.h> // headerfile_for_colors
#include <string>    //for_strings
#include <time.h>    //for_random_numbers
using namespace std;
int counter = 0;
int option; // to select the menu
int c1 = 0;
int c2 = 0;

int c3 = 0;
int c4 = 0;
int i = 1;  // subscript for player1
int j = 14; // subscript for player2
int k = 40; // subscript for player3
int l = 27; // subscript for player4
char t1, t2, t3, t4;
string p1, p2, p3, p4;
int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0; // count marks for eachplayer
int dice = 0;
int members;
char p11, p12, p13, p14;
char r11, r12, r13, r14; // each tokens
char q11, q12, q13, q14;
char s11, s12, s13, s14;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // declaration_for_colors
void MENU(char arr[], char left[], char up[], char down[], char right[]);
void SELECTION(char arr[], char left[], char up[], char down[], char right[]);
void BOARD(char arr[], char left[], char up[], char down[], char right[]);
void TWOPLAyers(char arr[], char left[], char up[], char down[], char right[]);
void THREEPLAyers(char arr[], char left[], char up[], char down[], char right[]);
void FOURPLAyers(char arr[], char left[], char up[], char down[], char right[]);
void p1turn(char arr[], char left[]);
void p2turn(char arr[], char up[]); // Globally_functions
void p3turn(char arr[], char down[]);
void p4turn(char arr[], char right[]);
void MENU(char arr[], char left[], char up[], char down[], char right[])
{
    fstream fout;
    fout.open("menu.txt");
    while (1)
    {
        cout << "\n";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 3; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "--";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        SetConsoleTextAttribute(h, 7);
        Sleep(1000);
        cout << "\n\n\t1. ";
        cout << "PLAY GAME";
        cout << "\n\t2.";
        cout << " HOW TO PLAY";
        cout << "\n\t3. ";
        cout << "HIGH SCORES";
        cout << "\n\t4. ";
        cout << "EXIT";
        fout << "\n\n\t1. ";
        fout << "PLAY GAME";
        fout << "\n\t2.";
        fout << " HOW TO PLAY";
        fout << "\n\t3. ";
        fout << "HIGH SCORES";
        fout << "\n\t4. ";
        fout << "EXIT";
        SetConsoleTextAttribute(h, 8);
        cout << "\n\n\tSELECT THE MENU : ";
        cin >> option;
        switch (option) // switch statement
        {
        case 1:
        {
            SELECTION(arr, left, up, down, right);
            break;
        }
        case 2:
        {
            SetConsoleTextAttribute(h, 8);
            cout << "\n\tHOW TO PLAY GAME\n"; // rules
            SetConsoleTextAttribute(h, 7);
            cout << "\n\tOn each player's turn, the player rolls the die to determine a move.\n";
            cout << "The goal of the game is to move all four of the player's pieces clockwise once \naround the board,";
            cout << "up the home column, and into the home triangle.\n";
            cout << "To begin, a player must roll a six to move a piece out of the baseand \nonto the start position.";
            fout << "\n\tOn each player's turn, the player rolls the die to determine a move.\n";
            fout << "The goal of the game is to move all four of the player's pieces clockwise once \naround the board,";
            fout << "up the home column, and into the home triangle.\n";
            fout << "To begin, a player must roll a six to move a piece out of the baseand \nonto the start position.";
        }
        break;
        case 3:
        {
            SetConsoleTextAttribute(h, 7); // high score
            cout << "\n\tHIGH SCORES : PROCESSING...";
            fout << "\n\tHIGH SCORES : PROCESSING...";
        }
        break;
        case 4:
            break;
        default:
        {
            SetConsoleTextAttribute(h, 7);
            cout << "\n\tWRONG INPUT!...."; // invalid enter
        }
        break;
        }
        SetConsoleTextAttribute(h, 15);
        cout << endl;
        if (option == 4)
        {
            SetConsoleTextAttribute(h, 5);
            for (int t = 0; t <= 1; t++)
            {
                for (int u = 0; u < 10; u++)
                {
                    if (u < 15)
                    {
                        SetConsoleTextAttribute(h, u);
                        Sleep(28);
                        cout << "-";
                    }
                    else
                    {
                        Sleep(28);
                        cout << "-";
                    }
                }
            }
            cout << "TERMINATE THE GAME";
            fout << "\n\nTERMINATE THE GAME";
            SetConsoleTextAttribute(h, 5);
            for (int t = 0; t <= 1; t++)
            {
                for (int u = 0; u < 10; u++)
                {
                    if (u < 15)
                    {
                        SetConsoleTextAttribute(h, u);
                        Sleep(28);
                        cout << "-";
                    }
                    else
                    {
                        Sleep(28);
                        cout << "-";
                    }
                }
            }
            cout << "\n";
            break;
        }
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 3; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "--";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
    }
    //	fout.close();
}
void SELECTION(char arr[], char left[], char up[], char down[], char right[])
{
    system("CLS");

    SetConsoleTextAttribute(h, 5);
    for (int t = 0; t <= 1; t++)
    {
        for (int u = 0; u < 10; u++)
        {
            if (u < 15)
            {
                SetConsoleTextAttribute(h, u);
                Sleep(28);
                cout << "-";
            }
            else
            {
                Sleep(28);
                cout << "-";
            }
        }
    }
    cout << "LETS START THE GAME";
    SetConsoleTextAttribute(h, 5);
    for (int t = 0; t <= 1; t++)
    {
        for (int u = 0; u < 10; u++)
        {
            if (u < 15)
            {
                SetConsoleTextAttribute(h, u);
                Sleep(28);
                cout << "-";
            }
            else
            {
                Sleep(28);
                cout << "-";
            }
        }
    }
    cout << "\n";
    SetConsoleTextAttribute(h, 8);
    cout << "\n\tHOW MANY PLAYERS WANT TO PLAY:- \n";
    SetConsoleTextAttribute(h, 7);
    cout << "\n\t2. TWO PLAYERS";
    cout << "\n\t3. THREE PLAYERS";
    cout << "\n\t4. FOUR PLAYERS\n";
    SetConsoleTextAttribute(h, 8);
    cout << "\n\tSELECT your choice:- ";
    cin >> members;
    if (members == 2)
    {
        SetConsoleTextAttribute(h, 8);
        cout << "\n\tWELCOME TO PLAY GAME: \n";
        SetConsoleTextAttribute(h, 7);
        cout << "\n\tENTER FIRST PLAYER NAME: ";
        cin >> p1;
        SetConsoleTextAttribute(h, 7);
        cout << "\n\tENTER SECOND PLAYER NAME: ";
        cin >> p2;
        Sleep(1000);
        system("CLS");
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 3; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "--";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        SetConsoleTextAttribute(h, 8);
        cout << "\n\tPress '&' for GREEN";
        cout << "\n\tPress '@' for RED";
        cout << "\n\tPress '$' for BLUE";
        cout << "\n\tPress '#' for YELLOW";
        SetConsoleTextAttribute(h, 4);
        cout << "\n\n\t" << p1 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        cin >> t1;
        SetConsoleTextAttribute(h, 1);
        cout << "\n\n\t" << p2 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        cin >> t2;
        t3 = ' ';
        t4 = ' ';
        p11 = t1, p12 = t1, p13 = t1, p14 = t1;
        r11 = t2, r12 = t2, r13 = t2, r14 = t2;
        q11 = t3, q12 = t3, q13 = t3, q14 = t3;
        s11 = t4, s12 = t4, s13 = t4, s14 = t4;
        Sleep(1000);
        cout << endl;
        system("CLS");
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 1; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "-";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "LUDO BOARD";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 1; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "-";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "\n\n";
        Sleep(1000);
        SetConsoleTextAttribute(h, 8);
        BOARD(arr, left, up, down, right);
        SetConsoleTextAttribute(h, 8);
        TWOPLAyers(arr, left, up, down, right);
    }
    if (members == 3)
    {
        SetConsoleTextAttribute(h, 8);
        cout << "\n\tWELCOME TO PLAY GAME: \n";
        SetConsoleTextAttribute(h, 4);
        cout << "\n\tENTER FIRST PLAYER NAME: ";
        cin >> p1;
        SetConsoleTextAttribute(h, 1);
        cout << "\n\tENTER SECOND PLAYER NAME: ";
        cin >> p2;
        SetConsoleTextAttribute(h, 2);
        cout << "\n\tENTER THIRD PLAYER NAME: ";
        cin >> p3;
        Sleep(1000);
        system("CLS");
        SetConsoleTextAttribute(h, 7);
        cout << "\n\tPress '&' for GREEN";
        cout << "\n\tPress '@' for RED";
        cout << "\n\tPress '$' for BLUE";
        cout << "\n\tPress '#' for YELLOW";
        SetConsoleTextAttribute(h, 4);
        cout << "\n\n\t" << p1 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        cin >> t1;
        SetConsoleTextAttribute(h, 1);
        cout << "\n\n\t" << p2 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        cin >> t2;
        SetConsoleTextAttribute(h, 2);
        cout << "\n\n\t" << p3 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        cin >> t3;
        t4 = ' ';
        p11 = t1, p12 = t1, p13 = t1, p14 = t1;
        r11 = t2, r12 = t2, r13 = t2, r14 = t2;
        q11 = t3, q12 = t3, q13 = t3, q14 = t3;
        s11 = t4, s12 = t4, s13 = t4, s14 = t4;
        Sleep(1000);
        cout << endl;
        system("CLS");
        cout << "\n";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 1; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "-";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "LUDO BOARD";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 1; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "-";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "\n\n";
        Sleep(1000);
        SetConsoleTextAttribute(h, 4);
        BOARD(arr, left, up, down, right);
        SetConsoleTextAttribute(h, 5);
        THREEPLAyers(arr, left, up, down, right);
    }
    if (members == 4)
    {
        SetConsoleTextAttribute(h, 8);
        cout << "\n\tWELCOME TO PLAY GAME: \n";
        SetConsoleTextAttribute(h, 4);
        cout << "\n\tENTER FIRST PLAYER NAME: ";
        cin >> p1;
        SetConsoleTextAttribute(h, 1);
        cout << "\n\tENTER SECOND PLAYER NAME: ";
        cin >> p2;
        SetConsoleTextAttribute(h, 2);
        cout << "\n\tENTER THIRD PLAYER NAME: ";
        cin >> p3;
        SetConsoleTextAttribute(h, 14);
        cout << "\n\tENTER FOURTH PLAYER NAME: ";
        cin >> p4;
        Sleep(1000);
        system("CLS");
        SetConsoleTextAttribute(h, 7);
        cout << "\n\tPress '&' for GREEN";
        cout << "\n\tPress '@' for RED";
        cout << "\n\tPress '$' for BLUE";
        cout << "\n\tPress '#' for YELLOW";
        SetConsoleTextAttribute(h, 4);
        cout << "\n\n\t" << p1 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        cin >> t1;
        SetConsoleTextAttribute(h, 1);
        cout << "\n\n\t" << p2 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        cin >> t2;
        SetConsoleTextAttribute(h, 3);
        cout << "\n\n\t" << p3 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        SetConsoleTextAttribute(h, 14);
        cin >> t3;
        cout << "\n\n\t" << p4 << "!";
        cout << "\n\tSELECT YOUR FAVOURITE TOKEN: ";
        cin >> t4;
        p11 = t1, p12 = t1, p13 = t1, p14 = t1;
        r11 = t2, r12 = t2, r13 = t2, r14 = t2;
        q11 = t3, q12 = t3, q13 = t3, q14 = t3;
        s11 = t4, s12 = t4, s13 = t4, s14 = t4;
        Sleep(1000);
        cout << endl;
        system("CLS");
        SetConsoleTextAttribute(h, 5);
        cout << "\n";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 1; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "-";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "LUDO BOARD";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 1; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "-";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "\n\n";
        Sleep(1000);
        SetConsoleTextAttribute(h, 4);
        BOARD(arr, left, up, down, right);
        SetConsoleTextAttribute(h, 5);
        FOURPLAyers(arr, left, up, down, right);
    }
}
void BOARD(char arr[], char left[], char up[], char down[], char right[])
{
    fstream fout;
    fout.open("board.txt");
    SetConsoleTextAttribute(h, 5);
    for (int t = 0; t <= 3; t++)
    {
        for (int u = 0; u < 10; u++)
        {
            if (u < 15)
            {
                SetConsoleTextAttribute(h, u);
                Sleep(28);
                cout << "--";
            }
            else
            {
                Sleep(28);
                cout << "-";
            }
        }
    }
    SetConsoleTextAttribute(h, 7);
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";

    fout << "\n\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";

    cout << " | " << arr[11] << " | ";
    cout << " | " << arr[12] << " | ";
    cout << " | " << arr[13] << " | ";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";

    fout << " | " << arr[11] << " | ";
    fout << " | " << arr[12] << " | ";
    fout << " | " << arr[13] << " | ";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";

    cout << " | " << arr[10] << " | ";
    cout << " | " << up[1] << " | ";
    cout << " | " << arr[14] << " | ";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t" << p11 << "\t" << p12 << "\t\t";

    fout << " | " << arr[10] << " | ";
    fout << " | " << up[1] << " | ";
    fout << " | " << arr[14] << " | ";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t" << p11 << "\t" << p12 << "\t\t";

    cout << " | " << arr[9] << " | ";
    cout << " | " << up[2] << " | ";
    cout << " | " << arr[15] << " | ";
    cout << "\t\t" << r11 << "\t" << r12 << "\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t" << p13 << "\t" << p14 << "\t\t";

    fout << " | " << arr[9] << " | ";
    fout << " | " << up[2] << " | ";
    fout << " | " << arr[15] << " | ";
    fout << "\t\t" << r11 << "\t" << r12 << "\t\t";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t" << p13 << "\t" << p14 << "\t\t";

    cout << " | " << arr[8] << " | ";
    cout << " | " << up[3] << " | ";
    cout << " | " << arr[16] << " | ";
    cout << "\t\t" << r13 << "\t" << r14 << "\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";

    fout << " | " << arr[8] << " | ";
    fout << " | " << up[3] << " | ";
    fout << " | " << arr[16] << " | ";
    fout << "\t\t" << r13 << "\t" << r14 << "\t\t";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";

    cout << " | " << arr[7] << " | ";
    cout << " | " << up[4] << " | ";
    cout << " | " << arr[17] << " | ";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";

    fout << " | " << arr[7] << " | ";
    fout << " | " << up[4] << " | ";
    fout << " | " << arr[17] << " | ";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";

    cout << " | " << arr[6] << " | ";
    cout << " | " << up[5] << " | ";
    cout << " | " << arr[18] << " | ";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\n";
    cout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  ";
    cout << "   |        |   ";
    cout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  \n";

    fout << " | " << arr[6] << " | ";
    fout << " | " << up[5] << " | ";
    fout << " | " << arr[18] << " | ";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\n";
    fout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  ";
    fout << "   |        |   ";
    fout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  \n";

    cout << " | " << arr[0] << " | ";
    cout << " | " << arr[1] << " | ";
    cout << " | " << arr[2] << " | ";
    cout << " | " << arr[3] << " | ";
    cout << " | " << arr[4] << " | ";
    cout << " | " << arr[5] << " | ";
    cout << "   |        |   ";

    fout << " | " << arr[0] << " | ";
    fout << " | " << arr[1] << " | ";
    fout << " | " << arr[2] << " | ";
    fout << " | " << arr[3] << " | ";
    fout << " | " << arr[4] << " | ";
    fout << " | " << arr[5] << " | ";
    fout << "   |        |   ";

    cout << " | " << arr[19] << " | ";
    cout << " | " << arr[20] << " | ";
    cout << " | " << arr[21] << " | ";
    cout << " | " << arr[22] << " | ";
    cout << " | " << arr[23] << " | ";
    cout << " | " << arr[24] << " | ";

    fout << " | " << arr[19] << " | ";
    fout << " | " << arr[20] << " | ";
    fout << " | " << arr[21] << " | ";
    fout << " | " << arr[22] << " | ";
    fout << " | " << arr[23] << " | ";
    fout << " | " << arr[24] << " | ";

    cout << "\n";
    cout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  ";

    fout << "\n";
    fout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  ";

    cout << "   | " << left[6] << "    " << up[6] << " |   ";
    cout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << " | " << arr[51] << " | ";

    fout << "   | " << left[6] << "    " << up[6] << " |   ";
    fout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << " | " << arr[51] << " | ";

    cout << " | " << left[1] << " | ";
    cout << " | " << left[2] << " | ";
    cout << " | " << left[3] << " | ";
    cout << " | " << left[4] << " | ";
    cout << " | " << left[5] << " | ";
    cout << "   |--------|   ";

    fout << " | " << left[1] << " | ";
    fout << " | " << left[2] << " | ";
    fout << " | " << left[3] << " | ";
    fout << " | " << left[4] << " | ";
    fout << " | " << left[5] << " | ";
    fout << "   |--------|   ";

    cout << " | " << right[5] << " | ";
    cout << " | " << right[4] << " | ";
    cout << " | " << right[3] << " | ";
    cout << " | " << right[2] << " | ";
    cout << " | " << right[1] << " | ";

    fout << " | " << right[5] << " | ";
    fout << " | " << right[4] << " | ";
    fout << " | " << right[3] << " | ";
    fout << " | " << right[2] << " | ";
    fout << " | " << right[1] << " | ";

    cout << " | " << arr[25] << " | ";
    cout << "\n";
    cout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  ";

    fout << " | " << arr[25] << " | ";
    fout << "\n";
    fout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  ";

    cout << "   | " << down[6] << "    " << right[6] << " |   ";
    cout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  \n";

    fout << "   | " << down[6] << "    " << right[6] << " |   ";
    fout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  \n";

    cout << " | " << arr[50] << " | ";
    cout << " | " << arr[49] << " | ";
    cout << " | " << arr[48] << " | ";
    cout << " | " << arr[47] << " | ";
    cout << " | " << arr[46] << " | ";
    cout << " | " << arr[45] << " | ";
    cout << "   |        |   ";

    fout << " | " << arr[50] << " | ";
    fout << " | " << arr[49] << " | ";
    fout << " | " << arr[48] << " | ";
    fout << " | " << arr[47] << " | ";
    fout << " | " << arr[46] << " | ";
    fout << " | " << arr[45] << " | ";
    fout << "   |        |   ";

    cout << " | " << arr[31] << " | ";
    cout << " | " << arr[30] << " | ";
    cout << " | " << arr[29] << " | ";
    cout << " | " << arr[28] << " | ";
    cout << " | " << arr[27] << " | ";
    cout << " | " << arr[26] << " | ";
    cout << "\n";
    cout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  ";
    cout << "   |        |   ";
    cout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";

    fout << " | " << arr[31] << " | ";
    fout << " | " << arr[30] << " | ";
    fout << " | " << arr[29] << " | ";
    fout << " | " << arr[28] << " | ";
    fout << " | " << arr[27] << " | ";
    fout << " | " << arr[26] << " | ";
    fout << "\n";
    fout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  ";
    fout << "   |        |   ";
    fout << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";

    cout << " | " << arr[44] << " | ";
    cout << " | " << up[5] << " | ";
    cout << " | " << arr[32] << " | ";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";

    fout << " | " << arr[44] << " | ";
    fout << " | " << up[5] << " | ";
    fout << " | " << arr[32] << " | ";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";

    cout << " | " << arr[43] << " | ";
    cout << " | " << up[4] << " | ";
    cout << " | " << arr[33] << " | ";
    cout << endl;
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t" << q11 << "\t" << q12 << "\t\t";

    fout << " | " << arr[43] << " | ";
    fout << " | " << up[4] << " | ";
    fout << " | " << arr[33] << " | ";
    fout << endl;
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t" << q11 << "\t" << q12 << "\t\t";

    cout << " | " << arr[42] << " | ";
    cout << " | " << down[3] << " | ";
    cout << " | " << arr[34] << " | ";
    cout << "\t\t" << s11 << "\t" << s12 << "\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t" << q13 << "\t" << q14 << "\t\t";

    fout << " | " << arr[42] << " | ";
    fout << " | " << down[3] << " | ";
    fout << " | " << arr[34] << " | ";
    fout << "\t\t" << s11 << "\t" << s12 << "\t\t";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t" << q13 << "\t" << q14 << "\t\t";

    cout << " | " << arr[41] << " | ";
    cout << " | " << up[2] << " | ";
    cout << " | " << arr[35] << " | ";
    cout << "\t\t" << s13 << "\t" << s14 << "\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";

    fout << " | " << arr[41] << " | ";
    fout << " | " << up[2] << " | ";
    fout << " | " << arr[35] << " | ";
    fout << "\t\t" << s13 << "\t" << s14 << "\t\t";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";

    cout << " | " << arr[40] << " | ";
    cout << " | " << up[1] << " | ";
    cout << " | " << arr[36] << " | ";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";

    fout << " | " << arr[40] << " | ";
    fout << " | " << up[1] << " | ";
    fout << " | " << arr[36] << " | ";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";

    cout << " | " << arr[39] << " | ";
    cout << " | " << arr[38] << " | ";
    cout << " | " << arr[37] << " | ";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    cout << "\t\t\t\t\t";
    cout << "\n";

    fout << " | " << arr[39] << " | ";
    fout << " | " << arr[38] << " | ";
    fout << " | " << arr[37] << " | ";
    fout << "\n";
    fout << "\t\t\t\t\t";
    fout << "  ---  "
         << "  ---  "
         << "  ---  \n";
    fout << "\t\t\t\t\t";
    fout << "\n";

    SetConsoleTextAttribute(h, 5);
    for (int t = 0; t <= 3; t++)
    {
        for (int u = 0; u < 10; u++)
        {
            if (u < 15)
            {
                SetConsoleTextAttribute(h, u);
                Sleep(28);
                cout << "--";
            }
            else
            {
                Sleep(28);
                cout << "-";
            }
        }
    }
    //	fout.close();
}
void TWOPLAyers(char arr[], char left[], char up[], char down[], char right[])
{
    fstream fout;
    fout.open("score2.txt");
    fout << "\n\t" << p1 << " : " << t1 << " : " << sum1;
    fout << "\n\t" << p2 << " : " << t2 << " : " << sum2;
    fout << "\n";
    char swap;
    int p1counter = 0;
    int p2counter = 0;
    p11 = t1;
    while (1)
    {
        char again = '0';
        SetConsoleTextAttribute(h, 4);
        cout << "\n\t" << p1 << " : " << t1 << " : " << sum1;
        SetConsoleTextAttribute(h, 1);
        cout << "\n\t" << p2 << " : " << t2 << " : " << sum2;
        cout << "\n";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 3; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "--";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "\n";
        p1turn(arr, left);
        p2turn(arr, up);
        if (left[6] == t1)
        {
            c1 = 0;
            p1counter++;
            if (p1counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p1 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p1counter << " tokens is/are in destination.";
            }
        }
        else if (up[6] == t2)
        {
            c2 = 0;
            p2counter++;
            if (p2counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p2 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p2counter << " tokens is/are in destination.";
            }
        }
        Sleep(1000);
        BOARD(arr, left, up, down, right);
        SetConsoleTextAttribute(h, 8);
        cout << "\n\tDO YOU WANT TO:\n";
        SetConsoleTextAttribute(h, 7);
        cout << '\t' << "c : continue\n";
        cout << '\t' << "e : exit"
             << "\n";
        cin >> again;
        if (again == 'e')
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\n\n"
                 << p1 << " : " << t1 << " : " << sum1;
            fout << "\n\n"
                 << p1 << " : " << t1 << " : " << sum1;
            SetConsoleTextAttribute(h, 1);
            cout << "\n\n"
                 << p2 << " : " << t2 << " : " << sum2;
            fout << "\n\n"
                 << p2 << " : " << t2 << " : " << sum2;
            if (sum1 > sum2)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum1;
                cout << " by " << p1;
                fout << "\n\n HIGHEST SCORE : " << sum1;
                fout << " by " << p1;
            }
            else if (sum1 < sum2)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum2;
                cout << " by " << p2;
                fout << "\n\n HIGHEST SCORE : " << sum2;
                fout << " by " << p2;
            }
            else if (sum1 == sum2)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n BOTH PLAYERS HAVE SAME SCORE : " << sum1;
                fout << "\n BOTH PLAYERS HAVE SAME SCORE : " << sum1;
            }
            SetConsoleTextAttribute(h, 7);
            cout << "\nEXITING! YOUR GAME DATA WILL BE LOSS\n\n";
            fout << "\nEXITING! YOUR GAME DATA WILL BE LOSS\n\n";
            break;
        }
        else if (again == 'c')
        {
            continue;
        }
        else
        {
            SetConsoleTextAttribute(h, 7);
            cout << "\nINVALID INPUT!";
        }
    }
    //	fout.close();
}
void THREEPLAyers(char arr[], char left[], char up[], char down[], char right[])
{
    fstream fout;
    fout.open("score3.txt");
    fout << "\n\t" << p1 << " : " << t1;
    fout << "\n\t" << p2 << " : " << t2;
    fout << "\n\t" << p3 << " : " << t3;
    int p1counter = 0;
    int p2counter = 0;
    int p3counter = 0;
    char again = '0';
    while (1)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\n\t" << p1 << " : " << t1;
        SetConsoleTextAttribute(h, 1);
        cout << "\n\t" << p2 << " : " << t2;
        SetConsoleTextAttribute(h, 2);
        cout << "\n\t" << p3 << " : " << t3;
        cout << "\n";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 3; t++)
        {
            for (int u = 0; u < 10; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "--";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "\n";
        p1turn(arr, left);
        p2turn(arr, up);
        p3turn(arr, down);
        if (left[6] == t1)
        {
            c1 = 0;
            p1counter++;
            if (p1counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p1 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p1counter << " tokens is/are in destination.";
            }
        }
        else if (up[6] == t2)
        {
            c2 = 0;
            p2counter++;
            if (p2counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p2 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p2counter << " tokens is/are in destination.";
            }
        }
        else if (down[6] == t3)
        {
            c3 = 0;
            p3counter++;
            if (p3counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p3 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p3counter << " tokens is/are in destination.";
            }
        }
        Sleep(1000);
        BOARD(arr, left, up, down, right);
        SetConsoleTextAttribute(h, 8);
        cout << "\n\tDO YOU WANT TO:\n";
        SetConsoleTextAttribute(h, 7);
        cout << '\t' << "c : continue\n";
        cout << '\t' << "e : exit"
             << "\n";
        // cout << '\t' << "p:pause" << "\n";
        cin >> again;
        if (again == 'e')
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\n\n"
                 << p1 << " : " << t1 << " : " << sum1;
            fout << "\n\n"
                 << p1 << " : " << t1 << " : " << sum1;
            SetConsoleTextAttribute(h, 1);
            cout << "\n\n"
                 << p2 << " : " << t2 << " : " << sum2;
            fout << "\n\n"
                 << p2 << " : " << t2 << " : " << sum2;
            SetConsoleTextAttribute(h, 2);
            cout << "\n\n"
                 << p3 << " : " << t3 << " : " << sum3;
            fout << "\n\n"
                 << p3 << " : " << t3 << " : " << sum3;
            if (sum1 > sum2 && sum1 > sum3)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum1;
                cout << " by " << p1;
                fout << "\n\n HIGHEST SCORE : " << sum1;
                fout << " by " << p1;
            }
            else if (sum2 > sum1 && sum2 > sum3)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum2;
                cout << " by " << p2;
                fout << "\n\n HIGHEST SCORE : " << sum2;
                fout << " by " << p2;
            }
            else if (sum3 > sum1 && sum3 > sum2)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum3;
                cout << " by " << p3;
                fout << "\n\n HIGHEST SCORE : " << sum3;
                fout << " by " << p3;
            }
            else if (sum1 == sum2 == sum3)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n ALL PLAYERS HAVE SAME SCORE : " << sum1;
                fout << "\n ALL PLAYERS HAVE SAME SCORE : " << sum1;
            }
            else if (sum1 == sum3 && sum1 > sum2)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 1 & 3 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 1 & 3 HAVE SAME SCORE : " << sum1;
            }
            else if (sum1 == sum2 && sum1 > sum3)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 1 & 2 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 1 & 2 HAVE SAME SCORE : " << sum1;
            }
            else if (sum2 == sum3 && sum2 > sum1)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 1 & 2 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 1 & 2 HAVE SAME SCORE : " << sum1;
            }
            SetConsoleTextAttribute(h, 7);
            cout << "\n EXITING! YOUR GAME DATA WILL BE LOSS\n\n";
            fout << "\n EXITING! YOUR GAME DATA WILL BE LOSS\n\n";
            break;
        }
        else if (again == 'c')
        {
            continue;
        }
        else
        {
            SetConsoleTextAttribute(h, 7);
            cout << "\nINVALID INPUT!";
        }
    }
    //	fout.close();
}
void FOURPLAyers(char arr[], char left[], char up[], char down[], char right[])
{
    fstream fout;
    fout.open("score4.txt");
    fout << "\n\t" << p1 << " : " << t1;
    fout << "\n\t" << p2 << " : " << t2;
    fout << "\n\t" << p3 << " : " << t3;
    fout << "\n\t" << p4 << " : " << t4;
    fout << "\n";
    int p1counter = 0;
    int p2counter = 0;
    int p3counter = 0;
    int p4counter = 0;
    char again = '0';
    while (1)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\n\t" << p1 << " : " << t1;

        SetConsoleTextAttribute(h, 1);
        cout << "\n\t" << p2 << " : " << t2;

        SetConsoleTextAttribute(h, 2);
        cout << "\n\t" << p3 << " : " << t3;

        SetConsoleTextAttribute(h, 14);
        cout << "\n\t" << p4 << " : " << t4;
        cout << "\n";
        SetConsoleTextAttribute(h, 5);
        for (int t = 0; t <= 3; t++)
        {
            for (int u = 0; u < 20; u++)
            {
                if (u < 15)
                {
                    SetConsoleTextAttribute(h, u);
                    Sleep(28);
                    cout << "--";
                }
                else
                {
                    Sleep(28);
                    cout << "-";
                }
            }
        }
        cout << "\n";
        p1turn(arr, left);
        p2turn(arr, up);
        p3turn(arr, down);
        p4turn(arr, right);
        if (left[6] == t1)
        {
            c1 = 0;
            p1counter++;
            if (p1counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p1 << "! YOU WON........";
                fout << "\n\t" << p1 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p1counter << " tokens is/are in destination.";
            }
        }
        else if (up[6] == t2)
        {
            c2 = 0;
            p2counter++;
            if (p2counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p2 << "! YOU WON........";
                fout << "\n\t" << p2 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p2counter << " tokens is/are in destination.";
            }
        }
        else if (down[6] == t3)
        {
            c3 = 0;
            p3counter++;
            if (p3counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p3 << "! YOU WON........";
                fout << "\n\t" << p3 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p3counter << " tokens is/are in destination.";
            }
        }
        else if (right[6] == t4)
        {
            c4 = 0;
            p4counter++;
            if (p4counter == 4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\t" << p4 << "! YOU WON........";
                fout << "\n\t" << p4 << "! YOU WON........";
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\tYOUR " << p4counter << " tokens is/are in destination.";
            }
        }
        Sleep(1000);
        BOARD(arr, left, up, down, right);
        SetConsoleTextAttribute(h, 8);
        cout << "\n\tDO YOU WANT TO:\n";
        SetConsoleTextAttribute(h, 7);
        cout << '\t' << "c : continue\n";
        cout << '\t' << "e : exit"
             << "\n";

        cin >> again;
        if (again == 'e')
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\n\n"
                 << p1 << " : " << t1 << " : " << sum1;
            fout << "\n\n"
                 << p1 << " : " << t1 << " : " << sum1;
            SetConsoleTextAttribute(h, 1);
            cout << "\n\n"
                 << p2 << " : " << t2 << " : " << sum2;
            fout << "\n\n"
                 << p2 << " : " << t2 << " : " << sum2;
            SetConsoleTextAttribute(h, 2);
            cout << "\n\n"
                 << p3 << " : " << t3 << " : " << sum3;
            fout << "\n\n"
                 << p3 << " : " << t3 << " : " << sum3;
            SetConsoleTextAttribute(h, 14);
            cout << "\n\n"
                 << p4 << " : " << t4 << " : " << sum4;
            fout << "\n\n"
                 << p4 << " : " << t4 << " : " << sum4;
            if (sum1 > sum2 && sum1 > sum3 && sum1 > sum4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum1;
                cout << " by " << p1;

                fout << "\n\n HIGHEST SCORE : " << sum1;
                fout << " by " << p1;
            }
            else if (sum2 > sum1 && sum2 > sum3 && sum2 > sum4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum2;
                cout << " by " << p2;

                fout << "\n\n HIGHEST SCORE : " << sum2;
                fout << " by " << p2;
            }
            else if (sum3 > sum1 && sum3 > sum2 && sum3 > sum4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum3;
                cout << " by " << p3;

                fout << "\n\n HIGHEST SCORE : " << sum3;
                fout << " by " << p3;
            }
            else if (sum4 > sum1 && sum4 > sum2 && sum4 > sum3)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n\n HIGHEST SCORE : " << sum4;
                cout << " by " << p4;

                fout << "\n\n HIGHEST SCORE : " << sum4;
                fout << " by " << p4;
            }
            else if (sum1 == sum2 == sum3 == sum4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\n ALL PLAYERS HAVE SAME SCORE : " << sum1;

                fout << "\n ALL PLAYERS HAVE SAME SCORE : " << sum1;
            }
            else if (sum1 == sum2 && sum1 > sum3 && sum2 > sum4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 1 & 2 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 1 & 2 HAVE SAME SCORE : " << sum1;
            }
            else if (sum1 == sum3 && sum1 > sum4 && sum3 > sum2)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 1 & 3 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 1 & 3 HAVE SAME SCORE : " << sum1;
            }
            else if (sum1 == sum4 && sum1 > sum3 && sum4 > sum2)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 1 & 4 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 1 & 4 HAVE SAME SCORE : " << sum1;
            }
            else if (sum2 == sum3 && sum2 > sum1 && sum3 > sum4)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 2 & 3 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 2 & 3 HAVE SAME SCORE : " << sum1;
            }
            else if (sum2 == sum4 && sum2 > sum3 && sum4 > sum1)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 2 & 4 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 2 & 4 HAVE SAME SCORE : " << sum1;
            }
            else if (sum3 == sum4 && sum3 > sum1 && sum4 > sum2)
            {
                SetConsoleTextAttribute(h, 7);
                cout << "\nPLAYERS 3 & 4 HAVE SAME SCORE : " << sum1;
                fout << "\nPLAYERS 3 & 4 HAVE SAME SCORE : " << sum1;
            }
            SetConsoleTextAttribute(h, 7);
            cout << "\n EXITING! YOUR GAME DATA WILL BE LOSS\n\n";

            fout << "\n EXITING! YOUR GAME DATA WILL BE LOSS\n\n";
            break;
        }
        else if (again == 'c')
        {
            continue;
        }
        else
        {
            SetConsoleTextAttribute(h, 7);
            cout << "\nINVALID INPUT!";
        }
    }
    //	fout.close();
}
void p1turn(char arr[], char left[])
{
    SetConsoleTextAttribute(h, 4);
    char swap1 = '0';
    // int counter = 0;
    int max = 6, min = 1;
    Sleep(1000);
    SetConsoleTextAttribute(h, 4);
    cout << "\n\t" << p1 << "! Its your turn: ";
    cout << "\n\tENTER ANY KEY TO ROLL THE DICE = ";
    cin.get();
    cout << "\n";
    int dice = 0;
    srand(time(0));
    dice = (rand() % (max - min + 1) + min);
    if (dice == 1)
    {
        cout << " -----" << endl;
        cout << "|     |" << endl;
        cout << "|  0  |" << endl;
        cout << "|     |" << endl;
        cout << " -----" << endl;
        sum1 = sum1 + dice;
    }
    else if (dice == 2)
    {
        cout << " -----" << endl;
        cout << "|    O|" << endl;
        cout << "|     |" << endl;
        cout << "|O    |" << endl;
        cout << " -----" << endl;
        sum1 = 2 + sum1;
    }
    else if (dice == 3)
    {
        cout << " -----" << endl;
        cout << "|    O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O    |" << endl;
        cout << " -----" << endl;
        sum1 = dice + sum1;
    }
    else if (dice == 4)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|     |" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        sum1 = sum1 + dice;
    }
    else if (dice == 5)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        sum1 = sum1 + dice;
    }
    else if (dice == 6)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        cout << endl;
        cout << "\n\tCongratulations ! you got 6 the dice will be rolled gaian" << endl;
        p11 = ' ';
        dice = 0;
        dice = ((rand() % 6) + 1);
        cout << "\n\tthis time you get = " << dice;
        sum1 = sum1 + 6 + dice;
        c1++;
        if (c1 > 1)
        {
            i = i + 6;
        }
    }
    if (c1 == 0)
    {
        sum1 = 0;
        cout << "\n\t"
             << "To begin, You must roll a six to move a piece out of the baseand onto the start position.";
        arr[i] = '/';
    }
    else if (c1 != 0)
    {
        if (i > 51)
        {
            i = i - 51;
            Sleep(1000);
            swap1 = left[i]; // swap1 = '/'
            char temp = '0';
            temp = left[i];
            i = i + dice;    // i = 1+5 = 6
            left[i] = t1;    // arr[i] = @
            i = i - dice;    // i = 6-5 = 1
            left[i] = swap1; // arr[i] = '/'
            left[i] = '/';
            if (i == 6)
            {
                cout << "\n\tCONGRATULATIONS!";
            }
            else if (i > 6)
            {
                cout << "\n\tsorry! NEXT TIME.....";
            }
            else if (i < 6)
            {
                i = i + dice;
            }
        }
        else
        {
            char req;
            req = arr[i];
            arr[i] = t1;
            Sleep(1000);
            swap1 = arr[i]; // swap1 = '/'
            char temp = '0';
            temp = arr[i];
            i = i + dice;   // i = 1+5 = 6
            arr[i] = t1;    // arr[i] = @
            i = i - dice;   // i = 6-5 = 1
            arr[i] = swap1; // arr[i] = '/'
            if (temp == arr[i])
            {
                if (i == 1 || i == 9 || i == 14 || i == 22 || i == 27 || i == 35 || i == 40 || i == 48)
                {
                    arr[i] = '/';
                }
                else
                {
                    arr[i] = ' ';
                }
            }
            i = i + dice; // i = 1+5 = 6
        }
    }
    Sleep(1000);
    // system("CLS");
    cout << "\n\t" << p1 << "'s SCORE: " << sum1 << endl;
}
void p2turn(char arr[], char up[])
{
    SetConsoleTextAttribute(h, 1);
    char swap2 = '0';
    SetConsoleTextAttribute(h, 2);
    int max = 6, min = 1;
    Sleep(1000);
    cout << "\n\t" << p2 << "! Its your turn: ";
    cout << "\n\tENTER ANY KEY TO ROLL THE DICE = ";
    cin.get();
    cout << "\n";
    int dice = 0;
    srand(time(0));
    dice = (rand() % (max - min + 1) + min);
    if (dice == 1)
    {
        cout << " -----" << endl;
        cout << "|     |" << endl;
        cout << "|  0  |" << endl;
        cout << "|     |" << endl;
        cout << " -----" << endl;
        sum2 = sum2 + dice;
    }
    else if (dice == 2)
    {
        cout << " -----" << endl;
        cout << "|    O|" << endl;
        cout << "|     |" << endl;
        cout << "|O    |" << endl;
        cout << " -----" << endl;
        sum2 = dice + sum2;
    }
    else if (dice == 3)
    {
        cout << " -----" << endl;
        cout << "|    O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O    |" << endl;
        cout << " -----" << endl;
        sum2 = dice + sum2;
    }
    else if (dice == 4)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|     |" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        sum2 = sum2 + dice;
    }
    else if (dice == 5)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        sum2 = sum2 + dice;
    }
    else if (dice == 6)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        cout << endl;
        cout << "\n\tCongratulations ! you got 6 the dice will be rolled gaian" << endl;
        r11 = ' ';
        dice = 0;
        dice = ((rand() % 6) + 1);
        cout << "\n\tthis time you get" << dice;
        sum2 = sum2 + dice + 6;
        c2++;
        if (c2 > 1)
        {
            j = j + 6;
        }
    }
    if (c2 == 0)
    {
        sum2 = 0;
        cout << "\n\t"
             << "To begin, You must roll a six to move a piece out of the baseand onto the start position.";
    }
    else if (c2 != 0)
    {
        if (j > 51)
        {
            j = j - 51;
            Sleep(1000);
            swap2 = arr[j]; // swap1 = '/'
            char temp = '0';
            temp = arr[j];
            j = j + dice;   // i = 1+5 = 6
            arr[j] = t2;    // arr[i] = @
            j = j - dice;   // i = 6-5 = 1
            arr[j] = swap2; // arr[i] = '/'
            arr[j] = '/';
            if (j > 12)
            {
                j = j - 12;
                Sleep(1000);
                swap2 = up[j]; // swap1 = '/'
                char temp = '0';
                temp = up[j];
                j = j + dice;  // i = 1+5 = 6
                up[j] = t2;    // arr[i] = @
                j = j - dice;  // i = 6-5 = 1
                up[j] = swap2; // arr[i] = '/'
                up[j] = '/';
                j = j + dice;
            }
            if (j == 6)
            {
                cout << "\n\tCONGRATULATIONS!";
            }
            else if (j > 6)
            {
                cout << "\n\tNO WORK!";
                j = j - dice;
                arr[j] = arr[j];
            }
            else if (j < 6)
            {
                j = j + dice;
                j = j + dice;  // i = 1+5 = 6
                up[j] = t2;    // arr[i] = @
                j = j - dice;  // i = 6-5 = 1
                up[j] = swap2; // arr[i] = '/'
                up[j] = '/';
            }
        }
        else
        {
            char req;
            req = arr[j];
            arr[j] = t2;
            Sleep(1000);
            swap2 = arr[j]; // swap2 = '/'
            char temp = '0';
            temp = arr[j];
            j = j + dice; // i = 1+5 = 6
            arr[j] = t2;  // arr[i] = @

            j = j - dice;   // i = 6-5 = 1
            arr[j] = swap2; // arr[i] = '/'
            if (temp == arr[j])
            {
                if (j == 1 || j == 9 || j == 14 || j == 22 || j == 27 || j == 35 || j == 40 || j == 48)
                {
                    arr[j] = '/';
                }
                else
                {
                    arr[j] = ' ';
                }
            }
            j = j + dice; // i = 1+5 = 6
        }
    }
    Sleep(1000);
    // system("CLS");
    cout << "\n\t" << p2 << "'s SCORE: " << sum2 << endl;
}
void p3turn(char arr[], char down[])
{
    SetConsoleTextAttribute(h, 2);
    char swap3 = '0';
    SetConsoleTextAttribute(h, 1);
    int max = 6, min = 1;
    Sleep(1000);
    cout << "\n\t" << p3 << "! Its your turn: ";
    cout << "\n\tENTER ANY KEY TO ROLL THE DICE = ";
    cin.get();
    cout << "\n";
    int dice = 0;
    srand(time(0));
    dice = (rand() % (max - min + 1) + min);
    if (dice == 1)
    {
        cout << " -----" << endl;
        cout << "|     |" << endl;
        cout << "|  0  |" << endl;
        cout << "|     |" << endl;
        cout << " -----" << endl;
        sum3 = sum3 + dice;
    }
    else if (dice == 2)
    {
        cout << " -----" << endl;
        cout << "|    O|" << endl;
        cout << "|     |" << endl;
        cout << "|O    |" << endl;
        cout << " -----" << endl;
        sum3 = dice + sum3;
    }
    else if (dice == 3)
    {
        cout << " -----" << endl;
        cout << "|    O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O    |" << endl;
        cout << " -----" << endl;
        sum3 = dice + sum3;
    }
    else if (dice == 4)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|     |" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        sum3 = sum3 + dice;
    }
    else if (dice == 5)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        sum3 = sum3 + dice;
    }
    else if (dice == 6)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        cout << endl;
        cout << "\n\tCongratulations ! you got 6 the dice will be rolled gaian" << endl;
        q11 = ' ';
        dice = 0;
        dice = ((rand() % 6) + 1);
        cout << "\n\tthis time you get" << dice;
        sum3 = sum3 + dice + 6;
        c3++;
        if (c3 > 1)
        {
            k = k + 6;
        }
    }
    if (c3 == 0)
    {
        sum3 = 0;
        cout << "\n\t"
             << "To begin, You must roll a six to move a piece out of the baseand onto the start position.";
    }
    else if (c3 != 0)
    {
        if (k > 51)
        {
            q11 = ' ';
            k = k - 51;
            Sleep(1000);
            swap3 = arr[k]; // swap1 = '/'
            char temp = '0';
            temp = arr[k];
            k = k + dice;   // i = 1+5 = 6
            arr[k] = t3;    // arr[i] = @
            k = k - dice;   // i = 6-5 = 1
            arr[k] = swap3; // arr[i] = '/'
            arr[k] = '/';
            if (k > 12)
            {
                s11 = ' ';
                l = l - 40;
                Sleep(1000);
                swap3 = down[k]; // swap1 = '/'
                char temp = '0';
                temp = down[k];
                k = k + dice;    // i = 1+5 = 6
                down[k] = t3;    // arr[i] = @
                k = k - dice;    // i = 6-5 = 1
                down[k] = swap3; // arr[i] = '/'
                down[k] = '/';
            }

            if (k == 6)
            {
                cout << "\n\tCONGRATULATIONS!";
            }
            else if (k > 6)
            {
                cout << "\n\tsorry! NEXT TIME.....";
            }
            else if (k < 6)
            {
                k = k + dice;
            }
        }
        else
        {
            char req;
            req = arr[k];
            arr[k] = t3;
            Sleep(1000);
            swap3 = arr[k]; // swap2 = '/'
            char temp = '0';
            temp = arr[k];
            k = k + dice; // i = 1+5 = 6
            arr[k] = t3;  // arr[i] = @

            k = k - dice;   // i = 6-5 = 1
            arr[k] = swap3; // arr[i] = '/'
            if (temp == arr[k])
            {
                if (k == 1 || k == 9 || k == 14 || k == 22 || k == 27 || k == 35 || k == 40 || k == 48)
                {
                    arr[k] = '/';
                }
                else
                {
                    arr[k] = ' ';
                }
            }
            k = k + dice; // i = 1+5 = 6
        }
    }

    Sleep(1000);
    // system("CLS");
    cout << "\n\t" << p3 << "'s SCORE: " << sum3 << endl;
}
void p4turn(char arr[], char right[])
{
    SetConsoleTextAttribute(h, 14);
    char swap4 = '0';
    SetConsoleTextAttribute(h, 14);
    int max = 6, min = 1;
    Sleep(1000);
    cout << "\n\t" << p4 << "! Its your turn: ";
    cout << "\n\tENTER ANY KEY TO ROLL THE DICE = ";
    cin.get();
    cout << "\n";
    int dice = 0;
    srand(time(0));
    dice = (rand() % (max - min + 1) + min);
    if (dice == 1)
    {
        cout << " -----" << endl;
        cout << "|     |" << endl;
        cout << "|  0  |" << endl;
        cout << "|     |" << endl;
        cout << " -----" << endl;
        sum4 = sum4 + dice;
    }
    else if (dice == 2)
    {
        cout << " -----" << endl;
        cout << "|    O|" << endl;
        cout << "|     |" << endl;
        cout << "|O    |" << endl;
        cout << " -----" << endl;
        sum4 = dice + sum4;
    }
    else if (dice == 3)
    {
        cout << " -----" << endl;
        cout << "|    O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O    |" << endl;
        cout << " -----" << endl;
        sum4 = dice + sum4;
    }
    else if (dice == 4)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|     |" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        sum4 = sum4 + dice;
    }
    else if (dice == 5)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|  O  |" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        sum4 = sum4 + dice;
    }
    else if (dice == 6)
    {
        cout << " -----" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << "|O   O|" << endl;
        cout << " -----" << endl;
        cout << endl;
        cout << "\n\tCongratulations ! you got 6 the dice will be rolled gaian" << endl;
        s11 = ' ';
        dice = 0;
        dice = ((rand() % 6) + 1);
        cout << "\n\tthis time you get" << dice;
        sum4 = sum4 + dice + 6;
        c4++;
        if (c4 > 1)
        {
            l = l + 6;
        }
    }
    if (c4 == 0)
    {
        sum4 = 0;
        cout << "\n\t"
             << "To begin, You must roll a six to move a piece out of the baseand onto the start position.";
    }
    else if (c4 != 0)
    {
        if (l > 51)
        {
            l = l - 51;
            Sleep(1000);
            swap4 = arr[l]; // swap1 = '/'
            char temp = '0';
            temp = arr[l];
            l = l + dice;   // i = 1+5 = 6
            arr[l] = t4;    // arr[i] = @
            l = l - dice;   // i = 6-5 = 1
            arr[l] = swap4; // arr[i] = '/'
            arr[l] = '/';
            if (l > 12)
            {
                s11 = ' ';
                l = l - 27;
                Sleep(1000);
                swap4 = right[l]; // swap1 = '/'
                char temp = '0';
                temp = right[l];
                l = l + dice;     // i = 1+5 = 6
                right[l] = t4;    // arr[i] = @
                l = l - dice;     // i = 6-5 = 1
                right[l] = swap4; // arr[i] = '/'
                right[l] = '/';
            }

            if (l == 6)
            {
                cout << "\n\tCONGRATULATIONS!";
            }
            else if (l > 6)
            {
                cout << "\n\tsorry! NEXT TIME.....";
            }
            else if (l < 6)
            {
                l = l + dice;
            }
            if (l == 6)
            {
                cout << "\n\tCONGRATULATIONS!";
            }
            else if (l > 6)
            {
                cout << "\n\tsorry! NEXT TIME.....";
            }
            else if (l < 6)
            {
                l = l + dice;
            }
        }
        else
        {
            char req;
            req = arr[l];
            arr[l] = t4;
            Sleep(1000);
            swap4 = arr[l]; // swap2 = '/'
            char temp = '0';
            temp = arr[l];
            l = l + dice; // i = 1+5 = 6
            arr[l] = t4;  // arr[i] = @

            l = l - dice;   // i = 6-5 = 1
            arr[l] = swap4; // arr[i] = '/'
            if (temp == arr[l])
            {
                if (l == 1 || l == 9 || l == 14 || l == 22 || l == 27 || l == 35 || l == 40 || l == 48)
                {
                    arr[l] = '/';
                }
                else
                {
                    arr[l] = ' ';
                }
            }
            l = l + dice; // i = 1+5 = 6
        }
    }
    Sleep(1000);
    // system("CLS");
    cout << "\n\t" << p4 << "'s SCORE: " << sum4 << endl;
}
int main()
{
    Sleep(2000);
    SetConsoleTextAttribute(h, 9);
    cout << "\n\n\n\t\aL";
    Sleep(300);
    SetConsoleTextAttribute(h, 12);
    Sleep(300);
    cout << "\aU";
    SetConsoleTextAttribute(h, 10);
    Sleep(300);
    cout << "\aD";
    SetConsoleTextAttribute(h, 14);
    Sleep(300);
    cout << "\aO";
    Sleep(300);
    SetConsoleTextAttribute(h, 9);
    Sleep(300);
    cout << "\t\aG";
    SetConsoleTextAttribute(h, 12);
    Sleep(300);
    cout << "\aA";
    SetConsoleTextAttribute(h, 10);
    Sleep(300);
    cout << "\aM";
    SetConsoleTextAttribute(h, 14);
    Sleep(300);
    cout << "\aE\n";
    SetConsoleTextAttribute(h, 7);
    Sleep(2000);
    cout << "\n\tLOADING" << endl
         << "\t\t";
    SetConsoleTextAttribute(h, 12);
    for (int s = 1; s <= 40; s++)
    {
        Sleep(28);
        cout << ".";
    }
    cout << endl
         << "\t\t";
    SetConsoleTextAttribute(h, 9);
    for (int s = 1; s <= 50; s++)
    {
        Sleep(28);
        cout << ".";
    }
    cout << endl
         << "\t\t";
    SetConsoleTextAttribute(h, 1);
    for (int s = 1; s <= 60; s++)
    {
        Sleep(28);
        cout << ".";
    }
    SetConsoleTextAttribute(h, 15);
    Sleep(2000);
    system("CLS");
    // string p1, p2, p3, p4;
    char arr[60];
    char left[25];
    char up[10];
    char down[10];
    char right[25];
    left[6] = ' ';
    up[6] = ' ';
    down[6] = ' ';
    right[6] = ' ';
    arr[11] = ' ';
    arr[12] = ' ';
    arr[13] = ' ';
    arr[10] = ' ';
    up[1] = '/';
    arr[14] = '/';
    arr[9] = '/';
    up[2] = '/';
    arr[15] = ' ';
    arr[8] = ' ';
    up[3] = '/';
    arr[16] = ' ';
    arr[7] = ' ';
    up[4] = '/';
    arr[17] = ' ';
    arr[6] = ' ';
    up[5] = '/';
    arr[18] = ' ';
    arr[0] = ' ';
    arr[1] = '/';
    arr[2] = ' ';
    arr[3] = ' ';
    arr[4] = ' ';
    arr[5] = ' ';
    arr[19] = ' ';
    arr[20] = ' ';
    arr[21] = ' ';
    arr[22] = '/';
    arr[23] = ' ';
    arr[24] = ' ';
    arr[51] = ' ';
    left[1] = '/';
    left[2] = '/';
    left[3] = '/';
    left[4] = '/';
    left[5] = '/';
    right[5] = '/';
    right[4] = '/';
    right[3] = '/';
    right[2] = '/';
    right[1] = '/';
    arr[25] = ' ';
    arr[50] = ' ';
    arr[49] = ' ';
    arr[48] = '/';
    arr[47] = ' ';
    arr[46] = ' ';
    arr[45] = ' ';
    arr[31] = ' ';
    arr[30] = ' ';
    arr[29] = ' ';
    arr[28] = ' ';
    arr[27] = '/';
    arr[26] = ' ';
    arr[44] = ' ';
    down[5] = '/';
    arr[32] = ' ';
    arr[43] = ' ';
    down[4] = '/';
    arr[33] = ' ';
    arr[42] = ' ';
    down[3] = '/';
    arr[34] = ' ';
    arr[41] = ' ';
    down[2] = ' ';
    arr[35] = '/';
    arr[40] = '/';
    down[1] = '/';
    arr[36] = ' ';
    arr[39] = ' ';
    arr[38] = ' ';
    arr[37] = ' ';

    MENU(arr, left, up, down, right);
    SetConsoleTextAttribute(h, 15);
    system("pause");
    return 0;
}