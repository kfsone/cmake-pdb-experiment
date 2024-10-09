#include <cstdio>

// We're putting this in a second translation unit and not doing
// full optimization to ensure that there are publicly visible
// symbols with a potential to be exposed.

namespace HiddenNamespace
{

void CrouchingSymbol() { printf("ok\n"); }

}
