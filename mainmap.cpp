#include "mainmap.h"

#define MouseClick(x1,y1,x2,y2) (mouse->x()>=(x1) && mouse->x()<=(x2) &&mouse->y()>=(y1) && mouse->y()<=(y2))

#define Distance(X1,Y1,X2,Y2) sqrt(((X1)-(X2))*((X1)-(X2))+((Y1)-(Y2))*((Y1)-(Y2)))

Mainmap::Mainmap(int hardlevel)
{

    for (int i=1;i<=4;i++){
        OptionboxList.push_back(new Optionbox(i));
    }
    this->setFixedSize(1200,700);
    QTimer *timer1=new QTimer(this);
    timer1->start(1500);


    player->setMedia(QUrl("qrc:/pic/music1.mp3"));
    player->setVolume(30);
    player->play();


    WinLabel->move(QPoint(350,250));
    WinLabel->setStyleSheet("color:yellow");
    WinLabel->setFont(QFont("Calibri",50));
    WinLabel->setText("Victory!");
    WinLabel->hide();



    MoneyLabel->move(QPoint(100,100));
    MoneyLabel->setStyleSheet("color:white");
    MoneyLabel->setFont(QFont("Calibri",24));
    MoneyLabel->setText(QString("Money:   ")+QString::number(Money));


    QLabel *LifeLabel =new QLabel(this);
    LifeLabel->move(QPoint(700,100));
    LifeLabel->setStyleSheet("color:white");
    LifeLabel->setFont(QFont("Calibri",24));
    LifeLabel->setText(QString("Life:%1").arg(Life));




    connect(timer1,&QTimer::timeout,[=](){
        SetMonsterWave(hardlevel);



    });
    QTimer *timer2=new QTimer(this);
    timer2->start(100);
    connect(timer2,&QTimer::timeout,[=]()
{
        /*for(auto tower: TowerList){
            if(!tower->GetAimMonster())
                for (auto mons=MonsterList.end();mons!=MonsterList.begin();mons--)//(*mons)
                    if((*mons)->IfShow==true){
                        tower->SetAimMonster(*mons);
                    break;}




            else
                if (Distance(tower->GetX(),tower->GetY(),tower->GetAimMonster()->GetX(),tower->GetAimMonster()->GetY())<=tower->GetRange() )
                    tower->AddBullet();
                if(Distance(tower->GetX(),tower->GetY(),tower->GetAimMonster()->GetX(),tower->GetAimMonster()->GetY())>tower->GetRange())
                    tower->SetAimMonster(NULL);
            }*/

        //qDebug("1");
        for(auto monster = MonsterList.begin();monster!=MonsterList.end();monster++){
            (*monster) ->Monster_move();
            if((*monster)->GetX()==1100 &&(*monster)->CanMove==true )
            {
                Life--;
                LifeLabel->setText(QString("Life:%1").arg(Life));
                if(Life<=0){LifeLabel->hide();      WinLabel->setText("GAME OVER!");WinLabel->show();player->stop();}
            }
        }

        /*
        //qDebug("2");
        for(auto tower : TowerList){
            tower->BulletMove();
            auto &TempBullet=tower->GetBulletList();
            switch (tower->GetKind()) {
            case 1:
                for(auto bullet=TempBullet.begin();bullet!=TempBullet.end();bullet++){

                        for (auto monster: MonsterList){
                            if (monster->IfShow==true && ((*bullet)->GetX()>=monster->GetX() && (*bullet)->GetX()<=(monster->GetX()+monster->GetWidth()) && (*bullet)->GetY()>=monster->GetY() && (*bullet)->GetY()<=(monster->GetY()+monster->GetHeight())))
                                monster->SetLife(monster->GetLife()-(*bullet)->GetDamage());
                            if(monster->GetLife()<=0){
                                monster->CanMove=false;
                                monster->IfShow=false;}
                                break;

                        delete *bullet;
                        TempBullet.erase(bullet);}
                }

                break;
            case 2:
                for(auto bullet=TempBullet.begin();bullet!=TempBullet.end();bullet++){

                        for (auto monster: MonsterList){
                            if (monster->IfShow==true && ((*bullet)->GetX()>=monster->GetX() && (*bullet)->GetX()<=(monster->GetX()+monster->GetWidth()) && (*bullet)->GetY()>=monster->GetY() && (*bullet)->GetY()<=(monster->GetY()+monster->GetHeight())))
                                monster->SetLife(monster->GetLife()-(*bullet)->GetDamage());
                            if(monster->GetLife()<=0){
                                monster->CanMove=false;
                                monster->IfShow=false;}
                                break;
                                }
                        for (auto monster: MonsterList){
                            if(monster->IfShow==true && Distance((*bullet)->GetX(),(*bullet)->GetY(),monster->GetX(),monster->GetY())<=50)
                            {monster->SetLife(monster->GetLife()-(*bullet)->GetDamage());
                                if(monster->GetLife()<=0){
                                    monster->CanMove=false;
                                    monster->IfShow=false;}}
                            delete *bullet;
                            TempBullet.erase(bullet);}
                }
                break;
            case 3:
                for(auto bullet=TempBullet.begin();bullet!=TempBullet.end();bullet++){
                    for (auto monster: MonsterList){

                            if (monster->IfShow==true && ((*bullet)->GetX()>=monster->GetX() && (*bullet)->GetX()<=(monster->GetX()+monster->GetWidth()) && (*bullet)->GetY()>=monster->GetY() && (*bullet)->GetY()<=(monster->GetY()+monster->GetHeight())))
                                monster->SetLife(monster->GetLife()-(*bullet)->GetDamage());
                            if(monster->GetLife()<=0){
                                monster->CanMove=false;
                                monster->IfShow=false;}
                                break;

                        if(Distance((*bullet)->GetX(),(*bullet)->GetY(),tower->GetX()+40,tower->GetY())>tower->GetRange()*2){

                            delete *bullet;
                            TempBullet.erase(bullet);}
                }
                break;
            }
            //qDebug("3");
            for (auto monster=MonsterList.begin();monster!=MonsterList.end();monster++){
                if (tower->GetAimMonster()== (*monster) && (*monster)->IfShow==false){
                    tower->SetAimMonster(NULL);
                    return;}

            }
        }
        }
        //qDebug("4");*/
        for(auto tower:TowerList){
            for (auto monster: MonsterList){

                if (Distance(monster->GetX(),monster->GetY(),tower->GetX(),tower->GetY())<=tower->GetRange()){
                    monster->SetLife(monster->GetLife()-tower->GetDamage());
                    if(monster->GetLife()<=0 && monster->IfShow==true){monster->IfShow=false;
                        monster->CanMove=false;
                        Money+=10;
                        MoneyLabel->setText(QString("Money:")+QString::number(Money));}


                }

            }






        }



        update();
    });
}

