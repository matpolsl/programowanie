bool gameover = false;
//Wspó³rzêdne 
int y = 0;
int x = 4;

int ptk = 0;
int block[4][4]{};// Tablica w której przechowywany jest blok
bool newblock = true;
int blocks[7][4][4] = {
    {
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 }
    },
    {
        { 0, 2, 2, 0 },
        { 0, 2, 0, 0 },
        { 0, 2, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 0, 3, 0 },
        { 0, 3, 3, 0 },
        { 0, 3, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 4, 0, 0 },
        { 0, 4, 4, 0 },
        { 0, 0, 4, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 5, 0, 0 },
        { 5, 5, 5, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 6, 6, 0 },
        { 0, 6, 6, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    {
        { 0, 7, 7, 0 },
        { 0, 0, 7, 0 },
        { 0, 0, 7, 0 },
        { 0, 0, 0, 0 }
    }
};
int board[22][12]{}; //Plansza gry
int boardc[22][12]{}; // Kopia planszy przed zapisaniem bloków w ostatecznym po³o¿eniu