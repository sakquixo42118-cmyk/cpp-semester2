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

    GameCharacter(){hp=0;attack=0;}
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
    Monster (){
        hp=0;attack=0;
    }
    bool operator<(Monster in)
    {
    if (attack>in.attack)
    return 0;
    if (attack==in.attack)
    {
        if (hp<in.hp)
        return 0;
        if (hp>in.hp)
        return 1;
        if (hp==in.hp)
        return 0;
    }    //简单的认为攻击力越高且血量越低的单位越需要早点处理
    if (attack<in.attack)
    {return 1;}
     return 0;
}
    
};

class Scuter:public GameCharacter
{
    public:
    
    Scuter(int a,int b){hp=a;attack=b;}
    int leastLossOfHp(Monster* monsters,int num)
    {
        int total=0;
        int round;
        int index;
        for (int i=0;i<num;i++)
        {
            index=i;
            Monster max=monsters[i];
            int j;
         for (j=i;j<num;j++)
         {
          if (!(monsters[j]<max))
           { max=monsters[j];
            index=j;} //养成好习惯，if 要加大括号！！！！！
         }
       
         
         Monster temp=monsters[index];
         monsters[index]=monsters[i];
         monsters[i]=temp;
         
         double floatround=double (temp.hp)/double(attack);
         round=temp.hp/attack;
         if ((floatround-int(temp.hp/attack))!=0)
         round++;
         for (int k=1;k<=round;k++)
         {
          for (int q=i;q<num;q++)
          {
            total+=monsters[q].attack;
          }
         }
        }
        hp=hp-total;
        return total;

    }
};

int main() {
	Monster* monster;
	int attack, hp, num;
	while (cin >> hp >> attack) {
		Scuter scuter(hp, attack);
		cin >> num;
		monster = new Monster[num];
		for (int i = 0; i < num; ++i) {
			cin >> hp >> attack;
			monster[i].setHp(hp);
			monster[i].setAttack(attack);
		}

        cout << scuter.leastLossOfHp(monster, num) << " ";
		if (scuter.isDeath()) {
			cout << "Dead" << endl;
		}
		else {
			cout << "Alive" << endl;
		}
		delete[] monster;
		monster = nullptr;
	}
	return 0;
}