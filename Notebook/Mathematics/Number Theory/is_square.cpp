#include "../template.cpp"

typedef long long int lld;
bool IsSquare(lld number)
{
    lld min = 1;
    lld max = number;
    lld mid = min + (max - min) / 2;
    if (number == 0 || number == 1)
        return true;
    while (min < max)
    {
        if (mid * mid > number)
        {
            max = mid - 1;
            mid = min + (max - min) / 2;
        }
        else if (mid * mid < number)
        {
            min = mid + 1;
            mid = min + (max - min) / 2;

        }
        if (mid * mid == number)
            return true;

    }
    return false;
}