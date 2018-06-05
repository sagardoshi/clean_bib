#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
    /* This code takes in a .bib file and removes any specified fields */

    ///////////////////
    // User Interaction
    ///////////////////
    string field_to_remove;
    cout << "\nThis program will clean up and process your 'export.bib \n";
    cout << "file into ";
    cout << "one that is much easier to import into LaTeX.\n" << endl;
    cout << "Please enter the name of any field you wish to remove. If \n";
    cout << "you only wish to clean up the file, type 'ok' and hit enter.\n";
    cout << "\n>> ";
    cin >> field_to_remove;
    cout << endl;

    if (field_to_remove != "ok") {
        cout << "Checking to see if '" << field_to_remove << "' is in the ";
        cout << "file, and removing it if so..." << endl;
    }
    cout << "Adding spaces between citations for readability..." << endl;
    cout << "Removing any extraneous commas at the end of citations..." << endl;
    cout << "Removing any extraneous whitespace within citations..." << endl;
    cout << "Escaping special characters like & and $..." << endl;


    ///////////////////////////////////
    // Reading through the current file
    ///////////////////////////////////
    ifstream input_file("export.bib");
    string line; // Buffering one line at a time
    string newfile = ""; // Will fill in with new file
    int counter = 1;

    while (getline(input_file, line)) {
        // Adds space between entries for readability and removes RefWorks ID
        if (line[0] == '@' &&
            line.find("RefWorks") != string::npos) {
            line = line.substr(0, line.find('{') + 1);
            line = "\n" + line + to_string(counter) + ",";
            counter++;
        }

        // Finds the key at the beginning of field rows
        string field_name = "";
        if (line.find("=") != -1) {
            field_name = line.substr(1, line.find("=") - 1);
            if (field_name.back() == ' ') field_name.pop_back();
        }

        // Copies all lines (except for the field requested)
        if (field_name != field_to_remove) newfile += line + "\n";

    }
    input_file.close();

    ////////////////////
    // Clean up new file
    ////////////////////
    const int NUM_PROBLEMS = 6; // Change this number as needed
    string bad_sub[NUM_PROBLEMS] = {"\n\n\n", "},\n}", "= \t {", " ={", " &",
                                    " $"};
    string better_sub[NUM_PROBLEMS] = {"\n\n", "}\n}", "={", "={", " \\&",
                                       " \\$"};

    for (int i = 0; i < NUM_PROBLEMS; i++) {
        int pos_prob = newfile.find(bad_sub[i]);
        while (pos_prob != string::npos) {
            newfile.replace(pos_prob, bad_sub[i].length(), better_sub[i]);
            pos_prob = newfile.find(bad_sub[i]);
        }
    }

    ////////////////////////////////////////////////////////////////////
    // Re-paste everything (minus the skipped field) into the same file
    ////////////////////////////////////////////////////////////////////
    ofstream ofs ("export.bib", ofstream::out);
    ofs << newfile;
    ofs.close();


    ///////////////////
    // User Interaction
    ///////////////////
    cout << "Done! Check 'export.bib', and enjoy.\n" << endl;

    return 0;
}
