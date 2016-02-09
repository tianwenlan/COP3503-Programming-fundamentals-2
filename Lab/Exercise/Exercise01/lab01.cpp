#include <iostream>

//You will need these 2 includes for randomness to work
#include <cstdlib>
#include <ctime>

using namespace std;

// You will need to place these functions above main or the
// compiler won't know what they are

// This function returns a random number between 1 and 100
int get_random()
{
  int low = 1;
  int high = 100;
  return low + (rand()%(high-low));
}

void set_up_random()
{
  srand(time(0));
}


// Required to ensure proper randomness. Call this once and only once from the first line in main:
int main()
{
  cout <<"Welcome to the guessing game!";
  cout <<"Enter your guessing number between 0 to 100, and the computer will give you hints whether your guessing number is too high or too low until you got the right answer. ";

  int num, guess;
  char replay;

  set_up_random();


 do{
  num= get_random();

  do{
     cout << "Enter a number to guess:"<<endl;
     cin >> guess;
     if (guess > num)
     cout << "your number is too high, "<<endl;
     else if (guess < num) 
     cout << "your number is too low, "<<endl;
     else if (guess == num) 
     cout << "**Correct!!Congraduations!!**" <<endl;             
     }
  while (guess!=num);

      cout << "Would you like to play again? Enter y/n"<<endl;
      cin >> replay;
      if (replay =='n')
      cout << "Thanks for playing! "<<endl;
     } 

    while(replay == 'y');



  

 }


