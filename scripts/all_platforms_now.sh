#!/bin/bash

export ROOTDIR=`pwd`

echo " ============================================== "
echo " HYPERBORG FULL QT PLATFORM INSTALLATION SCRIPT "
echo " ============================================== "
echo " ROOT directory: " $ROOTDIR
echo
echo " Please enter root password for enabling subsequent, unattended sudo calls"

sudo time

wget https://hyperborg.com/scripts.tar.gz
tar -zxvf scripts.tar.gz

cd scripts/linux
./0_get_prereq

cd $ROOTDIR/scripts
mcedit config.ini
. ./config.ini

cd $ROOTDIR/scripts/cmake
./1_get_cmake

cd $ROOTDIR/scripts/emsdk
./1_get_emsdk

cd $ROOT/scripts/linux
./2_get_qt
./4_configure_qt
./5_compile_qt
./6_install_qt

cd $ROOT/scripts/android
./1_get_sdk
./2_get_qt
./4_configure_qt
./5_compile_qt
./6_install_qt

cd $ROOT/scripts/wasm
./2_get_wasm_qt
./4_configure_wasm_qt
./5_compile_wasm_qt
./6_install_wasm_qt

echo "== DONE =="






