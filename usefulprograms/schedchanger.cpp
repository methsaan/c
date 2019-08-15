#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream file;
	ofstream file2;
	string wantedpdbr;
	string wantedsched;
	string wantedsubject;
	string wanteddate;
	string wantedschedtype;
	cout << "Enter PD/break schedule: ";
	getline(cin, wantedpdbr);
	cout << "Enter schedule number: ";
	getline(cin, wantedsched);
	cout << "Enter subject: ";
	getline(cin, wantedsubject);
	cout << "Enter date (index): ";
	getline(cin, wanteddate);
	cout << "Timed or regular (timed=1, regular=0): ";
	getline(cin, wantedschedtype);
	file.open("schedfile", ios::in);
	string filelines[] = {"", "", "", "", ""};
	char ch;
	string s;
	for (int x = 0; !file.eof();) {
		file >> noskipws >> ch;
		if (ch != '\n') {
			s = ch;
			filelines[x] += s;
		}else {
			x++;
		}
	}
	file.close();
	file2.open("schedfile");
	file2 << wanteddate << endl;
	file2 << stoi(wantedpdbr.substr(wantedpdbr.length()-1, 1))-1 << endl;
	file2 << stoi(wantedsched.substr(wantedsched.length()-1, 1))-1 << endl;
	file2 << wantedschedtype << endl;
	file2 << wantedsubject << endl;
	file2.close();
}
