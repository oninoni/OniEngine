#include "stdafx.h"

#include "CoreEngine.h"
#include "TestGame.h"

#include "LightHandler.h"
#include "DirectionalLight.h"

int main() {
    CoreEngine coreEngine(600, 600, 3600, new TestGame()); // NOSCOPE!!!!!!!! (+)
    coreEngine.createWindow("Test");
    coreEngine.start();
}