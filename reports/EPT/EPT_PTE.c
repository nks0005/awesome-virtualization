#include <Windows.h>

typedef union _EPT_PTE
{
    ULONG64 All;

    struct
    {
        UINT64 Read : 1;
        UINT64 Write : 1;
        UINT64 Execute : 1;
        UINT64 EPTMemoryType : 3;
        UINT64 IgnorePAT : 1;
        UINT64 Ignored1 : 1;
        UINT64 AccessedFlag : 1;
        UINT64 DirtyFlag : 1;
        UINT64 ExecuteForUserMode : 1;
        UINT64 Ignored2 : 1;
        UINT64 PhysicalAddress : 36;
        UINT64 Reserved : 4;
        UINT64 Ignored3 : 11;
        UINT64 SuppressVE : 1;
    } Fields;
} EPT_PTE, *PEPT_PTE;