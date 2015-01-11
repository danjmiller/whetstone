#include <string>


class BitTools{


public:  
    template< typename T> std::string printBinary(const T num, bool pretty=false) const;
    template<typename T> T swapEvenOdd(const T num) const;
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


template<typename T>
T BitTools::swapEvenOdd(const T num) const
{
    T out;
    
    //TODO genreate even/odd bitmap for any number..

    //Get Odd Bits
    T odd = num & 0xAA;
    //Get Even Bits
    T even = num & 0x55;

    //Shift Odd Right 1
    odd = odd >> 1; 
    //Shift Even Left 1
    even = even << 1;

    //OR Them together
    T result = odd | even;

    return result;

}

