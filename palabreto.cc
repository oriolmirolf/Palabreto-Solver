#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

int contador = 0;
set<string> diccionario;

void cargar_diccionario(){
    ifstream infile;
    infile.open("palabras.txt");

    if(infile.fail()){
        cout << "File Could Not Be Reached";
        return;
    }

    while(infile.good()){
        string str;
        infile >> str;
        diccionario.insert(str);
    }
    infile.close();
}

void comprobar(const string& p) {
    if (diccionario.find(p) != diccionario.end()){
        cout << contador << ": " << p << endl;
        ++contador;
    }
}

void resolver_recursivo(const vector<char>& letras, string palabra, int tact, bool usada) {
    if (tact == 10) return; //tamaño maximo = 10; tam^10 es mucho ya!


    if (tact >= 3 and usada){
        comprobar(palabra);
    }

    for (auto c : letras) {
        palabra.push_back(c);
        if (c == letras[0])
            resolver_recursivo(letras, palabra, tact+1, true);
        else 
            resolver_recursivo(letras, palabra, tact+1, usada);
        palabra.pop_back();

    }
}

void resolver(const vector<char>& letras) {
    string aux = "";
    resolver_recursivo(letras, aux, 0, false);
}

int main() {
    //cargamos el diccionario
    cargar_diccionario();
    
    int n;
    cout << "Cuantas letras son?" << endl;
    cin >> n;
    vector<char> letras(n);
    cout << "Introduce las letras, siendo PRIMERA la necesaria" << endl;
    for (int i = 0; i < n; ++i) cin >> letras[i];

    resolver(letras);
}