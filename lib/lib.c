#include "lib.h"

[[nodiscard]] const int verify(int const lhs, int const rhs)
{
    return sub(add(lhs, rhs), rhs);
}