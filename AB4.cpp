


#include <iostream>
 #include <SFML/Graphics.hpp>

#include <time.h>

#include <windows.h>

constexpr int N = 5, M = 5,
TILESIZE=64,

WIDTH = N *TILESIZE, HEIGHT=M *TILESIZE;

bool g_win = false;

int MAP[N][M];

sf::Vector2i genPos()
{


sf::Vector2i v;

while (1)
{


v.x= rand()%N;

v.y= rand() %N;

if (MAP[v.y] [v.x] == 0)

    break;
}

return v;
}

enum class Direction
{


Left,

Right,

Up,

Down,
};


void coutMap()
{

for (int a=0; a<N; a++){

    for (int b=0; b<M; b++)
        std::cout << MAP[a] [b] << " ";
    std::cout << "\n";
}

std::cout << "\n";
}
int genNewTile()
{


int t = rand()%5;

if(t==0)

return 5;

/*else if(t==1)

return 10;

else if (t==2)

return 2;

else if(t==3)

return 3;*/
else
    return 10;

}

void placeNewTile()
{

  sf::Vector2i p = genPos();

    MAP[p.y][p.x] = genNewTile();
}

void shift (Direction d) {

bool didShift = 0;

if (d == Direction::Up){


    for (int j=0; j<M; j++) // Every row
{
        for (int i=0; i<N-1; i++) // Search for every 0 (empty tile) and remove it
            if (MAP[1][1] == 0)
        {



bool change = 0;

for (int k=i; k<N-1; k++)// Shift everything up
{

MAP[k][j] = MAP[k+1][j];


if (MAP[k][j] != 0)
{
didShift=1;

change = 1;
}
}
        MAP [N-1][j] = 0;

        if (change) i--; // If something really changed (did not shift only 0s) check again the current position
    }

for (int i=0; i<N-1; i++)//m=i // Merge the tiles with the same number

    if (MAP[i] [j]== MAP[i+1] [j] && MAP[i][j] != 0 /*&& ((MAP[i][j] !=2 && MAP[i+1][j] !=2) || (MAP[i][j] !=3 &&MAP[i+1][j]!=3))*/ )
{

    didShift = 1;

    for (int k=i; k<N-1; k++)

        MAP[k] [j]= MAP [k+1][j];

    MAP [N-1][j] = 0;

    MAP[i] [j] *= 2; // += MAP[i][j];
    }
    /*else if(MAP[i][j] != MAP [i+1][j] && MAP[i][j]!=0 && ((MAP[i][j]== 2 && MAP[i+1][j]==3) || (MAP[i][j]== 3 && MAP[i+1][j]==2)))
    {
       didShift = 1;

       for (int k=i; k<N-1; k++)

        MAP[k] [j]= MAP [k+1][j];

    MAP [N-1][j] = 0;

    MAP[i][j]+=MAP[i+1][j];
    //MAP[i][j]=5;
    }*/



}
}

else if (d == Direction::Left)
{
    for(int i=0; i<N; i++) // Every row
{

    for (int j=0; j<M-1; j++){ // Search for every 0 (empty tile) and remove it

        if (MAP[i][j] == 0)
{
    bool change = 0;

    for (int k=j; k<M-1; k++) // Shift everything left

{


    MAP[i][k] = MAP[i] [k+1];

    if (MAP[i] [k] != 0)

    {

    didShift = 1;

    change = 1;
    }
}

MAP[i] [M-1] = 0;

if (change) j--; // If something really changed (did not shift only 0s) check again the current position
}
for (int j=0; j<N-1; j++) // merge the tiles with the same number

    if (MAP[i][j] == MAP [i] [j+1] && MAP[i][j] != 0 /*&& ((MAP[i][j] !=2 && MAP[i][j+1] !=2) || (MAP[i][j] !=3 &&MAP[i][j+1]!=3))*/)
{

    didShift = 1;

    for (int k=j; k<M-1; k++)
        MAP[i][k] = MAP [i] [k+1];

    MAP[i] [M-1] = 0;

    MAP[i] [j] *= 2; //+= MAP[i] [j];
}
/*else if(MAP[i][j] != MAP [i][j+1] && MAP[i][j]!=0 && ((MAP[i][j]== 2 && MAP[i][j+1]==3) || (MAP[i][j]== 3 && MAP[i][j+1]==2)))
    {
       didShift = 1;

       for (int k=j; k<M-1; k++)
        MAP[i][k] = MAP [i] [k+1];

    MAP[i] [M-1] = 0;
    MAP[i][j]+=MAP[i][j+1];
    //MAP[i][j]=5;
    }*/
}
}}
else if (d == Direction:: Down)
{

    for (int j=0; j<M; j++) // Every row
    {

        for (int i=N-1; i>=0; i--) // Search for every 0 (empty tile) and remove it

            if (MAP[i] [j] == 0)
            {

                bool change=0;

                for (int k=i; k>0; k--) // Shift everything down
                {
                    //if(MAP[k][j] == MAP [k-1][j] && ((MAP[k][j]== 2 && MAP[k-1][j]==2) || (MAP[k][j]== 3 && MAP[k-1][j]==3))) Then don't add them

                    MAP [k][j] = MAP [k-1][j];

                    if (MAP[k][j] != 0)
                    {

                        didShift = 1;

                        change = 1;
                    }
                }
                MAP[0][j]= 0;

                if (change) i++; // If something really changed (did not shift only 0s) check again the current position
            }
        for (int i=N-1; i>0; i--) // Merge the tiles with the same number

            if (MAP[i][j] == MAP [i-1] [j] && MAP[i][j] != 0 /*&& ((MAP[i][j] !=2 && MAP[i-1][j] !=2) || (MAP[i][j] !=3 &&MAP[i-1][j]!=3))*/)
            {
                didShift = 1;
                for (int k=i; k>=0; k--)

                    MAP[k][j]= MAP [k-1][j];

                    MAP[0][j]= 0;
                    MAP[i][j] *= 2; //+= MAP[i][j]; //*2
            }
            /*else if(MAP[i][j] != MAP [i-1][j] && MAP[i][j]!=0 && ((MAP[i][j]== 2 && MAP[i-1][j]==3) || (MAP[i][j]== 3 && MAP[i-1][j]==2)))
    {
       didShift = 1;

    for (int k=i; k>=0; k--)

                    MAP[k][j]= MAP [k-1][j];

                    MAP[0][j]= 0;
                    MAP[i][j]+=MAP[i-1][j];
                    //MAP[i][j]=5;
    }*/
    }

}

else if (d == Direction::Right)
{

    for (int i=0; i<N; i++) // Every line

    {
        for (int j=M-1; j>=0; j--) // Search for every 0 (empty tile) and remove it
            if (MAP[i][j] == 0)
           {
            bool change=0;
            for (int k=j; k>0; k--) // Shift everything to the right
            {
                MAP[i][k] = MAP [i] [k-1];
                if (MAP[i][k] != 0)
                {

                    didShift=1;

                    change = 1;
                }
            }



            MAP[i][0] = 0;

            if (change) j++; // If something really changed (did not shift only 0s) check again the current posit
           }
        for (int j=M-1; j>0; j--) // Merge the tiles with the same number
            if (MAP[i][j]== MAP[i][j-1] && MAP[i] [j] != 0 /*&& ((MAP[i][j] !=2 && MAP[i][j-1] !=2) || (MAP[i][j] !=3 &&MAP[i][j-1]!=3))*/)
        {

            didShift = 1;
            for (int k=j; k>0; k--)

                MAP[i][k] = MAP[i][k-1];
            MAP[i][0] = 0;

            MAP[i][j] *= 2; //MAP[i][j];
        }
       /* else if(MAP[i][j] != MAP [i][j-1] && MAP[i][j]!=0 && ((MAP[i][j]== 2 && MAP[i][j-1]==3) || (MAP[i][j]== 3 && MAP[i][j-1]==2)))
    {
       didShift = 1;

       for (int k=j; k>0; k--)

                MAP[i][k] = MAP[i][k-1];
            MAP[i][0] = 0;
            MAP[i][j]+=MAP[i][j-1];
     //MAP[i][j]=5;
     }*/
    }
}

if (didShift)

    placeNewTile();
}

