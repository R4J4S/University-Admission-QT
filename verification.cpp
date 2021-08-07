#include "verification.h"

verification::verification()
{

}

int check_marks(std::string s)
{
    if()
}

int check_input(std::string s)
{
    if(s.empty()==true)
        return 0;
    else if(s.find_first_of("0123456789") != std::string::npos)
        return 0;
    else
        return 1;
}
