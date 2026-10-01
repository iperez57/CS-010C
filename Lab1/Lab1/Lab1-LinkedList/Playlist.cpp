//Playlist.cpp

#include "Playlist.h"

PlaylistNode::PlaylistNode()
{
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string uID, string sName, string aName, int sLength)
{
	uniqueID = uID;
	songName = sName;
	artistName = aName;
	songLength = sLength;
	nextNodePtr = nullptr;
}
void PlaylistNode::InsertAfter(PlaylistNode* node)
{
	node->SetNext(this->GetNext());
	this->SetNext(node);
}
void PlaylistNode::SetNext(PlaylistNode* node)
{
	nextNodePtr = node;
}

string PlaylistNode::GetArtistName()
{
	return artistName;
}
string PlaylistNode::GetID()
{
	return uniqueID;
}
string PlaylistNode::GetSongName()
{
	return songName;
}
int PlaylistNode::GetSongLength()
{
	return songLength;
}
PlaylistNode* PlaylistNode::GetNext()
{
	return nextNodePtr;
}


void PlaylistNode::PrintPlaylistNode()
{
	cout << "Unique ID: " << GetID() << endl;
	cout << "Song Name: " << GetSongName() << endl;
	cout << "Artist Name: " << GetArtistName() << endl;
	cout << "Song Length (in seconds): " << GetSongLength() << endl;
}