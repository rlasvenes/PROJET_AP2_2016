#include "View.h"
#include "Model.h"

#include <iostream>

#define JEU 1
#define MENU 2
#define GAME_OVER 3
#define SCORE 4

/*

  Notes à moi-même: se renseigner sur FMOD pour faire une analyse spectrale du son pour faire un changement de couleur en fonction des "pics"

 */

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

        model.nextStep();

        view.draw();
    }

    return EXIT_SUCCESS;
}
