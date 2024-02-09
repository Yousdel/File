#include "filec.h"
//c++
#include <string.h>


FileC::FileC()
{
}

FileC::FileC(const char *filename)
    :m_filename(filename)
{
}

bool
FileC::open(const int &flags)
{
    std::string s_flags{
        flags==(Text | WriteOnly)? "w":
        flags==(Text | ReadOnly)? "r":
        flags==(Binary | WriteOnly)? "wb" :
        /*flags==(Binary | ReadOnly)?*/ "rb"
    };
    fptr = fopen(m_filename.c_str(),
                     s_flags.c_str());
    return fptr==NULL? false:true;
}

const std::string
&FileC::readAll()
{
    static std::string s;
    s.clear();
    char *readedData = new char[40];
    fscanf(fptr,"%s", readedData);  //esta funcion esta incompleta
    //porque solo lee hasta un espacio de l acadena leida

    s = readedData;
    return s;
}







