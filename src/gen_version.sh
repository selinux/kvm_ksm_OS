#!/bin/bash
# Script that generates a version header file whenever there is a new commit.

if [ $# -ne 1 ]; then
	app=`basename $0`
    echo "Usage: $app <header_file_to_write>"
    exit 1
fi

current_version_file=current_version
prev_version=`cat $current_version_file`
version=`git rev-parse --short HEAD`
header_file=$1

if [ "$version" != "$prev_version" ]; then
	echo $version > $current_version_file
	t=`date -R`
	printf "#ifndef _VERSION_H_\n#define _VERSION_H_\n" > $header_file
	printf "#define __KERN_VERSION__ \"$version\"\n" >> $header_file
	printf "#define __BUILD_TIME__ \"$t\"\n" >> $header_file
	printf "#endif\n" >> $header_file
fi
