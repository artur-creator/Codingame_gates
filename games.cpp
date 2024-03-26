#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;


enum class Operats {
AND,
OR,
XOR,
NAND,
NOR ,
NXOR
};


Operats getOperation(const std::string& operationStr) {
    if (operationStr == "AND") {
        return Operats::AND;
    }
    else if (operationStr == "OR") {
        return Operats::OR;
    }
    else if (operationStr == "XOR") {
        return Operats::XOR;
    }
    else if (operationStr == "NAND") {
        return Operats::NAND;
    }
    else if (operationStr == "NOR") {
        return Operats::NOR;
    }
    else if (operationStr == "NXOR") {
        return Operats::NXOR;
    }
}



string operation(Operats name, string a, string b)
{
    string res;
    for (int i = 0; i < a.length(); i++)
    {
        switch (name)
        {
        case Operats::AND:
            (a[i] == '-' && b[i] == '-') ? res += '-' : res += '_';
            break; 
        case Operats::OR:
            (a[i] == '_' && b[i] == '_') ? res += '_' : res +=  '-';
            break;
        case Operats::XOR:
            (a[i] != b[i]) ? res += '-' : res += '_';
            break;
        case Operats::NAND:
            (a[i] == '-' && b[i] == '-') ? res += '_' : res += '-';
            break;
        case Operats::NOR:
            (a[i] == '_' && b[i] == '_') ? res += '-' : res += '_';
            break;
        case Operats::NXOR:
            (a[i] == b[i]) ? res += '-' : res += '_';
            break;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    int m;
    cin >> m; cin.ignore();

    map<string, string> inputs;
    for (int i = 0; i < n; i++) 
    {
        string input_name;
        string input_signal;
        cin >> input_name >> input_signal; cin.ignore();
        inputs[input_name]= input_signal; 

    }
    vector <tuple<string, string, string, string>> ask;

    for (int i = 0; i < m; i++)
    {
        string output_name;
        string type;
        string input_name_1;
        string input_name_2;
        cin >> output_name >> type >> input_name_1 >> input_name_2; cin.ignore();
        ask.push_back(make_tuple(output_name, type, input_name_1, input_name_2));
    }


    for (int i = 0; i < m; i++)
    {
        cout << get<0>(ask[i]) << " " << operation(getOperation(get<1>(ask[i])), inputs[ get<2>(ask[i])], inputs[get<3>(ask[i])]) << '\n';
    }
    return 0;
}