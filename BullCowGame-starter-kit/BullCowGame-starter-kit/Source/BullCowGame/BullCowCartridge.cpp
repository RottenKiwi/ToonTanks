// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordsList.h"




void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); //Initiatation game (Trys and hiddenword)
 

    
    
    PrintLine(TEXT("You have: %i trys"), PlayerLives);
    PrintLine(TEXT(" Hidden word containing: %i"),  HiddenWord.Len());
   // PrintLine(TEXT(" Hidden word : %s"), HiddenWord);
    PrintLine(TEXT("Characters.  guess it ....\n For hint type /hint "));
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
  
    ClearScreen();
    
    
    
    PrintLine(TEXT("You lives: %i "),PlayerLives);
    

    if (!bGameOver) {
        ProcessGuess(Input);
    }
    else
    {
        PrintLine(TEXT("Game has ended...."));
        PrintLine(TEXT("Would you like to play again?"));
        PrintLine(TEXT("Press Y/N "));
        if (Input == "Y" && "n") {
            SetupGame();
            ClearScreen();
            PrintLine(TEXT("Welcome to guess the word "));
            PrintLine(TEXT("You have: %i trys"), PlayerLives);
            PrintLine(TEXT(" We chose a random  word containing: %i"), HiddenWord.Len());
            PrintLine(TEXT("Characters. \n guess it ...."));
            PlayerLives--;
        }
        if (Input == "N" && "n") {
            bGameOver = true;
            PrintLine(TEXT("Thanks for playing..."));

        }
    }
    
   
   
}
void UBullCowCartridge::SetupGame() {
    
    


   
        HiddenWord = HiddenWordsList[rand() % 7];//init hiddinWord
        PlayerLives = 10;//INIT PlayerLives  w
        bGameOver = false;
    
   
        
}


void UBullCowCartridge::Hint(const FString& Word) const {

    TCHAR FirstChar = Word[0];
    TCHAR SecondChar = Word[Word.Len() -1];
    PrintLine(TEXT("first character of the hidden word is %c \n"), FirstChar);
    PrintLine(TEXT(" last character of the hidden word is %c "), SecondChar);
   
    

    

}

void UBullCowCartridge::ProcessGuess(const FString& Guess) {

    if (Guess == "/hint") {
        Hint(HiddenWord);
    }

    if (PlayerLives != 0)
    {
        
        GetBullsCows(Guess);
        

        if (HiddenWord == Guess) {
            PrintLine(TEXT("Good job , you are right!"));
            PrintLine(TEXT("Press enter to continue..."));
            bGameOver = true;

        }
        else {
            

            PrintLine(TEXT("Incorrect guess, try again..."));
            
            PlayerLives--;
            if (Guess.Len() != HiddenWord.Len()) {
                PrintLine(TEXT("You've entered incorrect number of characters."));
                if (Guess.Len() > HiddenWord.Len()) {
                    PrintLine(TEXT("Guess has %i extra characters.."), Guess.Len() - HiddenWord.Len());                  
                }
                if (Guess.Len() < HiddenWord.Len()) {
                    PrintLine(TEXT("Guess is missing %i more characters.."), HiddenWord.Len() - Guess.Len());
                }
            }
            
            

        }

    }
    else {
        PrintLine(TEXT("Out of tries..."));
        PrintLine(TEXT("Do you wish to try agian? Y/N and enter..."));
        if (Guess == "Y" && "n") {
            SetupGame();
            ClearScreen();
            PrintLine(TEXT("Welcome to guess the word "));
            PrintLine(TEXT("You have: %i trys"), PlayerLives);
            PrintLine(TEXT(" We chose a random  word containing: %i"), HiddenWord.Len());
            PrintLine(TEXT("Characters. \n guess it ...."));
            PlayerLives--;
        }
        if (Guess == "N" && "n") {
            bGameOver = true;
            PrintLine(TEXT("Thanks for playing..."));

        }
    }

}

void UBullCowCartridge::GetBullsCows(const FString& Guess) const
{

int32 BullCount = 0;
int32 CowCount = 0;

//if the index guess is same as index , bullocunt++;
//if not a bull was it a cow, if yes, CowCount++;

for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
{
    if(Guess[GuessIndex] == HiddenWord[GuessIndex])
    {
        BullCount++;
        continue;
    }
    for (int32 HiddenIndex= 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
    {
       if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
       {
           CowCount++;
       }
       
    }
    
}

PrintLine(TEXT("You have %i Bulls and %i Cows"),BullCount, CowCount);

}