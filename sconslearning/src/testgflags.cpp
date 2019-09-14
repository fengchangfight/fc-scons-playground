#include <iostream>
#include <vector>
#include <string>
#include <gflags/gflags.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;

using namespace google;

DEFINE_string(languages, "english,french,german", "comma-separated list of languages to offer in the 'lang' menu");

int main(int argc, char *argv[])
{
    google::SetUsageMessage("some usage message");
    google::SetVersionString("1.0.0");
    google::ParseCommandLineFlags(&argc, &argv, true);
    cout << "My language is:" << FLAGS_languages << endl;
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code!"};

    int a = 2;
    int b = 1;
    int c = a + b;

    msg.push_back("fuck");

    for (const string &word : msg)
    {
        cout << word << " ";
        cout << c;
    }
    cout << "I\n";
    cout << "love\n";
    cout << "dogs\n";
    cout << "cats\n";
    cout << "miao\n";
    cout << "horse\n";
    cout << "tuck\n";
    cout << "bitch\n";

    return 0;
}
