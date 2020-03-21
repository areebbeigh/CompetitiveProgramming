for((i = 1; i <= 100; ++i)); do
    echo $i
    ./gen.py > inp_gen
    ./brute.py < inp_gen > out_b
done