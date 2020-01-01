//playlist.cpp
//defining class functions

#include <iostream>
#include <sstream>
#include <vector>
#include "playlist.h"
using namespace std;

//////////////////////////////////////
///////playlist implementation////////
//////////////////////////////////////

//constructor
playlist::playlist(vector<string> new_array) {
	int i = 0;
	while(i < new_array.size()) {
		add_song(new_array[i]);
		i++;
	}
}

//empty constructor
playlist::playlist() {

}

//copy constructor
playlist::playlist(playlist& copy) {
	array.clear();

	int i = 0;
	while(i < copy.getSize()) {
		add_song(copy.getSong(i));
		i++;
	}
}

//destructor
playlist::~playlist() {
	array.clear();
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//access song
string playlist::getSong(int indx) {
	return array[indx];
}

//access playlist size
int playlist::getSize() {
	return array.size();
}

//checks if song already exists
bool playlist::doesSongNameExist(string song_to_add) {
	//iterate through array
	int i = 0;
	while(i < array.size()) {
		//compare song_to_add to current song_name

		if(array[i] == song_to_add) {
			return true;
		}
		i++;
	}
	return false;
}

//checks if a song exists based on indx
bool playlist::doesSongIndxExist(int indx) {
	if(indx > 0 && indx <= array.size()) {
		return true;
	}
	else {
		return false;
	}
}

//display playlist
void playlist::display() {
	int i = 0;
	while(i < array.size()) {
		cout << i << ": " << array[i] << endl;
		i++;
	}
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//add song
void playlist::add_song(string song_name) {
	//check if song already exists
	if(doesSongNameExist(song_name)) {
		cout << "can not insert " << song_name << endl;
	}
	//add song to end of list
	else {
		array.push_back(song_name);
		cout << "success" << endl;
	}
}

//play song
void playlist::play_song(int indx) {
	//check if song exists
	if(doesSongIndxExist(indx)) {
		//play song
		cout << "played " << indx << " " << array[indx-1] << endl;
	}
	else {
		cout << "could not play " << indx << endl;
	}
}

//remove song
void playlist::remove_song(int indx) {
	if(doesSongIndxExist(indx)) {
		array.erase(array.begin()+indx-1);
		cout << "success" << endl;
	}
	else {
		cout << "could not erase " << indx << endl;
	}
}