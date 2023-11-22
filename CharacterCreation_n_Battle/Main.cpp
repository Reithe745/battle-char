#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
//test git files
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

	//validades if class exist in game
	bool Table_classExist(string playClass) {

		if (ClassMap.find(playClass) == ClassMap.end()) {
			return false;
		}
		else {
			return true;
		}
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
	string playClass;
	string playName;
	Stats playStats;
	int playXP = 0;

public:
	//choosing a name for the character
	void Player_defineName() {
		
		string holderName;
		string confirmYN = "";
		
		while (confirmYN != "Y" && confirmYN != "y" && confirmYN != "yes" && confirmYN != "YES") {
			
			system("cls");
			cout << "Choose a name for the character: " << endl;
			getline(cin, holderName);

			system("cls");
			cout << "Confirm this name: " << holderName << endl;
			cout << "[Y][N]" << endl;
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

		playStats.LIFE = ClassMap[playClass].LIFE;
		playStats.DAMAGE = ClassMap[playClass].DAMAGE;

	}

	//eliminate player
	void Player_kill() {
		playClass = "";
		playStats.LIFE = 0, playStats.DAMAGE = 0;
	}

	//checks if player has name and life
	bool Player_isAlive() {
		if (playClass == "" && playStats.LIFE == 0) {		//player alive = true
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
		cout << "Life: " << playStats.LIFE << endl;
		cout << "Damage: " << playStats.DAMAGE << endl;
		system("pause");
	}
};

void MENUbuild() {
	cout << "Wellcome to the game, just choose a class from the list below and start playing" << endl << endl;
}

void MENUCredits() {
	system("cls");
	cout << "Developed by Reithe" << endl;
	cout << "This is a study project to show use of classes and objects" << endl;
	system("pause");
}

void MENU(playerChar * player) {

	int op;

	while (true) {
		system("cls");
		cout << "Wellcome to the game" << endl << endl;
		cout << "1 - Create new character" << endl;
		cout << "2 - Character information" << endl;
		cout << "3 - Play (if no character is selected, a random one will be given)" << endl;
		cout << "4 - Credits" << endl;
		cout << "0 - EXIT" << endl;
		cin >> op;
		cin.ignore();

		switch (op) {
		case 1:
			player->Player_defineName();
			player->Player_defineClass();
			MENU(player);
			break;
		case 2:
			player->Player_printInfo();
			MENU(player);
			break;
		case 3:		//TODO - add game battle mechanic
			MENU(player);
			break;
		case 4:
			MENUCredits();
			MENU(player);
			break;
		default:
			return; //ends program
			break;
		}
	}
}

int main() {
	playerChar player;

	MENU(&player);

}