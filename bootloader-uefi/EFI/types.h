#ifndef EFI_TYPES_H
#define EFI_TYPES_H

#define In
#define Out
#define Optional

#ifndef EFI_USE_CUSTOM_NATIVES
typedef char BYTE;
typedef short INT16;
typedef int INT32;
typedef long long INT64;

typedef unsigned char UBYTE;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;

typedef INT64 INTN;
typedef UINT64 UINTN;

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;
#endif

typedef UBYTE CHAR8;
typedef UINT16 CHAR16;
typedef UBYTE BOOLEAN;

typedef UINTN EFI_STATUS;
typedef void* EFI_HANDLE;
typedef void* EFI_EVENT;

#define TRUE 1
#define FALSE 0

typedef struct
{
    UINT32 data1;
    UINT16 data2;
    UINT16 data3;
    UBYTE data4[8];
} EFI_GUID;

typedef struct
{
    UINT64 signature;
    UINT64 revision;
    UINT32 headerSize;
    UINT32 crc32;
    UINT32 reserved;
} EFI_TABLE_HEADER;

typedef struct
{
    UINT16 year;        // 1998 - 20XX
    UBYTE month;        // 1 - 12
    UBYTE day;          // 1 - 31
    UBYTE hour;         // 0 - 23
    UBYTE minute;       // 0 - 59
    UBYTE second;       // 0 -59
    UBYTE pad1;
    UINT32 nanosecond;  // 0 - 999,999,999
    UINT16 timeZone;    // -1440 to 1440 or 2047
    UBYTE daylight;
    UBYTE pad2;
} EFI_TIME;

#endif // EFI_TYPES_H
