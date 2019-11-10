search_dir=$1
i=0
for entry in "$search_dir"/*.sam
do
    let "i++"
    echo $entry
   ./parser $entry test_res/$i.parsed test_res/$i.token > test_res/$i.txt
done