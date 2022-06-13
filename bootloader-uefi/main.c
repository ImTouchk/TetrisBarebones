#include "efi/types.h"
#include "efi/system_table.h"

EFI_STATUS efi_main(EFI_HANDLE imageHandle, EFI_SYSTEM_TABLE* systemTable)
{
    for(;;)
    {
        systemTable->pConIn->reset(systemTable->pConIn, FALSE);

    }
}