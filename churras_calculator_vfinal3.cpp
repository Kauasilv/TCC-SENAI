#include <iostream>
#include <iomanip>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <typeinfo>

using namespace std;

void logoChurras () {
	cout << "___________________________________________________________________________________________" <<endl;
	cout << "_                                                                                         _" <<endl;
    cout << "_   _____ _                                 _____      _            _       _             _" << endl;
    cout << "_  / ____| |                               / ____|    | |          | *     | |            _" << endl;
    cout << "_ * |    | |__  _   _ _ __ _ __ __ _ ___  | |     __ _* | ___ _   _| | __ _| |_ ___  _ __ _" << endl;
    cout << "_ | |    | '_ *| | | | '__| '__/ _` / __| | |    / _` | |/ __| | | | |/ _` | __/ _ *| '__|_" << endl;
    cout << "_ | |____| | | | |_| | |  | | | (_| *__ * | |___| (_| | | (__| |_| | | (_| | || (_) | |   _" << endl;
    cout << "_  *_____|_| |_|*__,_|_|  |_|  *__,_|___/  *_____*__,_|_|*___|*__,_|_|*__,_|*__*___/|_|   _" << endl;
    cout << "_                                                                                         _" <<endl;
    cout << "___________________________________________________________________________________________" <<endl;

}

