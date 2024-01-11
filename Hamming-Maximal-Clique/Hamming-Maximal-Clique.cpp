#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int hammingDist(string a, string b)
{
    int len = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            len++;
        }
    }
    return len;
}

set<string> maxClique(int d, vector<string>& verts) {
    set<string> clique;

    for (int i = 0; i < verts.size(); i++)
    {
        bool accept = true;

        for (auto vertex : clique)
        {
            if (hammingDist(verts[i], vertex) < d) {
                accept = false;
                break;
            }
        }

        if (accept == true)
        {
            clique.insert(verts[i]);
        }
    }

    return clique;
}

void CliqueCalc(int first, int last) {

    auto clockStart = high_resolution_clock::now();
    vector<string> verts;

    for (int i = 0; i < (1 << first); i++)
    {
        string v = "";

        for (int j = 0; j < first; j++)
        {

            if (i & (1 << j))
            {
                v += '1';
            }
            else {
                v += '0';
            }

        }
        verts.push_back(v);
    }

    set<string> cliq = maxClique(last, verts);

    auto clockEnd = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(clockEnd - clockStart);

    cout << (time.count()) / (double)1000000 << " Sec\n" << endl;
    cout << "Max clique: " << endl;

    int countVertex = 0;
    for (auto vertex : cliq) {
        cout << vertex << " " << endl;
        countVertex++;
    }

    cout << countVertex << " Vertex" << endl;
}

int main() {

    int aCliqueN = 5;  //Example
    int aCliqueD = 4;

    int bCliqueN = 7;
    int bCliqueD = 4;

    CliqueCalc(aCliqueN, aCliqueD);
    cout << "\n\n*************\n\n";
    CliqueCalc(bCliqueN, bCliqueD);

    return 0;
}