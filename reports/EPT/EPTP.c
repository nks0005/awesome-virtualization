#include <Windows.h>

typedef union _EPTP
{
    ULONG64 All;

    struct
    {
        UINT64 MemoryType : 3;           // bit 2:0. EPT paging-structure memory type
        UINT64 PageWalkLength : 3;       // bit 5:3. This value is 1 less than EPT page-walk length
        UINT64 DirtyAndAccessEnable : 1; // bit 6. Setting this control to 1 enables accessed and dirty flags for EPT
        UINT64 Reserved1 : 5;            // bit 11:7
        UINT64 PML4Address : 36;
        UINT64 Reserved2 : 16;
    }
}