#include<iostream>
using namespace std;
class checker;
int getIndex(int x, int y, checker array[12]);
class checker
{
    private:
    char player;
    int x;
    int y;
    int index;
    bool king;

    public:
    checker()
    {
        player='-';
    }

    void setK(bool x)
    {
        king=x;
    }

    bool getK()
    {
        return king;
    }

    checker(char a)
    {
        player=a;
    }

    char getP()
    {
        return player;
    }

    void setP(char a)
    {
        player=a;
    }

    int gety()
    {
        return y;
    }
    int getx()
    {
        return x;
    }

    void setx(int a)
    {
        x=a;
    }

    void sety(int a)
    {
        y=a;
    }

   
    void validMove(int x_move , int y_move)
    {
        bool movee;
        int a;
        int b;
        movee=false;
        
        

        if(player=='B')
        {

            if(king==false)
            {


                while(movee==false)
                

                {
                    if(y_move!=(y-1))
                    {

                        
                        
                        cout<<"enter x ";
                        cin>>a;
                        x_move=a;

                        cout<<"enter y dum ";
                        cin>>b;
                        y_move=b;
                        
                        cout<<endl;
                        cout<<"X: "<<x<<endl;
                        cout<<"X move: "<<x_move<<endl;
                        cout<<"Y: "<<y<<endl;
                        cout<<"Y move: "<<y_move<<endl;
                        cout<<player<<endl;
                        cout<<endl;
                        movee=false;

                    }


                    if(y_move==y-1)
                    {
                        if(x_move==x-1 || x_move==x+1)
                        {

                            cout<<"a"<<endl;
                            movee=true;
                            break;

                        }
                    }
                }
                
                    
                

            }
             
            if(king==true)
            {
                while(movee!=false)
                {
 
                    if((y_move==y-1 || y_move==y+1) && (x_move==x+1 || x_move==x-1))
                    movee=true;
                    else
                    {
                        cout<<"enter x ";
                        cin>>a;
                        x_move=a;
                        cout<<"enter y ";
                        cin>>b;
                        cout<<"exe2";
                        y_move=b;

                        
                    }
                        
                }

            }
            
            
        }

        if(player=='R')
        {
            if(king==false)
            {
                while(movee==false)
                {
                    
                    if(y_move==y+1 && (x_move==x-1 || x_move==x+1))
                    {
                        movee=true;
                        break;

                    }
                    else
                    {
                        cout<<"enter x ";
                        cin>>a;
                        x_move=a;
                        cout<<"enter y ";
                        cin>>b;
                        y_move=b;
                        cout<<"exe2";
                    }
                
                }
                
                


            }
            if(king==true)
            {
                while(movee==false)
                {
                    
                    if((y_move==y-1 || y_move==y+1) && (x_move==x+1 || x_move==x-1))
                    {
                        movee=true;
                        break;
                    }
                    else
                    {
                         cout<<"enter x ";
                         cin>>a;
                         x_move=a;
                         cout<<"enter y ";
                         cin>>b;
                         y_move=b;
                         cout<<"exe4";


                    }
                }

            }
            
            
        }       
    }
    int move(char arr[][8],int movex, int movey,checker p1[12], checker p2[12],int has, int mus)
    {
        cout<<endl<<"Player:"<<player<<endl;
        int i;
       
        
        if(player=='B')
        {
            cout<<endl;
            for(i=0;i<12;i=i+1)
            {
                cout<<"X: "<<p2[i].getx()<<" , Y:"<<p2[i].gety()<<", P :"<<p2[i].getP()<<endl;
                


            }
            if(arr[movey][movex]=='-')
            {
                cout<<"you have been moved";
               
                arr[mus][has]='-';
                setx(movex);
                sety(movey);
               
                arr[movey][movex]='B';

                cout<<endl<<"Current X: "<<has;
                cout<<endl<<"Current y: "<<mus;
                cout<<endl<<"Move X: "<<movex;
                cout<<endl<<"Current Y: "<<movey;
                cout<<endl;

                return 1;
            }
            else if(arr[movey][movex]=='B')
            {

                cout<<"cant move your checker already there";
                cout<<endl<<"Current X: "<<has;
                cout<<endl<<"Current y: "<<mus;
                cout<<endl<<"Move X: "<<movex;
                cout<<endl<<"Current Y: "<<movey;
                cout<<endl;
                return 3;
            }
            else if(arr[movey][movex]=='R')
            {
                if(movex>x)
                {
                    if(arr[movey-1][movex+1]=='-')
                    {
                        cout<<endl<<"youve killed the oppent";
                        index=getIndex(movex,movey,p1);
                        
                        arr[mus][has]='-';
                        arr[movey][movex]='-';
                        arr[movey-1][movex+1]='B';
                        
                        p1[index].player='-';
                        setx(movex+1);
                        sety(movey-1);
                        
                        cout<<endl;

                        return 2;
                    }
                    else if(arr[movey-1][movex+1]!='-')
                    {
                        cout<<endl<<"Cant kill that peice cause next sqaure not empty!!";
                        cout<<endl<<"try moving another peice";
                        
                        return 4;

                    }
                   

                }

                else if(movex<x)
                {
                    if(arr[movey-1][movex-1]=='-')
                    {
                        cout<<endl<<"youve killed the oppent";
                        
                        
                        index=getIndex(movex,movey,p1);
                        
                        arr[mus][has]='-';
                        arr[movey][movex]='-';
                        arr[movey-1][movex-1]='B';
                        
                        p1[index].player='-';
                        setx(movex-1);
                        sety(movey-1);
                        
                        
                        return 2;
                    }
                    else if(arr[movey-1][movex-1]!='-')
                    {
                        cout<<endl<<"Cant kill that peice cause next sqaure not empty!!";
                        cout<<endl<<"try moving another peice";
                        
                        return 4;

                    }
                }
                
            }

        }

        if(player=='R')
        {
            if(arr[movey][movex]=='-')
            {
                cout<<"you have been moved";
                cout<<endl<<"X: "<<has;
                cout<<endl<<"Y: "<<mus;
                cout<<endl<<"X move : "<<movex;
                cout<<endl<<"Y move : "<<movey;


                
                arr[movey][movex]='R';
                arr[mus][has]='-';
                setx(movex);
                sety(movey);
                
                
               
                
                return 1;
            }
            if(arr[movey][movex]=='R')
            {
                cout<<"cant move your checker already there";
                return 3;
            }
            if(arr[movey][movex]=='B')
            {
                if(movex>x)
                {
                    if(arr[movey+1][movex+1]=='-')
                    {
                        cout<<endl<<"youve killed the oppent";
                       
                        index=getIndex(movex,movey,p2);
                        cout<<endl<<"curren space: "<<arr[mus][has];
                        cout<<endl<<"move to space: "<<arr[movey][movex];
                        cout<<endl<<"new space: "<<arr[movey+1][movex+1];

                       
                        arr[mus][has]='-';
                        arr[movey][movex]='-';
                        arr[movey+1][movex+1]='R';
                        

                        p2[index].player='-';
                        setx(movex+1);
                        sety(movey+1);
                        cout<<endl<<"Current X: "<<has;
                        cout<<endl<<"Current y: "<<mus;
                        cout<<endl<<"Move X: "<<movex;
                        cout<<endl<<"move Y: "<<movey;
                        cout<<endl<<"New X: "<<movex+1;
                        cout<<endl<<"New Y: "<<movey+1;
                        
                       
                        
                        return 2;
                    }
                    else if(arr[movey+1][movex+1]!='-')
                    {
                        cout<<endl<<"Cant kill that peice cause next sqaure not empty!!";
                        cout<<endl<<"try moving another peice";
                       
                        return 4;

                    }
                }

                if(movex<x)
                {
                    if(arr[movey+1][movex-1]=='-')
                    {
                        cout<<endl<<"youve killed the oppent";
                        
                        index=getIndex(movex,movey,p2);
                        cout<<endl<<"curren space: "<<arr[mus][has];
                        cout<<endl<<"move to space: "<<arr[movey][movex];
                        cout<<endl<<"new space: "<<arr[movey+1][movex-1];
                        
                        arr[mus][has]='-';
                        arr[movey][movex]='-';
                        arr[movey+1][movex-1]='R';
                        p2[index].player='-';
                        setx(movex-1);
                        sety(movey+1);
                        cout<<endl<<"Current X: "<<has;
                        cout<<endl<<"Current y: "<<mus;
                        cout<<endl<<"Move X: "<<movex;
                        cout<<endl<<"Move Y: "<<movey;
                        cout<<endl<<"New X: "<<movex-1;
                        cout<<endl<<"New Y: "<<movey+1;
                       
                        return 2;
                    }
                    else if(arr[movey+1][movex-1]!='-')
                    {

                        cout<<endl<<"Cant kill that peice cause next sqaure not empty!!";
                        cout<<endl<<"try moving another peice";
                        cout<<endl<<"curren space: "<<arr[mus][has];
                        cout<<endl<<"move to space: "<<arr[movey][movex];
                        cout<<endl<<"new space: "<<arr[movey+2][movex-2];
                        return 4;

                    }
                }
                
            }

        }

    }
    
};

