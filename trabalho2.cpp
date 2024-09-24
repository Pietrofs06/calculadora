#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    double valorMediaArray[1000]; // todos os valores inseridos para criar uma média
    bool aindaDigitando = true;   // verifica se o usuário deseja dar continuidade ao código
    int valoresInseridos = 0;     // qualquer valor matemático inserido
    double inserirPotencia;       // valor que será elevado (potência)
    double inserirPotencia2;      // potência
    double coeficienteA;          // coeficiente de n°1
    double coeficienteB;          // coeficiente de n°2
    double coeficienteC;          // coeficiente de n°3
    char continuar;               // define o estado de continuidade de inserção de números
    string escolha;               // escolha do cálculo

    cout << "Escolha seu cálculo: (media, potencia, equacao)" << "\n" << endl;
    cin >> escolha; //define a escolha de cálculo do usuário

    while (aindaDigitando == true)
    {
        if (escolha == "media")
        {
            cout << "Digite um número para inserir na sua média aritmética: " << "\n";
            float valorAinserir;
            cin >> valorAinserir;
            if (valorAinserir >= 1 && valorAinserir < 9)
            {
                valoresInseridos += 1;
                aindaDigitando = true;
                valorMediaArray[valoresInseridos] = valorAinserir; // acresenta o numero no array e a posição é definida com base no valoresInseridos
                cout << "Deseja inserir mais um valor? (0 para sim e 1 para não)" << "\n";
                cin >> continuar;
                while (continuar != '0' && continuar != '1')
                {
                    cout << "Resposta inválida, digite 0 para sim e 1 para não!" << "\n";
                    cin >> continuar;
                }
                if (continuar == '0')
                {
                    aindaDigitando = true;
                }
                else if (continuar == '1')
                {
                    aindaDigitando = false;
                }
            }
            else if (valorAinserir < 1)
            {
                aindaDigitando = true;
                cout << "Insira um número maior que 0!" << "\n";
            }
        }
        else if (escolha == "potencia")
        {
            cout << "Digite um número para elevar a potência: " << "\n";
            cin >> inserirPotencia;
            if (inserirPotencia - int(inserirPotencia) == 0) //compara o valor para checar se é um número inteiro
            {
                cout << "Digite o número da potência: " << "\n";
                cin >> inserirPotencia2;
                if (inserirPotencia2 - int(inserirPotencia2) == 0)
                {
                    cout << "Executando cálculo... " << "\n" << endl;
                    break;
                }
                else
                {
                    aindaDigitando = true;
                    cout << "Digite um número válido! " << "\n" << endl;
                    cin >> inserirPotencia2;
                }
            }
            else
            {
                aindaDigitando = true;
                cout << "Digite um número para elevar a potência válido! " << "\n" << endl;
                cin >> inserirPotencia;
            }
        }
        else if (escolha == "equacao")
        {
            cout << "Digite um número para ser o coeficiente a: " << "\n";
            cin >> coeficienteA;
            if (coeficienteA != 0)
            {
                cout << "Digite um número para ser o coeficiente b: " << "\n";
                cin >> coeficienteB;
                if (coeficienteB >= -9999999999999) //forma temporaria de definir quais casas de numeros podem ser usados
                {
                    cout << "Digite um número para ser o coeficiente c: " << "\n";
                    cin >> coeficienteC;
                    if (coeficienteC >= -9999999999999)
                    {
                        cout << "Executando cálculo... " << "\n" << endl;
                        break;
                    }
                    else
                    {
                        aindaDigitando = true;
                        cout << "Digite um número válido! " << "\n" << endl;
                        cin >> coeficienteC;
                    }
                }
                else
                {
                    aindaDigitando = true;
                    cout << "Digite um número válido! " << "\n" << endl;
                    cin >> coeficienteB;
                }
            }
            else
            {
                aindaDigitando = true;
                cout << "Digite um número válido! " << "\n" << endl;
                cin >> coeficienteA;
            }
        }
        else
        {
            aindaDigitando = true;
            cout << "Digite um formato de cálculo válido: (media, potencia, equacao)" << "\n" << endl;
            cin >> escolha;
        }
    }
    // calculos
    if (escolha == "media")
    {
        cout << "Quantidade de valores: " << valoresInseridos << "\n";
        float valoresAsomar;
        float media;
        for (int i = 1; i <= valoresInseridos; ++i)
        {
            cout << "Valor N°" << i << ": " << valorMediaArray[i] << "\n"; //vai listando todos os valores inseridos dentro do array para criar a mediana
            valoresAsomar += valorMediaArray[i];
        }
        //analise e print da media
        media = valoresAsomar / valoresInseridos;
        cout << media << "\n" << endl;
    }
    else if (escolha == "potencia")
    {
        cout << "O resultado da sua potência foi: " << pow(inserirPotencia, inserirPotencia2) << "\n" << endl; //mostra o resultado da potência
    }
    else if (escolha == "equacao")
    {
        double delta = 0;
        double valorDeX1 = 0;
        double valorDeX2 = 0;
        delta = pow(coeficienteB, 2) - 4 * coeficienteA * coeficienteC;
        valorDeX1 = (-coeficienteB - sqrt(delta)) / (2 * coeficienteA);
        valorDeX2 = (-coeficienteB + sqrt(delta)) / (2 * coeficienteA);
        cout << "O valor de delta é: " << delta << "\n" << endl; //mostra o resultado de delta
        cout << "O valor de x¹: " << valorDeX1 << "\n" << endl; //mostra o resultado de x1
        cout << "O valor de x²: " << valorDeX2 << "\n" << endl; //mostra o resultado de x2
    }
}
// © Direitos reservados exclusivamente para Felipe e Pietro