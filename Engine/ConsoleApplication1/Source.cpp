#include "CoreEngine.h"
#include "TestGame.h"
#include "InputManager.h"

int main() {
    CoreEngine coreEngine(800, 600, 120, new TestGame());
    coreEngine.createWindow("Test");
    coreEngine.start();
}