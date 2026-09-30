//Playlist.cpp

#include "Playlist.h"

PlaylistNode::PlaylistNode()
{
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string uID, string sName, string aName, int sLength)
{
	uniqueID = uID;
	songName = sName;
	artistName = aName;
	songLength = sLength;
	nextNodePtr = 0;
}

void PlaylistNode::PrintPlaylistNode()
{
	cout << "Unique ID: " << GetID() << endl;
	cout << "Song Name: " << GetSongName() << endl;
	cout << "Artist Name: " << GetArtistName() << endl;
	cout << "Song Length (in seconds): " << GetSongLength() << endl;
}