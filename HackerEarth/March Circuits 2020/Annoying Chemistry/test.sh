for((i = 1; i <= 100; ++i)); do
    echo $i
    ./gen.py $i > inp_gen
    ./sol.py < inp_gen > out_s
    export c=$?
    if [ $c -ne 0 ]; then exit $c; fi
done