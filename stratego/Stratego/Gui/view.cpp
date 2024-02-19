#include "view.h"
#include "mapreader.h"

using namespace std;
View::View(Game * g, QWidget * parent)
    : QWidget(parent)
    , game{g}
    , window {new QVBoxLayout(this)}
    , hbox {new QHBoxLayout(this)}
    , grid {new QGridLayout(this)}
    , rightSide {new QGridLayout(this)}
    , config {new QHBoxLayout(this)}
    , data_list{}
    , state {new QLabel("Bienvenue",this)}
    , buttons{new QHBoxLayout(this)}
    , start {new QPushButton("Commencer", this)}
    , load {new QPushButton("Charger", this)}
{
    loaded=false;
    take =false;

    from = new Position(-1, -1);
    to = new Position(-1, -1);

    setWindowTitle("Stratego");
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

    load->setDisabled(true);

    buttons->addWidget(start);
    connect(start,SIGNAL(clicked()),this,SLOT(beginStart()));

    buttons->addWidget(load);
    connect(load,SIGNAL(clicked()),this,SLOT(beginLoad()));

    buttons->setSpacing(10);
    config->addWidget(state);
    config->addLayout(buttons);

    initView();
    display();
    show();

}

void View::beginStart(){
    if(game->getState()==MENU){
        game->start();
    }
    else{
        game->reset();
    }
    state->setText("Placé un pion ou appuyer sur le bouton Charger");
}

void View::beginLoad(){
        loaded=true;
        createFileMap();
        display();
        load->setDisabled(true);
        loaded=false;
}
void View::initView()
{
    initRightSide();
    hbox->addLayout(grid);
    hbox->addLayout(rightSide);

    window->addLayout(hbox);
    window->addLayout(config);
    setLayout(window);
}

void View::initRightSide(){
        for(int i =0 ; i<=11;i++){
            QPushButton * mob = new QPushButton(this);
            QString lien{":/pawn/"};
            connect(mob,SIGNAL(clicked()),this,SLOT(spawnSelect()));

            if(i==0||i==1||i==11){
                QString m;
                if(i==0){m="F";}
                if(i==1){m="S";}
                if(i==11){m="B";}
                lien=lien+m;
                mob->setText(m.at(0));
            }
            else{
                lien=lien+QString::number(i);
                mob->setText(QString::number(i));
            }
            mob->setIcon(QIcon(QPixmap(lien)));
            rightSide->addWidget(mob,i,0);
            mob->setContentsMargins(0,0,0,0);
        }
}
void View::display(){
    grid->setGeometry(QRect(0, 0, 500, 500));
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);

    while(!data_list.empty()){
        delete data_list.takeFirst();
    }

    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10; i++){
            Pawn * p;

            if(game->getCase(Position{i, j})->isHole()){
                p = new Pawn(i, j, nullptr,0);

            }else{
                p = new Pawn(i, j, game->getCase(Position{i, j}), 0);
            }
            data_list.append(p);
            p->setContentsMargins(0,0,0,0);
            connect(p, SIGNAL(clicked()), this, SLOT(moveToPut()));

            grid->addWidget(p, j, i);

            p->updateIcon(game->getCurrentPlayer());
        }
    }
}

void View::moveToPut() {
    Pawn * p  = (Pawn *)sender();
    load->setDisabled(true);
    if(!game->isEnd()){
        if(game->getState()==TURN){
            if(from->getX() == -1){
                delete from;

                from = new Position(p->getX(), p->getY());
                grid->itemAtPosition((from->getY()),(from->getX()))
                    ->widget()->setStyleSheet("background-color: blueviolet;border:none;");

            }else if ( to->getX() == -1){
                delete to;
                to = new Position(p->getX(), p->getY());
            }
            if(from->getX() != -1 && to->getX() != -1){
                try{
                    game->moveTo(*from, *to);
                }catch(std::exception &e){
                    state->setText(e.what());
                }
                delete from;
                delete to;
                from = new Position (-1,-1);
                to = new Position (-1,-1);
            }
        }

        if(game->getState()==SPAWN){
                try{
                    to = new Position(p->getX(), p->getY());
                    if(!game->getCase(*to)->isDispo()){
                        throw std::invalid_argument("La case n'est pas disponible");
                    };
                    if(!take){
                        throw std::invalid_argument("Tu n'as pas choisi de role!");
                    }
                    if(roleSpawn->compare("S")==0){
                        game->put("1",*to);
                    }
                    else{
                        game->put(roleSpawn->toStdString(),*to);
                    }

                    delete to;
                    to=new Position(-1,-1);
                    delete roleSpawn;
                    take=false;
                }
                catch(std::exception &e){
                    state->setText(e.what());
                }
        }
    }else{
    }
}
void View::spawnSelect(){
    QPushButton * mob=(QPushButton*)sender();
    if(game->getState()==SPAWN){
        if(mob->text()=="F"){
            roleSpawn=new QString("D");
        }
        else if(mob->text()=="b"){
            roleSpawn=new QString("B");
        }
        else if(mob->text()=="S"){
            roleSpawn=new QString("S");
        }
        else{
            roleSpawn=new QString(mob->text());
        }
        state->setText("Choix du role "+* roleSpawn+" du joueur"+QString::number(game->getCurrentPlayer()));
        take=true;
    }
}


void View::createFileMap(){
    mapReader read{};
    while(!(game->spawnEnd(1)&&game->spawnEnd(2))){
        for(int p = 1; p <= 2; p++){
            read.init(p);

            for (int x=0;x<10 ;x++ ) {
                for (int y=0;y<4 ;y++ ) {
                    game->put(read.getValueOf(x,y),Position(x,y + ((p-1) * 6)));
                }
            }
        }
    }

}


void View::update(std::string m){
    if(game->getState()==TURN){
        loaded=false;
    }
    if(loaded){
        return;
    }
    if(m.compare("Started") == 0)
    {
        load->setDisabled(false);
        start->setText("Réinitialiser");
    }else if(m.compare("Moved") == 0)
    {
        string w;
        if(game->getCurrentPlayer()==2){
            w="Tour au joueur Bleu";
        }
        else{
            w="Tour au joueur Rouge";
        }
        state->setText(QString::fromStdString(w));
        game->turnPlayer();
    }else if(m.compare("End") == 0)
    {
        start->setDisabled(false);
        load->setDisabled(true);
        string w = "Bleu";
        if(game->getCurrentPlayer() == 2){
            w = "Rouge";
        }
        state->setText(QString::fromStdString("Le gagnant est le joueur: "  + w));
        game->reset();
    }
    else if(m.compare("Reset")==0){
        start->setText("Commencer");
        load->setDisabled(true);

    }
    else{
        state->setText(QString::fromStdString(m));
    }
    display();
}

View::~View()
{
    delete from;
    delete to;
    delete grid;
    delete rightSide;
}
