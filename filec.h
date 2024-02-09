#ifndef FILE_H
#define FILE_H


#include <iostream>


/**
 * @brief Clase para facilitar el trabajo con archivos,
 * similar a QFile en Qt, pero la parte de archivos
 * esta basada en C plano.
 */
class FileC
{
public:
    enum AccessMode
    {
        WriteOnly = 0x01,
        ReadOnly  = 0x02,
        Binary = 0x10,
        Text   = 0x11
    };

    //CTORES-------------------------------------------------
    FileC();
    FileC(const char* filename);
    //METODOS------------------------------------------------
    void
    setFilename(const char *filename)
    {
        m_filename = filename;
    }

    bool
    open(const int &flags);

    bool
    close()
    {
        return fclose(fptr);
    }

    bool
    flush()
    {
        return fflush(fptr);
    }

    bool
    write(const std::string &data)
    {
        return fprintf(fptr, "%s",
                       data.c_str());
    }

    const std::string
    &readAll();

private:
    FILE *fptr {nullptr};
    std::string m_filename ;
};

#endif // FILE_H
