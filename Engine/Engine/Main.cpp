#include "stdafx.h"

#include "CoreEngine.h"
#include "TestGame.h"

int main() {
    CoreEngine coreEngine(800, 600, 360, new TestGame()); // NOSCOPE!!!!!!!! (+)
    coreEngine.createWindow("Test");
    coreEngine.start();
}