#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>

using namespace std;
/**
 * @brief Clase para facilitar el trabajo con archivos,
 * similar a QFile en Qt, pero la parte de archivos
 * esta basada en C++ plano.
 */
class File
{
public:
    enum AccessMode
    {
        WriteOnly = 0x01,
        ReadOnly  = 0x02,
        Binary = 0x10,
        Text   = 0x20
    };

    //CTORES-------------------------------------------------
    File();
    File(const char* filename);
    //METODOS------------------------------------------------
    void
    setFilename(const char *filename)
    {
        m_filename = filename;
    }

    bool
    open(const int &flags);

    void
    close();

    bool
    flush()
    {
        return true;
    }

    bool
    write(const std::string &data);

    const std::string
    &readAll();

private:
    ifstream *finPtr {nullptr};
    std::string m_filename ;
    int flags=0x0;
};

#endif // FILE_H
