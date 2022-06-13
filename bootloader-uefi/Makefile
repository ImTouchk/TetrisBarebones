CC      := clang
LD      := lld-link-10

CFLAGS  := -ffreestanding -flto -fno-stack-protector -fshort-wchar -MMD -mno-red-zone -std=c11 \
		   -target x86_64-pc-win32-coff -Wall -Wextra
LDFLAGS := -subsystem:efi_application -nodefaultlib -dll

SRC     := $(shell find -name "*.c")
OBJ     := $(patsubst ./%.c, obj/%.o, $(SRC))

$(OBJ): obj/%.o : %.c
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $(patsubst obj/%.o, %.c, $@) -o $@

.PHONY: all
all: $(OBJ)
	${LD} ${LDFLAGS} -entry:efi_main -out:obj/BOOTX64.efi ${OBJ}
