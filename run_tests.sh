g++ DeRossi/*cpp -o a.out
echo `pwd`
cat inputs.txt | xargs -I % sh -c 'echo "testing %:" && echo "%" | ./a.out | tr "\n" "\t" | cut  -f2- && echo "\n"'
