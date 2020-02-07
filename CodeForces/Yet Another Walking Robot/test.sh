for((i = 1; i <= 100; ++i)); do
    echo $i
    ./gen.py $i > inp_gen
    ./a.out < inp_gen > out_s
    ./brute.py < inp_gen > out_b
    diff -w out_s out_b || break
done