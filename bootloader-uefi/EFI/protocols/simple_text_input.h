#ifndef EFI_SIMPLE_TXT_INPUT_PROTOCOL_H
#define EFI_SIMPLE_TXT_INPUT_PROTOCOL_H

#include "../types.h"

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID \
    { 0x387477c1,0x69c7,0x11d2, {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b} }

struct EFI_INPUT_KEY
{
    UINT16 scanCode;
    CHAR16 unicodeChar;
};

typedef EFI_STATUS (*PFN_EfiInputReset)
(
    In struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL* pThis,
    In BOOLEAN extendedVerification
);

typedef EFI_STATUS (*PFN_EfiInputReadKey)
(
    In struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL* pThis,
    Out struct EFI_INPUT_KEY* pKey
);

struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL
{
    PFN_EfiInputReset reset;
    PFN_EfiInputReadKey readKeyStroke;
    EFI_EVENT waitForKey;
};

#endif // EFI_SIMPLE_TXT_INPUT_PROTOCOL_H