void kingCheck(checker x[], int a)
{
    int i;
    for(i=0;i<12;i=i+1)
    {
        if(x[i].gety()==a)
        {
            
            x[i].setK(true);

        }
       
        
    }
}

int getIndex(int x, int y, checker array[12])

{


    {

        int i;
        int fx;
        int fy;
        for(i=0;i<12;i=i+1)
        {
        
            fx=array[i].getx();
            fy=array[i].gety();
            if(fx==x && fy==y)
            {
                return i;
                break;

            }
        }    
        
    }
}




int dead(checker arr[12])
{
    int i;
    int count;
    for(i=0;i<12;i=i+1)
    {
        if(arr[i].getP()=='-')
        {
            count=count+1;
        }
    }
    return count;
}
void initilise(char arr[][8],checker pi[],int start , int end)
{

    int c;
    int i;
    int j;
    char a;  
    c=0;
    for(i=start;i<end;i=i+1)
    {
        for(j=0;j<8;j=j+1)
        {
            if(i%2!=0)
            {
                if(j%2==0)
                {
                    a=pi[c].getP();
                    arr[i][j]=a;
                    
                    pi[c].setx(j);
                    
                    pi[c].sety(i);
                    c=c+1;
                    

                }
                    
            }
            else
            {
                if(j%2!=0)
                {
                    a=pi[c].getP();
                    arr[i][j]=a;
                    
                    pi[c].setx(j);
                    
                    pi[c].sety(i);
                    c=c+1;
                    
                }
            }
        }

    }
}

