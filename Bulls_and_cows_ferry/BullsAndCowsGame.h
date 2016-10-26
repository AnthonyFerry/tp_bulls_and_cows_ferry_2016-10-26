/**
 * Voici le fichier d'entête de la classe BullsAndCowsGame contenant tous les prototypes des méthodes de celle-ci.
 */

#pragma once
#include <iostream>
#include <string>

// Structure permettant de compter le nombre de Bulls et de Cows.
typedef struct SCount {
	int bulls, cows;
}SCount;

// Enum permettant de connaitre de connaitre le status du jeu.
enum gameStatus {
	invalidStatus,
	ok,
	notIsogram,
	wrongLength,
	notLowerCase
};

class BullsAndCowsGame
{
private: 
	int _myCurrentTry = 0;
	std::string _myHiddenWord;
	bool _gameIsWon = false;
	SCount _count;

public:
	//Constructeur et destructeur
	BullsAndCowsGame(std::string hiddenWord);
	~BullsAndCowsGame();

	//Mutateurs
	int myCurrentTry(void) const;
	std::string myHiddenWord(void) const;
	bool gameIsWon(void) const;
	int bullsCount(void) const;
	int cowsCount(void) const;

	void setMyCurrentTry(int value);
	void addCurrentTry(void);
	void setMyHiddenWord(std::string value);
	void setGameIsWon(bool value);
	void setBullsCount(int value);
	void setCowsCount(int value);

	//Methodes

	//Affiche l'écran d'accueil du jeu.
	void titleScreen(void) const;

	//Ecran de continue
	char continuSreen(void);

	//Ecran des règles.
	void rulesScreen(void);

	//Retourne le nombre maximum d'essais possible.
	int getMaxTries(void) const;

	//Retourne le nombre de coup restant
	int getRemainigTries(void) const;

	//Retourne si la chaine saisie par le joueur est conforme.
	int checkInput(std::string value);

	//Verifie si l'input est un isogramme.
	bool isIsogram(std::string value) const;

	//Vérifie si le mot ne contient aucune majuscule
	bool isLowerCase(std::string value) const;

	//Retourne le message d'erreur lié à l'input.
	std::string getStatusError(int value) const;

	//Compare l'input avec le mot caché.
	void compareWords(std::string value);
};