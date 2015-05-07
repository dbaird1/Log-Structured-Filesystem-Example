#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <map>
#include <map>
#include <utility>
#include <pair>
using namespace std;
//returns index of max ele
struct block{
	int type;
	//data only for inode
	int fileId;
	//
	vector <int> inode;
};
block* newBlock(int type, int fileId, vector <int> inode){
	block* retBlock= new block();
	//-1: empty, 0: block, 1: inode, 2: imap
	retBlock->type= type;
	retBlock->fileId= fileId;
	retBlock->inode= inode;
	return retBlock;
}
void updateBlock(block* oldBlock, block* headBlock){
	
}
int main(int argc, char* argv[]){
	ifstream infile;
	int i, numSegments, segSize;
        string inputFile;
	if(argc!=3){
		cout<<"incorrect arguments"<<endl;
		exit(1);
	}
	srand(time(NULL));
	numSegments=atoi(argv[1]);
	segSize=atoi(argv[2]);
	inputFile= argv[3];

	//number of active blocks in segment i
	activeBlocks[numSegments];
	for(i = 0; i < numSegments; i++)
		activeBlocks[i] = 0;

	int numBlocks = numSegments*segSize;
	block* disk[numBlocks];
	for(i=0;i<numBlocks; i++){
		disk[i]->type=-1;	
		disk[i]->fileId=-1;
	}

	infile.open(inputFile);
	string line; 
	bool inFile = true;
	int currWriteBlock, currWriteFile;


	//create and write imap
	int mapLoc = 0;
	map<int,int> imap;
	block * mapBlock;
	mapBlock->type = 2;
	disk[0] = mapblock
	disk[i]->fileId=-1;
	if(infile.is_open())
	{
		int rwHead = 1;
		while(inFile)
		{
			if(timeToClean)
			{
				int lowestIndex = 0;
				for(i = 0; i < numSegments; i++)
				{
					if(activeBlocks[i] < activeBlocks[lowestIndex];
						lowestIndex = i;
				}
				int cleanStartINdex = (numBlocks/numSegments) * lowestIndex;
				//move all blocks in cleaned segment to head
				for(i = cleanStartIndex; i < (cleanStartIndex + (numBlocks/numSegments)) && i < numBlocks; i++)
				{
					vector <int> temp;
					while(disk[i]->type ==-1 &&  i < (cleanStartIndex + (numBlocks/numSegments)) && i < numBlocks)
					{
						i++;
					}
					if(disk[i]->type == 1)
					{
						for(int j = 0; j < disk[i]->inode.size(); j++)
							temp.push_back(disk[i]->inode[j]);
						disk[i]->type = -1;
						disk[i]->inode.clear();
						disk[rwHead]->type = 1;
						disk[rwHead]->inode.clear();
						for(int j = 0; j < temp.size(); j++)
							disk[rwHead]->inode.push_back(temp[j]);
					}
					else if (disk[i]->type == 0)
					{
						disk[i]->type = -1;
						disk[i]->inode.clear();
						disk[rwHead]->type = 0;
						disk[rwHead]->inode.clear();
					}

					while(disk[rwHead]->type !=-1)
					{
						rwHead++;
						if(rwHead == numBlocks)
							rwHead = 0;
					}
				} 
			}
			//if current block unocupied
			if(disk[rwHead].type == -1)
			{
				inFile = (getline(infile, line))
				stringstream ss(line);
				string word;
				vector<string> words;
				while (ss>>word)
				{
				        words.push_back(word);
				}

				if(words[0]=="READ")
				{
					//just alter stats on disk needle movement
				}
				else if(words[0] == "WRITE")
				{	
					currWriteFile = stoi(words[1], nullptr);
					currWriteBlock = stoi(words[2], nullptr);

					//if file exists
					if(imap.find(currWriteFile) != imap.end)
					{
						//if the block exists de-alloc
						if(disk[imap[currWriteFile]]->inode.size() >= currWriteBlock)
						{
							int blockLocation = disk[imap[currWriteFile]]->inode[currWriteBlock];
							//"de-aloc" (change type) old block, this may be unnessesary
							disk[blockLocation]->type = -1;
							activeBlocks[blockLocation/(numBlocks/numSegments)]--;
						}

						//write new block to disk
						disk[rwHead] = &newBlock(0, -1, nullptr);
						activeBlocks[rwHead/(numBlocks/numSegments)]++;

						while(disk[rwHead]->type !=-1)
						{
							rwHead++;
							if(rwHead == numBlocks)
								rwHead = 0;
						}

						//write new inode to disk and "de-aloc" old
						vector <int> newBlockMap;
						for(int j = 0; j < disk[imap[currWriteFile]]->inode.size(); j++)
						{	
							newBlockMap.push_back(disk[imap[currWriteFile]]->inode[j]);
						}

						disk[imap[currWriteFile]]->type = -1;
						disk[imap[currWriteFile]]->inode.clear();
						
						activeBlocks[imap[currWriteFile]/(numBlocks/numSegments)]--;

						disk[rwHead] = &newBlock(1, currWriteFile, newBlockMap);
						
						activeBlocks[rwHead/(numBlocks/numSegments)]++;
						//change imap
						imap[currWriteFile] = rwHead;
						
						while(disk[rwHead]->type !=-1)
						{
							rwHead++;
							if(rwHead == numBlocks)
								rwHead = 0;
						}

						//rewrite imap to file
						disk[mapLoc]->type = -1;
						
						disk[rwHead]->type = 2;
						mapLoc = rwHead;
					}
					else//if file does not yet exist
					{


						//write block to disk
						disk[rwHead] = &newBlock(0, -1, nullptr);

						activeBlocks[rwHead/(numBlocks/numSegments)]++;
						int newBlockLoc = rwHead;
						while(disk[rwHead]->type !=-1)
						{
							rwHead++;
							if(rwHead == numBlocks)
								rwHead = 0;
						}

						//write inode to disk
						vector <int> newBlockMap;
						newBlockMap.push_back(newBlockLoc);
						disk[rwHead] = &newBlock(1, currWriteFile, newBlockMap);

						activeBlocks[rwHead/(numBlocks/numSegments)]++;

						imap.insert(pair<int, int>(currWriteFile,rwHead));

						while(disk[rwHead]->type !=-1)
						{
							rwHead++;
							if(rwHead == numBlocks)
								rwHead = 0;
						}

						//rewrite imap to file
						disk[mapLoc]->type = -1;

						disk[rwHead]->type = 2;
						mapLoc = rwHead;
					}
				}
				else
				{
					cout << "Bad input." << endl;
				}
			}


			while(disk[rwHead]->type !=-1)
			{
				rwHead++;
				if(rwHead == numBlocks)
					rwHead = 0;
			}

		}






	}				
	return 0;
}


/*
		{
			stringstream ss(line);
                        string word;
                        vector<string> words;
                        while (ss>>word){
                                words.push_back(word);
                        }

			if(words[0]=="READ"){
			}

			else if(words[0] == "WRITE"){	

			}
		}
*/