void display(char arr[][8])
{
    int i,j;
    for(i=0;i<8;i=i+1)
    {
        for(j=0;j<8;j=j+1)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }    

}

int stuckp2(checker arr[12], char board[][8])
{
    int i;
    int current_x;
    int current_y;
    int stu;
    for(i=0;i<12;i=i+1)
    {
        current_x=arr[i].getx();
        current_y=arr[i].gety();
        if(board[current_y-1][current_x+1]=='B' || board[current_y-1][current_x-1]=='B' )
        {
            stu=stu+1;
        }
        
        
        
    }
    return stu;

}

int stuckp1(checker arr[12], char board[][8])
{
    int i;
    int current_x;
    int current_y;
    int stu;
    for(i=0;i<12;i=i+1)
    {
        current_x=arr[i].getx();
        current_y=arr[i].gety();
        if(board[current_y+1][current_x+1]=='R' || board[current_y-1][current_x-1]=='R' )
        {
            stu=stu+1;
        }
        
        
        
    }
    return stu;

}
int main()
{
    int cho;
    char board[8][8];
    int i;
    int j;
    int check;
    checker p1[12];
    checker p2[12];
    
    for(i=0;i<12;i=i+1)
    {
        p1[i].setP('R');
        p2[i].setP('B');
        
        
    }
    for(i=0;i<8;i=i+1)
    {
        for(j=0;j<8;j=j+1)
        {
            board[i][j]='-';
        }
        
    }    
    
    initilise(board,p1,0,3);
    
    initilise(board,p2,5,8);

    
    bool end=false;
    
    char corner;
    int select_x;
    int select_y;
    int has;
    int mus;
    
    corner='R';
    cout<<"Welcome to the game!"<<endl;
    cout<<"Player one is Blue and player two is Red!"<<endl;
    bool does_not_exist=false;
    int index;
    for(i=0;i<12;i=i+1)
    {
        p1[i].setK(false);
        p2[i].setK(false);

        
    }
    while(end==false)
    {

        if(corner=='B')


        {
            kingCheck(p2,0);
            cout<<endl;
            display(board);
            does_not_exist=false;
            cout<<endl<<"Player 1 turn";
            while(does_not_exist==false)
            {
                cout<<"Enter cordinates of checker you wanna move"<<endl;
                cout<<"X:";
                cin>>select_x;
                cout<<"Y:";
                cin>>select_y;;

                has=select_x;
                mus=select_y;
                if(board[select_y][select_x]=='B')
                {
                    does_not_exist=true;
                    break;

                }

            }
            index=getIndex(select_x,select_y,p2);
            cout<<"enter x cordinate to move to";
            cin>>select_x;
            cout<<"enter y cordinate to move to";
            cin>>select_y;
            
            p2[index].validMove(select_x,select_y);
            check=p2[index].move(board,select_x,select_y,p1,p2,has,mus);
            
            if(check==1)
            {
                corner='R';
            }
            if(check==2)
            {
                cout<<endl<<"youve killed the openent . you have another try";

            }
            if(check==3)
            {
                cout<<endl<<"Try moving another piece";
                cout<<endl<<"if your checkers are stuck press 1 to forfiet/draw . press any other numebred key to continue";
                cin>>cho;
                if(cho==1)
                end=true;
                else if(cho!=1)
                corner='B';

            }

            if(dead(p1)==12)
            {
                cout<<endl<<"P1 won";
                end=true;
            }
            
            if(check==4)
            {
                corner='B';
            }
        }


        if(corner=='R')

        {
            kingCheck(p1,7);
            cout<<endl;
            display(board);
            does_not_exist=false;
            cout<<endl<<"Player 2 turn";
            while(does_not_exist==false)
            {
                cout<<"Enter cordinates of checker you wanna move"<<endl;
                cout<<"X:";
                cin>>select_x;
                cout<<"Y:";
                cin>>select_y;
                has=select_x;
                mus=select_y;

                if(board[select_y][select_x]=='R')
                {
                    
                    does_not_exist=true;
                    

                }

                 
                
            }
            index=getIndex(select_x,select_y,p1);
            cout<<"enter x cordinate to move to";
            cin>>select_x;
            cout<<"enter y cordinate to move to";
            cin>>select_y;
            
            p1[index].validMove(select_x,select_y);
            check=p1[index].move(board,select_x,select_y,p1,p2,has,mus);
            
            if(check==1)
            {
                corner='B';
            }
            else if(check==2)
            {
                cout<<endl<<"youve killed the openent . you have another try";

            }

            else if(check==3)
            {
                cout<<endl<<"Try moving another piece";
                cout<<endl<<"if your checkers are stuck press 1 to forfiet/draw . press any other key to continue";
                cin>>cho;
                if(cho==1)
                end=true;
            }
            if(dead(p2)==12)
            {
                cout<<endl<<"P1 wins";
                end=true;
            }
            if(check==4)
            {
                corner='R';
            }

        }
        
    }

    return 0;
}
