// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"




UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void ProcessGuess(const FString& Guess);
	void Hint(const FString& Word) const;
	void GetBullsCows(const FString& Guess) const;
	void SetupGame();
	// Your declarations go below!

	
private:
	
	
	FString HiddenWord;
	int32 PlayerLives;
	int32 PlayerTrys;
	FString HiddenWords;
	bool bGameOver;
	
};