bool Mainmap::CanSpend(int money){
    if (this->Money>=money){
        this->Money-=money;
        MoneyLabel->setText(QString("Money:")+QString::number(Money));
        return true;
    }
    else
        return false;
}

void Mainmap::DrawTowerbase(QPainter &painter){
    for (int i=1;i<=4;i++){
    painter.drawPixmap(Towerbase(i).GetX(),Towerbase(i).GetY(),Towerbase(i).GetWidth(),Towerbase(i).GetHeight(),Towerbase(i).GetImage());
    }
}



void Mainmap::DrawSelectBox(QPainter &painter,int index){
    painter.drawPixmap(Optionbox(index).GetX1(),Optionbox(index).GetY1(),100,100,Optionbox(index).GetBoxImage());
    painter.drawPixmap(Optionbox(index).GetX2(),Optionbox(index).GetY2(),100,100,Optionbox(index).GetBoxImage());
    painter.drawPixmap(Optionbox(index).GetX3(),Optionbox(index).GetY3(),100,100,Optionbox(index).GetBoxImage());
    painter.drawPixmap(Optionbox(index).GetX4(),Optionbox(index).GetY4(),100,100,Optionbox(index).GetBoxImage());
    painter.drawPixmap(Optionbox(index).GetX5(),Optionbox(index).GetY5(),100,100,Optionbox(index).GetBoxImage());
    painter.drawPixmap(Optionbox(index).GetX1()+2,Optionbox(index).GetY1()+2,96,96,Optionbox(index).GetImage1());
    painter.drawPixmap(Optionbox(index).GetX2()+2,Optionbox(index).GetY2()+2,96,96,Optionbox(index).GetImage2());
    painter.drawPixmap(Optionbox(index).GetX3()+2,Optionbox(index).GetY3()+2,96,96,Optionbox(index).GetImage3());
    painter.drawPixmap(Optionbox(index).GetX4()+2,Optionbox(index).GetY4()+2,96,96,Optionbox(index).GetImage4());
    painter.drawPixmap(Optionbox(index).GetX5()+2,Optionbox(index).GetY5()+2,96,96,Optionbox(index).GetImage5());
}

