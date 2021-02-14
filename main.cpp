#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    struct enemy
    {
        double blood=1,attack=1;
        int number,hitrate=3;
    }e;
    struct boss
    {
        double blood=3,attack=2;
        int hitrate=2;
    }b;
    struct you
    {
        double blood=3,attack=1;
        int revive=1;
    }y;
    int level=1,wait_ap,wait_sh,dead_e=0;
    double temp_yb=0,temp_eb=0,temp_m=0;
    bool cheat1,cheat2,cheat3,cheat4;
    //No cheating
    cheat1=0;
    cheat2=0;
    cheat3=0;
    cheat4=0;
    string begin,shoot;
    int v1=0,v2=8,v3=6;
    bool debug=0;
    //V0:Debug version
    cout<<"GAMO.F\nGo to:\nAttack\nMindstorm\nOrganize\n......\nFight,Player!\n";
    cout<<"This is GAMO.F/"<<v1<<"."<<v2<<"."<<v3<<"V"<<endl;
    cout<<"Wanna play?";
    cin>>begin;
    if(begin=="0")
        return 0;
    if(begin=="debug")
    {
        debug=1;
        cout<<"vertion:";
        cin>>v1>>v2>>v3;
        if(v1==0&&v2==0&&v3==0)
            return 0;
        cout<<"GAMO.F\nGo to:\nAttack\nMindstorm\nOrganize\n......\nFight,Player!\n";
        cout<<"This is GAMO.F/"<<v1<<"."<<v2<<"."<<v3<<"V"<<endl;
        cout<<"Wanna play?";
        cin>>begin;
    }
    if(begin=="cheated")
    {
        cin>>cheat1;
        cin>>cheat2;
        cin>>cheat3;
        cin>>cheat4;
        if(cheat1==1||cheat2==1||cheat4==1)
            cheat3=0;
        begin="yes";
    }
    //Auto fight
    if(begin=="Auto")
    {
        e.number=rand()%50+1;
        int rand_blood=rand()%25+1;
        int rand_level=rand()%e.number+1;
        level=rand_level;
        cout<<"WIN!"<<endl;
        if((double)level/e.number>=2.5)
            cout<<"SUPER!!"<<endl;
        if((double)level/e.number>=4.5)
            cout<<"UNBELIEVABLE!!!"<<endl;
        cout<<"Level:"<<level<<endl;
        cout<<"Blood:"<<rand_blood<<endl;
        cout<<"Enemies killed:"<<e.number<<"/"<<e.number<<endl;
        cout<<"Enemy's doomer"<<endl;
        cout<<"Businessman"<<endl;
        if(y.blood>temp_yb*2)
            cout<<"Good chef"<<endl;
    }
    if(begin=="yes"||begin=="Yes")
    {
        cout<<"Let's begin!"<<endl;
        cout<<"Check rules?";
        cin>>begin;
        if(begin=="Yes"||begin=="yes")
        {
            //Rules
            cout<<"Rules:"<<endl;
            cout<<"You have to fight enemies in this game.The enemies shoot you and try to ";
            cout<<"kill you.When your blood is'0',you're dead.Game over.So,you have to kill ";
            cout<<"the enemies."<<endl;
            cout<<"Prop Shop"<<endl;
            cout<<"Buy props to strengthen yourself.That takes your money.So,you have to make ";
            cout<<"choices carefully."<<endl;
            cout<<"Fight"<<endl;
            cout<<"You can choose how many enemies you have to face.Of course,not together.";
            cout<<"After a period of time of waiting,an enemy appears.You can choose to shoot ";
            cout<<"him or not.If you do,he will hurt or die.If you don't,your level will go up";
            cout<<" with blood increasing,and that might help you to gain some achievements.";
            cout<<"Then,it's his turn.He might miss,or not.When you're dead,you can revive ";
            cout<<"once,unless you have used some props.Finally,you will face a boss."<<endl;
            cout<<"Achievements"<<endl;
            cout<<"'Enemy doomer':Killed all of the enemies."<<endl;
            cout<<"'Businessman':Didn't spend any money but won."<<endl;
            cout<<"'Good chef':Have more blood than twice of the initial blood at the end of ";
            cout<<"the game."<<endl;
            cout<<"At Last"<<endl;
            cout<<"This game is just for fun.If this game can't satisfy you,in a near future,";
            cout<<"there might be a better game which is programmed by you."<<endl;
            cout<<"Game begin:"<<endl;
        }
        else if(begin=="0")
            return 0;
        cout<<"Your blood:"<<y.blood<<endl;
        cout<<"Your attack:"<<y.attack<<endl;
        cout<<"Your revive chance:"<<y.revive<<endl;
        cout<<"How many enemies do you want to fight?";
        cin>>e.number;
        if(e.number==0)
            return 0;
        //Prop Shop
        int money=e.number*2,out=0,vcount=0;
        temp_m=money;
        string prop;
        cout<<"Prop Shop\nmoney:$"<<money<<endl;
        cout<<"revivion:To add one revive chance                    $4"<<endl;
        cout<<"whetonion:To add one attack point                    $2"<<endl;
        cout<<"enhancion:To add two blood                           $3"<<endl;
        cout<<"vertigion:reduce hit rate of the enemies             $3"<<endl;
        if(cheat2==0)
        {
            while(money>=2&&out<=2)
            {
                cout<<"Wanna buy any thing?";
                cin>>prop;
                if(prop=="revivion")
                {
                    if(money>=4)
                    {
                        cout<<"Purchased"<<endl;
                        money-=4;
                        y.revive++;
                    }
                    else
                        cout<<"Sorry,your money isn't enough."<<endl;
                }
                else if(prop=="whetonion")
                {
                    if(money>=2)
                    {
                        cout<<"Purchased"<<endl;
                        money-=2;
                        y.attack++;
                    }
                    else
                        cout<<"Sorry,your money isn't enough."<<endl;
                }
                else if(prop=="enhancion")
                {
                    if(money>=3)
                    {
                        cout<<"Purchased"<<endl;
                        money-=3;
                        y.blood+=2;
                    }
                    else
                        cout<<"Sorry,your money isn't enough."<<endl;
                }
                else if(prop=="vertigion")
                {
                    if(money>=3&&vcount<1)
                    {
                        cout<<"Purchased"<<endl;
                        money-=3;
                        e.hitrate--;
                        vcount++;
                    }
                    else if(money<3)
                        cout<<"Sorry,your money isn't enough."<<endl;
                    else
                        cout<<"Sold out!"<<endl;
                }
                else if(prop=="all"||prop=="All")
                {
                    if(money>=12)
                    {
                        cout<<"Purchased"<<endl;
                        money-=12;
                        y.revive++;
                        y.attack++;
                        y.blood+=2;
                        e.hitrate--;
                        vcount++;
                    }
                }
                else if(prop=="no"||prop=="No")
                    break;
                else if(prop=="0")
                    return 0;
                else
                {
                    cout<<"hmm..."<<endl;
                    out++;
                }
            }
        }
        else
        {
            while(true)
            {
                cout<<"Wanna buy any thing?";
                cin>>prop;
                if(prop=="revivion")
                {
                    cout<<"Purchased"<<endl;
                    y.revive++;
                }
                else if(prop=="whetonion")
                {
                    cout<<"Purchased"<<endl;
                    y.attack++;
                }
                else if(prop=="enhancion")
                {
                    cout<<"Purchased"<<endl;
                    y.blood++;
                }
                else if(prop=="vertigion")
                {
                    if(vcount<1)
                    {
                        cout<<"Purchased"<<endl;
                        money-=3;
                        e.hitrate--;
                        vcount++;
                    }
                    else
                        cout<<"Sold out!"<<endl;
                }
                else if(prop=="no"||prop=="No")
                    break;
                else if(prop=="0")
                    return 0;
                else
                    cout<<"hmm..."<<endl;
            }
        }//Shop off
        bool exit=0;
        temp_yb=y.blood;
        if(e.number==0)
            return 0;
        if(cheat3==0)
        {
            for(int i=1;i<=e.number;i++)
            {
                temp_eb=e.blood;
                cout<<"Your blood:"<<y.blood<<"\nYour attack:"<<y.attack<<endl;
                wait_ap=rand()%10+1;
                cout<<"Now......";
                usleep(1000000*wait_ap);
                cout<<"watch out!"<<endl;
                if(cheat4==0)
                    cout<<"Here's an enemy!"<<endl;
                else
                    cout<<"Enemy No."<<dead_e+1<<" is coming."<<endl;
                cout<<"He's blood:"<<e.blood<<"\nHe's attack:"<<e.attack;
                cout<<endl;
                while(e.blood>0&&(y.blood>0||y.revive>0))
                {
                    cout<<"Shoot the enemy?";
                    cin>>begin;
                    if(begin=="0")
                        return 0;
                    else if(begin=="yes"||begin=="Yes")
                        e.blood-=y.attack;
                    else if(begin=="no"||begin=="No")
                    {
                        level++;
                        cout<<"Level up!"<<endl;
                        y.blood+=0.5;
                    }
                    if(e.blood>0)
                    {
                        cout<<"He's going to shoot you!"<<endl;
                        wait_sh=rand()%e.hitrate;
                        if(wait_sh>=1)
                        {
                            y.blood-=e.attack;
                            cout<<"You're shot."<<endl;
                        }
                        else
                            cout<<"He missed."<<endl;
                    }
                    if(y.blood<=0&&y.revive>0)
                    {
                        cout<<"You're dead.\nRevive?";
                        cin>>begin;
                        if(begin=="Yes"||begin=="yes")
                        {
                            cout<<"Keep play!";
                            y.blood=temp_yb;
                            y.revive--;
                        }
                        else if(begin=="0")
                            return 0;
                        else
                        {
                            exit=1;
                            break;
                        }
                    }
                    if(cheat4==1)
                        cout<<"Your blood:"<<y.blood<<"\nYour attack:"<<y.attack<<endl;
                }
                if(exit==1)
                    break;
                if(e.blood<=0)
                {
                    cout<<"Enemy was dead."<<endl;
                    e.blood=temp_eb;
                    dead_e++;
                }
                if(y.blood<=0&&y.revive<0)
                {
                    cout<<"GAME OVER"<<endl;
                    return 0;
                }
                if(i%2==0)
                    e.blood++;
                if(i%3==0)
                    e.attack++;
                //revive
                if(y.blood<=0&&y.revive>0)
                {
                    cout<<"You're dead.\nRevive?";
                    cin>>begin;
                    if(begin=="Yes"||begin=="yes")
                    {
                        cout<<"Keep play!";
                        y.blood=temp_yb;
                        y.revive--;
                    }
                    else if(begin=="0")
                        return 0;
                    else
                    {
                        cout<<"GAME OVER"<<endl;
                        exit=1;
                        break;
                    }
                }
                //Boss
                if(i==e.number)
                {
                    cout<<"BOSS WARNING"<<endl;
                    cout<<"Your blood:"<<y.blood<<"\nYour attack:"<<y.attack<<endl;
                    cout<<"He's blood:"<<b.blood<<"\nHe's attack:"<<b.attack<<endl;
                    while(b.blood>0&&(y.blood>0||y.revive>0))
                    {
                        cout<<"Shoot the boss?";
                        cin>>begin;
                        if(begin=="0")
                            return 0;
                        else if(begin=="yes"||begin=="Yes")
                            b.blood-=y.attack;
                        else if(begin=="no"||begin=="No")
                        {
                            level++;
                            cout<<"Level up!"<<endl;
                            y.blood+=0.5;
                        }
                        if(b.blood>0)
                        {
                            cout<<"He's going to shoot you!"<<endl;
                            wait_sh=rand()%b.hitrate;
                            if(wait_sh>=2)
                            {
                                y.blood-=b.attack;
                                cout<<"You're shot."<<endl;
                            }
                            else
                                cout<<"He missed."<<endl;
                        }
                        else if(b.blood<=0)
                        {
                            cout<<"Boss was dead."<<endl;
                            dead_e++;
                        }
                        if(y.blood<=0&&y.revive>0)
                        {
                            cout<<"You're dead.\nRevive?";
                            cin>>begin;
                            if(begin=="Yes"||begin=="yes")
                            {
                                cout<<"Keep play!";
                                y.blood=temp_yb;
                                y.revive--;
                            }
                            else if(begin=="0")
                                return 0;
                            else
                            {
                                cout<<"GAME OVER"<<endl;
                                exit=1;
                                break;
                            }
                        }
                    }
                }
                b.blood++;
                if(i%3==0)
                {
                    b.attack++;
                    b.hitrate++;
                }
                if(cheat4==1)
                    cout<<"Your blood:"<<y.blood<<"\nYour attack:"<<y.attack<<endl;
                if(exit==1)
                    break;
            }
        }
        else
        {
            for(int i=1;i<=e.number;i++)
            {
                temp_eb=e.blood;
                cout<<"Your blood:"<<y.blood<<"\nYour attack:"<<y.attack<<endl;
                wait_ap=rand()%10+1;
                cout<<"Now......";
                usleep(1000000*wait_ap);
                cout<<"watch out!"<<endl;
                cout<<"Here's an enemy!"<<"\nHe's blood:"<<e.blood<<"\nHe's attack:"<<e.attack;
                cout<<endl;
                while(e.blood>0&&(y.blood>0||y.revive>0))
                {
                    cout<<"Shoot the enemy?";
                    cin>>begin;
                    if(begin=="0")
                        return 0;
                    else if(begin=="yes"||begin=="Yes")
                        e.blood=0;
                    else if(begin=="no"||begin=="No")
                    {
                        level++;
                        cout<<"Level up!"<<endl;
                        y.blood+=0.5;
                    }
                    if(e.blood>0)
                    {
                        cout<<"He's going to shoot you!"<<endl;
                        wait_sh=rand()%3;
                        if(wait_sh>=1)
                            cout<<"You're shot."<<endl;
                        else
                            cout<<"He missed."<<endl;
                    }
                    if(y.blood<=0)
                    {
                        cout<<"You're dead.\nRevive?";
                        cin>>begin;
                        if(begin=="Yes"||begin=="yes")
                        {
                            cout<<"Keep play!";
                            y.blood=temp_yb;
                            y.revive--;
                        }
                        else if(begin=="0")
                            return 0;
                        else
                        {
                            cout<<"GAME OVER"<<endl;
                            exit=1;
                            break;
                        }
                    }
                    //Boss
                    if(i==e.number)
                    {
                        cout<<"BOSS WARNING"<<endl;
                        cout<<"Your blood:"<<y.blood<<"\nYour attack:"<<y.attack<<endl;
                        cout<<"He's blood:"<<b.blood<<"\nHe's attack:"<<b.attack<<endl;
                        while(b.blood>0&&(y.blood>0||y.revive>0))
                        {
                            cout<<"Shoot the boss?";
                            cin>>begin;
                            if(begin=="0")
                                return 0;
                            else if(begin=="yes"||begin=="Yes")
                                b.blood=0;
                            else if(begin=="no"||begin=="No")
                            {
                                level++;
                                cout<<"Level up!"<<endl;
                                y.blood+=0.5;
                            }
                            if(b.blood>0)
                            {
                                cout<<"He's going to shoot you!"<<endl;
                                wait_sh=rand()%b.hitrate;
                                if(wait_sh>=2)
                                    cout<<"You're shot."<<endl;
                                else
                                    cout<<"He missed."<<endl;
                            }
                            else if(b.blood<=0)
                            {
                                cout<<"Boss was dead."<<endl;
                                dead_e++;
                            }
                            if(y.blood<=0&&y.revive>0)
                            {
                                cout<<"You're dead.\nRevive?";
                                cin>>begin;
                                if(begin=="Yes"||begin=="yes")
                                {
                                    cout<<"Keep play!";
                                    y.blood=temp_yb;
                                    y.revive--;
                                }
                                else if(begin=="0")
                                    return 0;
                                else
                                {
                                    cout<<"GAME OVER"<<endl;
                                    exit=1;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(exit==1)
                    break;
                if(e.blood<=0)
                {
                    cout<<"Enemy was dead."<<endl;
                    e.blood=temp_eb;
                    dead_e++;
                }
                if(y.blood<=0)
                {
                    cout<<"GAME OVER"<<endl;
                    break;
                }
                if(i%2==0)
                    e.blood++;
                if(i%3==0)
                    e.attack++;
            }
        }
        if(cheat1==0)
        {
            if(y.blood>0)
                cout<<"WIN!"<<endl;
            if(y.blood>0&&(double)level/e.number>=2.5)
                cout<<"SUPER!!"<<endl;
            if((y.blood>0&&(double)level/e.number>=4.5)||(y.blood>0&&(double)level/e.number>=2.5)||y.revive>0)
                cout<<"UNBELIEVABLE!!!"<<endl;
        }
        else
        {
            cout<<"WIN!"<<endl;
            cout<<"SUPER!!"<<endl;
            cout<<"UNBELIEVABLE!!!"<<endl;
        }
        cout<<"Level:"<<level<<endl;
        if(y.blood>0)
            cout<<"Blood:"<<y.blood<<endl;
        else
        {
            if(cheat1==1)
                cout<<"Blood:"<<y.blood<<endl;
            else
                cout<<"Blood:0"<<endl;
        }
        cout<<"Enemies killed:"<<dead_e<<"/"<<e.number+1<<endl;
        //Achievements
        if(dead_e==e.number)
            cout<<"Enemy's doomer"<<endl;
        if(money==temp_m&&y.blood>0)
            cout<<"Businessman"<<endl;
        if(y.blood>temp_yb*2)
            cout<<"Good chef"<<endl;
    }
    cout<<"Actually......\n'GAMO':'GAME-O'\n'.F':'.First version'\n";
    return 0;
}
