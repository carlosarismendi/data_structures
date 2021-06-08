
for FILE in */*.cpp ; do
	echo "Evaluando $FILE"
	cp $FILE tad.cpp
	cd ..
	make
	cd src
	valgrind -q --tool=memcheck --leak-check=full ../tad > $FILE.out
	diff -b -B -i $FILE.out $FILE.sal
	if [ "$?" == "0" ]; then
		echo "OK"
	else
		echo "ERROR"
	fi
done