void Mainmap::DrawMonster(QPainter &painter){
    for (auto monster : MonsterList){
        if (monster->IfShow==true)

        painter.drawPixmap(monster ->GetX(),monster ->GetY(),monster ->GetWidth(),monster->GetHeight(),monster->GetImage());

    }

    update();
}

void Mainmap::DrawTower(QPainter &painter){
    for (auto tower = TowerList.begin();tower!=TowerList.end();tower++){
        if((*tower)->IfShow==true){
        painter.drawPixmap((*tower)->GetX(),(*tower)->GetY(),(*tower)->GetWidth(),(*tower)->GetHeight(),(*tower)->GetImage());
        painter.drawEllipse(QPoint((*tower)->GetX()+40,(*tower)->GetY()+60),(*tower)->GetRange(),(*tower)->GetRange());}
        /*for(auto bullet:(*tower)->GetBulletList()){

            painter.drawPixmap(bullet->GetX(),bullet->GetY(),bullet->GetWidth(),bullet->GetHeight(),bullet->GetImage());
        }*/
    }
}


void Mainmap::paintEvent(QPaintEvent *){
    QPainter painter(this);

    QPixmap background(":/pic/background.png");
    painter.setPen(Qt::green);
    painter.drawPixmap(0,0,this->width(),this->height(),background);
    DrawTowerbase(painter);
    DrawTower(painter);
    DrawMonster(painter);

    for (int i=0;i<4;i++){
        if(OptionboxList[i]->IfShow==true){DrawSelectBox(painter,i+1);}
    }

}

void Mainmap::mousePressEvent(QMouseEvent *mouse){
    if (mouse->button() != Qt::LeftButton)
        return;

    for (int i=1;i<=4;i++){
        if (MouseClick(Towerbase(i).GetX(),Towerbase(i).GetY(),Towerbase(i).GetX()+Towerbase(i).GetWidth(),Towerbase(i).GetY()+Towerbase(i).GetHeight()))
            OptionboxList[i-1]->SetIfShow(true);
        if (OptionboxList[i-1]->IfShow==true ){
            if(MouseClick(OptionboxList[i-1]->GetX1(),OptionboxList[i-1]->GetY1(),OptionboxList[i-1]->GetX1()+100,OptionboxList[i-1]->GetY1()+100) && CanSpend(Normtower(Towerbase(i).GetX()+10,Towerbase(i).GetY()-20).GetPrice())){
                TowerList.push_back(new Normtower(Towerbase(i).GetX()+10,Towerbase(i).GetY()-20));
                OptionboxList[i-1]->IfShow=false;
            }
            if(MouseClick(OptionboxList[i-1]->GetX2(),OptionboxList[i-1]->GetY2(),OptionboxList[i-1]->GetX2()+100,OptionboxList[i-1]->GetY2()+100) && CanSpend(Firetower(Towerbase(i).GetX()+10,Towerbase(i).GetY()-20).GetPrice())){
                TowerList.push_back(new Firetower(Towerbase(i).GetX()+10,Towerbase(i).GetY()-20));
                OptionboxList[i-1]->IfShow=false;
            }
            if(MouseClick(OptionboxList[i-1]->GetX3(),OptionboxList[i-1]->GetY3(),OptionboxList[i-1]->GetX3()+100,OptionboxList[i-1]->GetY3()+100) && CanSpend(Blacktower(Towerbase(i).GetX()+10,Towerbase(i).GetY()-20).GetPrice())){
                TowerList.push_back(new Blacktower(Towerbase(i).GetX()+10,Towerbase(i).GetY()-20));
                OptionboxList[i-1]->IfShow=false;
            }
            if(MouseClick(OptionboxList[i-1]->GetX4(),OptionboxList[i-1]->GetY4(),OptionboxList[i-1]->GetX4()+100,OptionboxList[i-1]->GetY4()+100) && CanSpend(50))
            {for (auto tower :TowerList){
                    if (tower->GetX()==Towerbase(i).GetX()+10 && tower->GetY()==Towerbase(i).GetY()-20){
                    tower->Upgrade();
                    OptionboxList[i-1]->IfShow=false;}
                }}
            if(MouseClick(OptionboxList[i-1]->GetX5(),OptionboxList[i-1]->GetY5(),OptionboxList[i-1]->GetX5()+100,OptionboxList[i-1]->GetY5()+100) )
            {for (auto tower :TowerList){
                    if (tower->GetX()==Towerbase(i).GetX()+10 && tower->GetY()==Towerbase(i).GetY()-20){
                    tower->IfShow=false;tower->SetDamage(0);
                    OptionboxList[i-1]->IfShow=false;}
                }}
            update();

        }

    }

}

