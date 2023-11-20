#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Stats
{
	int LIFE;
	int DAMAGE;
};

class databaseInfo {
public:
	map < string, Stats> ClassMap = { 
		{"druid", {50, 20}},
		{"mage", {40, 30}}, 
		{"warlock", {30, 40}}, 
		{"roge", {45, 15}},
		{"paladin", {80, 10}} };
	vector<string> tableClasses = { "druid", "mage", "warlock", "roge", "paladin" };
	int tableStatusByClass[5][2] = { {50, 20}, {40, 30}, {30, 40}, {45, 15}, {80, 10} }; //{LIFE, DAMAGE}

	//validades if class exist in game
	bool Table_classExist(string playClass) {

		if (ClassMap.find(playClass) == ClassMap.end()) {
			return false;
		}
		else {
			return true;
		}
		/*for (int i = 0; i < tableClasses.size(); i++) {
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
		}*/
	}

	void Table_outputOptions() {
		
		cout << "Classes in game:" << endl;

		for (const auto& i : ClassMap) {
			cout << " > " << i.first << endl;
			cout << "   - Life: " << i.second.LIFE << endl;
			cout << "   - Damage: " << i.second.DAMAGE << endl << endl;
		}
	}
};

class playerChar : public databaseInfo{

private:
	string playClass, playName;
	int playLife = 0;
	int	playDamage = 0;
	int playXP = 0;

public:
	//choosing a name for the character
	void Player_defineName() {
		
		string holderName;
		string confirmYN = "";
		
		while (confirmYN != "yes") {
			
			system("cls");
			cout << "Choose a name for the character: " << endl;
			getline(cin, holderName);

			system("cls");
			cout << "Confirm this name: " << holderName << endl;
			cout << "[yes][no]" << endl;
			cin >> confirmYN;
			cin.ignore();
		}
		
		playName = holderName;

	}
	
	//shows all possible classes, makes you choose one and go to setting all up for the game
	void Player_defineClass() {
		
		string holderClassChoosen = "";

		while (!Table_classExist(holderClassChoosen)) {
			
			system("cls");

			Table_outputOptions();

			cin >> holderClassChoosen;
			cin.clear();
		}

		playClass = holderClassChoosen;
		Player_setupStats();
	}

	//informs the status of each variable of the player object
	void Player_setupStats() {

		playLife = ClassMap[playClass].LIFE;
		playDamage = ClassMap[playClass].DAMAGE;

		/*int i;

		for (i = 0; i < tableClasses.size(); i++) {
			if (playClass == tableClasses[i]) {
				break;
			}
		}
		playLife = tableStatusByClass[i][0];
		playDamage = tableStatusByClass[i][1];*/
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
		system("cls");
		cout << "Name: " << playName << endl;
		cout << "Class: " << playClass << endl;
		cout << "Life: " << playLife << endl;
		cout << "Damage: " << playDamage << endl;
		system("pause");
	}
};

//class EnemyChar {
//public:
//	string playType;
//	int playLife;
//	int	playDamage;
//	int playXP;
//
//};

void MENUbuild() {
	cout << "Wellcome to the game, just choose a class from the list below and start playing" << endl << endl;
}

void MENUCredits() {
	system("cls");
	cout << "Developed by Reithe" << endl;
	cout << "This is a study project to show use of classes and objects" << endl;
	system("pause");
}

int MENUOptions() {

	int op = 0;

	while (op > 4 or op < 1) {
		system("cls");
		cout << "Wellcome to the game" << endl;
		cout << "1 - Create new character" << endl;
		cout << "2 - Character information" << endl;
		cout << "3 - Play (if no character is selected, a random one will be given)" << endl;
		cout << "4 - Credits" << endl;
		cin >> op;
		cin.ignore();
	}
	
	return op;
}

void MENU(playerChar * player) {

	switch (MENUOptions()) {
	case 1:
		player->Player_defineName();
		player->Player_defineClass();
		MENU(player);
		break;
	case 2:
		player->Player_printInfo();
		MENU(player);
		break;
	case 3 :
		break;
	case 4:
		MENUCredits();
		MENU(player);
		break;
	default:
		break;
	}
}

int main() {
	playerChar player;

	MENU(&player);

}