#pragma once

#include "m_vector.h"
#include "MainComponent.h"

#include "OpenGL.h"

#define IM_SCROLL_UP -2
#define IM_SCROLL_DOWN -1

enum KeyAction {
	kaUp,
	kaDown,
	kaLeft,
	kaRight,
	kaFirePrimary,
	kaFireSecondary,
	kaReload,
    kaWeaponSwitchUp,
    kaWeaponSwitchDown,

    // add new above
	KA_SIZE
};

class InputManager {
private:
    // Private Constructor cause only one Instance;
    InputManager(GLFWwindow* w);
    ~InputManager();

	GLFWwindow* window;

	int keyBinds[KA_SIZE];
	bool keyStateOld[KA_SIZE];
	bool keyState[KA_SIZE];

    int scrollData[2];

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    int getScroll(int keyCode);
public:
    static InputManager* getInstance();

    vec2 getMousePos();

	void bindKey(KeyAction keyaction, int keyID);
    void bindDefaults();

	void update();

	bool keyPressed(KeyAction keyaction);
	bool keyReleased(KeyAction keyaction);
	bool keyDown(KeyAction keyaction);
	bool keyUp(KeyAction keyaction);

    int* getScrollData();
};

