#include "vcruntime_string.h"
#include "overridecaps.h"

extern "C"
{
    void* __cdecl memcpy_unaligned(
        _Out_writes_bytes_all_(_Size) void*       _Dst,
        _In_reads_bytes_(_Size)       void const* _Src,
        _In_                          size_t      _Size
        );

   _CRT_INSECURE_DEPRECATE_MEMORY(memcpy_s)
    _Post_equal_to_(_Dst)
    _At_buffer_(
        (unsigned char*)_Dst,
        _Iter_,
        _Size,
        _Post_satisfies_(((unsigned char*)_Dst)[_Iter_] == ((unsigned char*)_Src)[_Iter_])
    )
    [[msvc::dispatch(map:[
        Arm64UnalignedCrt -> memcpy_unaligned
    ])]]
    void* __cdecl memcpy(
        _Out_writes_bytes_all_(_Size) void*       _Dst,
        _In_reads_bytes_(_Size)       void const* _Src,
        _In_                          size_t      _Size
        );

    _Post_equal_to_(_Dst)
    _At_buffer_(
        (unsigned char*)_Dst,
        _Iter_,
        _Size,
        _Post_satisfies_(((unsigned char*)_Dst)[_Iter_] == ((unsigned char*)_Src)[_Iter_])
    )
    void* __cdecl memmove_unaligned(
        _Out_writes_bytes_all_opt_(_Size) void*       _Dst,
        _In_reads_bytes_opt_(_Size)       void const* _Src,
        _In_                              size_t      _Size
        );

    _CRT_INSECURE_DEPRECATE_MEMORY(memmove_s)
    [[msvc::dispatch(map:[
        Arm64UnalignedCrt -> memmove_unaligned
    ])]]
    _VCRTIMP void* __cdecl memmove(
        _Out_writes_bytes_all_opt_(_Size) void*       _Dst,
        _In_reads_bytes_opt_(_Size)       void const* _Src,
        _In_                              size_t      _Size
        );

    _NODISCARD _Check_return_
    int __cdecl memcmp_unaligned(
        _In_reads_bytes_(_Size) void const* _Buf1,
        _In_reads_bytes_(_Size) void const* _Buf2,
        _In_                    size_t      _Size
        );

    [[msvc::dispatch(map:[
        Arm64UnalignedCrt -> memcmp_unaligned
    ])]]
    _NODISCARD _Check_return_
    int __cdecl memcmp(
        _In_reads_bytes_(_Size) void const* _Buf1,
        _In_reads_bytes_(_Size) void const* _Buf2,
        _In_                    size_t      _Size
        );


    _Post_equal_to_(_Dst)
    _At_buffer_(
        (unsigned char*)_Dst,
        _Iter_,
        _Size,
        _Post_satisfies_(((unsigned char*)_Dst)[_Iter_] == _Val)
    )
    void* __cdecl memset_unaligned_zva(
        _Out_writes_bytes_all_(_Size) void*  _Dst,
        _In_                          int    _Val,
        _In_                          size_t _Size
        );

    _Post_equal_to_(_Dst)
    _At_buffer_(
        (unsigned char*)_Dst,
        _Iter_,
        _Size,
        _Post_satisfies_(((unsigned char*)_Dst)[_Iter_] == _Val)
    )
    void* __cdecl memset_unaligned_zva_large(
        _Out_writes_bytes_all_(_Size) void*  _Dst,
        _In_                          int    _Val,
        _In_                          size_t _Size
        );

    _Post_equal_to_(_Dst)
    _At_buffer_(
        (unsigned char*)_Dst,
        _Iter_,
        _Size,
        _Post_satisfies_(((unsigned char*)_Dst)[_Iter_] == _Val)
    )
    [[msvc::dispatch(map:[
        all(Arm64UnalignedCrt, Arm64Dczva, Arm64DczvaStride_64Bytes, Arm64CpuImplementerArm) -> memset_unaligned_zva,
        all(Arm64UnalignedCrt, Arm64Dczva, Arm64DczvaStride_64Bytes, Arm64CpuImplementerMicrosoft) -> memset_unaligned_zva,
        Arm64UnalignedCrt -> memset_unaligned_zva_large
    ])]]
    void* __cdecl memset(
        _Out_writes_bytes_all_(_Size) void*  _Dst,
        _In_                          int    _Val,
        _In_                          size_t _Size
        );
}
