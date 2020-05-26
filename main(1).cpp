#include <iostream>
using namespace std;

class Human {
protected:
	char* Name;
public:
	Human(const char* name) {
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
	}
	Human(const Human &human) {
		Name = new char[strlen(human.Name) + 1];
		strcpy(Name, human.Name);
	}
	void SetName(const char* name) {
		delete Name;
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
	}
	char* GetName() {
		return Name;
	}
	virtual void Clear() {
		delete Name;
		Name = new char[7];
		strcpy(Name, "NoName");
	}
	virtual void Print() {
		cout << "Name: " << Name << endl;
	}
	~Human() {
		if (Name != nullptr) {
			delete Name;
			Name = nullptr;
		}
	}
};

class Player : public Human {
protected:
	int number;
public:
	Player(const char* name, int number) : Human(name) {
		if (number < 0) {
			throw "Number less then zero!";
		}
		this->number = number;
	}
	Player(const Player& player): Human(player) {
		if (number < 0) {
			throw "Number less then zero!";
		}
		this->number = player.number;
	}
	void SetNumber(int number) {
		if (number < 0) {
			throw "Number less then zero!";
		}
		this->number = number;
	}
	int GetNumber() {
		return number;
	}
	 void  Clear() override {
		 Human::Clear();
		 number = 0;
	 }
	 void Print() override {
		 Human::Print();
		 cout << "Number: " << number << endl;
	 }
};

class Coach : public Human {
protected:
	bool main;
public:
	Coach(const char* name, bool main) : Human(name) {
		this->main = main;
	}
	Coach(const Coach& coach) : Human(coach) {
		main = coach.main;
	}
	void SetMain(bool main) {
		this->main = main;
	}
	bool GetMain() {
		return main;
	}
	void Clear() override {
		Human::Clear();
		main = false;
	}
	void Print() override {
		Human::Print();
		cout << "Main coach: " << main << endl;
	}
};

class PlayingCoach : public Player, public Coach {
protected:
	char* team;
public:
	PlayingCoach(const char* name, int number, bool main, const char* team) :Player(name, number), Coach(name, main) {
		this->team = new char[strlen(team) + 1];
		strcpy(this->team, team);
	}
	PlayingCoach(const PlayingCoach& playingcoach) :Player(playingcoach), Coach(playingcoach) {
		this->team = new char[strlen(team) + 1];
		strcpy(this->team, team);
	}
	~PlayingCoach() {
		if (team != nullptr) {
			delete team;
			team = nullptr;
		}

	}
	void SetTeam(const char* team) {
		delete this->team;
		this->team = new char[strlen(team) + 1];
		strcpy(this->team, team);
	}
	char* GetTeam() {
		return team;
	}
	void Clear() override {
		Human::Clear();
		Coach::Clear();
		Player::Clear();
		delete this->team;
		this->team = new char[7];
		strcpy(this->team, "NoTeam");
	}
	void Print() override {
		Human::Print();
		cout << "Number: " << GetNumber() << endl;
		cout << "Main coach: " << GetMain() << endl;
		cout << "Team: " << team << endl;
	}
	void SetName(const char* name) {
		Human::SetName(name);
	}
	char* GetName() {
		return Human::GetName();
	}
};

int main() {
	
	Human human("Alex");
	human.Print();
	cout << endl << endl;


	Player player("John", 251);
	player.Print();
	cout << endl << endl;

	Coach coach("Tom", true);
	coach.Print();
	cout << endl << endl;

	PlayingCoach playingCoach("Boobs", 22, false, "New-York");
	playingCoach.Print();
	cout << endl << endl;
	playingCoach.Clear();
	playingCoach.Print();
	cout << endl << endl;

	playingCoach.SetName("Felix");
	playingCoach.SetNumber(251);
	playingCoach.SetMain(true);
	playingCoach.SetTeam("Lviv");
	playingCoach.Print();
	cout << endl << endl;

	Coach newCoach(playingCoach);
	newCoach.Print();
	cout << endl << endl;
	system("pause");
	return 0;
}