#include <Windows.h>
#include "overridecaps.h"

extern "C"
{
    // N.B. _guard_check_icall2 and _guard_dispatch_icall2 are undefined. We use them here in combination
    // with the alternatename linker directives to produce unorthodox decision trees where both "yes" and "no"
    // target the same function.
    #pragma comment(linker, "/alternatename:_guard_check_icall2=_guard_check_icall")
    void _guard_check_icall2(ULONG_PTR);

    [[msvc::dispatch(map:[
        Arm64CfgCheckOpt -> _guard_check_icall2
    ])]]
    void _guard_check_icall(ULONG_PTR);

    #pragma comment(linker, "/alternatename:_guard_dispatch_icall2=_guard_dispatch_icall")
    void _guard_dispatch_icall2(ULONG_PTR);

    [[msvc::dispatch(map:[
        Arm64CfgDispatchOpt -> _guard_dispatch_icall2
    ])]]
    void _guard_dispatch_icall(ULONG_PTR);
}