int main()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale (LC_ALL, "Portuguese");
    bool input_ok;
    double h, m, totalpessoas, novoValor;
    int i, opcao, id;
    string nomeProduto [18] = {
    "Carne", "Linguiça", "Cerveja", "Refrigerante", "Pão", "Farofa", "Carvão", "Guardanapos", "Álcool",
    "Panos de prato", "Facas", "Pratos", "Talheres", "Copos", "Sal grosso", "Limão", "Pinga", "Açúcar"
    };
    string unidadeProduto [18] = {
    "kg", "kg", "latas", "latas", "unidades", "kg", "kg", "pacotes de 50 un.", "litros",
    "unidades", "unidades", "unidades", "pares", "pacotes de 50 un.", "kg", "unidades", "litros", "kg"
    };
    double precoProduto [18] = {
    49.00, 38.00, 3.09, 2.95, 1.20, 9.14, 9.45, 3.14, 9.50,
    3.00, 5.00, 3.00, 1.99, 11.99, 2.95, 0.55, 5.00, 3.99
    };


    /*Índice de items para consulta:

    0 - carne - kg.
    1 - linguica - kg.
    2 - cerveja - lata un.
    3 - refri - lata un.
    4 - pao - un.
    5 - farofa - kg.
    6 - carvao - kg.
    7 - guardanapo - 50 un.
    8 - alcool
    9 - panos
    10 - facas
    11 - pratos
    12 - talheres
    13 - copos - 50 un.
    14 - sal grosso
    15 - limao
    16 - pinga
    17 - acucar*/
    do {
        system ("cls");
        logoChurras ();
        cout << "Digite a quantidade de pessoas"<<endl;
        do {
            cout << "Homem: ";
            cin >> h;
            if (cin.fail()) {
                cin.clear ();
                cin.ignore ();
                cout << "Digite apenas números!\n";
            }
            else if (h < 0) {
                cout << "O número mínimo é 0! \n";
            }
            else
                input_ok = true;
        }
        while (input_ok == false);
        input_ok = false;
        do {
            cout << "Mulher: ";
            cin >> m;
            if (cin.fail()) {
                cin.clear ();
                cin.ignore ();
                cout << "Digite apenas números!\n";
            }
            else if (m < 0) {
                cout << "O número mínimo é 0! \n";
            }
            else
                input_ok = true;
        }
        while (input_ok == false);
        input_ok = false;


        double nProduto [18] = {
        (0.5 * h + 0.2 * m), //carne
        (0.3 * h + 0.2 * m), //linguiça
        (5 * h + 3 * m), //cerveja
        (3 * h + 5 * m), //refri
        (3 * h + 2 * m), //pão
        (0.05 * h + 0.05 * m), //farofa
        (nProduto [0] * 1.5), //carvão
        (ceil ((5 * h + 5 * m)/50.00)), //guardanapos - 50 un.
        1, //álcool
        (1 + ceil ((h + m)/10.00)), //panos de prato
        (1 + ceil ((h + m)/10.00)), //facas para churrasqueira
        (h + m), //pratos
        (h + m), //talheres - faca e garfo
        (ceil ((2 * h + m)/50.00)), //copos - 50 un.
        (0.025 * nProduto [0]), //sal grosso
        (3 + ceil ((h + m)/2)), //limão
        (1 + 0.2 * (h + m)), //pinga
        ((nProduto [16])/5 + 1), //açúcar
        };

    do {
        system ("cls");
        logoChurras ();
        cout << " _____________________________ ________________________ _______________ _________________ \n";
        cout << "|       Nome do Produto       |       Quantidade       |   Preço Un.   |  Despesa Total  |\n";
        cout << "|_____________________________|________________________|_______________|_________________|\n";
        float precoTotal = 0;
        for (int i = 0; i <= 17; i++) {
            cout << "|" << std::left << setw (29) << nomeProduto [i];
            cout << "|" << setw (6) << nProduto [i] << " " << setw (17) << unidadeProduto [i];
            cout.setf (ios::fixed);
            cout.precision (2);
            cout << "|" << "R$ " << setw (12) << precoProduto [i];
            cout << "|";
            SetConsoleTextAttribute(hConsole, 12);
            cout << "R$ " << setw (14) << (precoProduto [i] * nProduto [i]);
            SetConsoleTextAttribute(hConsole, 15);
            cout << "|\n";
            cout.unsetf (ios::fixed);
            cout.precision (3);
            cout << "|_____________________________|________________________|_______________|_________________| \n";
            precoTotal = precoTotal + (precoProduto [i] * nProduto [i]);
        }
        cout.setf (ios::fixed);
        cout.precision (2);
        cout << setw (64) << " " << "| TOTAL: ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "R$ " << setw(13) << precoTotal;
        SetConsoleTextAttribute(hConsole, 15);
        cout << "|\n";
        cout << setw (64) << " " << "|________________________| \n";
        totalpessoas=(h+m);
        cout << setw (64) << " " << "| VALOR P/PESSOA:";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "R$ " << setw(5) << precoTotal/totalpessoas;
        SetConsoleTextAttribute(hConsole, 15);
        cout << "|\n";
        cout << setw (64) << " " << "|________________________| \n";

        do {
            cout << "Selecione uma opção:\n";
            cout << "[1] Novo cálculo \n";
            cout << "[2] Alterar valor dos produtos \n";
            cout << "[3] Finalizar \n";
            cin >> opcao;
        }
        while ((opcao != 1) && (opcao != 2) && (opcao != 3));
        system ("cls");
        if (opcao == 2) {
            do {
                system ("cls");
                cout << " ________ ________________________ __________________ \n";
                cout << "|   ID   |         Produto        |    Valor atual   |\n";
                cout << "|________|________________________|__________________|\n";
                for (int i = 0; i <= 17; i++) {
                    cout << "|" << setw (8) << i + 1 << "|" << setw (24) << nomeProduto [i] << "|";
                    cout << "R$ " << setw (15) << precoProduto [i] << "|\n";
                    cout << "|________|________________________|__________________|\n";
                }
                do {
                    cout << "Digite o ID do produto para alterar seu valor ou digite 0 para retornar:";
                    cin >> id;
                }
                while ((id < 0) || (id > 18));
                for (int i = 1; i <= 18; i++) {
                    if (id == i) {
                        do {
                            cout << "Digite o novo valor para o produto " << "[" << nomeProduto [id-1] << "]: \n";
                            cin >> novoValor;
                            if (novoValor < 0.01) {
                                cout << "O valor mínimo é 0.01 real!\n";
                            }

                        }
                        while (novoValor < 0.01);
                        precoProduto [id-1] = novoValor;
                        break;
                    }
                }
            }
            while (id != 0);
            system ("cls");
        }
    }
    while (opcao == 2);

    }
    while (opcao == 1);



    return 0;
}
