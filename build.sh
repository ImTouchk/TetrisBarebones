#!/bin/bash
## [Tetris Barebones] build system | Version 0.1
## Usage: $PROG [OPTION...] [COMMAND]...
## Options:
##  -bl, --build-loader           Build loader
##  -b, --build-project           Build entire project
##  -c, --clean-project           Clean entire project
##  -s, --setup-project           Do first-time project setup
##  -r, --run-vm                  Run inside QEMU
## Examples:
##   $PROG -c -b -r          (Does full rebuild and starts VM)
##   $PROG -bk -r            (Rebuilds only the kernel and starts VM)
PROG=${0##*/}
IMAGE_FILE="bin/tetris_os.img"
OVMF_FILE="res/OVMF.fd"

setup_project()
{
  sudo apt install clang lld mtools

  mkdir bin
  mkdir bootloader-uefi/obj
  dd if=/dev/zero of=${IMAGE_FILE} bs=1k count=1440
  mformat -i ${IMAGE_FILE} -f 1440 ::
  mmd -i ${IMAGE_FILE} ::/EFI
  mmd -i ${IMAGE_FILE} ::/EFI/BOOT
  mcopy -i ${IMAGE_FILE} res/font.ppm ::
  echo "--------------- First-time setup complete."
}

clean_project()
{
  rm -rf bin/
  rm -rf bootloader-uefi/obj/
  setup_project
  echo "--------------- Project cleanup complete."
}

build_loader()
{
  cd bootloader-uefi
  make all
  cd ../
  mcopy -o -i ${IMAGE_FILE} bootloader-uefi/obj/BOOTX64.efi ::/EFI/BOOT
  echo "--------------- Bootloader compiled."
}

build_project()
{
  build_loader
  echo "--------------- PROJECT BUILD COMPLETE."
}

run_vm()
{
  qemu-system-x86_64 -pflash ${OVMF_FILE} -cdrom ${IMAGE_FILE} -d int
}

help()
{
  grep "^##" "$0" | sed -e "s/^...//" -e "s/\$PROG/$PROG/g"; exit 0
}

[ $# = 0 ] && help
while [ $# -gt 0 ]; do
  CMD=$(grep -m 1 -Po "^## *$1, --\K[^= ]*|^##.* --\K${1#--}(?:[= ])" build.sh | sed -e "s/-/_/g")
  if [ -z "$CMD" ]; then echo "ERROR: Command '$1' not supported"; exit 1; fi
  shift; eval "$CMD" $@ || shift $? 2> /dev/null
done