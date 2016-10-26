#include "BullsAndCowsGame.h"
#include <string>
#include <map>

//Constructeur de la classe
BullsAndCowsGame::BullsAndCowsGame(std::string hiddenWord)
{
	this->_myHiddenWord = hiddenWord;
}

//Destructeur (ici ne fait rien de particulier)
BullsAndCowsGame::~BullsAndCowsGame()
{
}

//Mutateur des différentes données membres.
/* --------------------------------------------------------------- */
int BullsAndCowsGame::myCurrentTry(void) const {
	return this->_myCurrentTry;
}

std::string BullsAndCowsGame::myHiddenWord(void) const {
	return this->_myHiddenWord;
}

bool BullsAndCowsGame::gameIsWon(void) const {
	return this->_gameIsWon;
}

int BullsAndCowsGame::bullsCount(void) const {
	return this->_count.bulls;
}

int BullsAndCowsGame::cowsCount(void) const {
	return this->_count.cows;
}

void BullsAndCowsGame::setMyCurrentTry(int value) {
	this->_myCurrentTry = (int) value;
}

void BullsAndCowsGame::addCurrentTry(void) {
	this->_myCurrentTry += 1;
}

void BullsAndCowsGame::setMyHiddenWord(std::string value) {
	this->_myHiddenWord = value;
}

void BullsAndCowsGame::setGameIsWon(bool value) {
	this->_gameIsWon = value;
}

void BullsAndCowsGame::setBullsCount(int value) {
	this->_count.bulls = value;
}

void BullsAndCowsGame::setCowsCount(int value) {
	this->_count.cows = value;
}
/* ----------------------------------------------------------------- */

/**
 * void titleScreen(void)
 *
 * Procédure affichant l'écran d'accueil du jeu.
 */
void BullsAndCowsGame::titleScreen(void) const {
	std::cout << "BULLS AND COWS" << std::endl << std::endl;

	std::cout << "                                                          >*" << std::endl;
	std::cout << "                                                   #      >*" << std::endl;
	std::cout << "                                                   #  ###>***~~~~~|" << std::endl;
	std::cout << "                                                   ####  *****^^^#" << std::endl;
	std::cout << "                                              _____|       *#####" << std::endl;
	std::cout << "                                             | ^^^#   \\/ \\/ #" << std::endl;
	std::cout << "                                            ##^^###         |" << std::endl;
	std::cout << "                                             ### ##*        *" << std::endl;
	std::cout << " |_                                ********~~|_____>         *" << std::endl;
	std::cout << " \\|_                 ________************        #>>***    ***" << std::endl;
	std::cout << " \\\\|_             __|     *************        ## >>>*  *****" << std::endl;
	std::cout << " |___  |______   __|         ***********       ##>### ^^^^^^^^^^" << std::endl;
	std::cout << "    |____    |__|           **********       >>>>## ^<^^^^^@^^^^^" << std::endl;
	std::cout << "         #          ***      ********      **>>>># ^<^^@^^^@^^^^^" << std::endl;
	std::cout << "          #      ***********    ******     *>>>## ^<<^^^^^^^^<<<" << std::endl;
	std::cout << "          #      ***********    ******    **>>>## ^<<<<^^^<<<<<" << std::endl;
	std::cout << "         #        *********      ****   ***>>>#### ^<<<<<<<<<" << std::endl;
	std::cout << "         #         **********          ****>>>###### <<<<<" << std::endl;
	std::cout << "         ##        **********          ****>>>>##      ##" << std::endl;
	std::cout << "         ##         **  ***             ****>>>>        #     ##XXX" << std::endl;
	std::cout << "         ##**                            *******         ##>>>>#XX" << std::endl;
	std::cout << "          >>*                             ******         #######XXX" << std::endl;
	std::cout << "          >>*****                           ***         ##__" << std::endl;
	std::cout << "           >>*****   **** ***               **    *****     \\__" << std::endl;
	std::cout << "           >># **    *********              *********>>>#      XXX" << std::endl;
	std::cout << "           ##        *********              *******>>>>>##     XXX" << std::endl;
	std::cout << "        |~~           ********                 *>>>>> >#######XXX" << std::endl;
	std::cout << "    X~~~~ ###          *********          ######>          >>>XXXX" << std::endl;
	std::cout << "  XXX  #>>>##          ********>>##  #######" << std::endl;
	std::cout << "   XXX#>      #   ##>>>>>>>>>>>>>###UUUUU^^" << std::endl;
	std::cout << "   XXX        #  ####>>>>>>>>>>UUUUUUUUU^^" << std::endl;
	std::cout << "              #  >>           UUUUUU^^^<()" << std::endl;
	std::cout << "             #  >              U()^<()  ()" << std::endl;
	std::cout << "           *#  *>               ()  ()" << std::endl;
	std::cout << "          **** #" << std::endl;
	std::cout << "            ***" << std::endl;
	std::cout << "            **" << std::endl << std::endl;

	system("PAUSE");
	system("cls");
}

/**
 * char continuSreen(void)
 *
 * Demande à l'utilisateur de saisir un char et le retourne.
 */
char BullsAndCowsGame::continuSreen(void) {
	char choice;
	
	std::cout << "Voulez vous refaire une partie ? y/n" << std::endl;
	std::cin >> choice;
	system("cls");

	return choice;
}

