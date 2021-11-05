#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool running = true;

//Open the file to wipe anything in it
void wipeFile() {
    ofstream cleansed("cleansed.txt");
}

//Open file of given name, read through and replace
//any lines that do not contain "-" will be put into cleansed.txt

void cleanFile() {
    wipeFile();
    fstream cleansed("cleansed.txt");
    fstream file;
    string fileName;
    string line;
    cout << "Enter file name: ";
    cin >> fileName;
    file.open(fileName);
    if(file.fail()) {
   	 running = false;
   	 cout << "File could not be found... exiting simulation.\n";
    }
    else {
   	 while(getline(file, line)) {
   		 cleansed.open("cleansed.txt",fstream::app);
   		 if (line.find("-") == string::npos) {
   			 cleansed << line << endl;
   		 }
   		 cleansed.close();
   	 }
    }
    file.close();
}

int main() {
    string stopSim;
    char inputType;
    char resume;
    string schedulerType;
    int inputPID;
    int inputBurst;
    int inputArrival;
    int inputPriority;
    int inputDeadline;
    int inputIO;
    int schedulerOption;
    while (running) {
   	 cout << "Please enter an 'f' if you'd like to read from a file or 'i' if you want to insert manually: ";
   	 cin >> inputType;
   	 if (inputType == 'f') cleanFile();
   	 else {
   		 bool enterInfo = true;
   		 while(enterInfo) {
   			 cout << "Would you like to enter a new process? (y/n): ";
   			 cin >> resume;
   			 if (resume == 'y') {
   				 cout << "Enter P_ID: ";
   				 cin >> inputPID;
   				 cout << "Enter burst time for P_ID " << inputPID << ": ";
   				 cin >> inputBurst;
   				 cout << "Enter arrival time for P_ID " << inputPID << ": ";
   				 cin >> inputArrival;
   				 cout << "Enter priority for P_ID " << inputPID << ": ";
   				 cin >> inputPriority;
   				 cout << "Enter deadline for P_ID " << inputPID << ": ";
   				 cin >> inputDeadline;
   				 cout << "Enter I/O for P_ID " << inputPID << ": ";
   				 cin >> inputIO;
   			 }
   			 else (enterInfo = false);
   		 }
   	 }
   	 cout << "Please enter a '1' if you would like to run MFQS or a '2' for RTS: ";
   	 cin >> schedulerOption;
   	 if(schedulerOption == 1) {
   		 //MFQS
   	 }
   	 else if (schedulerOption == 2) {

   		 //RTS
   	 }

   	 //End simulation or run another
   	 cout << "Would you like to run a different simulation? (y/n): ";
   	 cin >> resume;
   	 if (resume == 'n') running = false;
    }
}

