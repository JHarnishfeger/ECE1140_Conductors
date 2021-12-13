#include "swtcinterface.h"
#include "ui_swtcinterface.h"

SWTCInterface::SWTCInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SWTCInterface){
    waysidesMade = 0;
    hwMade = 0;
    selected = 0;
    ui->setupUi(this);
    Block a(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block b(10,"g","a","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block c(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block d(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block e(10,"g","b","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block f(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,1,1,1,1,0,0,0);
    Block g(10,"g","b","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block h(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block i(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block j(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block k(10,"g","c","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block l(10,"g","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block m(10,"g","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block n(10,"r","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block o(10,"r","d","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block p(10,"r","e","rail","north","bc",10.0,0,0,1,5,50,45,45,0,1,1,1,1,0,0,0);
    Block q(10,"r","e","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block r(10,"r","e","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block s(10,"r","f","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block t(10,"r","f","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);

    vector<Block*> green{&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m};
    vector<Block*> red{&n,&o,&p,&q,&r,&s,&t};
    //ui->CreateWaysides->setEnabled(0);
    tc.initialize(red,green,1);
    //fillLists();
}

SWTCInterface::~SWTCInterface(){
    delete ui;
}

void SWTCInterface::setTrack(vector<Block*> rl,vector<Block*> gl){
    ui->CreateWaysides->setEnabled(1);
    tc.initialize(rl,gl,!ui->autoMode->isChecked());
}

void SWTCInterface::getHWWaystruct(WayStruct* hwWaystr){
    emit waysidesSet(tc.wayPtr,hwWaystr);
}

vector<Block> SWTCInterface::getHWTrack(){
    return hwTrack;
}

void SWTCInterface::update(){
    for(int i=0;i<wui.size();i++)
        wui[i]->update();
}

void SWTCInterface::on_CreateWaysides_clicked(){
    if(!waysidesMade&&ui->WaysideNum->value()>0){
        QString title;
        string holder;
        tc.createWaysides(ui->WaysideNum->value());
        //fillLists();
        waysidesMade = 1;
        for(int i=0;i<tc.waysides.size();i++){
            holder = "";
            if(tc.waysides[i].getLine())
                holder += "GREEN ";
            else
                holder += "RED ";
            holder += "LINE - Wayside " + std::to_string(i+1) + ": Blocks " + std::to_string(tc.waysides[i].sector[0].getId()) + " - " + std::to_string(tc.waysides[i].sector[tc.waysides[i].sector.size()-1].getId());
            title = QString::fromStdString(holder);
            ui->WaysideList->addItem(title);
        }
        for(int i=0;i<ui->WaysideNum->value();i++){
            WaysideWin *win = new WaysideWin;
            wui.append(win);
            tc.waysides[i].setID(i+1);
            wui[i]->initialize(tc.waysides[i],i+1);
            wui[i]->show();
        }
        tc.updateWaysides();
    }
}

void SWTCInterface::on_DesignateHWWayside_clicked(){
    if(!hwMade&&selected!=0){
        hwMade = 1;
        for(int i=0;i<wui.size();i++){
            if(wui[i]->way->getID()==selected){
                for(int j=0;j<wui[i]->way->sector.size();j++){
                    tc.hwTrack.push_back(wui[i]->way->sector[j]);
                    hwTrack.push_back(wui[i]->way->sector[j]);
                    tc.hwWay = i;
                }
                wui[i]->close();
            }
        }
        std::cout << "Set Wayside " << tc.hwWay+1 << " as hardware controlled wayside!" << std::endl;
        //vector<WayStruct> swWayPtr;
        tc.wayPtr->clear();
        for(int i=0;i<tc.waysides.size();i++){
            if(i!=tc.hwWay){
                tc.wayPtr->push_back(tc.waysides[i].wayStr);
            }
        }
        //tc.wayPtr = &swWayPtr;
        WayStruct hWay = tc.waysides[tc.hwWay].wayStr;
        //CTC ctcMod(tc.wayPtr,&hWay);
        emit hwSet(hwTrack);
    }
}


void SWTCInterface::on_WaysideList_itemClicked(QListWidgetItem *item){
    QString qs = item->text();
    string word;
    stringstream str(qs.toStdString());
    str >> word;
    str >> word;
    str >> word;
    str >> word;
    str >> word;
    word.pop_back();
    selected = std::stoi(word);
}


void SWTCInterface::on_autoMode_stateChanged(int arg1){
    //std::cout << arg1 << std::endl;
    if(arg1==0)
        tc.setMode(1);
    else
        tc.setMode(0);
    tc.updateWaysides();
}

