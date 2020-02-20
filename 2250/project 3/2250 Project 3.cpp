//============================================================================
// Name        :Brandon London 2250.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Horse race.ccp
//============================================================================
#include <iostream>
#include<cstdlib>
#include<limits>
using namespace std;
class Horse
{
private:
	string name;
	string rider;
	int maxRunningDistPerSecond;
	int distanceTraveled;
	int raceWon;
public:
	Horse(string hname, string rname) {
		name = hname;
		rider = rname;
		maxRunningDistPerSecond = rand() % 100 + 1;
		distanceTraveled = 0;
		raceWon = 0;
	}
	int distanceCover() {
		return distanceTraveled;
	}
	void runASecond() {
		distanceTraveled += maxRunningDistPerSecond;
	}
	void win()
	{
		raceWon += 1;
	}
	int hasWon() {
		return raceWon;
	}
	void sendToGate() {
		distanceTraveled = 0;
	}
	string getHorseName() {
		return name;
	}
	void displayHorse(int goalLength) {
		if (distanceTraveled > goalLength) {
			cout << "|";
			for (int i = 0; i < goalLength; i++)
				cout << " ";
			cout << "|>" << rider << endl;
		}
		else {
			cout << "|";
			for (int i = 0; i < goalLength; i++) {
				if (i == distanceTraveled)
					cout << ">";
				else
					cout << " ";
			}
			cout << "| " << name << ", ridden by " << rider << endl;
		}
	}

};
int main() {
	int n;
	cout << "How many horse are in the race:";
	do {
		cin >> n;
	} while (n <= 0 && (cout << "Please Enter Valid number of Horse:"));
	Horse *arr[n];
	string hname;
	string rname;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < n; i++) {
		cout << "please give me the name of horse " << i + 1 << ":";
		getline(cin, hname);
		cout << "please give me the name of rider " << i + 1 << ":";
		getline(cin, rname);
		arr[i] = new Horse(hname, rname);
	}
	int goalLength;
	char ch;
	int winner = -1;
	bool flag = false;
	int noOfRace = 1;
	bool start = true;
	do {
		if (start)
		{
			cout << "Please enter the distance of the race:";
			do {
				cin >> goalLength;
			} while (goalLength <= 0
					&& (cout << "Please enter valid distance of race:"));
			cout << "The start:" << endl;
			for (int i = 0; i < n; i++)
				arr[i]->displayHorse(goalLength);
			start = false;
		} else {
			for (int i = 0; i < n; i++) {
				arr[i]->runASecond();
				arr[i]->displayHorse(goalLength);
				int x = arr[i]->distanceCover();
				if (x > goalLength) {
					flag = true;
					winner = i;
				}
			}
			if (flag) {
				arr[winner]->win();
				for (int i = 0; i < n; i++) {
					cout << arr[i]->getHorseName() << " has won "
							<< arr[i]->hasWon() << "/" << noOfRace
							<< " races.\n";
					arr[i]->sendToGate();
					start = true;
				}
				noOfRace++;
			}
		}
		cout << "\nDo you wish to continue(y/n)?:";
		cin >> ch;
	} while (ch == 'y');
	return 0;
}
