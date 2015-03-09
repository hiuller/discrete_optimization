#include <iostream.h>
#include <string.h>
#include <fstream.h>

using namespace std;

class KSReader
{
public:
    KSReader(char* fileName);
    //void read();
private:
    char* s_fileName;
};


KSReader::KSReader(char* fileName)
{
    s_fileName = fileName;
    printf("Trying to read file <%s>...\n", s_fileName);

    //https://www.daniweb.com/software-development/cpp/threads/193750/declaration-of-ifstream-causes-runtime-error
    ifstream input(s_fileName);

    if(!input.is_open())
    {
        printf("Couldn't open <%s>\n", s_fileName);
        return;
    }

    char ch;
    string line;

    while(!input.eof())
    {
        input.get(ch);
        if(ch != '\n')
            line.append(&ch);
        else{
            printf("%s\n", line.c_str());
        }
    }

    input.close();
}
