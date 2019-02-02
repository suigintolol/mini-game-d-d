#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
 

class unit {
	public:
		unit(string name);

		int get_damage() {
			return damage;
		}

		int get_armor() {
			return armor;
		}

		int get_hitpoint() {
			return hitpoint;
		}

		int get_intellect() {
			return intellect;
		}

		int get_agility() {
			return agility;
		}

		int get_strength() {
			return strength;
		}

		int get_charisma() {
			return charisma;
		}

		int get_luck() {
			return luck;
		}

		int get_moral() {
			return moral;
		}

		int get_speed() {
			return speed;
		}

		string get_name() {
			return name_object;
		}

		void print_skill() {
			cout << name_object <<" skill: \ndamage = " << damage << endl;
			cout << "armor = " << armor << endl;
			cout << "hitpoint = " << hitpoint << endl;
			cout << "intellect = " << intellect << endl;
			cout << "agility = " << agility << endl;
			cout << "strength = " << strength << endl;
			cout << "charisma = " << charisma << endl;
			cout << "luck = " << luck << endl;
			cout << "moral = " << moral << endl;
			cout << "speed = " << speed << endl<< endl;
		}

		~unit();

	private:
		int damage = 1,
			armor = 0,
			hitpoint = 10,
			intellect = 0,
			agility = 0,
			strength = 0,
			charisma = 0,
			luck = 0,
			moral = 0,
			speed = 0,
			znachenie_skillpoint = 0;
		float skillpoint;
		string name_object;

		void create_skillpoint() {
			for (size_t i = 0; i < 4; i++) {
				znachenie_skillpoint += rand() % 25 + 1;
			}
		}

		void raspredelenie_skillpoint() { 
			int max = rand() % 10 + 1;
			int kolvo_ochkov;
			while (znachenie_skillpoint != 0) {
				kolvo_ochkov = rand() % max + 1;
				if (kolvo_ochkov > znachenie_skillpoint) {
					kolvo_ochkov = znachenie_skillpoint;
				}
				switch (rand() % 10+1) {
				case 1:
					damage += kolvo_ochkov;
					break;
				case 2:
					armor += kolvo_ochkov;
					break;
				case 3:
					hitpoint += kolvo_ochkov;
					break;
				case 4:
					intellect += kolvo_ochkov;
					break;
				case 5:
					agility += kolvo_ochkov;
					break;
				case 6:
					strength += kolvo_ochkov;
					break;
				case 7:
					charisma += kolvo_ochkov;
					break;
				case 8:
					luck += kolvo_ochkov;
					break;
				case 9:
					moral += kolvo_ochkov;
					break;
				case 10:
					speed += kolvo_ochkov;
					break;
				default:
					cout << "ERROR create unit";
					break;
				}
				znachenie_skillpoint -= kolvo_ochkov;
			}
		}
};

unit::unit(string name) {
	create_skillpoint();
	raspredelenie_skillpoint();
	name_object = name;
	print_skill();
}

unit ::~unit() {
}

void fite(unit one, unit two) {
	int write_damage_one = one.get_damage() - two.get_armor();
	int write_damage_two = two.get_damage() - one.get_armor();

	if (write_damage_one <= 0 && write_damage_two <= 0) {
		cout << endl << one.get_name() << " & " << two.get_name() << " get tired.\n";
		return;
	}
	else if (write_damage_one <= 0) {
		cout << endl << two.get_name() << " WIN ! " << one.get_name() << " get tired.\n";
	} else if (write_damage_two <= 0) {
		cout << endl << one.get_name() << " WIN ! " << two.get_name() << " get tired.\n";
	} else {
		if (trunc(two.get_hitpoint() / write_damage_one) < trunc(one.get_hitpoint() / write_damage_two)) {
			cout << endl << one.get_name() << " WIN ! " << two.get_name() << " dead :)  )X\n";
		}
		else if (trunc(two.get_hitpoint() / write_damage_one) > trunc(one.get_hitpoint() / write_damage_two)) {
			cout << endl << two.get_name() << " WIN ! " << one.get_name() << " dead X(  (:\n";
		}
		else {
			cout << endl << two.get_name() << " & " << one.get_name() << " dead X(  )X\n";
		}
	}
}

int main() {
	srand(time(NULL));
	unit you("you");
	unit enemy0("crook");
	unit enemy1("goblin");
	unit enemy2("leha");
	unit enemy3("vampire");
	unit enemy4("god");
	
	
	fite(you, enemy0);
	return 0;
}
