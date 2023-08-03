#include <iostream>
#include <cstdlib>

using namespace std;

//#DRBC The game of NIM
//#DRBC  Akhil Karri

int myRand ()  // Generate a 4 digit pseudo-random integer 
{ 
  static int next = 3251 ; 
  next = ((next * next) / 100 ) % 10000 ; 
  return next ; 
}

int main() {
    int choice = 1;

    while (choice == 1) {
       int n_obj = 32;
       int cur_pl = 1;
       int move;

       cout << "Welcom to Nim Game.\n You have 32 objects.\n Enter a number between 1 - 4 to remove them,\n and the computer will remove <4 objects.\n Last man standing wins!\n";
        // ----------- Beginning of the main game loop ----------------
        while (n_obj > 0) {
            
            if (n_obj < 5) {
                cout << "Someone is going to be a winner soon\n";
            }
            
            if (cur_pl == 1) { 
                cout << "Player 1 enter your move (1-4):  ";
                cin >> move; 
                while (move < 1 || move > 4 || move > n_obj) {
                    cout << "Illegal move. \nEnter a new move (1-4): ";
                    cin >> move;
                }
            }
            else { 
                    if (n_obj > 1 && n_obj < 5) {
                        move = n_obj - 1;
                    }
                    else if (n_obj == 1){
                        move = 1;
                    }
                    else {
                         move = 1 + myRand() % 4; // random computer move
                    }

                cout << "Computer removed " << move << endl;
            }
            n_obj = n_obj - move; // implement the move
            int i = 0;
            for(i = 0; i < n_obj; i++) {
                cout << "#";
            }
            cout << " " << n_obj << " objects remaining.\n";
            if (n_obj > 25) {
                cout << "There's still a lot of game left\n";
            }
              
            
            cur_pl = (cur_pl + 1) % 2; // switch players
        } 
        // ------------ end of the game loop --------------------------
        if (cur_pl == 1) {
            cout << "Confgratulations, You won!!!\n";
        }
        else {
            cout << "Sorry, you lost\n";
        }
        cout << "Enter 1 to replay, or any other number to quit: ";
        cin >> choice;
    }
    cout << "\nPress enter to quit.\n";
    return 0;
}
