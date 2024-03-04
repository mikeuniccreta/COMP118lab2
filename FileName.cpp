/** \fileName.cpp
*   \ brief Draw horizontal , vertical ,random shapes
*    \details program can draw shapes with all condition 
*   \ author Michail Kapetanakis
*   \version 1.2
*   \date 2024
*   \copyright University of Nicosia
*/
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() to seed rand()
using namespace std;

// Function prototypes
void printmenu();
void drawHorizontalLine(int length, char ch);
void drawVerticalLine(int height, char ch);
void drawSquare(int size, char ch);
void drawRectangle(int height, int length, char ch);
void drawRandomShape(int shapety[], int shapelen[], char shapeCh[], int arrsize);

int main()
{
    const int max_array = 10; // Maximum array for shapes
    int shape_ty[max_array] = { 0 };
    int shape_len[max_array] = { 0 };
    char shape_ch[max_array]; // Changed from int to char for character array
    int userChoice;

    printmenu(); // Display the menu to the user
    cout << "Please enter your selection: ";
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
    {
        int length;
        char ch;
        cout << "Enter the length: ";
        cin >> length;
        cout << "Enter the character to draw with: ";
        cin >> ch;
        drawHorizontalLine(length, ch);
        break;
    }
    case 2:
    {
        int height;
        char ch;
        cout << "Enter the height: ";
        cin >> height;
        cout << "Enter the character to draw with: ";
        cin >> ch;
        drawVerticalLine(height, ch);
        break;
    }
    case 3:
    {
        int size;
        char ch;
        cout << "Enter the size: ";
        cin >> size;
        cout << "Enter the character to draw with: ";
        cin >> ch;
        drawSquare(size, ch);
        break;
    }
    case 4:
    {
        int height, width;
        char ch;
        cout << "Enter the height: ";
        cin >> height;
        cout << "Enter the width: ";
        cin >> width;
        cout << "Enter the character to draw with: ";
        cin >> ch;
        drawRectangle(height, width, ch);
        break;
    }
    case 5:
        cout << "Quitting program...\n";
        break;
    case 6:
        drawRandomShape(shape_ty, shape_len, shape_ch, max_array);
        break;
    default:
        cout << "Invalid choice! Exiting program...\n";
        break;
    }

    return 0;
}

/**
* Define a number (given as a parameter) of shapes, which
* are then stored in the three arrays passed in.
* <BR>
* @param shapety Array which define which shape to draw
* @param shapelen Array which define the length of the shape
* @param shapeCh Array which defines the symbol used to print the shape
* @param arrsize the size of the arrays
*/
void drawRandomShape(int shapety[], int shapelen[], char shapeCh[], int arrsize)
{
    srand(time(0)); // Seed the random number generator with current time

    for (int i = 0; i < arrsize; ++i)
    {
        shapety[i] = rand() % 4 + 1; // Random shape type (1 to 4)
        shapelen[i] = rand() % (10 - 3 + 1) + 3; // Random length (3 to 10)
        shapeCh[i] = rand() % ('`' - '!') + '!'; // Random character ('!' to '`')

        switch (shapety[i])
        {
        case 1:
            drawHorizontalLine(shapelen[i], shapeCh[i]);
            break;
        case 2:
            drawVerticalLine(shapelen[i], shapeCh[i]);
            break;
        case 3:
            drawSquare(shapelen[i], shapeCh[i]);
            break;
        case 4:
            drawRectangle(shapelen[i], shapelen[i] * 2, shapeCh[i]); // Assuming length represents the height of the rectangle
            break;
        default:
            cout << "Invalid shape type!\n";
            break;
        }
    }
}

void printmenu()
{
    cout << "Hello World, this is a menu!" << endl;
    cout << "1) Draw a horizontal line" << endl;
    cout << "2) Draw a vertical line" << endl;
    cout << "3) Draw a square" << endl;
    cout << "4) Draw a rectangle" << endl;
    cout << "5) Quit" << endl;
    cout << "6) Draw random shapes  " << endl;
}

void drawHorizontalLine(int length, char ch)
{
    for (int i = 0; i < length; ++i)
    {
        cout << ch;
    }
    cout << endl;
}

void drawVerticalLine(int height, char ch)
{
    for (int i = 0; i < height; ++i)
    {
        cout << ch << endl;
    }
}

void drawSquare(int size, char ch)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << ch;
        }
        cout << endl;
    }
}

void drawRectangle(int height, int length, char ch)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            cout << ch;
        }
        cout << endl;
    }
}
