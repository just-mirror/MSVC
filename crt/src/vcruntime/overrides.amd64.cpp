#include "vcruntime_string.h"
#include "overridecaps.h"

extern "C"
{
    void* __cdecl memcpy_avx_ermsb_amd(
        _Out_writes_bytes_all_(_Size) void*       _Dst,
        _In_reads_bytes_(_Size)       void const* _Src,
        _In_                          size_t      _Size
    );
    void* __cdecl memcpy_avx512_ermsb_amd(
        _Out_writes_bytes_all_(_Size) void*       _Dst,
        _In_reads_bytes_(_Size)       void const* _Src,
        _In_                          size_t      _Size
    );
    void* __cdecl memcpy_sse2_ermsb_amd(
        _Out_writes_bytes_all_(_Size) void*       _Dst,
        _In_reads_bytes_(_Size)       void const* _Src,
        _In_                          size_t      _Size
    );
    void* __cdecl memcpy_avx_no_faststring_amd(
        _Out_writes_bytes_all_(_Size) void*       _Dst,
        _In_reads_bytes_(_Size)       void const* _Src,
        _In_                          size_t      _Size
    );
    void* __cdecl memcpy_avx_ermsb_Intel(
        _Out_writes_bytes_all_(_Size) void*       _Dst,
        _In_reads_bytes_(_Size)       void const* _Src,
        _In_                          size_t      _Size
    );
    void* __cdecl memcpy_sse2_ermsb_Intel(
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
        all(Amd64V2Capset, Amd64CpuManufacturerAmd,   Amd64Avx, Amd64CpuFamily15, any(Amd64CpuExtendedFamily8, Amd64CpuExtendedFamily10)) -> memcpy_avx_no_faststring_amd,
        all(Amd64V2Capset, Amd64CpuManufacturerAmd,   Amd64Avx512F, Amd64Ermsb) -> memcpy_avx512_ermsb_amd,
        all(Amd64V2Capset, Amd64CpuManufacturerIntel, Amd64Avx512F, Amd64Ermsb) -> memcpy_avx_ermsb_Intel,
        all(Amd64V2Capset, Amd64CpuManufacturerIntel, Amd64Avx, Amd64Ermsb) -> memcpy_avx_ermsb_Intel,
        all(Amd64V2Capset, Amd64CpuManufacturerAmd,   Amd64Avx, Amd64Ermsb) -> memcpy_avx_ermsb_amd,
        all(Amd64V1Capset, Amd64CpuManufacturerIntel, Amd64Ermsb) -> memcpy_sse2_ermsb_Intel,
        all(Amd64V1Capset, Amd64CpuManufacturerAmd,   Amd64Ermsb) -> memcpy_sse2_ermsb_amd
    ])]]
    void* __cdecl memcpy(
        _Out_writes_bytes_all_(_Size) void*       _Dst,
        _In_reads_bytes_(_Size)       void const* _Src,
        _In_                          size_t      _Size
        );

    [[msvc::dispatch(map:[
        all(Amd64V2Capset, Amd64CpuManufacturerAmd,   Amd64Avx, Amd64CpuFamily15, any(Amd64CpuExtendedFamily8, Amd64CpuExtendedFamily10)) -> memcpy_avx_no_faststring_amd,
        all(Amd64V2Capset, Amd64CpuManufacturerAmd,   Amd64Avx512F, Amd64Ermsb) -> memcpy_avx512_ermsb_amd,
        all(Amd64V2Capset, Amd64CpuManufacturerAmd,   Amd64Avx, Amd64Ermsb) -> memcpy_avx_ermsb_amd,
        all(Amd64V1Capset, Amd64CpuManufacturerAmd,   Amd64Ermsb) -> memcpy_sse2_ermsb_amd
    ])]]
    void* __cdecl memmove(
        _Out_writes_bytes_all_opt_(_Size) void*       _Dst,
        _In_reads_bytes_opt_(_Size)       void const* _Src,
        _In_                          size_t      _Size
        );


    _NODISCARD _Check_return_
    int __cdecl memcmp_avx2_amd(
        _In_reads_bytes_(_Size) void const* _Buf1,
        _In_reads_bytes_(_Size) void const* _Buf2,
        _In_                    size_t      _Size
        );

    _NODISCARD _Check_return_
    int __cdecl memcmp_sse2_amd(
        _In_reads_bytes_(_Size) void const* _Buf1,
        _In_reads_bytes_(_Size) void const* _Buf2,
        _In_                    size_t      _Size
        );
    
    [[msvc::dispatch(map:[
        all(Amd64V2Capset, Amd64CpuManufacturerAmd,   Amd64Avx2) -> memcmp_avx2_amd,
        all(Amd64V2Capset, Amd64CpuManufacturerAmd) -> memcmp_sse2_amd
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
    void* __cdecl memset_avx512_ermsb_amd(
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
        all(Amd64V2Capset, Amd64CpuManufacturerAmd,   Amd64Avx512F, Amd64Ermsb, none(all(Amd64CpuFamily15, Amd64CpuExtendedFamily10))) -> memset_avx512_ermsb_amd
    ])]]
    void* __cdecl memset(
        _Out_writes_bytes_all_(_Size) void*  _Dst,
        _In_                          int    _Val,
        _In_                          size_t _Size
        );

    void _CONST_RETURN* __cdecl memchr_avx2_amd(
        _In_reads_bytes_opt_(_MaxCount) void const* _Buf,
        _In_                            int         _Val,
        _In_                            size_t      _MaxCount
    );

    void _CONST_RETURN* __cdecl memchr_avx512_amd(
        _In_reads_bytes_opt_(_MaxCount) void const* _Buf,
        _In_                            int         _Val,
        _In_                            size_t      _MaxCount
    );

    [[msvc::dispatch(map:[
        all(Amd64V2Capset, Amd64CpuManufacturerAmd, Amd64Avx512F)->memchr_avx512_amd,
        all(Amd64V2Capset, Amd64CpuManufacturerAmd, Amd64Avx2)->memchr_avx2_amd
    ] )]]
    _NODISCARD _Check_return_
        void _CONST_RETURN* __cdecl memchr(
            _In_reads_bytes_opt_(_MaxCount) void const* _Buf,
            _In_                            int         _Val,
            _In_                            size_t      _MaxCount
        );
}
