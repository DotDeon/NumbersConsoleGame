#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std:: cout << "\n\nYou're a developer, trying to help your mother remember all her passwords. Let's do number " << Difficulty << std:: endl;;
    std:: cout << "You need to enter the numbers codes to continue...(add spaces between your numbers)\n\n";  
}

bool PlayGame(int Difficulty)
{
   
    PrintIntroduction(Difficulty);
    //Declare 3 Number Code
    const int CodeA = rand() % Difficulty + Difficulty ;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" ;
    std::cout << "\n+ The codes add up to :" << CodeSum;
    std::cout << "\n+ The multiply to give :" << CodeProduct << std:: endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check player guess
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std:: cout << "\nWell Done, Lets move on";
        return true;
    }
    else
    {
        std:: cout << "\nPlease try again!";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //Create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty  = 5;
    while(LevelDifficulty <= MaxDifficulty) //Loop game untill all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if(bLevelComplete)
        {
          ++LevelDifficulty;
        }
        else
        {

        }
    }
    std:: cout << "\nWell done, you completed the game!";
    return 0;
}


//Run Game using these commands 
// cl NumbersConsoleGame.cpp /EHsc
// NumbersConsoleGame.exe