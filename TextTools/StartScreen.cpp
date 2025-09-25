#include "StartScreen.h"



void StartScreen::hideCursor() { //copied from MyGraph
    //This will hide the cursor every time gotoxy function is called
    CONSOLE_CURSOR_INFO CURSOR{};
    BOOL result;
    CURSOR.dwSize = 1;
    CURSOR.bVisible = FALSE;
    result = SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURSOR);
}


void StartScreen::displayScreen() {
	//console setup moved from MyGraph
    hideCursor(); //hide console cursor

    //Kevin: programmatically set console font size to 12 (even if it was 16 before)
    //see https://stackoverflow.com/questions/35382432/how-to-change-the-console-font-size
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 12;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_BOLD;// FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    //Kevin : end console window/font tricks

    //Kevin: changed the console title
    SetConsoleTitleA("Animated Search Example"); //Absalom: changed console title

    //Kevin: now I maximize window to full size
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);//set the window to max size so the entire graph can be seen

    //starting cordinates
    int x = 5;
    int y = 5;

     /*  ...     .....     .....   .....   ......
        .   .    .    .   .        .    .  .     
        .....    .....    .        .    .  ....
        .   .    .    .   .        .    .  .
        .   .    .....     .....   .....   ......*/ //text art is broken so I'm doing a simipler design manually
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //set color yellow
    gotoxy(x, y);
    cout << " " << char(219) << char(219) << char(219) << "     " << char(219) << char(219) << char(219) << char(219) << char(219) << "     "
        << char(219) << char(219) << char(219) << char(219) << char(219) << "  " << char(219) << char(219) << char(219) << char(219) << char(219) << "    "
        << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
    gotoxy(x, y + 1);
    cout << char(219) << "   " << char(219) << "    " << char(219) << "    " << char(219) << "   " << char(219) << "       " << char(219) << "    " << char(219) << "   " << char(219);
    gotoxy(x, y + 2);
    cout << char(219) << char(219) << char(219) << char(219) << char(219) << "    " << char(219) << char(219) << char(219) << char(219) << char(219) << "    "
        << char(219) << "       " << char(219) << "    " << char(219) << "   " << char(219) << char(219) << char(219) << char(219);
    gotoxy(x, y + 3);
    cout << char(219) << "   " << char(219) << "    " << char(219) << "    " << char(219) << "   " << char(219) << "       " << char(219) << "    " << char(219) << 
        "   " << char(219);
    gotoxy(x, y + 4);
    cout << char(219) << "   " << char(219) << "    " << char(219) << char(219) << char(219) << char(219) << char(219) << "     "
        << char(219) << char(219) << char(219) << char(219) << char(219) << "  " << char(219) << char(219) << char(219) << char(219) << char(219) << "    "
        << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);

    gotoxy(x - 1, y + 5);
    for (int i = 0; i < 43; i++) { //loop to create underline
        cout << char(196);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //set color white

    //instructions
    gotoxy(x, y + 6);
    cout << "This demonstration shows how BFS or DFS search works in a five node (A-E) graph.";
    gotoxy(x, y + 7);
    cout << "The connections are set in an adjacency matrix inside the code, which is also displayed.";
    gotoxy(x, y + 8);
    
    //select mode
    cout << "To see BFS, type B and press enter. To see DFS, type D and press enter. ";
    char mode;
    cin >> mode;
    gotoxy(x, y + 9);
    if (mode == 'B' || mode == 'b') {
        displayBFS = true;
        cout << "Mode set to BFS.";
    }
    else if (mode == 'D' || mode == 'd') {
        displayBFS = false;
        cout << "Mode set to DFS.";
    }
    else {
        cout << "Invalid input. Defaulting to BFS.";
        displayBFS = true;
    }

    //select starting node
    gotoxy(x, y + 10);
    cout << "Please select a starting node by inputing a letter A-E and then pressing enter. ";
    char start;
    cin >> start;

    gotoxy(x, y + 11);
    if (start == 'A' || start == 'a' || start == '0') { //numbers refer to the internal numbers used for the nodes, in case someone uses them
        startingNode = 0;
        cout << "Starting node set to A.";
    }
    else if (start == 'B' || start == 'b' || start == '1') {
        startingNode = 1;
        cout << "Starting node set to B.";
    }
    else if (start == 'C' || start == 'c' || start == '2') {
        startingNode = 2;
        cout << "Starting node set to C.";
    }
    else if (start == 'D' || start == 'd' || start == '3') {
        startingNode = 3;
        cout << "Starting node set to D.";
    }
    else if (start == 'E' || start == 'e' || start == '4') {
        startingNode = 4;
        cout << "Starting node set to E.";
    }
    else {
        cout << "Invalid input. Defaulting to A.";
    }
    
    //wait for user input to begin
    gotoxy(x, y + 12);
    cout << "To begin the demonstration, type any character and press enter. ";
    char p;
    cin >> p;
}
    