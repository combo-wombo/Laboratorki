#!/bin/bash
set -x

if [ "$#" -ne 4 ]; then
	echo "Illegal number of parameters";
	exit 1;
fi

for file in `pwd`/*; do  
`sed -i -e "s/\$1/\$2/g" $file`
`sed -i -e "s/\$3/\$4/g" $file`
mv -v "$file" "${file/$1/$2}" ;
done

echo "Accept"

