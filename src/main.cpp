#include "View.h"
#include "Model.h"

#include <iostream>

#define JEU 1
#define MENU 2
#define GAME_OVER 3
#define SCORE 4

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {

    srand(time(NULL));

    Model model(SCREEN_WIDTH, SCREEN_HEIGHT);

    View view(SCREEN_WIDTH, SCREEN_HEIGHT, MENU);

    view.setModel(&model);
    view.setPositionCenter();

    while (view.treatEvents()) {

        view.synchronize();
        view.treatKeyState();

        switch (view.getStateMode()) {

        case JEU:
            model.nextStep();
            break;

        case MENU:
            break;

        default:
            break;
        }

        view.draw();
    }

    return EXIT_SUCCESS;
}
