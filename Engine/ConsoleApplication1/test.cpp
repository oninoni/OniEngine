#include <iostream>

using namespace std;

#include "MainComponent.h"
#include "RecourceLoader.h"

int main(int * argc, char ** argv) {

    MainComponent* m = new MainComponent(argc, argv);
    m->start();
}