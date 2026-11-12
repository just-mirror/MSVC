#pragma once
#include <overridecapabilities.h>

#if !defined _VCRT_BUILD && !defined _VCRT_ALLOW_INTERNALS
    // This is an internal C Runtime header file.  It is used when building the
    // C Runtime only.  It is not to be used as a public header file.
    #error ERROR: Use of C Runtime library internal header file.
#endif

// This can be removed once overridecapabilities.h has been converted from macro to enum
namespace {
enum OverrideCaps
{
    Amd64Ermsb                              = OVRDCAP_AMD64_ERMSB,
    Amd64CpuManufacturerIntel               = OVRDCAP_AMD64_CPU_MANUFACTURER_INTEL,
    Amd64CpuManufacturerAmd                 = OVRDCAP_AMD64_CPU_MANUFACTURER_AMD,
    Amd64V1Capset                           = OVRDCAP_AMD64_V1_CAPSET,
    Amd64Avx                                = OVRDCAP_AMD64_AVX,
    Amd64Avx2                               = OVRDCAP_AMD64_AVX2,
    Amd64Avx512F                            = OVRDCAP_AMD64_AVX512F,
    Amd64V2Capset                           = OVRDCAP_AMD64_V2_CAPSET,
    Amd64CfgCheckOpt                        = OVRDCAP_AMD64_CFG_CHECK_OPT,
    Amd64CfgDispatchOpt                     = OVRDCAP_AMD64_CFG_DISPATCH_OPT,
    Amd64CpuFamily15                        = OVRDCAP_AMD64_CPU_FAMILY_15,
    Amd64CpuExtendedFamily8                 = OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_8,
    Amd64CpuExtendedFamily10                = OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_10,
    Arm64UnalignedCrt                       = OVRDCAP_ARM64_UNALIGNED_CRT,
    Arm64Dczva                              = OVRDCAP_ARM64_DCZVA,
    Arm64DczvaStride_64Bytes                = OVRDCAP_ARM64_DCZVA_STRIDE_64BYTES,
    Arm64CpuImplementerArm                  = OVRDCAP_ARM64_CPU_IMPLEMENTER_ARM,
    Arm64CpuImplementerMicrosoft            = OVRDCAP_ARM64_CPU_IMPLEMENTER_MICROSOFT,

    Arm64CfgCheckOpt                        = OVRDCAP_ARM64_CFG_CHECK_OPT,
    Arm64CfgDispatchOpt                     = OVRDCAP_ARM64_CFG_DISPATCH_OPT,
    Arm64ECCfgCheckOpt                      = OVRDCAP_ARM64_EC_CFG_CHECK_OPT,
    Arm64ECICallCheckOpt                    = OVRDCAP_ARM64_EC_ICALL_CHECK_OPT,
    Arm64ECCallCheckOpt                     = OVRDCAP_ARM64_EC_CALL_CHECK_OPT,
};
} // anonymous namespace
