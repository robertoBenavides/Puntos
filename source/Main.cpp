
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <math.h>

using namespace std;
std::random_device r;
std::default_random_engine generator{ r() };
std::uniform_real_distribution<double> distribution(1.0, 1000.0);
std::uniform_real_distribution<double> pointrnd(0.0, 20000.0);

struct Punto{
    double x;
    double y;
    Punto() {
        x = 0; y = 0;
    }
    Punto(double x, double y) {
        this->x = x;
        this->y = y;
    }
    string toString() {
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }
};

void createPuntos(vector<Punto>& p,int cant) {
    ;
    for (int i = 0; i < cant; i++) {
        p.push_back(Punto(distribution(generator), distribution(generator)));
    }

}

double distancia(Punto a, Punto b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
int main()
{
    vector<Punto> puntos;
    int cant = 20000;
    createPuntos(puntos, cant);
    vector<double>cantpoints;
    double max=0, min=100000;
    Punto selected = puntos[pointrnd(generator)];
    for (Punto &p : puntos) {
        double d = distancia(selected, p);
        max = (d > max) ? d : max;
        min = (d < min) ? d : min;
        cantpoints.push_back(d);
    }
    vector<int> final = {0,0,0,0,0,0,0,0,0,0,0};
    for (double c : cantpoints) {
        double i =10* ((c - min) / (max - min));
        final[i]++;
    }
    double count = 0;
    int sum = 0;
    for (int f : final) {
        sum += f;
        cout <<count<<"-" << f << endl;
        count += .1;
    }
    cout << "total: " << sum << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
