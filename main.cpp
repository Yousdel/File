#include <iostream>

#include <fstream>

#include "file.h"


using namespace std;

int main()
{

    cout << "bienvenido" << endl;

    //guardar archivo texto----------------------------------

//    File f("E:\\example.txt");
//    if (!f.open(File::Text | File::WriteOnly))
//        cout <<"Error, no se pudo abrir\n";
//    else
//    {
//        if (!f.write("hola\n"
//                     "mundo\n"
//                     "que tal."))
//        {
//            cout << "Error, no puedo escribir";
//            return 0x0;
//        }

//        f.close();
//        cout << "\n\nexito\n\n";
//    }



    //leer archivo texto------------------------------------

    File f("E:\\example.txt");
    if (!f.open(File::Text | File::ReadOnly))
        cout <<"Error, no se pudo abrir\n";
    else {
        std::string s=
                f.readAll();
        f.flush();
        f.close();
        cout << "lei "<< s;
    }
    cout << endl;


    return 0;
}
