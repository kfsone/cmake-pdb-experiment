// Use a second translation unit to force symbols to be exposed.

namespace HiddenNamespace { extern void CrouchingSymbol(); }

int main() { HiddenNamespace::CrouchingSymbol(); }
