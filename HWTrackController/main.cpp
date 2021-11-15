#include<iostream>
#include"HWTrackController.cpp"
#include<vector>
using namespace std;

int main(){

  vector<Block> assignedBlocks;
  Block b1, b2, b3, b4;
  assignedBlocks.push_back(b1);
  assignedBlocks.push_back(b2);
  assignedBlocks.push_back(b3);
  assignedBlocks.push_back(b4);

  HWTrackController hwCon(assignedBlocks);
  Wayside *waysidePtr;
  waysidePtr = hwCon.getWayside();
  if(ifArduConnected()){
    cout << "Connected! xixi" << endl;
  }else{
    cout << "Error in port name" << endl;
  }

  char carryOn = 'y';
  vector<int> idVec;
  int id, whichBlock = 0;
  idVec = waysidePtr->getId();
  int trackSize = hwCon.getTrackSize();

  while(ifArduConnected() && carryOn == 'y'){
    cout << "Select a block: " << endl;
    cin >> whichBlock;
    if(whichBlock < trackSize){
      id = idVec[whichBlock];
      hwCon.selectBlock_Manual(id);
      //for(int a = 0 ; a < 10000; a++){}
      waysidePtr->receiveFromArduino();
  }
    cin >> carryOn;
  }

    /*
    cin >> command;
    char *charArray = new char[command.size() + 1];
    copy(command.begin(), command.end(), charArray);
    charArray[command.size()] = '\n';

    ardu.writeSerialPort(charArray, MAX_DATA_LENGTH);
    ardu.readSerialPort(output, MAX_DATA_LENGTH);

    cout << output << endl;

    delete [] charArray;
    */

//  }
/*
  vector<Block> assignedBlocks;
  Block b1, b2, b3, b4;
  assignedBlocks.push_back(b1);
  assignedBlocks.push_back(b2);
  assignedBlocks.push_back(b3);
  assignedBlocks.push_back(b4);
  int s = assignedBlocks.size();

  /*
  Wayside haha;
  haha.initWayside(assignedBlocks);
  cout << 'a' << haha.getTrackSize() << endl;

  Wayside *hahaptr;

  hahaptr = &haha;

 cout << 'b' << hahaptr->getTrackSize() << endl;
*/

/*
  HWTrackController hwCon(assignedBlocks);

  vector<double> suggSpeed(3, 11.1);
  int size = suggSpeed.size();
  cout << size << endl;
  vector<double> commSpeed;
  hwCon.setSuggestedSpeed(suggSpeed);
  commSpeed = hwCon.getCommandedSpeed();

  for (int i = 0; i < size; i++){
    cout << commSpeed[i] << endl;
  }

*/
  return 0;
}
