#include<iostream>
#include<cstdlib>
#include<ctime>


int main()
{
  // first to generate a random number 
  // with a help of built in librarary ctime 

  std::srand(std::time(0));

  int random_number_var = std::rand() % 100 + 1; // by performing modulus by 100 and adding one to it makes the random number come under the range 100

  int guess = 0;//intially guess variable is set to zero 

  std::cout<<"I have generated a random number which is in the range between 1 and 100."<<std::endl;
  std::cout<<"Can you guess the number ?"<<std::endl;

  // to accpet the guess from the user 
  // i am gonna generate a loop
  while(guess != random_number_var)
    {
      std::cout<<"ENTER YOUR GUESS: ";
      std::cin>>guess; // get the input and store it in guess variable now the guess varible is changed from 0 to value input from user

      // using conditinal statements to check if guess is close to random number generated


      if(guess <  random_number_var)
      {
        std::cout<<"Your guess is too low.TRY higher value"<<std::endl;
      }
      else if(guess >  random_number_var)
      {
         std::cout<<"Your guess is too high.TRY lower value"<<std::endl;
      }
      else
      {
        std::cout<<"AWESOME! YOU GUESSED THE CORRECT VALUE."<<std::endl;
      }
    }//loop ends when the right number is guessed

    return 0;
}
