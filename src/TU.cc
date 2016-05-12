#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TU_Runner_rlasvenes

#include <boost/test/unit_test.hpp>
#include "View.h"

BOOST_AUTO_TEST_CASE(test_balle)
{
    Ball * b = new Ball(0, 0, 0, 0, 0, 0);
    MovableElement * me = dynamic_cast<MovableElement *> (b);

    BOOST_CHECK(me != nullptr);

    int value = 42;
    b->setDeltaY(value);
    int res = b->getDeltaY();

    BOOST_CHECK(res == value);

    b->setJump(true);

    BOOST_CHECK(b->isJumping() == true);

    const MovableElement * testCollision = new MovableElement(0, 0, 0, 0); // dimensions identiques à

    bool isColliding = b->treatColision(testCollision);

    BOOST_CHECK(isColliding == true);

    // ======================== GraphicElement =============================================================
    //
    // =====================================================================================================

    sf::Texture img;
    img.loadFromFile(PATH_BALL_IMAGE);

    GraphicElement * ge = new GraphicElement(img, 0, 0, 0, 0);

    BOOST_CHECK(ge != NULL);

}

