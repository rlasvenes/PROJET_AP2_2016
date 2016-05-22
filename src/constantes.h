#ifndef CONSTANTES_H
#define CONSTANTES_H

#endif // CONSTANTES_H

// images jeu
const std::string PATH_BACKGROUND_IMAGE = "../img/city_3.png";
const std::string PATH_FOREGROUND_IMAGE = "../img/city_1.png";
const std::string PATH_BALL_IMAGE = "../img/ball3.png";
const std::string PATH_OBSTACLE_IMAGE = "../img/block.png";

// sons
const std::string PATH_SOUND_TEST = "../sounds/the_run.wav";

// fontes
const std::string PATH_FONT = "../fonts/8_bit_font2.ttf";

// images menu/interface
const std::string PATH_MENU_IMAGE = "../img/Runner2.png";
const std::string PATH_PLAY_BTN_IMAGE = "../img/play_button.png";
const std::string PATH_QUIT_BTN_IMAGE = "../img/quit_button.png";
const std::string PATH_SHOP_BTN_IMAGE = "../img/shop_button.png";
const std::string PATH_SCORE_BTN_IMAGE = "../img/scores_button.png";
const std::string PATH_BACK_BTN_IMAGE = "../img/back_button.png";

// images animés
const std::string PATH_ANIMATED_BALL = "../img/bonus.png";

// paramètres jeu
const int FRAME_LIMIT = 60;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

const int SOL = SCREEN_HEIGHT/1.35;


// defines
#define PI 3.14159265359*1.f
#define Console _model->console
#define BLACK sf::Color(0, 0, 0)
#define GRIS sf::Color(0, 0, 0, 168)

#define MENU 1
#define GAME 2
#define SCORE 3
#define GAME_OVER 4
