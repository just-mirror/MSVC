#include <Windows.h>
#include "overridecaps.h"

extern "C"
{
    // N.B. _guard_dispatch_icall2 is undefined. We use it here in combination with the
    // alternatename linker directive to produce an unorthodox decision tree where both
    // "yes" and "no" target the same function.
    #pragma comment(linker, "/alternatename:_guard_dispatch_icall2=_guard_dispatch_icall")
    void _guard_dispatch_icall2(ULONG_PTR);

    [[msvc::dispatch(map:[
        Amd64CfgDispatchOpt -> _guard_dispatch_icall2
    ])]]
    void _guard_dispatch_icall(ULONG_PTR);
}

#include "..\checkcfg.cpp"
