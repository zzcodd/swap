#! /bin/sh
# Original Auth: Albert Zhang <xhzzhang@yeah.net>
# Last Modified: 2016-04-27 12:54:23

if [ ! $1 ]; then
    exit 1
fi

export LC_ALL=en_US.UTF-8
VERSION_CONFIG_FILE=$1

echo "/* This file was generated automatically, all modifies will overvided. */" > $VERSION_CONFIG_FILE
echo "#pragma once" >> $VERSION_CONFIG_FILE
echo "" >> $VERSION_CONFIG_FILE
# svn
#echo "#define VERSION_CODE \"r`svn info | grep 'Revision' | awk '{print $2}'`\"" >> $VERSION_CONFIG_FILE
# git
echo "#define VERSION_CODE \"`git rev-parse --short HEAD`\"" >> $VERSION_CONFIG_FILE
echo "" >> $VERSION_CONFIG_FILE
echo "#define VERSION_DATE \"`date`\"" >> $VERSION_CONFIG_FILE
echo "" >> $VERSION_CONFIG_FILE
cd -

exit 0
