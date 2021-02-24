#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    int Great=0;
    double temp_m=0;
    cout<<"GAMO.F\nGo to:\nAttack\nMindstorm\nOrganize\n......\nFighting,Player!\n";
    while(true)
    {
        struct Gamo
        {
            struct enemy
            {
                double blood=1,attack=1;
                int number=1,hitrate=3,dead=0;
            }e;
            struct boss
            {
                double blood=3,attack=2;
                int hitrate=2;
            }b;
            struct you
            {
                double blood=3,attack=1;
                int revive=1,level=1;
            }y;
            struct propshop
            {
                string prop;
                struct revivion
                {
                    string name="revivion",sEffect="To add one revive chance                    ";
                    int money=3,iEffect=1;
                }re;
                struct whetonion
                {
                    string name="whetonion",sEffect="To add one attack point                    ";
                    int money=2,iEffect=1;
                }wh;
                struct enhancion
                {
                    string name="enhancion",sEffect="To add two blood                           ";
                    int money=3,iEffect=2;
                }en;
                struct vertigion
                {
                    string name="vertigion",sEffect="To reduce hit rate of the enemies          ";
                    int money=4,iEffect=1;
                }ve;
                int money;
            }p;
            int appeartime,shotrate,rand_blood,rand_level,out=0,count=0;
            double temp_yb=0,temp_eb=0;
            string begin,shoot;
        }G;
        G.e.attack+=Great/2;
        G.e.blood+=Great;
        G.b.attack+=Great/2;
        G.b.blood+=Great;
        srand(static_cast<unsigned int>(time(nullptr)));
        cout<<"This is GAMO.F/1.0.1V\nWanna play?";
        cin>>G.begin;
        if(G.begin=="Of")
        {
            cin>>G.begin;
            if(G.begin=="course!")
            {
                cout<<"You're allowed to play GAMO.S:2.0.0V:"<<endl;
                cout<<"GAMO.S\nGo to:\nAttack\nMindstorm\nOrganize\n......\nShoot him?Sure!\n";
                cout<<"This is GAMO.S:2.0.0V"<<endl;
                cout<<"Wanna play?";
                cin>>G.begin;
                cout<<"Please wait a moment...";
                while(true)
                {
                    for(int i=0;i<4;i++)
                    {
                        usleep(5000000);
                        cout<<"\nSorry,the system has an error.Please try again:";
                        cin>>G.begin;
                        if(G.begin=="break"||G.begin=="Break")
                        {
                            G.out=1;
                            break;
                        }
                        cout<<"Please wait a moment...";
                    }
                    if(G.out==1)
                    {
                        G.out=0;
                        break;
                    }
                    else
                    {
                        cout<<"\n(This will never end.)";
                        for(int i=0;i<100;i++)
                        {
                            cout<<"\nLoading";
                            usleep(1000000);
                            for(int i=0;i<3;i++)
                            {
                                cout<<".";
                                usleep(1000000);
                            }
                        }
                        cout<<"\nIt's really touching!"<<endl;
                        cout<<"Actually......\n'GAMO':'GAME-O'\n'.S':'.Second version'\n\n";
                        break;
                    }
                }
            }
            else
                cout<<"hmm...\n\n";
            continue;
        }
        //Auto fight
        else if(G.begin=="Auto")
        {
            cout<<"Tip:Anything in 'Auto fight' will not be placed in Gamo:Evolution.\n";
            cout<<"How many enemies do you want to fight?";
            cin>>G.e.number;
            if(G.e.number==0)
                return 0;
            else if(G.e.number>0)
            {
                G.rand_blood=rand()%25+1;
                G.rand_level=rand()%(G.e.number*6)+1;
                G.y.level=G.rand_level;
                G.p.money=G.e.number*2+Great;
                G.e.dead=rand()%G.e.number;
                G.y.blood=G.y.level*0.5-G.rand_blood;
            }
        }
        else if(G.begin=="yes"||G.begin=="Yes")
        {
            cout<<"Let's begin!"<<endl;
            cout<<"Your blood:"<<G.y.blood<<"\nYour attack:"<<G.y.attack<<endl;
            cout<<"Your revive chance:"<<G.y.revive<<"\nHow many enemies do you want to fight?";
            cin>>G.e.number;
            if(G.e.number<=0)
            {
                cout<<"hmm..."<<endl;
                continue;
            }
            //Prop Shop
            G.p.money=G.e.number*2+Great/10+temp_m;
            cout<<"Prop Shop\nmoney:$"<<G.p.money<<endl;
            cout<<G.p.re.name<<":"<<G.p.re.sEffect<<"$"<<G.p.re.money<<endl;
            cout<<G.p.wh.name<<":"<<G.p.wh.sEffect<<"$"<<G.p.wh.money<<endl;
            cout<<G.p.en.name<<":"<<G.p.en.sEffect<<"$"<<G.p.en.money<<endl;
            cout<<G.p.ve.name<<":"<<G.p.ve.sEffect<<"$"<<G.p.ve.money<<endl;
            while(G.p.money>=2&&G.out<=2)
            {
                cout<<"Wanna buy any thing?";
                cin>>G.p.prop;
                if(G.p.prop=="check"||G.p.prop=="Check")
                    cout<<"money:$"<<G.p.money<<endl;
                else if(G.p.prop==G.p.re.name)
                {
                    if(G.p.money>=4)
                    {
                        cout<<"Purchased"<<endl;
                        G.p.money-=G.p.re.money;
                        G.y.revive+=G.p.re.iEffect;
                    }
                    else
                        cout<<"Sorry,your money isn't enough."<<endl;
                }
                else if(G.p.prop==G.p.wh.name)
                {
                    if(G.p.money>=2)
                    {
                        cout<<"Purchased"<<endl;
                        G.p.money-=G.p.wh.money;
                        G.y.attack+=G.p.wh.iEffect;
                    }
                    else
                        cout<<"Sorry,your money isn't enough."<<endl;
                }
                else if(G.p.prop==G.p.en.name)
                {
                    if(G.p.money>=3)
                    {
                        cout<<"Purchased"<<endl;
                        G.p.money-=G.p.en.money;
                        G.y.blood+=G.p.en.iEffect;
                    }
                    else
                        cout<<"Sorry,your money isn't enough."<<endl;
                }
                else if(G.p.prop==G.p.ve.name)
                {
                    if(G.p.money>=3)
                    {
                        cout<<"Purchased"<<endl;
                        G.p.money-=G.p.ve.money;
                        G.e.hitrate+=G.p.ve.iEffect;
                    }
                    else if(G.p.money<3)
                        cout<<"Sorry,your money isn't enough."<<endl;
                }
                else if(G.p.prop=="no"||G.p.prop=="No")
                    break;
                else
                {
                    cout<<"hmm..."<<endl;
                    G.out++;
                }
            }
            temp_m=G.p.money;
            G.out=0;
            G.temp_yb=G.y.blood;
            for(int i=1;i<=G.e.number;i++)
            {
                G.b.blood++;
                if(i%2==0)
                    G.e.blood++;
                if(i%3==0)
                {
                    G.e.attack++;
                    G.b.attack++;
                    G.b.hitrate++;
                }
                G.temp_eb=G.e.blood;
                cout<<"Your blood:"<<G.y.blood<<"\nYour attack:"<<G.y.attack<<endl;
                cout<<"Your revive chance:"<<G.y.revive<<endl;
                G.appeartime=rand()%10+1;
                cout<<"Now......";
                usleep(1000000*G.appeartime);
                cout<<"watch out!\nHere's an enemy!"<<endl;
                cout<<"He's blood:"<<G.e.blood<<"\nHe's attack:"<<G.e.attack<<endl;
                while(G.e.blood>0&&(G.y.blood>0||G.y.revive>0))
                {
                    cout<<"Shoot the enemy?";
                    cin>>G.begin;
                    if(G.begin=="yes"||G.begin=="Yes")
                        G.e.blood-=G.y.attack;
                    else if((G.begin=="go"||G.begin=="Go")&&G.count<3)
                    {
                        cout<<"Goodbye,enemy--"<<endl;
                        G.count++;
                        G.out=1;
                        break;
                    }
                    else
                    {
                        G.y.level++;
                        cout<<"Level up!"<<endl;
                        G.y.blood+=0.5;
                    }
                    if(G.e.blood>0)
                    {
                        cout<<"He's going to shoot you!"<<endl;
                        G.shotrate=rand()%G.e.hitrate;
                        if(G.shotrate==G.e.hitrate-1||G.shotrate==G.e.hitrate-2)
                        {
                            G.y.blood-=G.e.attack;
                            cout<<"You're shot."<<endl;
                        }
                        else
                            cout<<"He missed."<<endl;
                    }
                    if(G.y.blood<=0)
                    {
                        cout<<"You're dead."<<endl;
                        if(G.y.revive>0)
                        {
                            cout<<"Revive?";
                            cin>>G.begin;
                            if(G.begin=="Yes"||G.begin=="yes")
                            {
                                cout<<"Keep play!";
                                G.y.blood=G.temp_yb;
                                G.y.revive--;
                            }
                            else
                            {
                                cout<<"GAME OVER"<<endl;
                                G.out=2;
                                break;
                            }
                        }
                    }
                }
                if(G.e.blood<=0)
                {
                    cout<<"Enemy was dead."<<endl;
                    G.e.blood=G.temp_eb;
                    G.e.dead++;
                }
                if(i==G.e.number)
                {
                    cout<<"Your blood:"<<G.y.blood<<"\nYour attack:"<<G.y.attack<<endl;
                    cout<<"Your revive chance:"<<G.y.revive<<endl;
                    G.appeartime=rand()%10+1;
                    cout<<"Now......";
                    usleep(1000000*G.appeartime);
                    cout<<"oops!"<<endl;
                    cout<<"BOSS WARNING"<<endl;
                    cout<<"He's blood:"<<G.b.blood<<"\nHe's attack:"<<G.b.attack<<endl;
                    while(G.b.blood>0&&(G.y.blood>0||G.y.revive>0))
                    {
                        cout<<"Shoot the boss?";
                        cin>>G.begin;
                        if(G.begin=="yes"||G.begin=="Yes")
                            G.b.blood-=G.y.attack;
                        else if(G.begin=="go"||G.begin=="Go")
                        {
                            cout<<"Goodbye,boss--"<<endl;
                            G.out=1;
                            break;
                        }
                        else
                        {
                            G.y.level++;
                            cout<<"Level up!"<<endl;
                            G.y.blood+=0.5;
                        }
                        if(G.b.blood>0)
                        {
                            cout<<"He's going to shoot you!"<<endl;
                            G.shotrate=rand()%G.b.hitrate;
                            if(G.shotrate==G.b.hitrate-1||G.shotrate==G.b.hitrate-2)
                            {
                                G.y.blood-=G.b.attack;
                                cout<<"You're shot."<<endl;
                            }
                            else
                                cout<<"He missed."<<endl;
                        }
                        else if(G.b.blood<=0)
                        {
                            cout<<"Boss was dead."<<endl;
                            G.e.dead++;
                        }
                        if(G.y.blood<=0)
                        {
                            cout<<"You're dead."<<endl;
                            if(G.y.revive>0)
                            {
                                cout<<"Revive?";
                                cin>>G.begin;
                                if(G.begin=="Yes"||G.begin=="yes")
                                {
                                    cout<<"Keep play!";
                                    G.y.blood=G.temp_yb;
                                    G.y.revive--;
                                }
                                else
                                {
                                    cout<<"GAME OVER"<<endl;
                                    G.out=2;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(G.out==1)
                    continue;
                else if(G.out==2)
                    break;
                if(G.y.blood<=0&&G.y.revive<0)
                {
                    cout<<"GAME OVER"<<endl;
                    break;
                }
            }
        }
        else if(G.begin=="no"||G.begin=="No")
        {
            cout<<"All right.\n";
            break;
        }
        else
        {
            cout<<"hmm...\n";
            continue;
        }
        if(G.y.blood>0&&G.e.dead==G.e.number+1)
        {
            cout<<"WIN!"<<endl;
            Great+=G.e.number;
        }
        if(G.y.blood>0&&G.e.dead==G.e.number+1&&(double)G.y.level-1/(G.e.number+1)>=2.5&&G.count<2)
        {
            cout<<"SUPER!!"<<endl;
            Great+=G.e.number*2;
        }
        if(G.y.blood>0&&G.e.dead==G.e.number+1&&(double)G.y.level-1/(G.e.number+1)>=4.5&&G.count<1)
        {
            cout<<"UNBELIEVABLE!!!"<<endl;
            Great+=G.e.number*3;
        }
        cout<<"Level:"<<G.y.level<<endl;
        if(G.y.blood>0)
            cout<<"Blood:"<<G.y.blood<<endl;
        else
            cout<<"Blood:0"<<endl;
        cout<<"Enemies killed:"<<G.e.dead<<"/"<<G.e.number+1<<"\n\n";
    }
    cout<<"Actually......\n'GAMO':'GAME-O'\n'.F':'.First version'\n";
    return 0;
}
