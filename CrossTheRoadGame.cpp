#include<iostream>
#include<deque>
#include<vector>
#include<conio.h>
#include<time.h>
#include<stddef.h>

using namespace std;

// width Genisik demek

class cPlayer

{

    public:
    int x , y; // Koordinatlar
    cPlayer(int width) { x = width / 2; y = 0; } // Oyuncu konumu


};

class cLane // Oyun Alanı

{

    private:
    deque<bool> cars; // Arabalar
    bool right;

    public:

    cLane( int width )

    {


        for ( int i = 0; i < width; i++)

            cars.push_front(true); // Arabaları sırayla ekliyoruz ön taraftan

            right == rand() % 2 ; // Rastgele sayi uretir
        
    }

      void Move()

      {

        if (right)

        {

        if (rand() % 10 == 1)

          cars.push_front(true); // Arabaları sırayla ekliyoruz ön taraftan

        else

            cars.push_front(false); // Arabaları sırayla ekliyoruz ön taraftan
            cars.pop_back(); // geriye dogru devam
            
        }
        
        else

        {

        if (rand() % 10 == 1)

          cars.push_back(true); // Arabaları sırayla ekliyoruz son taraftan

        else

            cars.push_back(false); // Arabaları sırayla ekliyoruz son taraftan
            cars.pop_front(); // ona dogru devam
            
        }
            
            
        }
            
        

      
      bool CheckPos(int pos ) { return cars[pos]; }


      void ChangeDirection() { right = !right; }  // Yon degistirme

    

};



class cGame

{
   
   private:
   bool quit; // Cikis
   int numberOfLanes; // Araba sayisi
   int width; // Genislik
   int score ; // Skor
   cPlayer * player; // Oyuncu
   vector<cLane*> map; // Arabaları map de yerleştiriyoruz

 public:
    
    cGame(int w = 20 , int h = 10)

    {

        numberOfLanes = h; // Araba sayisi 10 tane
        width = w; // Genislik 20
        quit = false; // Cikis Yapmıyoruz

        for(int i = 0 ; i < numberOfLanes ; i++)

            map.push_back(new cLane(width)); // Arabaları map de yerleştiriyoruz
            player = new cPlayer(width); // Oyuncu konumu
    
    }

    ~cGame()

    {

        delete player; // Oyuncu siliyoruz

        for(int i = 0 ; i < map.size() ; i++)
        
        {

        cLane * current = map.back(); // Arabaları map de yerleştiriyoruz
        map.pop_back(); // Arabaları map de yerleştiriyoruz

        delete current; 

       }  

    }

    void Draw()

    {

        system("cls"); // Ekranı temizliyoruz

        for(int i = 0 ; i < numberOfLanes ; i++) // Araba sayisi kadar döngü 10 tane yani

        {
            

            for(int j = 0 ; j < width ; j++)  // Genislik kadar döngü 20 tane yani

            {

            if (i == 0 && (j == 0 || j == width - 1)) 

            {
                
                cout<<"S";
                
            }

            if (i == numberOfLanes - 1 && (j == 0 || j == width - 1)) 

            {
                
                cout<<"E";
                
            }

                if(map[i]->CheckPos(j) && i != 0 && i !=numberOfLanes - 1 ) // Arabaları map de yerleştiriyoruz

                    cout << "#"; // Araba varsa # yazdır

                else if(player->x == j && player->y == i) // Oyuncu konumu

                    cout << "V"; // Araba yoksa v yazdır

                else

                   cout<<" "; // Bosluk
                    
            }

            cout << endl;

        }

        cout<<"Score: "<<score<<endl; // Skor


    }

    void Input() // Giris

    {

        if (_kbhit())  // Klavyedeki bir tuşa basılıp basılmadıgını bize söyler

        {

            char current = _getch(); // Klavyeden girilen karakteri al

            if (current == 'a')

            {

                player->x--; // Oyuncu sola gidiyor


                
            }

            if (current == 'd')

            {

                player->x++; // Oyuncu saga gidiyor

            }
            
            if (current == 'w')

            {

                player->y--; // Oyuncu yukari gidiyor

            }

            if (current == 's')

            {

                player->y++; // Oyuncu asagi gidiyor

            }
                
            
            
        }

        

    }

    void Logic() // Mantik

    {

        for(int i = 1 ; i < numberOfLanes - 1 ; i++) // Araba sayisi kadar döngü 10 tane yani

        {

            if(rand() % 10 == 1) // Rastgele sayi uretir

                map[i]->Move(); // Arabaları map de yerleştiriyoruz

                if (map[i]->CheckPos(player->x) && player->y == i) // Arabaları map de yerleştiriyoruz

                {
                    quit = true; // Cikis Yapıyoruz
                    
                }

        }

       if(player->y == numberOfLanes - 1) // Arabaları map de yerleştiriyoruz

       {

           score++; // Skor
           player->y = 0; // Oyuncu konumu
           cout<<"Score: "<<score<<endl; // Skor
           map[rand() % numberOfLanes]->ChangeDirection(); // Yon degistirme
           
       }

    }
   
    void Run()

    {

        while(!quit) // Kosula'a esit degilse

        {

            Input();
            Draw();
            Logic();

        }
    }


};

int main()

{
    system("color B");
    srand(time(NULL));
    cGame game(40,10);
    game.Run();
    cout<<"Game Over!"<<endl;
    getchar();
    return 0;

}
