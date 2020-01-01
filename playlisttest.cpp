//playlisttest.cpp
//driver file

#include <iostream>
#include <sstream>
#include <vector>
#include "playlist.h"
using namespace std;


string processSong(string input) {
	string name = input.erase(0, 2);

	//remove a vertical tab (ascii 13) at the end if there is one
	if(name[name.size()-1] == 13) {
		name.erase(name.begin()+name.size()-1);
	}

	return name;
}

int processIndx(string input) {
	string indx = input;
	
	indx.erase(0,2);
	if(indx[indx.size()-1] == 13) {
		indx.erase(indx.begin()+indx.size()-1);
	}
	
	int number;
	std::istringstream iss (indx);
	iss >> number;
	if(iss.fail()) {
		cout << "something wrong happened" << endl;
	}
	return number;
}

int main() {
	
	string input;
	playlist Chungs_Playlist;


	getline(cin, input);
	while(!input.empty()) {

		//detect i
		if(input[0] == 'i') {
			//cout << "inserting " << processSong(input) << endl;
			Chungs_Playlist.add_song(processSong(input));
		}

		//detect p
		if(input[0] == 'p') {
			//cout << "playing " << processSong(input) << endl;
			Chungs_Playlist.play_song(processIndx(input));
		}

		//detect e
		if(input[0] == 'e') {
			//cout << "removing " << processSong(input) << endl;
			Chungs_Playlist.remove_song(processIndx(input));
		}

		input.clear();
		getline(cin, input);
	}

	return 0;
}