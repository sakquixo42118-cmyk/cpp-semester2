#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>  
#include <vector>
using namespace std;

class Athlete
{
    public:
    string athleteName;
    string team;
    
    Athlete(string a,string b):athleteName(a),team(b){};
   
    
};

class SportsEventbase
{
    public:
    string eventName;
    string location;
    string time;

    virtual void displayEventDetails ()=0;
    //vector<Athlete> Athletes //没有声明？？？
    SportsEventbase (string a,string b,string c):eventName(a),location(b),time(c){};
};




class TrackAndFieldEvent:public SportsEventbase
{
 public:
    string trackEventItem;
   string worldRecord;
   vector<Athlete> Athletes;
  TrackAndFieldEvent (string a,string b,string c,string d,string e):SportsEventbase(a,b,c),trackEventItem(d),worldRecord(e){};
void addAthlete (Athlete a)
{
    Athletes.push_back(a);
}
 void displayEventDetails ()
 {
    cout<<"Track and Field Event Details:"<<endl;
    cout<<"Event Name: "<<eventName<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Time: "<<time<<endl;
    cout<<"Event Item: "<<trackEventItem<<endl;
    cout<<"World Record: "<<worldRecord<<endl;
    cout<<"Athletes:"<<endl;
    for (Athlete outtt:Athletes)
    {
        cout<<"-Name: "<<outtt.athleteName<<", Team: "<<outtt.team<<endl;
    }

 }


};

class BallGameEvent:public SportsEventbase
{
   public:
    int teamCount;
   string rules;
    vector<Athlete> Athletes;
   BallGameEvent (string a,string b,string c,int d,string e):SportsEventbase(a,b,c),teamCount(d),rules(e){};
   void addAthlete (Athlete a)
{
    Athletes.push_back(a);
}
 void displayEventDetails ()
 {
    cout<<"Ball Game Event Details:"<<endl;
    cout<<"Event Name: "<<eventName<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Time: "<<time<<endl;
    cout<<"Team Count: "<<teamCount<<endl;
    cout<<"Rules: "<<rules<<endl;
    cout<<"Athletes:"<<endl;
    for (Athlete outtt:Athletes)
    {
        cout<<"-Name: "<<outtt.athleteName<<", Team: "<<outtt.team<<endl;
    }

 }

};

int main() {

    string eventName;// 赛事类型名称

    string location; // 地点

    string time;// 时间

    string trackEventItem;// 具体项目

    string worldRecord;// 世界记录

    int teamCount;//队伍数量

    string rules;//比赛规则

    string athleteName;//运动员名称

    string team;//队伍名称

 

    // 创建田径赛事对象并添加运动员

    cin >> eventName >> location >> time >> trackEventItem >> worldRecord;

    TrackAndFieldEvent trackEvent(eventName, location, time, trackEventItem, worldRecord);

    cin >> athleteName >> team;

    trackEvent.addAthlete(Athlete(athleteName, team));

    cin >> athleteName >> team;

    trackEvent.addAthlete(Athlete(athleteName, team));

    

    // 创建球类赛事对象并添加运动员

    cin >> eventName >> location >> time >> teamCount >> rules;

    BallGameEvent basketballEvent(eventName, location, time, teamCount, rules);

    cin >> athleteName >> team;

    basketballEvent.addAthlete(Athlete(athleteName, team));

    cin >> athleteName >> team;

    basketballEvent.addAthlete(Athlete(athleteName, team));




    // 展示田径赛事详细信息

    trackEvent.displayEventDetails();

    cout << endl;

    // 展示球类赛事详细信息

    basketballEvent.displayEventDetails();

    return 0;

}