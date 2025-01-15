#include <iostream>
#include <iomanip>

using namespace std;

void print_menu(int current_point, float player_balance, bool active_game, float bet_amount);

void pre_menu();

void active_menu();

void game_logic(string &player_choice, float &player_balance, bool &active_game, int &current_point, float &bet_amount);

int dice_logic();

void win_condition(int current_point, bool &active_game, float &bet_amount, int running_point);

int main(){


  float player_balance = 500, bet_amount = 0, bet_pass = 0, bet_dont_pass = 0, bet_come = 0, bet_dont_come = 0;
  int min_bet = 10, max_bet = 200;
  int current_point = 0;
  bool active_game = false;
  string player_choice = "0";

  srand(time(0));

  print_menu(current_point, player_balance, active_game, bet_amount);

  //Start of game loop
  while((active_game == true) || (player_balance >= 9)){
  cin >> player_choice;
  if(player_choice == "4"){
    break;
  }

  game_logic(player_choice, player_balance, active_game, current_point, bet_amount);

  }
  return 0;
}


void print_menu(int current_point, float player_balance, bool active_game, float bet_amount){
  if(active_game != true){
    cout << "Off" << endl;
  }
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


  //Will display the intializing bet menu with pass
  if(active_game != true){
    pre_menu();
  }
  else{
    active_menu();
  }
}


void pre_menu(){
  cout << setw(12) << "Bet Menu" << endl;
  cout << "1.) Bet Pass Line" << endl;
  cout << "2.) Bet Don't Pass Line" << endl;
  cout << "3.) Roll the Dice" << endl;
  cout << "4.) Quit" << endl;
  cout << "Your Choice? ";
}


void active_menu(){
  cout << setw(12) << "Bet Menu" << endl;
  cout << "1.) Bet Come" << endl;
  cout << "2.) Bet Don't Come" << endl;
  cout << "3.) Roll the Dice" << endl;
  cout << "4.) Quit" << endl;
  cout << "Your Choice? ";
}


void game_logic(string &player_choice, float &player_balance, bool &active_game, int &current_point, float &bet_amount){
  int running_point = 0;
 
 
  if(player_choice == "1"){
    cout << "You have $" << player_balance << ". How much do you wish to bet? ";
    cin >> bet_amount;
    player_balance -= bet_amount;
    if(active_game != true){
      pre_menu();
    }
    if(active_game == true){
      active_menu();
    }
  }
  else if(player_choice == "2"){
    cout << "You have $" << player_balance << ". How much do you wish to bet? ";
    cin >> bet_amount;
    player_balance -= bet_amount;
    if(active_game != true){
      pre_menu();
    }
    if(active_game == true){
      active_menu();
    }
  }
  else if(player_choice == "3"){
    if(active_game != true){
      current_point = dice_logic();
      cout << current_point;
      cout << running_point;
    }
    else{
      running_point = dice_logic();
      cout << current_point;
      cout << running_point;
    }
    win_condition(current_point, active_game, bet_amount, running_point);
    print_menu(current_point, player_balance, active_game, bet_amount);
    

  }
  else{
    cout << "Unknown option selected, please type 1,2,3, or 4 ";
  }
}


int dice_logic(){
  int die1 = 0, die2 = 0;

  die1 = rand() % 6 + 1;
  die2 = rand() % 6 + 1;

  return(die1 + die2);
}


void win_condition(int current_point, bool &active_game, float &bet_amount, int running_point){

  if(active_game != true){
    if(current_point == 7 || current_point == 11){
      cout << "Shoot has rolled " << current_point << ". Right bettors win." << endl;
      active_game = false;
    }
    else if(current_point == 2 || current_point == 3 || current_point == 12){
      cout << "Shoot has rolled " << current_point << ". Wrong bettors win." << endl;
      active_game = false;
    }
    else{
      active_game = true;
      cout << "On " << current_point << endl;

    }
  }
  else{
    if(current_point == running_point){
      cout << "Point is reached! Right bettors win." << endl;
      active_game = false;
    }
    else if(running_point == 7){
      cout << "Seven out! Shooter retires. Wrong bettors win." << endl;
      active_game = false;
    }
  }

}