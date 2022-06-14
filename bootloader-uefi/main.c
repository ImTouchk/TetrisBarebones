#include "efi/types.h"
#include "efi/system_table.h"

EFI_STATUS efi_main(EFI_HANDLE imageHandle, struct EFI_SYSTEM_TABLE* systemTable)
{
    systemTable->pConOut->reset(systemTable->pConOut, FALSE);
    for(;;)
    {
        systemTable->pConOut->outputString(systemTable->pConOut, L"aksjdgsakdjhasdksjahdkjashdaskh\r\n");
    }
}
