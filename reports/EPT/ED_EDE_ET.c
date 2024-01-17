#include <Windows.h>

typedef union _EPT_PML4E
{
    ULONG64 All;

    struct
    {
        UINT64 Read : 1;
        UINT64 Write : 1;
        UINT64 Execute : 1;
        UINT64 Reserved1 : 1;
        UINT64 Accessed : 1;
        UINT64 Ignored1 : 1;
        UINT64 ExecuteForUserMode : 1;
        UINT64 Ignored2 : 1;
        UINT64 PhysicalAddress : 36;
        UINT64 Reserved2 : 4;
        UINT64 Ignored3 : 12;
    } Fields;
} EPT_PML4E, *PEPT_PML4E, EPT_PDPTE, *PEPT_PDPTE, EPT_PDE, *PEPT_PDE;
