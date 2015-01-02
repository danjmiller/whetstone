#include <string>

class StringUtils
{


public:
    void reverse( std::string &input);
    //char*  reverse( const char* input, int length);

private:
    bool swap(std::string &input, int p1, int p2);

};
