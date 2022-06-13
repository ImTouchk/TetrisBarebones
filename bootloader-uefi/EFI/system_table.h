#ifndef EFI_SYSTEM_TABLE_H
#define EFI_SYSTEM_TABLE_H

#include "types.h"
#include "protocols/simple_text_input.h"

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_90_SYSTEM_TABLE_REVISION ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_90_SYSTEM_TABLE_REVISION

typedef struct
{
    EFI_TABLE_HEADER header;
    CHAR16* pFirmwareVendor;
    UINT32 firmwareRevision;
    EFI_HANDLE consoleInHandle;
    struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL* pConIn;
    EFI_HANDLE consoleOutHandle;
    void* pConOut;
    EFI_HANDLE stdErrorHandle;
    void* pStdErr;
    void* pRuntimeServices;
    void* pBootServices;
    UINTN numberOfTableEntries;
    void* pConfigurationTable;
} EFI_SYSTEM_TABLE;

#endif // EFI_SYSTEM_TABLE_H
