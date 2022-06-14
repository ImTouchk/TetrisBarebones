#ifndef EFI_SIMPLE_TXT_OUTPUT_PROTOCOL_H
#define EFI_SIMPLE_TXT_OUTPUT_PROTOCOL_H

#include "../types.h"

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID \
    { 0x387477c2,0x69c7,0x11d2, {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b} }

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

struct SIMPLE_TXT_OUTPUT_MODE
{
    INT32 maxMode;
    // current settings
    INT32 mode;
    INT32 attribute;
    INT32 cursorColumn;
    INT32 cursorRow;
    BOOLEAN cursorVisible;
};

typedef EFI_STATUS (*PFN_EfiTextReset)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis,
    In BOOLEAN extendedVerification
);

typedef EFI_STATUS (*PFN_EfiTextString)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis,
    In CHAR16* pString
);

typedef EFI_STATUS (*PFN_EfiTextTestString)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis,
    In CHAR16* pString
);

typedef EFI_STATUS (*PFN_EfiTextQueryMode)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis,
    In UINTN modeNumber,
    Out UINTN* pCols,
    Out UINTN* pRows
);

typedef EFI_STATUS (*PFN_EfiTextSetMode)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis,
    In UINTN modeNumber
);

typedef EFI_STATUS (*PFN_EfiTextSetAttribute)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis,
    In UINTN attribute
);

typedef EFI_STATUS (*PFN_EfiTextClearScreen)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis
);

typedef EFI_STATUS (*PFN_EfiTextSetCursorPosition)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis,
    In UINTN column,
    In UINTN row
);

typedef EFI_STATUS (*PFN_EfiTextEnableCursor)
(
    In struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* pThis,
    In BOOLEAN visible
);

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    PFN_EfiTextReset reset;
    PFN_EfiTextString outputString;
    PFN_EfiTextTestString testString;
    PFN_EfiTextQueryMode queryMode;
    PFN_EfiTextSetMode setMode;
    PFN_EfiTextSetAttribute setAttribute;
    PFN_EfiTextClearScreen clearScreen;
    PFN_EfiTextSetCursorPosition setCursorPosition;
    PFN_EfiTextEnableCursor enableCursor;
    struct SIMPLE_TXT_OUTPUT_MODE* pMode;
};

#endif