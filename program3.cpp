#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<fstream>
#include<sstream>
#include<map>
#include<map>
#include <utility>
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
	map<int,int> imap;
	block * mapBlock;
	mapBlock->type = 2;
	disk[0] = mapblock
	disk[i]->fileId=-1;
	if(infile.is_open())
	{
		int blockIndex = 1;
		while(inFile)
		{

			//if current block unocupied
			if(disk[blockIndex].type == -1)
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

					if(imap.find(currWriteFile) != imap.end)
					{
						disk[imap[currWriteFile]]->inode[currWriteBlock];
					}
					else
					{

					}
				}
				else
				{
					cout << "Bad input." << endl;
				}
			}


			numBlocks++;
			if(blockIndex == numBlocks)
				blockIndex = 0;
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