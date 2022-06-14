CC      := clang
CFLAGS  := -ffreestanding -fno-stack-protector -fshort-wchar -MMD -mno-red-zone -std=c11 \
		   -target x86_64-pc-win32-coff -Wall -Wextra
LDFLAGS := -Wl,-subsystem:efi_application -Wl,-entry:efi_main -fuse-ld=lld-link -nostdlib \
		   -target x86_64-pc-win32-coff

SRC     := $(shell find -name "*.c")
OBJ     := $(patsubst ./%.c, obj/%.o, $(SRC))

$(OBJ): obj/%.o : %.c
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $(patsubst obj/%.o, %.c, $@) -o $@

.PHONY: all
all: $(OBJ)
	${CC} ${LDFLAGS} -o obj/BOOTX64.efi ${OBJ}
