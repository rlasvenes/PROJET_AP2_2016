#include "View.h"
#include "Model.h"

#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {

    srand(time(NULL));

    Model model(SCREEN_WIDTH, SCREEN_HEIGHT);



    View view(SCREEN_WIDTH, SCREEN_HEIGHT);

    view.setModel(&model);
    view.setPositionCenter();

    while (view.treatEvents()) {

        view.synchronize();
        view.treatKeyState();

        model.nextStep();

        view.draw();
    }

    return EXIT_SUCCESS;
}
