#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
void exec(string cmd) {
    system(cmd.c_str());
}
int main(int argc, char* argv[]) {
    if(argc == 1) {
        cout << "Not enough arguments. Syntax is walman [add] [use] [default] file" << endl;
        return 1;
    }
    else if(argc == 2) {
        string s = argv[1];
        if(s == "-l" || s == "-list") {
            exec("cd ~/.config/hypr/wall && ls");
        }
        else {
            cout << "Unknown field: " + s << endl;
            return 1;
        }
    }
    else if(argc > 2) {
        string s = argv[argc-1];
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
        exec("cd ~/.config/hypr/wall");
        for(int i = 1; i < argc - 1; ++ i) {
            string op = argv[i];
            if(op == "add") {
                //cout << "detected add flag" << endl;

                if(idx == -1 || idx == 0 || idx == s.size() - 1) {
                    cout << "Invalid format. " << endl;
                    return 1;
                }
                exec("file -b ~/.config/wallpapers/" + s + " > .file_type.temp");
                ifstream readType(".file_type.temp");
                if(!readType) {
                    cout << "Unknown error." << endl;
                    return 1;
                }
                string extension;
                readType >> extension;
                //cout << "Recognized extension: " << extension << endl;
                exec("rm .file_type.temp");
                //swww supported formats: PNG, JPG, JPEG, WEBP, BMP, TGA, PNM
                if(extension == "PNG" || extension == "JPG" || extension == "JPEG" || extension == "WEBP" || extension == "TGA" || extension == "PNM") {
                    exec("cp .swww_dummy.conf " + s + ".conf");
                    exec("sed -i 's/YOURIMAGE/" + s + "/' " + s + ".conf");
                }
                else {
                    exec("cp .mpvpaper_dummy.conf " + s + ".conf");
                    exec("sed -i 's/YOURIMAGE/" + s + "/' " + s + ".conf");
                }
            }
            else if(op == "use") {
                exec("cp " + s + ".conf w.conf");
                exec("head -n 1 w.conf > .engine_type.temp");
                ifstream fin(".engine_type.temp");
                if(!fin) {
                    cout << "Error reading from temp file." << endl;
                    return 1;
                }
                string type;
                fin >> type;
                cout << type << endl;
                if(type == "#swww") {
                    exec("wal -i ~/.config/wallpapers/" + s + " >/dev/null 2>&1");
                }
                else if(type == "#mpvpaper") {
                    string snapshot = "~/.config/wallpapers/.walman_temp_" + s;
                    exec("ffmpeg -ss 00:00:00 -i ~/.config/wallpapers/" + s + " -frames:v 1 " + snapshot);
                    exec("wal -i " + snapshot + " >/dev/null 2>&1");
                    exec("rm " + snapshot);
                }
                exec("rm .engine_type.temp >/dev/null 2>&1");
            }
            else if(op == "default") {
                exec("cp " + s + ".conf d.conf");
                exec("cp ~/.config/wallpapers/" + s + " ~/.config/wallpapers/d");
            }
            else {
                cout << "Invalid operator " << op << endl;
                return 1;
            }
        }
    }
}
