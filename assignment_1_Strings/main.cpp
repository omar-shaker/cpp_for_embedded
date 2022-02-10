#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    int testCases = 0, extensionPos = 0, sizePos = 0;
    string outputString, temp, extension;
    getline(cin, temp);
    stringstream ss(temp);
    ss >> testCases;
    int linesCount[testCases];
    int size[testCases][4]{0};
    for (int i = 0; i < testCases; i++)
    {
        ss >> linesCount[i];
        for (int j = 0; j < linesCount[i]; j++)
        {
            getline(cin, temp);
            extensionPos = temp.rfind(".");
            sizePos = temp.rfind(" ");
            string extension = temp.substr(extensionPos, (sizePos - extensionPos));
            if (extension == ".mp3" || extension == ".aac" || extension == ".flac")
            {
                size[i][0] += stoi(temp.substr(sizePos));
            }
            else if (extension == ".jpg" || extension == ".bmp" || extension == ".gif")
            {
                size[i][1] += stoi(temp.substr(sizePos));
            }
            else if (extension == ".mp4" || extension == ".avi" || extension == ".mkv")
            {
                size[i][2] += stoi(temp.substr(sizePos));
            }
            else
            {
                size[i][3] += stoi(temp.substr(sizePos));
            }
        }
    }
    for (int i = 0; i < testCases; i++)
    {
        outputString = "music " + to_string(size[i][0]) +
                       "b images " + to_string(size[i][1]) +
                       "b movies " + to_string(size[i][2]) +
                       "b other " + to_string(size[i][3]) + "b";
        cout << outputString << endl;
    }

    return 0;
}