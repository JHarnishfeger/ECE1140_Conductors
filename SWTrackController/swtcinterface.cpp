#include "swtcinterface.h"
#include "ui_swtcinterface.h"

SWTCInterface::SWTCInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SWTCInterface){
    waysidesMade = 0;
    hwMade = 0;
    selected = 0;
    ui->setupUi(this);
    vector<int> nb(0,0);
    Block a("g","a","RAIL","","bc",nb,1,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block b("g","a","SWITCH","","bc",nb,2,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block c("g","a","RAIL","","bc",nb,3,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,1,0,0,0);
    Block d("g","a","CROSSING","","bc",nb,4,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block e("g","a","RAIL","","bc",nb,5,45,45,-1,-1,45,50,30,1,1,0,1,0,0,0,0,0,0,0,0,0);
    Block f("g","a","SWITCH","","bc",nb,6,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block g("g","a","RAIL","","bc",nb,7,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,1,0,0,0);
    Block h("g","a","CROSSING","","bc",nb,8,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block i("g","a","RAIL","","bc",nb,9,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block j("g","a","SWITCH","","bc",nb,10,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block k("g","a","RAIL","","bc",nb,11,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block l("r","a","CROSSING","","bc",nb,12,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block m("r","a","RAIL","","bc",nb,13,45,45,-1,-1,45,50,30,1,1,0,1,0,0,0,0,0,0,0,0,0);
    Block n("r","a","RAIL","","bc",nb,14,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,1,0,0,0);
    Block o("r","a","SWITCH","","bc",nb,15,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block p("r","a","RAIL","","bc",nb,16,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block q("r","a","CROSSING","","bc",nb,17,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block r("r","a","SWITCH","","bc",nb,18,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,1,0,0,0);
    Block s("r","a","RAIL","","bc",nb,19,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);
    Block t("r","a","RAIL","","bc",nb,20,45,45,-1,-1,45,50,30,1,1,0,0,0,0,0,0,0,0,0,0,0);

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

void SWTCInterface::updateFromTrack(vector<Block*> red, vector<Block*> green){
    emit updateWaysidesFromTrack(red,green);
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
            holder += "LINE - Wayside " + std::to_string(i+1) + ": Blocks " + std::to_string(tc.waysides[i].sector[0].getBlockNumber()) + " - " + std::to_string(tc.waysides[i].sector[tc.waysides[i].sector.size()-1].getBlockNumber());
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
        for(int i=0;i<wui.size();i++)
        {
            QObject::connect(this,SIGNAL(updateWaysidesFromTrack(vector<Block*>, vector<Block*>)),wui[i],SLOT(updateFromTrack(vector<Block*>, vector<Block*>)));
        }
    }
}

void SWTCInterface::on_DesignateHWWayside_clicked(){
    if(!hwMade&&selected!=0){
        hwMade = 1;
        for(int i=0;i<wui.size();i++){
            if(wui[i]->way->getBlockNumber()==selected){
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

