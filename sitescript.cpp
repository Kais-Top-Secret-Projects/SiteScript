#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int siteScriptCompile(string fileName){
    // Open Files
    ifstream siteScript;
    siteScript.open(fileName);

    ofstream javaScript;
    javaScript.open ("output.js");

    // Lexer/Parser
    if(siteScript.is_open()){
        string line;
        while(getline(siteScript, line)){
            // Check for comment
            if (!line.find("//")){
                line = "";
            }
            // check for empty lines
            if (line.size() == 0){
                // This does nothing, I will figure out why it does nothing later.
                line.erase(remove(line.begin(), line.end(), '\n'), line.end());
            }

            cout << line <<  endl;
        }
    }

    // Translator


    // Close file
    siteScript.close();
}

bool hasEnding (string const &fullString, string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

int main( int argc, char *argv[] ){
    if (argv[1] == NULL){
        cout << "ERROR: No file arguments" << endl <<
        "Usage: " << argv[0] << " programName" << endl;
        return 1;
    } else if(argc - 1 > 1){
        cout << "ERROR: Too many arguments" << endl <<
        "Usage: " << argv[0] << " programName" << endl;
    } else {
        if (!hasEnding(argv[1], ".ss")){
            cout << "ERROR: Invalid file name!" << endl <<
            "File Extension: .ss" << endl;
        } else {
            siteScriptCompile(argv[1]);   
        }
    }
}