void Mainmap::SetMonsterWave(int hardlevel){
    switch(hardlevel) {
    case 1:
        if (Monster_number>=0 && Monster_number<=5)
            MonsterList.push_back(new Monster(1,Monster_path,2));
        if (Monster_number>5 && Monster_number<=7){
            MonsterList.push_back(new Monster(2,Monster_path,2));
            MonsterList.push_back(new Monster(1,Monster_path,2));}
        if (Monster_number>7 && Monster_number<=8){
            MonsterList.push_back(new Monster(3,Monster_path,2));
            MonsterList.push_back(new Monster(1,Monster_path,2));}
        if (Monster_number>8 && Monster_number<=9){
            MonsterList.push_back(new Monster(3,Monster_path,2));
            }
        if (Monster_number>9 && Monster_number<=12){
            MonsterList.push_back(new Monster(3,Monster_path,2));
            MonsterList.push_back(new Monster(1,Monster_path,2));
            }


        if (Monster_number>13 && Monster_number<=20){
            MonsterList.push_back(new Monster(3,Monster_path,2));
            MonsterList.push_back(new Monster(1,Monster_path,2));
            }
        if (Monster_number>40){WinLabel->show();return;}

        Monster_number++;


        break;
      case 2:
        if (Monster_number>=0 && Monster_number<=10)
            MonsterList.push_back(new Monster(1,Monster_path,2));
        if (Monster_number>10 && Monster_number<=20){
            MonsterList.push_back(new Monster(2,Monster_path,2));
            MonsterList.push_back(new Monster(3,Monster_path,2));}
        if (Monster_number>21 && Monster_number<=25){
            MonsterList.push_back(new Monster(3,Monster_path,2));
            MonsterList.push_back(new Monster(3,Monster_path,2));}
        if (Monster_number>25 && Monster_number<=30){
            MonsterList.push_back(new Monster(3,Monster_path,2));
            }
        if (Monster_number>31 && Monster_number<=35){
            MonsterList.push_back(new Monster(3,Monster_path,2));
            MonsterList.push_back(new Monster(1,Monster_path,2));
            }


        if (Monster_number>13 && Monster_number<=20){
            MonsterList.push_back(new Monster(3,Monster_path,2));
            MonsterList.push_back(new Monster(1,Monster_path,2));
            }
        if (Monster_number>40){WinLabel->show();player->stop();return;}

        Monster_number++;
        break;



    default:
        break;
    }

}
Mainmap::~Mainmap(){
    for (auto it = MonsterList.begin(); it != MonsterList.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
    for (auto it = TowerList.begin(); it != TowerList.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
    for (auto it = OptionboxList.begin(); it != OptionboxList.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
}
