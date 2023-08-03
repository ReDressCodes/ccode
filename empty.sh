#!/bin/bash

for file in *; do
    if [ ! -s "$file" ]; then 
       echo "$file"
       rm "$file"
    fi
done
