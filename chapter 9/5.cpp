#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class GameCharacter
{
    public:
    int attack;
    int hp;

    GameCharacter(int a,int b):attack(a),hp(b){};
    bool isDeath()
    {
        if(hp<=0)
        return 1;
        else
        return 0;
    }
    int getAttack()
    {
        return attack;
    }
    int getHp()
    {
        return hp;
    }
    void setAttack(int a)
    {
        attack=a;
    }
    void setHp(int a)
    {
        hp=a;
    }
};

class Monster:public GameCharacter
{
    public:
    bool operator<(Monster in)
    {
    if (attack>in.attack)
    return 0;
    if (attack==in.attack)
    {
        if (hp<in.hp)
        return 0;
        else
        return 1;
    }
    if (attack<in.attack)
    return 1;
    }
};

class Scuter:public GameCharacter
{
    public:
    int leastLossOfHp(Monster* monsters,int num)
    {
        for (int i=0;i<num;i++)
        {
         Monster max=monsters[i];
            for (int j=i;j<num;j++)
         {
          if (!(monsters[j]<max))
          max=monsters[j];
         }
         Monster temp=max;
         max=monsters[i];
         monsters[i]=temp;
         
        }

    }
};