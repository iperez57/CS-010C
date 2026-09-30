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
