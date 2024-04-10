#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Menhely
{
public:
    string fajta, nev;
    int kor;
    string szin;
    Menhely(string a, string b, int c, string d) : fajta(a), nev(b), kor(c), szin(d) {}
};

int main()
{
    string search;
    string searchParameter;

    ifstream mh;
    mh.open("menhely.txt");
    if (!mh)
    {
        cout << "Error in opening the file" << endl;
        return 1;
    }

    vector<Menhely> menhely;
    Menhely temp("", "", 0, "");
    while (mh >> temp.fajta >> temp.nev >> temp.kor >> temp.szin)
    {
        menhely.push_back(temp);
    }

    for (const auto &allat : menhely)
    {
        cout << allat.fajta << ' ' << allat.nev << ' ' << allat.kor << ' ' << allat.szin << endl;
    }
    while(true)
    {
        cout << "What would you like to search by? (fajta - nev - kor - szin) \t Press x to exit." << endl;
        cin >> search;
        if(search == "x") break;
        cout << "Searching by " << search << "! Please add parameter." << endl;
        cin >> searchParameter;
        for (const auto &allat : menhely)
        {
            if (search == "fajta" && allat.fajta == searchParameter)
            {
                cout << allat.fajta << ' ' << allat.nev << ' ' << allat.kor << ' ' << allat.szin << endl;
            }
            else if (search == "nev" && allat.nev == searchParameter)
            {
                cout << allat.fajta << ' ' << allat.nev << ' ' << allat.kor << ' ' << allat.szin << endl;
            }
            else if (search == "kor" && to_string(allat.kor) == searchParameter)
            {
                cout << allat.fajta << ' ' << allat.nev << ' ' << allat.kor << ' ' << allat.szin << endl;
            }
            else if (search == "szin" && allat.szin == searchParameter)
            {
                cout << allat.fajta << ' ' << allat.nev << ' ' << allat.kor << ' ' << allat.szin << endl;
            }
        }
    }


    return 0;
}
