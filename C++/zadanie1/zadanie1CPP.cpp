#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


bool czy_pierwsza(int64_t liczba)
{
    int64_t pierwiastek = int64_t (sqrt(liczba));
    for(int i=2; i<pierwiastek; i++)
    {
        if(liczba%i==0)return false;
    }
    return true;
}

vector<int64_t>(v);

void rozklad(int64_t liczba,int64_t pierwsza)
{
    if(liczba==1)return;
    while(liczba!=1)
    {
        if(liczba%pierwsza==0)
        {
            liczba = liczba/pierwsza;
            v.push_back(pierwsza);    
        }
        else
        {
            pierwsza++;
        }
        if(pierwsza*pierwsza > liczba)
        {
            v.push_back(liczba);
            break;
        }
        if(pierwsza*pierwsza < 0) //iloczyn przekroczy zakres inta
        {
            v.push_back(liczba);
            break;
        }
    }
}

int64_t zmien_na_inta(const char* liczba)
{
    string x(liczba);
    int i = 0;
    string max={};
    if(x[0]=='-')
    {   
        i = 1; max = "-9223372036854775808";
    }
    else max = "9223372036854775807";
    if(x>max || x.size()>max.size())
    {
        throw invalid_argument(liczba);
    }
    for(i ; i<x.size(); i++)
    {
        if(!isdigit(x[i]))throw invalid_argument(liczba);
    }
    int64_t out = strtoll(liczba,NULL,0);
    if(x==max && x[0]=='-')
    {
        out = out/2;
        out = out*-1;
        v.push_back(-1);
        v.push_back(2);
    }
    cout << x << endl;
    if(out<0)
    {
        out = out*-1;
        v.push_back(-1);
    }
    return out;    
}

int main(int argc,char* argv[])
{
    if(argc >= 2)
    {
        for(int i=1; i<argc; i++)
        {
            try
            {
                
                const char* number(argv[i]);
                int64_t x = zmien_na_inta(number);
                rozklad(x,2);
                cout << x << "=";
                for(auto i=v.begin(); i!=v.end(); i++)
                {
                    if(i == v.end()-1)
                    {
                        cout<< *i <<endl;
                    }
                    else cout << *i << "*";
                }
                v.clear();
            }
            catch(const exception &err)
            {
                cerr << "invalid argument:" << err.what() << endl;
            }
            
        }
    }
    else
    {
        cerr << "Jesli chcesz by program dzialal poprawnie, wpisz liczbe ktora chcesz rozlozyc na czynniki pierwsze" << endl;
    }
    return 0;
}