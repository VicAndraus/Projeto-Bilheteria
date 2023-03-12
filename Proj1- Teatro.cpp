#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <iomanip>


using namespace std;

const int linha = 15;
const int coluna = 40;
string lugares[linha][coluna];
int fileira;
int poltrona;
int livres = 15 * 40;
int ocupados = 0;
double totalapagar = 0;
int opcao;

void sala()
{
    cout<< "______________________" <<endl;
    cout<< " " <<endl;
    cout<< " SALA DE TEATRO" <<endl;
    cout<< "______________________" <<endl;
    
    for (int i = 0; i < linha; i++)
    {
        for(int j=0; j < coluna; j++)
        {
            cout << lugares[i][j] << ". ";
        }
        cout << endl;
    }
}

void mostrasala()
{
        cout<< "____________________________________" <<endl;
        cout<< " " <<endl;
        cout<< " SALA DE TEATRO" <<endl;
        cout<< "____________________________________" <<endl;
        
      for (int i = 0; i < linha; i++)
    {
        for(int j=0; j < coluna; j++)
        {
            if(lugares[i][j] == "# ")
            {
                cout << lugares[i][j];
            }
            else
            {
                cout << lugares[i][j] << ". ";
            }
        
        }
        cout << endl;
    }
    
        cout<< "Legenda: " <<endl;
        cout<< "'.' -> Lugar vago" <<endl;
        cout<< "'#' -> Lugar ocupado" <<endl;
}


void escolha()
{
    if (fileira < 0 || fileira > linha || poltrona < 0 || poltrona > coluna)
        {
        cout << "Valores inv�lidos." <<endl;
            
        }
    else 
    {
        if (lugares[fileira-1][poltrona-1] == "# ") 
        {
            cout << "Desculpa, essa poltrona j� foi reservada." << endl;
        }
        else
        {
            lugares[fileira-1][poltrona-1] = "# ";
            livres--;
            ocupados++;
            cout << "Poltrona selecionada com sucesso!"<<endl;
            if( fileira-1 >= 0 && fileira-1 <= 5)
            {
                totalapagar = totalapagar + 50;
            }
            else
            {
                if( fileira-1 > 5 && fileira-1 <= 10)
                {
                    totalapagar = totalapagar + 30;
                }
                else
                {
                    if( fileira-1 > 10 && fileira-1 <= 15)
                {
                    totalapagar = totalapagar + 15;
                }
                }
            }    
            
            
           
        }
    }
    
    
}

void faturamento ()
{
    
     cout << "Lugares ocupados: " << ocupados <<endl;
     cout << "Lugares livres: " << livres << endl;
     cout << "Total a pagar: R$" << totalapagar <<endl;
     
}


int main()
{
    sala();
    
    do
    {
    
    cout << "Escolha uma op��o: " << endl;
    cout<<endl;
    cout << "0.	Finalizar" << endl;
    cout << "1.	Reservar poltrona" << endl;
    cout << "2.	Mapa de ocupa��o" << endl;
    cout << "3.	Faturamento" << endl;
    
    cin >> opcao;
    cout << endl;
    
    if(opcao == 1)
    {
        cout << "Escolha a fileira" << endl;
        cin >> fileira;
        cout << "Escolha a poltrona" << endl;
        cin >> poltrona;
        
        escolha();
        
        cout << endl;
    }
    else
    {
        if(opcao == 2)
        {
            mostrasala();
            cout << endl;
        }
        else
        {
            if (opcao == 3)   
            {
                faturamento();
                cout << endl;
            }
        }
    }
    
  
    
    }
    while (opcao != 0);
    
    cout << "Conclu�do, obrigada!";
    
    return 0;
}