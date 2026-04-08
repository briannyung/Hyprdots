#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
void exec(string cmd) {
    system(cmd.c_str());
}
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    exec("cd $HOME/.config/hypr/wall");
    ifstream file(".random.txt");
    char c;
    if (!file.get(c)) {
        return 2;
    }
    else if(c != '1') {
        return 1;
    }
    vector<string> files;
    for(const auto & entry : fs::directory_iterator(".")) {
        string name = entry.path().filename().string();
        if(name.size() < 5) continue;
        if(name.substr(name.size() - 5) != ".conf") continue;
        if(name == "w.conf" || name == "d.conf" || name == ".awww_dummy.conf" || name == ".mpvpaper_dummy.conf") continue;
        name = name.substr(0, name.size() - 5);
        cout << name << endl;
        files.push_back(name);
    }
    int idx = rand() % files.size();
    exec("walman use " + files[idx]);
}
