#include <iostream>
#include <Windows.h>
#include "TextArt.h"
#include "TextDraw.h"
#include "Coordinates.h"
using namespace std;

class StartScreen : public Coordinates {
public:
	void displayScreen();
	bool displayBFS;
	int startingNode;
private:
	void hideCursor();

};