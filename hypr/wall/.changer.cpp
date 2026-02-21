#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    if(argc == 1) {
        cout << "Not enough arguments. " << endl;
        return 1;
    }
    else if(argc == 2) {
        string s = argv[1];
        if(s == "-l" || s == "-list") {
            string cd = "cd ~/.config/hypr/wall && ls";
            system(cd.c_str());
        }
        else {
            cout << "Unknown field: " + s << endl;
            return 1;
        }
    }
    else if(argc == 3) {
        string s = argv[2];
        int idx = -1;
        for(int i = s.size() - 1; i >= 0; -- i) {
            if(s[i] == '.') {
                idx = i;
                break;
            }
        }
        /*
         example command:
         ./changer add wallpaper.png
         ./changer use wallpaper.png
        */ 
        string cd = "cd ~/.config/hypr/wall";
        system(cd.c_str());
        string op = argv[1];
        if(op == "add") {
            //cout << "detected add flag" << endl;

            if(idx == -1 || idx == 0 || idx == s.size() - 1) {
                cout << "Invalid format. " << endl;
                return 1;
            }
            string extension = s.substr(idx + 1);
            //swww supported formats: PNG, JPG, JPEG, WEBP, BMP, TGA, PNM
            if(extension == "png" || extension == "jpg" || extension == "jpeg" || extension == "webp" || extension == "tga" || extension == "pnm") {
                string copy = "cp .swww_dummy.conf " + s + ".conf";
                string replace = "sed -i 's/YOURIMAGE/" + s + "/' " + s + ".conf";
                //cout << copy << endl << replace << endl;
                system(copy.c_str());
                system(replace.c_str()); 
            }
            else {
                cout << "Invalid file type." << endl;
                return 1;
            }
        }
        else if(op == "use") {
            string use = "cp " + s + ".conf w.conf";
            string pipe = "head -n 1 w.conf > .engine_type.temp";
            system(use.c_str());
            system(pipe.c_str());
            ifstream fin(".engine_type.temp");
            if(!fin) {
                cout << "Error reading from temprorary file." << endl;
                return 1;
            }
            string type;
            fin >> type;
            cout << type << endl;
            if(type == "#swww") {
                string pywal = "wal -i ~/.config/wallpapers/" + s + " >/dev/null 2>&1";
                system(pywal.c_str());
            }
            string cleanup = "rm engine_type.temp >/dev/null 2>&1";
            system(cleanup.c_str());
        }
        else {
            cout << "Unknown flag. --help for info" << endl;
            return 1;
        }
    }
}
