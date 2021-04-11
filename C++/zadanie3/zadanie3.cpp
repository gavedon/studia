#include <iostream>
#include <vector> 
#include <cstdlib>
#include <string>

using namespace std;

const vector<pair<int,string>> rzym=
{
    {1000,"M"},
    {900,"CM"},
    {500,"D"},
    {400,"CD"},
    {100,"C"},
    {90,"XC"},
    {50,"L"},
    {40,"XL"},
    {10,"X"},
    {9,"IX"},
    {5,"V"},
    {4,"IV"},
    {1,"I"}
};

string bin2rom(int x)
{   
    string roman_num;
    for(int k=0; k<rzym.size(); ++k)
    {
        while(x != x%rzym[k].first)
        {
            x = x - rzym[k].first;
            roman_num = roman_num + rzym[k].second;
        }
    }
    return roman_num;
}

int main(int argc, char* argv[])
{
    for(int k=1; k<argc; ++k)
    {
        try
        {
            string decimal = argv[k];
            int x;
            for(int i=0; i<decimal.size(); ++i)
            {
                if(decimal[i]>'9' || decimal[i]<'0')
                {
                    throw invalid_argument(" , poniewaz podany na wejsciu znak nie jest cyfra :/");
                }
            }
            x = stoi(argv[k]);
            if(x<=0 || x>=4000)
            {
                throw invalid_argument(" ,poniewaz liczba jest spoza przedzialu :/");
            }
            cout << x << " w zapisie rzymskim to: " << bin2rom(x) << endl;
        }
        catch(exception& e)
        {
            clog << "Nipoprawnie podano dane wejsciowe"<< e.what() << endl;
        }
    }
    return 0;
}