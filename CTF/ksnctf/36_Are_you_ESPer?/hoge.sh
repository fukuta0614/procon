
for i in {8160..8180}; do
./a.out $i | nc ctfq.sweetduet.info 10777
echo $i
done

