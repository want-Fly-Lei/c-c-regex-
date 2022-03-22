#include<iostream>
#include<regex>
#include<string>
using namespace std;
int main() {
    smatch res;
    string str = "hypehc u ug khilhype.";
    string pat("hype[^ ]+[ |.]");
    regex r(pat);
    for(sregex_iterator it(str.begin(),str.end(),r), end_it; it != end_it; ++it) {
        cout<<it->str()<<endl;
    }
    return 0;
}