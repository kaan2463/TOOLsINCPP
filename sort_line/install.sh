#!/bin/bash
make install
echo sorter is moved to /usr/local/bin
mv sorter /usr/local/bin
echo allowing permission!
chmod a+x /usr/local/bin/sorter/sorter
#add path -not work
#export PATH=$PATH:/usr/local/bin/sorter
#delete path
#PATH=`echo $PATH | sed -e 's/:\/usr\/local\/bin\/sorter\/$//'`
echo completed!
