#include <iostream>

using namespace std;

#include "MainComponent.h"

int main(int * argc, char ** argv) {
    MainComponent* m = MainComponent::getInstance(argc, argv);
    m->start();
}