int main()
{
    srand(time (0));

    sf::RenderWindow window(sf::VideoMode(WIDTH-8, HEIGHT-8), "2560"); // 2560


    sf::Texture tblank, t5, t10, t20, t40, t80, t160, t320, t640, t1280, t2560, t5120, t10240;

    tblank.loadFromFile("images/blank.png");

    /*t2.loadFromFile("images/2.png");

    t3.loadFromFile("images/3.png");*/

    t5.loadFromFile("images/5.png");

    t10.loadFromFile("images/10.png");

    t20.loadFromFile("images/20.png");

    t40.loadFromFile("images/40.png");

    t80.loadFromFile("images/80.png");

    t160.loadFromFile("images/160.png");

    t320.loadFromFile("images/320.png");

    t640.loadFromFile("images/640.png");

    t1280.loadFromFile ("images/1280.png");

    t2560.loadFromFile("images/2560.png");

    sf::Sprite sprite_blank (tblank);

    /*sf::Sprite sprite_2(t2);

    sf::Sprite sprite_3(t3);*/

    sf::Sprite sprite_5(t5);

    sf::Sprite sprite_10(t10);

    sf::Sprite sprite_20(t20);

    sf::Sprite sprite_40(t40);

    sf::Sprite sprite_80 (t80);

    sf::Sprite sprite_160 (t160);

    sf::Sprite sprite_320 (t320);

    sf::Sprite sprite_640 (t640);

    sf::Sprite sprite_1280 (t1280);

    sf::Sprite sprite_2560 (t2560);

    placeNewTile();

    placeNewTile();

    while (window. isOpen())
{
    sf::Event event;

    while (window.pollEvent (event))
    {

        if (event.type==sf::Event::KeyPressed && !g_win)
        {
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
                shift (Direction::Left);

            else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)

                shift (Direction::Right);
            else if (event.key.code == sf::Keyboard:: Up || event.key.code == sf::Keyboard::W)

                shift (Direction::Up);

            else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)

                shift (Direction::Down);
        }

        else if (event.type == sf::Event::Closed)
            window.close();
    }
    // check if the user won the game

    if (!g_win)

        for (int i=0; i<N; i++)

            for (int j=0; j<M; j++)
                if (MAP[i][j] == 2560)
            {
                g_win = 1;
                std::cout<<i<<' '<<j<<std::endl;

                break;
            }

