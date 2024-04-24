// Készítette: Tóth Ádám
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void print_vector(const vector<string>& array) {
    for (const string item : array)
    {
        cout << item << " ";
    }
    cout << endl;
}

void Combination(vector<string> a, int reqLen, int start, int currLen, vector<bool> check, int len, map<string, int>& comb)
{
    if (currLen > reqLen)
        return;
    else if (currLen == reqLen)
    {
        string combination = "";
        for (int i = 0; i < len; i++)
        {
            if (check[i] == true)
            {
                combination += a[i] + " ";
            }
        }
        if (!combination.empty())
        {
            comb[combination.substr(0, combination.length() - 1)];
        }
        return;
    }
    if (start == len)
    {
        return;
    }
    check[start] = true;
    Combination(a, reqLen, start + 1, currLen + 1, check, len, comb);
    check[start] = false;
    Combination(a, reqLen, start + 1, currLen, check, len, comb);
}

int main()
{
    map<int, vector<string>> purchase;
    map<int, vector<string>>::iterator itr;
    map<string, int> singlecount;
    map<string, int> combinations;
    map<string, int>::iterator itrs;
    vector<string> vec;
    ifstream file;
    file.open("vasarlas.txt");
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int key;
        if (iss >> key)
        {
            vector<std::string> values;
            string value;
            while (iss >> value)
            {
                values.push_back(value);
            }
            sort(values.begin(), values.end());
            purchase[key] = values;
        }
    }
    for (itr = purchase.begin(); itr != purchase.end(); itr++)
    {
        cout << itr->first << " ";
        for (string value : itr->second)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    file.close();
    float size = purchase.size();
    cout << endl;
    map<int, vector<string>> purchasecopy = purchase;
    for (itr = purchasecopy.begin(); itr != purchasecopy.end(); itr++)
    {
        vector<string>::iterator it;
        it = unique((itr->second).begin(), (itr->second).end());
        (itr->second).resize(distance((itr->second).begin(), it));
    }
    for (itr = purchasecopy.begin(); itr != purchasecopy.end(); itr++)
    {
        for (string value : itr->second)
        {
            singlecount[value]++;
        }
    }
    cout << "Minden arucikk szazalekos aranya a vasarlasokban: " << endl;
    for (itrs = singlecount.begin(); itrs != singlecount.end(); itrs++)
    {
        cout << itrs->first << ": " << setprecision(4) << (itrs->second / size) * 100 << "%" << endl;
    }
    for (itr = purchasecopy.begin(); itr != purchasecopy.end(); itr++)
    {
        for (string value : itr->second)
        {
            if (find(vec.begin(), vec.end(), value) == vec.end())
            {
                vec.push_back(value);
            }
        }
    }
    sort(vec.begin(), vec.end());
    cout << endl;
    cout << "Egyes arucikk-kombinaciok szazalekos aranya a vasarlasokban: " << endl;
    vector<bool> check;
    for (int i = 0; i < vec.size(); i++)
    {
        check.push_back(false);
    }
    for (int i = 0; i <= vec.size(); i++)
    {
        Combination(vec, i, 0, 0, check, vec.size(), combinations);
    }

    for (itr = purchasecopy.begin(); itr != purchasecopy.end(); itr++)
    {
        vector<string> line = itr->second;
        sort(line.begin(), line.end());
        string str;
        for (const auto c : line) {
            str+=c;
            str += " ";
        }
        combinations[str.substr(0,str.length()-1)]++;
    }
    for (pair <string, int> i : combinations)
    {
        cout << i.first << ": " <<setprecision(4)<< (i.second/float(size))*100 <<"%"<< endl;
    }
    return 0;
}
