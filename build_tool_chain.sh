#!/bin/sh

if [ ! -d buildroot ]; then
	echo -e "\033[32mStart to build the tool chain !\033[0m"
	tar zxvf buildroot.tgz
	cp buildroot/configs/mipseb_gcc-3.3.5_uclibc-0.9.28.config buildroot/.config
	make -C buildroot oldconfig
	make -C buildroot
fi

TOPDIR=`pwd`
ENV_VAR=setupenv

echo export TPATH_UC=$TOPDIR/buildroot/build_mips/staging_dir		> $ENV_VAR
echo export TPATH_KC=$TOPDIR/buildroot/build_mips/staging_dir		>>$ENV_VAR
echo export PATH=$TOPDIR/buildroot/build_mips/staging_dir/bin:$PATH	>>$ENV_VAR

echo ""
echo -e "\033[32mUse \033[33msource ./$ENV_VAR\033[32m to setup your environment variables !\033[0m"
echo ""
