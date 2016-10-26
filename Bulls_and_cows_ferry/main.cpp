/**
 * Ceci est le programme du jeu "bulls and cows".
 *
 * Le jeu consiste � deviner un mot (ici inscrit en dur dans le code) dans un nombre limit� d'essais.
 * Une fois que l'utilisateur a	saisi un mot, le programme retourne une r�ponse.
 * Cette r�ponse est sous la forme de "bulls: x, cows: y", "bulls" repr�sentant le nombre de lettres pr�sentes dans le mot ET bien plac�e,
 * "cows" repr�sentant le nombre de lettres pr�sentes dans le mot MAIS pas � la bonne place.
 */

//On include les biblioth�ques utiles pour le programme.
#include <iostream>
#include <string>
#include "BullsAndCowsGame.h"

//On d�fini l'espace de nom que l'on utilisera.
using namespace std;


int main(){

	//On instancie l'objet "game" de la classe BullsAndCowsGame.
	BullsAndCowsGame game("test");

	//Mot entr� par le joueur.
	std::string playerInput;

	//Etat du jeu r�cup�r�.
	int state;

	//Boucle principale du programme.
	do {
		//Initialisation
		game.setMyCurrentTry(0);
		game.setGameIsWon(false);
		
		//On affiche l'�cran titre.
		game.titleScreen();

		//On affiche les regles.
		game.rulesScreen();

		/**
		 * Boucle du jeu.
		 * On boucle tant qu'il nous reste des coups et tant qu'on a pas gagner
		 */
		while (game.getRemainigTries() != 0 && !game.gameIsWon()) {

			cout << "Mot a trouver : " << game.myHiddenWord().length() << " lettres." << endl;
			cout << "Il vous reste " << game.getRemainigTries() << " coup(s) a jouer." << endl << endl;

			cout << "Votre proposition : ";

			//Le joueur entre un mot
			cin >> playerInput;

			//On verifie ce mot et on r�cup�re l'�tat du jeu.
			state = game.checkInput(playerInput);

			//Si le mot n'est pas bon.
			if (state != ok) {
				//On affiche l'erreur.
				cout << game.getStatusError(state) << endl << endl;

				//On ajoute un tour.
				game.addCurrentTry();
			}
			//Sinon
			else {

				//On compare l'input joueur au mot a deviner.
				game.compareWords(playerInput);

				//On affiche les bulls and cows.
				cout << "BULLS : " << game.bullsCount() << " ---------- " << "COWS : " << game.cowsCount() << endl << endl;

				//Si on a autant de bulls que de lettres dans le mot
				if (game.bullsCount() == game.myHiddenWord().length()) {
					
					//On set la victoire a true
					game.setGameIsWon(true);
				}
				else {

					//On ajoute un tour
					game.addCurrentTry();
				}
			}

			system("PAUSE");
			system("cls");
		}

		//Verification de la sortie de boucle et affichage du message de fin de partie.
		if (game.gameIsWon()) {
			cout << "Bravo !! Le mot a deviner etait bien : ";
		}
		else {
			cout << "Zuutt !! Il fallait deviner le mot : ";
		}

		cout << game.myHiddenWord() << endl << endl;

	} while (game.continuSreen() == 'y');

	return 0;
}