#include "stdafx.h"

#include "CoreEngine.h"
#include "TestGame.h"

int main() {
    CoreEngine coreEngine(800, 600, 120, new TestGame());
    coreEngine.createWindow("Test");
    coreEngine.start();
}