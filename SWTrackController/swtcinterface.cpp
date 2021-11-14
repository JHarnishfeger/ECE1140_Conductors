#include "swtcinterface.h"
#include "ui_swtcinterface.h"

SWTCInterface::SWTCInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SWTCInterface)
{
    waysidesMade = 0;
    hwMade = 0;
    selected = 0;
    ui->setupUi(this);
    Block a('g','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block b('g','a',"crossing",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block c('g','a',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block d('g','a',"rail",2.0,true,5.0,25.0,30.0,'e',32.0,0,1.0,true,false,false,false,false); //Occ
    Block e('g','a',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block f('g','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block g('g','b',"crossing",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block h('g','b',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block i('g','b',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block j('g','b',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block k('g','b',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block l('g','b',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,true,false,false,false,false);
    Block m('g','b',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block n('r','c',"rail",2.0,true,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block o('r','c',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block p('r','c',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block q('r','c',"crossing",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block r('r','c',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block s('r','c',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    Block t('r','c',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
    vector<Block> green{a,b,c,d,e,f,g,h,i,j,k,l,m};
    vector<Block> red{n,o,p,q,r,s,t};
    tc.initialize(red,green,0,0,0);
    //fillLists();
}

SWTCInterface::~SWTCInterface()
{
    delete ui;
}

vector<Block> SWTCInterface::getHWTrack()
{
    return hwTrack;
}

void SWTCInterface::on_CreateWaysides_clicked()
{
    if(!waysidesMade&&ui->WaysideNum->value()>0)
    {
        QString title;
        string holder;
        tc.createWaysides(ui->WaysideNum->value());
        //fillLists();
        waysidesMade = 1;
        for(int i=0;i<tc.waysides.size();i++)
        {
            holder = "";
            if(tc.waysides[i].getLine())
                holder += "GREEN ";
            else
                holder += "RED ";
            holder += "LINE - Wayside " + std::to_string(i+1) + ": Blocks " + std::to_string(tc.waysides[i].sector[0].getId()) + " - " + std::to_string(tc.waysides[i].sector[tc.waysides[i].sector.size()-1].getId());
            title = QString::fromStdString(holder);
            ui->WaysideList->addItem(title);
        }
        for(int i=0;i<ui->WaysideNum->value();i++)
        {
            WaysideWin *win = new WaysideWin;
            wui.append(win);
            wui[i]->initialize(tc.waysides[i],i+1);
            wui[i]->show();
        }
    }
}

void SWTCInterface::on_DesignateHWWayside_clicked()
{
    if(!hwMade&&selected!=0)
    {
        hwMade = 1;
        for(int i=0;i<wui.size();i++)
        {
            if(wui[i]->way->getID()==selected)
            {
                for(int j=0;j<wui[i]->way->sector.size();j++)
                {
                    tc.hwTrack.push_back(wui[i]->way->sector[j]);
                    hwTrack.push_back(wui[i]->way->sector[j]);
                }
                wui[i]->close();
            }
        }
    }
}


void SWTCInterface::on_WaysideList_itemClicked(QListWidgetItem *item)
{
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

