#include "View.h"
#include "Model.h"

#include <iostream>

/*

  Notes à moi-même: se renseigner sur FMOD pour faire une analyse spectrale du son pour faire un changement de couleur en fonction des "pics"

  Faire un mode de jeu avec une seul vie, si perd => vie = 0, erase savegame

  faire un double tap (init timer, si timer != 0 alors double tap = true, si double tap et que reste appuyé, faire chargé balle

 */



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
