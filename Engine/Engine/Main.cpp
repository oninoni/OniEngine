#include "stdafx.h"

#include "CoreEngine.h"
#include "TestGame.h"

#include "PerspectiveCamera.h"

#include "LightHandler.h"
#include "DirectionalLight.h"

int main() {
    CoreEngine coreEngine(600, 600, 120, new TestGame()); // NOSCOPE!!!!!!!! (+)
    coreEngine.createWindow("Test");
    coreEngine.start();
}