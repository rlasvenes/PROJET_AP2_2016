#include "View.h"
#include "Model.h"

#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {

    srand(time(NULL));

    Model model(SCREEN_WIDTH, SCREEN_HEIGHT);

    View viewMenu(SCREEN_WIDTH, SCREEN_HEIGHT, 2);

    viewMenu.setModel(&model);
    viewMenu.setPositionCenter();

    while (viewMenu.treatEvents()) {

        viewMenu.synchronize();
        viewMenu.treatKeyState();

        switch (viewMenu.getStateMode()) {

        case 1:
            model.nextStep();
            break;

        case 2:
            break;

        default:
            break;
        }

        viewMenu.draw();
    }

    return EXIT_SUCCESS;
}
