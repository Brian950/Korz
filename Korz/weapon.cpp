#include "weapon.h"

Weapon::Weapon()
{
    id = 0;
    name = "Weapon";
    damage = 10;
    fire_rate = 10;
}

Weapon::Weapon(int i, QString n, int d, double fr)
{
    id = i;
    name = n;
    damage = d;
    fire_rate = fr;
}

int Weapon::get_id() const
{
    return id;
}

QString Weapon::get_name() const
{
    return name;
}

bool Weapon::compare_weapons(Weapon *b){
    if(b = this){
        return true;
    }
    else
        return false;
}

void Weapon::set_name(QString name){
    this->name = name;
}

int Weapon::get_damage() const
{
    return damage;
}

void Weapon::set_damage(int dam){
    damage = dam;
}

double Weapon::get_fire_rate() const
{
    return fire_rate;
}

void Weapon::set_fire_rate(int fr){
    fire_rate = fr;
}

void Weapon::fire()
{
    if(ready_to_fire == true){
        ready_to_fire = false;
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(set_ready()));
        timer->start(fire_rate*1000);
    }
}

void Weapon::set_ready(){
    ready_to_fire = true;
}

bool Weapon::can_fire(){
    return ready_to_fire;
}

Weapon::~Weapon(){}
