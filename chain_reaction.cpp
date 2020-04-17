#include<iostream>
#include<iomanip>
using namespace std;

const int row=3;
const int column=3; 

struct postman
{
    int pos;
    char counter;
}post;

class player
{
    char name[30];
    char counter;
    int pos;

    public:

        player(char a)
        {
            counter=a;
        }

        void input_details()
        {
            cout<<"Enter your name(Don't use space):";
            cin>>name;           
        }

        void output_details()
        {
            cout<<"Cogratulations "<<name<<" , you are the winner."<<endl;
        }

        void get()
        {
            cout<<name<<"'s turn.\nEnter position:";
            cin>>pos;

            post.pos=pos;
            post.counter=counter;
        }
};


class gameboard
{
    char board[row][column];
    int f[row][column];   
    int x,y;
    int pos;
    char c;

    public:

        gameboard()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                    f[i][j]=0;
            }

            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                    board[i][j]='_';
            }
        }

        int winner_decider()
        {
            int m=0;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    if(board[i][j]!=c && board[i][j]!='_')
                        m++;
                }
            }

                if(m==0)
                    return 1;

                else return 0;    
        }

        void show()
        {
        	cout<<"          ";
            for(int j=0;j<column;j++)
                cout<<setw(5)<<j+1;
            cout<<endl;

            for(int i=0;i<row;i++)
            {
                cout<<setw(10)<<i+1<<". ";

                for (int j = 0; j < column; j++)
                {
                    if(f[i][j]==3)
                        cout<<setw(5)<<board[i][j];

                    else cout<<setw(5)<<" ";    
                }
                cout<<endl;                
            
				cout<<setw(12)<<" ";
                for(int j=0;j<column;j++)
                {
                    char a[3]="  ";
                    if(f[i][j]==2 || f[i][j]==3)
                    {
                        a[0]=board[i][j];
                        a[1]=board[i][j];
                    }
                    else if(f[i][j]==1)
                        a[0]=board[i][j];

                    cout<<setw(5)<<a;
                }
                cout<<endl;
            }    
        }

        void blast(int x,int y)
        {
            if(winner_decider())
                return;

            if(x==0 && y==0 && f[x][y]==2)
            {
                f[x][y]=0; board[x][y]='_';
                board[x][y+1]=c; f[x][y+1]++; blast(x,y+1); system("cls"); show(); system("cls");
                board[x+1][y]=c; f[x+1][y]++; blast(x+1,y); system("cls"); show(); system("cls");
            }

            else if(x==0 && y==column-1 && f[x][y]==2)
            {
                f[x][y]=0; board[x][y]='_';
                board[x][y-1]=c; f[x][y-1]++; blast(x,y-1); system("cls"); show(); system("cls");
                board[x+1][y]=c; f[x+1][y]++; blast(x+1,y); system("cls"); show(); system("cls");
            }
            
            
            else if(x==row-1 && y==0 && f[x][y]==2)
            {
                f[x][y]=0; board[x][y]='_';
                board[x][y+1]=c; f[x][y+1]++; blast(x,y+1); system("cls"); show(); system("cls");
                board[x-1][y]=c; f[x-1][y]++; blast(x-1,y); system("cls"); show(); system("cls");
            }

            
            else if(x==row-1 && y==column-1 && f[x][y]==2)
            {
                f[x][y]=0; board[x][y]='_';
                board[x][y-1]=c; f[x][y-1]++; blast(x,y-1); system("cls"); show(); system("cls");
                board[x-1][y]=c; f[x-1][y]++; blast(x-1,y); system("cls"); show(); system("cls");
            }

            else if(x==0 && f[x][y]==3)
            {
                f[x][y]=0; board[x][y]='_';
                board[x][y-1]=c; f[x][y-1]++; blast(x,y-1); system("cls"); show(); system("cls");
                board[x][y+1]=c; f[x][y+1]++; blast(x,y+1); system("cls"); show(); system("cls");
                board[x+1][y]=c; f[x+1][y]++; blast(x+1,y); system("cls"); show(); system("cls");
            }

            else if(x==row-1 && f[x][y]==3)
            {
                f[x][y]=0; board[x][y]='_';
                board[x][y-1]=c; f[x][y-1]++; blast(x,y-1); system("cls"); show(); system("cls");
                board[x][y+1]=c; f[x][y+1]++; blast(x,y+1); system("cls"); show(); system("cls");
                board[x-1][y]=c; f[x-1][y]++; blast(x-1,y); system("cls"); show(); system("cls");
            }

            else if(y==0 && f[x][y]==3)
            {
                f[x][y]=0; board[x][y]='_';
                board[x-1][y]=c; f[x-1][y]++; blast(x-1,y); system("cls"); show(); system("cls");
                board[x][y+1]=c; f[x][y+1]++; blast(x,y+1); system("cls"); show(); system("cls");
                board[x+1][y]=c; f[x+1][y]++; blast(x+1,y); system("cls"); show(); system("cls");
            }

            else if(y==column-1 && f[x][y]==3)
            {
                f[x][y]=0; board[x][y]='_';
                board[x-1][y]=c; f[x-1][y]++; blast(x-1,y); system("cls"); show(); system("cls");
                board[x+1][y]=c; f[x+1][y]++; blast(x+1,y); system("cls"); show(); system("cls");
                board[x][y-1]=c; f[x][y-1]++; blast(x,y-1); system("cls"); show(); system("cls");
            }

            else if(f[x][y]==4)
            {
                f[x][y]=0; board[x][y]='_';
                board[x-1][y]=c; f[x-1][y]++; blast(x-1,y); system("cls"); show(); system("cls");
                board[x+1][y]=c; f[x+1][y]++; blast(x+1,y); system("cls"); show(); system("cls");
                board[x][y-1]=c; f[x][y-1]++; blast(x,y-1); system("cls"); show(); system("cls");
                board[x][y+1]=c; f[x][y+1]++; blast(x,y+1); system("cls"); show(); system("cls");
            }
        }

        void assign(int pos)
        {
            switch(pos)
            {
                case 7: x=0;y=0;break;
                case 8: x=0;y=1;break;
                case 9: x=0;y=2;break;
                case 4: x=1;y=0;break;
                case 5: x=1;y=1;break;
                case 6: x=1;y=2;break;
                case 1: x=2;y=0;break;
                case 2: x=2;y=1;break;
                case 3: x=2;y=2;break;   
            }
        }

        void place()
        {
            pos=post.pos;
    LABEL: assign(pos);
            c=post.counter;

            if(f[x][y]==0)
            {
                board[x][y]=c;
                f[x][y]++;
            }

            else if(c==board[x][y])
                    f[x][y]++;

            else 
            {
                if(x>row || y>column)    
                    cout<<"Out of bounds.\n";
                else
                cout<<"This place has been selected by another player.\n"; 
                
                cout<<"Enter again:";
                cin>>pos;

                goto LABEL;
            }

            blast(x,y);        
        }

        
};

int main()
{
    system("cls");

    gameboard g;
    player p1('x'),p2('o');

    for(int i=0;i<2;i++)
    {
        cout<<"For Player "<<i+1<<": "<<endl;

        if(i==0)
        {
            p1.input_details();
            cout<<endl<<"Your counter is *\n\n";
        }

        else
        {
            p2.input_details();
            cout<<"\nYour counter is ^\n\n";
        }            
    }

    int i=1;
    while(i++)
    {
    	g.show();
        if((i&1)==0)
        {	
            p1.get();
            g.place();
            g.show();
            int flag=0;

            if(i>2)
              flag=g.winner_decider();

            if(flag==1)
            {
                p1.output_details();
                break;
            }
        }

        else
        {
            p2.get();
            g.place();
            g.show();
            int flag=0;

            if(i>2)
            flag=g.winner_decider();

            if(flag==1)
            {
                p2.output_details();
                break;
            }
        }
        system("cls");
    }
    return 0;
}
