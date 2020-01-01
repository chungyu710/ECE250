//playlist.h
//declaring classes

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class playlist {
private:
	vector<string> array;

public:
	//constructor
	playlist(vector<string> new_array);

	//empty constructor
	playlist();

	//copy constructor
	playlist(playlist& copy);

	//destructor
	~playlist();

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

	//access song
	string getSong(int indx);

	//access playlist size
	int getSize();

	//checks if a song exists based on song name
	bool doesSongNameExist(string song_to_add);

	//checks if a song exists based on indx
	bool doesSongIndxExist(int indx);

	//display playlist
	void display();

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

	//add song
	void add_song(string song_name);

	//play song
	void play_song(int indx);

	//remove song
	void remove_song(int indx);
};