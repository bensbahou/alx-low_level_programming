#!/bin/bash
# This script is used to search for files in a directory and its subdirectories and then copy them to another directory

# The directory to search for files is the same as the directory where the script is located
search_dir="../"

# The directory to copy the files to
copy_dir="./"

# create a table to store the names of files we want to copy
files=(
0-isupper.c
0-memset.c
0-strcat.c
1-isdigit.c
1-memcpy.c
1-strncat.c
100-atoi.c
2-strchr.c
2-strlen.c
2-strncpy.c
3-islower.c
3-puts.c
3-strcmp.c
3-strspn.c
4-isalpha.c
4-strpbrk.c
5-strstr.c
6-abs.c
9-strcpy.c
)

# q: how to declare a table with some values in it?

# a: declare -a files = ( "0-isupper.c" "0-memset.c" )

# loop through the files array
for file in "${files[@]}"; do
    # search for the file in the search directory and its subdirectories
    # and copy it to the copy directory
    find "$search_dir" -name "$file" -exec cp {} "$copy_dir" \;
done


