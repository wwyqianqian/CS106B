// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <fstream>
#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include "random.h"
#include "strlib.h"
#include "vector.h"
#include "map.h"
using namespace std;


//Function Prototype
void fileScanner(ifstream &infile,int order);
void fileWriter(int order);
string findSeed(void);

//Named Constant
const int REQUIRED_WORDS =2000;

//Global Variable
Map<string, Vector<char> > writterDatabase;


int main() {
    ifstream infile;
    while(true){
        string fileName = getLine("Please enter filename containing source text: ");
        infile.open(fileName.c_str());
        //in order to obtain the correct file name
        if (!infile.fail()) break;
        infile.clear();
        cout<<"Unable to open the file. Please try again! "<<endl;
    }
    int order = getInteger("What order of analysis (1 to 10)");
    fileScanner(infile,order);
    fileWriter(order);
	return 0;
}
/*
 Function Name: fileScanner
 Usage: void fileWriter(ifstream in,int order)
 this method is firstly achieving read all txt file into a char stream. Then, according to the order entered, the keyword of map will be listed. the following char of each keyword will be added to the vector.
 */

void fileScanner(ifstream &infile,int order){
    Vector<string> key;
    Vector<char> keyStream;
    //eof: end of file
    while(!infile.eof()){
        keyStream.add(infile.get());
    }
    for (int i =0; i<keyStream.size()-order; i++) {
        string singleKey = "";
        for(int j=0;j<order;j++){
            singleKey+=string(1,keyStream.get(i+j));
        }
        if(!writterDatabase.containsKey(singleKey)){
            Vector<char> possibleChoices;
            possibleChoices.add(keyStream.get(i+order));
            writterDatabase.put(singleKey,possibleChoices);
        }else{
            Vector<char> possibleChoices;
            possibleChoices= writterDatabase.get(singleKey);
            possibleChoices.add(keyStream.get(i+order));
            writterDatabase.put(singleKey,possibleChoices);
        }
    }
}
/*
 Function Name: fileWriter
 Usage: void fileWriter(int)
 the mostly appeared keyword will be treated as seed and the next char will be selected from the vector related to keyword. then this char will combined with the previous seed except the first char to form a new seed. Until reach 2000 char, it won't finish.
 */
void fileWriter(int order){
    cout<<"Analyzing, please wait."<<endl;
    string seed = findSeed();
    string article = "";
    article+=seed;
    for(int i=0;i<REQUIRED_WORDS-order;i++){
        Vector<char> follower = writterDatabase.get(seed);
        //randomly choose one from all the followers
        int randomIndex =randomInteger(0, follower.size()-1);
        char nextChar = follower[randomIndex];
        seed=seed.substr(1)+string(1,nextChar);
        article+=string(1,nextChar);
    }
    cout<<article<<endl;
}
/*
 Fuction Name: findSeed
 usage: string str = findSeed
 this is simply a normal find maximum problem. the only useful poing is using foreach method to iterate within a map.
 */
string findSeed(){
    int maxFollower = 0;
    string seed = "";
    //awesome foreach method
    foreach(string key in writterDatabase){
        if(writterDatabase.get(key).size()>maxFollower){
            maxFollower=writterDatabase.get(key).size();
            seed = key;
        }
    }
    return seed;
}
