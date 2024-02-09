#include "file.h"
//c++


File::File()
{
}

File::File(const char *filename)
    :m_filename(filename)
{

}

bool
File::open(const int &flags)
{
    this->flags = flags;
    if (flags==(Text | ReadOnly) ||
            flags==(Binary | ReadOnly))
    {
        finPtr= new ifstream(m_filename);
    }
    if (flags==(Binary | ReadOnly))
    {
        finPtr->open(m_filename,
                      ios::binary | ios::in);
    }
    if (finPtr == nullptr && (flags != (Text|WriteOnly)) &&
            (flags != (Binary|WriteOnly)))
        return false;
    return true;
}

void
File::close()
{
    if (finPtr != nullptr)
        finPtr->close();
}

bool
File::write(const string &data)
{
    ofstream ff(m_filename);
    if (!ff.is_open()) return false;

    if (flags==(Binary | WriteOnly))
    {
        ff.open(m_filename,
                      ios::binary | ios::out);
        if (!ff.is_open()) return false;
    }
    ff << data;
    ff.close();
    return true;
}

const std::string
&File::readAll()
{
    static std::string s;
    std::string line;
    line.clear();
    while (getline(*finPtr, line))
    {
        s+=line;
        if (finPtr->eof()) break;
        s += "\n";
    }
    return s;
}







