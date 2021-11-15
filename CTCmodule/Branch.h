#ifndef BRANCH_H
#define BRANCH_H

struct Branch{

	//Constructor
	Branch(std::string _name, int _start, int _end) :
		name(_name), start(_start), end(_end) {}
	
	//Get whether thhis branch contains a given block
	bool hasBlock(int id){
		return (id >= start && id <= end);
	}
		
	std::string name; //Name of the branch
	int start; //First block of the branch
	int end; //Last block of the branch
};

#endif
