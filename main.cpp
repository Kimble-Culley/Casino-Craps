#include <iostream>
#include <iomanip>

using namespace std;

void print_menu(int current_point, float player_balance, bool active_game);

int main(){


  float player_balance = 500;
  int min_bet = 10, max_bet = 200;
  int current_point = 8;
  bool active_game = false;

  print_menu(current_point,player_balance,active_game);
  

  current_point = 5;
  player_balance = 40;
  print_menu(current_point,player_balance,active_game);

  return 0;
}


void print_menu(int current_point, float player_balance,bool active_game){
  cout << setw(22) << "Don't" << endl;
  cout << "   Point   Come   Come" << endl;
  cout << "   =====  =====  =====" << endl;

  string points[6] = {"4","5","Six","8","Nine","10"};
  int num_points[6] = {4,5,6,8,9,10}; 

  for(int i = 0; i < 6; i++){
    if(current_point == num_points[i]){
      cout << "On" << setw(6) << points[i] << endl;
    }else{
    cout << setw(8) << points[i] << endl;
    }
  }
  cout << endl;

  cout << "Don't Come:" << endl;
  cout << setw(11) << "Come:" << endl;
  cout << "Don't Pass:" << endl;
  cout << setw(11) << "Pass:" << endl;

  cout << "Chips Balance: $" << player_balance << endl;
  cout << endl;
  //make pre active game function
  if(active_game != true){
    cout << setw(12) << "Bet Menu" << endl;
    cout << "1.) Bet Pass Line" << endl;
    cout << "2.) Bet Don't Pass Line" << endl;
    cout << "3.) Roll the Dice" << endl;
    cout << "4.) Quit" << endl;
    cout << "Your Choice? ";
  }

  //make active game function

}
