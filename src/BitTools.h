#include <string>


class BitTools{


public:  
    template< typename T> std::string printBinary(const T num, bool pretty=false) const;
};

template< typename T> 
std::string BitTools::printBinary(const T num, bool pretty) const
{
    std::string out;
    for(int i = 0; i < sizeof(T)*8; i++)
    {
        if( i > 0 && pretty && (i % 8 == 0) )
        {
            out.insert(0, " ");
        }

        if(((num >> i) & 0x1) == 1)
        {
            out.insert(0, "1");
        }
        else
        {
            out.insert(0, "0");
        }        
    }
    return out;
}

