#include <iostream>
#include <string>
#include <vector>

using namespace std;

class databaseInfo {
public:
	vector<string> tableClasses = { "druid", "mage", "warlock", "roge", "paladin" };
	int tableStatusClass[5][2] = { {50, 20}, {40, 30}, {30, 40}, {45, 15}, {80, 10} };

	//validades if class exist in game
	bool Table_classExist(string playClass) {

		string test;


		for (int i = 0; i < tableClasses.size(); i++) {
			if (playClass == tableClasses[i]) {
				return true;
			}
		}
		if (playClass == "") {
			return false;
		}
		else {
			system("cls");
			cout << "INVALID CLASS" << endl << endl;
			return false;
		}
	}

	void Table_outputOptions() {
		cout << "Classes in game:" << endl;

		for (int i = 0; i < tableClasses.size(); i++) {
			cout << " > " << tableClasses[i] << endl;
			cout << "   - Life: " << tableStatusClass[i][0] << endl;
			cout << "   - Damage: " << tableStatusClass[i][1] << endl << endl;
		}
	}
};

class playerChar : public databaseInfo{

private:
	string playClass, playName;
	int playLife = 0, playDamage = 0;
	int playXP = 0;

public:
	void Player_defineClass(string playClass) {
		this->playClass = playClass;
	}

	//eliminate player
	void Player_kill() {
		playClass = "";
		playLife = 0, playDamage = 0;
	}

	//checks if player has name and life
	bool Player_isAlive() {
		if (playClass == "" && playLife == 0) {		//player alive = true
			return false;
		}
		else {
			return true;
		}
	}

	//print
	void Player_printInfo() {
		//system("cls");
		cout << "Name: " << playName << endl;
		cout << "Class: " << playClass << endl;
		cout << "Life: " << playLife << endl;
		cout << "Damage: " << playDamage << endl;
	}
};

void MENUbuild() {
	cout << "Wellcome to the game, just choose a class from the list below and start playing" << endl << endl;
}

int MENUOptions() {

	int op;

	system("cls");
	cout << "Wellcome to the game" << endl;
	cout << "1 - Create new character" << endl;
	cout << "2 - Play (if no character is selected, a random one will be given)" << endl;
	cout << "3 - Credits" << endl;
	cin >> op;
	cin.clear();

	if (op > 3 or op < 1) {
		return 0;
	}
	return op;
}

void MENU(playerChar * player) {
	
	string initClass = "";
	int menuOptionSelected = 0;

	while (true) {
		menuOptionSelected = MENUOptions();
		if (menuOptionSelected != 0) {
			break;
		}
	}

	switch (menuOptionSelected) {
	case 1:
		while (!player->Table_classExist(initClass)) {
			system("cls");
			player->Table_outputOptions();
			cin >> initClass;
			cin.clear();
		}
		player->Player_defineClass(initClass);
		MENU(player);										//returns to main menu choose

		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}

int main() {
	playerChar player;

	MENU(&player);

}