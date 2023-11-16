#include <iostream>
using namespace std;

struct tipo_reg
{
    string cod;
    string desc;
    double qtd;
    double vlr;
};
int main()
{
    tipo_reg material[10];
    char C;
    int j = 0;

    cout << "MENU:\n I - Incluir\n C - Consultar\n R - Retirar\n F - Finalizar\n";
    cin >> C;
    do
    {
        if ((C == 'I')||(C == 'i'))
        {
            cin >> material[j].cod;
            cin >> material[j].desc;
            cin >> material[j].qtd;
            cin >> material[j].vlr;
            j++;
        }
    }
    while((C=!'F')||(C=!'f'));
}
/* i= 73 || +26
c = 67
r82
f70*/