/**
 * void rulesScreen(void)
 *
 * Procedure affichant les regles du jeu à l'utilisateur.
 */
void BullsAndCowsGame::rulesScreen(void)
{
	std::cout << "Bienvenue dans le jeu du \"Bulls and Cows\" !!!" << std::endl;
	std::cout << "Dans ce jeu vous allez devoir deviner un mot. Apres avoir saisi ce mot, le programme vous indiquera un nombre de 'Bulls' et de 'Cows'" << std::endl;
	std::cout << "Les 'Bulls' representent le nombre de lettre a leur place." << std::endl;
	std::cout << "Les 'Cows' representent le nombre de lettre presentent dans le mot mais au mauvais endroit." << std::endl;
	std::cout << "La partie s'arrete lorsque vous avez trouve le mot ou lorsque vous n'avez plus de coups." << std::endl << std::endl;
	std::cout << "Bonne chance !!!" << std::endl << std::endl;

	system("PAUSE");
	system("cls");

}

/**
 * int getMaxTries(void)
 *
 * Fonction retournant le nombre de coup jouable.
 */
int BullsAndCowsGame::getMaxTries(void) const {
	//Création d'un tableau clés -> valeurs ayant pour clé la longueur du mot et en valeur le nombre de coups à jouer.
	std::map<int, int> WordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[_myHiddenWord.length()];
}

int BullsAndCowsGame::getRemainigTries(void) const {
	return this->getMaxTries() - this->_myCurrentTry;
}

/**
 * bool isIsogram(string)
 * 
 * Fonction déterminant si une chaine de caractères est isogramme.
 * Retourne "true" si c'est le cas et "false" si ça ne l'est pas.
 */
bool BullsAndCowsGame::isIsogram(std::string value) const {

	//Pour chacune des lettres composant notre mot.
	for (int i = 0; i < value.length(); i++) {

		//On vérifie les lettres qui la suivent.
		for (int j = i+1; j < value.length(); j++) {
		
			//Si les deux lettres sont identtiques, on renvoi "false".
			if (value[i] == value[j])
				return false;
		}
	}

	//Sinon on renvoi "true".
	return true;
}

/**
 * bool isLowerCase(string)
 *
 * Fonction retournant "true" si toute les lettres du mot passées en paramètres sont en minuscule.
 */
bool BullsAndCowsGame::isLowerCase(std::string value) const {
	
	//Pour chaque lettres composants le mot.
	for (int i = 0; i < value.length(); i++) {

		//Si elle n'est pas minuscule on retourne "false".
		if (!islower(value[i]))
			return false;
	}

	//Sinon on retourne "true".
	return true;
}

/**
 * int checkInput(string)
 *
 * Fonction déterminant si un mot passé en paramètre est conforme aux règles du jeu.
 */
int BullsAndCowsGame::checkInput(std::string value) {
	
	//On vérifie si le mot ne contient pas de caractères spéciaux ou de numériques.
	if (value.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos)
		return invalidStatus;

	//On vérifie si le mot est à la bonne longueur.
	if (value.length() != this->_myHiddenWord.length())
		return wrongLength;

	//On vérifie si le mot n'est pas un isogramme.
	if (!this->isIsogram(value))
		return notIsogram;

	//On vérifie si le mot est bien en minuscule.
	if (!this->isLowerCase(value))
		return notLowerCase;

	//Si rien n'est vérifier c'est que le mot est valide, on retourne ok
	return ok;
}

/**
 * string getStatusError(int)
 *
 * Fonction retournant un message d'erreur correspondant au code d'erreur passé en paramètre.
 */
std::string BullsAndCowsGame::getStatusError(int value) const {
	std::string err;
	
	switch (value) {
	case invalidStatus:
		err = "Il semblerait que le mot que vous aillez saisi ne soit pas conforme.";
		break;
	case notIsogram:
		err = "Le mot ne doit pas contenir deux fois la meme lettre !";
		break;
	case wrongLength:
		err = "Le mot saisi n'est pas a la bonne longueur.";
		break;
	case notLowerCase:
		err = "Le mot saisi ne doit contenir que des lettres minuscules.";
		break;
	default:
		err = "Il semblerait qu'il y ait une erreur ...";
		break;
	}

	return err;
}

/**
 * void compareWords(string)
 *
 * Compare la chaine de caractères entrées en paramètres avec la chaine à deviner.
 */
void BullsAndCowsGame::compareWords(std::string value) {
	int bulls = 0;
	int cows = 0;

	//Pour chacune des lettres du mot caché.
	for (int i = 0; i < this->_myHiddenWord.length(); i++) {
		
		//Et pour chacune des lettres du mot de l'utilisateur 
		for (int j = 0; j < value.length(); j++) {
			
			//Si elle coincident.
			if(this->_myHiddenWord[i] == value[j]){
				
				//Et si les index sont egaux
				if (i == j) {
					//On ajoute 1 à bulls
					bulls++;
				}
				else {
					//Sinon on ajoute 1 à cows.
					cows++;
				}
			}
		}
	}

	this->setBullsCount(bulls);
	this->setCowsCount(cows);
}