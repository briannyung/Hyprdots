for file in *; do
    echo $file
    sed -i 's/swww/awww/g' $file
done