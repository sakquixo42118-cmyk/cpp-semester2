#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
using namespace std;

class Character
{
    public:
    int hp;
    int atk;

    virtual void attack (Character& tar)=0;
    bool isDead ()
    {
        if (hp<=0)
        return 1;
        else
        return 0;
    }
    Character (int a,int b):hp(a),atk (b){};
    int getHp ()
    {
        return hp;
    }
};

class Warrior:public Character
{
    public:
    
    Warrior (int a,int b):Character (a,b){};
    
    void attack (Character& in)
    {
        in.hp-=atk+int(0.1*hp);


    }
};

class Mage :public Character
{
    public:
    Mage (int a,int b):Character (a,b){};
    void attack (Character& in)
    {
        in.hp-=int(atk*1.5);


    }
};

int main() {
    int wh, wa, mh, ma;
    while (cin >> wh >> wa >> mh >> ma) {
        Warrior w(wh, wa);
        Mage m(mh, ma);
        w.attack(m);
        m.attack(w);
        cout << w.getHp() << " " << m.getHp() << " ";
        bool wd = w.isDead();
        bool md = m.isDead();
        if (wd && md)//都死了
            cout << "Both";
        else if (wd)//战士死了
            cout << "Mage";
        else if (md)//法师死了
            cout << "Warrior";
        else//都活着
            cout << "None";
        cout << endl;
    }
    return 0;
}