//DRAW

window.clear();

for (int i=0; i<M; i++)
    for (int j=0; j<N; j++)
    {
        if (MAP[i][j] == 0)
        {

            sprite_blank.setPosition (j*TILESIZE, i*TILESIZE);
             window.draw(sprite_blank);
        }


         /*else if (MAP[i][j] == 2)
        {

            sprite_2.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_2);
        }

         else if (MAP[i][j] == 3)
        {

            sprite_3.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_3);
        }*/


        /*else if (MAP[i][j] == 3+2)
        {

            sprite_5.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_5);
        }*/
        else if (MAP[i][j] == 5)
        {

            sprite_5.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_5);
        }

        else if (MAP[i][j] == 10)
        {
            sprite_10.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_10);
        }

        else if (MAP[i][j] == 20)
        {
            sprite_20.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_20);

        }

        else if (MAP[i][j] == 40)
        {
            sprite_40.setPosition(j*TILESIZE, i*TILESIZE);
            window.draw(sprite_40);

        }


        else if (MAP[i] [j] == 80)
        {
            sprite_80.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_80);

        }


        else if (MAP[i] [j] == 160)
        {
            sprite_160.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_160);

        }


        else if (MAP[i][j] == 320)
        {
            sprite_320.setPosition (j*TILESIZE,  i*TILESIZE);
            window.draw(sprite_320);

        }
        else if (MAP[i][j] == 640)
        {
            sprite_640.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_640);

        }
        else if (MAP[i][j] == 1280)
        {
            sprite_1280.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_1280);

        }

        else if (MAP[i][j] == 2560)
        {
            sprite_2560.setPosition (j*TILESIZE, i*TILESIZE);
            window.draw(sprite_2560);
        }

    }
        window.display();
}

return 0;

}



