#include <Windows.h>
#include "overridecaps.h"

extern "C"
{
    // N.B. __os_arm64x_direct_check_icall_cfg2, __os_arm64x_direct_check_icall2, and __os_arm64x_direct_check_call2
    // are undefined. We use them here in combination with the alternatename linker directives to produce unorthodox
    // decision trees where both "yes" and "no" target the same function.
    #pragma comment(linker, "/alternatename:#__os_arm64x_direct_check_icall_cfg2=#__os_arm64x_direct_check_icall_cfg")
    void __os_arm64x_direct_check_icall_cfg2(ULONG_PTR);

    [[msvc::dispatch(map:[
        Arm64ECCfgCheckOpt -> __os_arm64x_direct_check_icall_cfg2
    ])]]
    void __os_arm64x_direct_check_icall_cfg(ULONG_PTR);

    #pragma comment(linker, "/alternatename:#__os_arm64x_direct_check_icall2=#__os_arm64x_direct_check_icall")
    void __os_arm64x_direct_check_icall2(ULONG_PTR);

    [[msvc::dispatch(map:[
        Arm64ECICallCheckOpt -> __os_arm64x_direct_check_icall2
    ])]]
    void __os_arm64x_direct_check_icall(ULONG_PTR);

    #pragma comment(linker, "/alternatename:#__os_arm64x_direct_check_call2=#__os_arm64x_direct_check_call")
    void __os_arm64x_direct_check_call2(ULONG_PTR);

    [[msvc::dispatch(map:[
        Arm64ECCallCheckOpt -> __os_arm64x_direct_check_call2
    ])]]
    void __os_arm64x_direct_check_call(ULONG_PTR);
}
