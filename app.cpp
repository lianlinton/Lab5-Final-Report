/**
 * Tester file to run the myCanvas class
 */

#include <iostream>
#include "myCanvas.cpp"

using namespace std;
int main() {
    MyCanvas myCanvas;

    if (myCanvas.doLogin()) {
        myCanvas.doCourseMenu();
        myCanvas.doMainMenu();
    }

    return 0;
}