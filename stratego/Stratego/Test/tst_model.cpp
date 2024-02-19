#include <catch2/catch.hpp>
#include "position.h"
#include "board.h"
TEST_CASE ("TEST Board set", "[]")
{

    Board b {};

    SECTION("LIST SET")
    {
        REQUIRE(b.getP1l().size() == 40);
        REQUIRE(b.getP2l().size() == 40);
    }

    SECTION("HOLE SET")
    {
        REQUIRE(b.getCase(Position{2, 4})->isHole());
        REQUIRE(b.getCase(Position{3, 4})->isHole());

        REQUIRE(b.getCase(Position{2, 5})->isHole());
        REQUIRE(b.getCase(Position{3, 5})->isHole());

        REQUIRE(b.getCase(Position{6, 4})->isHole());
        REQUIRE(b.getCase(Position{7, 4})->isHole());


        REQUIRE(b.getCase(Position{6, 5})->isHole());
        REQUIRE(b.getCase(Position{7, 5})->isHole());
    }

    SECTION("PUT")
    {
        Entity e{MARSHAL, 1};
        REQUIRE(b.put(&e, Position{0, 0}) == 0);
        REQUIRE(b.put(&e, Position{0, 0}) == 2);
    }

    SECTION("DESTROY")
    {
        b.destroy(Position{0, 0}, 1);

        REQUIRE(b.getCase(Position{0, 0})->isAvailable() == true);
        REQUIRE(b.getCase(Position{0, 0})->isAvailable() == true);
        //REQUIRE(b.getP1l().size() == 39);

        Board b {};
        Entity e {DRAPEAU, 1};
        b.put(&e, Position {0,0});

        b.destroy(Position {0,0}, 1);

        REQUIRE(b.isEnd() == true);
    }

    SECTION ("MOVE")
    {
        Entity e {SCOUT, 1};
        b.put(&e, Position{0,0});
        REQUIRE_THROWS_AS(b.move(Position{-1,-1}, Position{0,0}, 1), std::invalid_argument);

        REQUIRE_THROWS_AS(b.move(Position{2,4}, Position{0,0}, 1), std::invalid_argument);

        REQUIRE_THROWS_AS(b.move(Position{0,0}, Position{1,0}, 2), std::invalid_argument);
    }


}





TEST_CASE("TEST neigbooh position", "[position] [neighboor]") // titre + tag
{

    Position pos {5,5};
    REQUIRE(pos.neighboor(Position{4, 5}) == true);
    REQUIRE(pos.neighboor(Position{6, 5}) == true);
    REQUIRE(pos.neighboor(Position{5, 4}) == true);
    REQUIRE(pos.neighboor(Position{5, 6}) == true);

    REQUIRE(pos.neighboor(Position{4, 4}) == false);
    REQUIRE(pos.neighboor(Position{6, 6}) == false);
    REQUIRE(pos.neighboor(Position{4, 6}) == false);
    REQUIRE(pos.neighboor(Position{6, 4}) == false);
}

TEST_CASE("Test entity operator==","[entity][operator]")
{

}
