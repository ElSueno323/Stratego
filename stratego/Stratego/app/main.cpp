#include <iostream>
#include "ROLE.h"
#include "board.h"
#include "view.h"
#include "controler.h"
#include <algorithm>
#include "mapreader.h"
#include <fstream>
#include <iostream>

using namespace std;



int main()
{
    Game * g {new Game{}};
    View * v {new View{g}};
    Controler cnn {g, v};

    cnn.loop();

    return 0;
}
