attack: mod_badbuf.c ipToMod ipForIp inputHw1.c badbuf.c file
	gcc -o mod_badbuf mod_badbuf.c
	./mod_badbuf <ipToMod >opOfMod ||:
	gcc -o inputHw1 inputHw1.c
	./inputHw1 ||:
	gcc -o badbuf badbuf.c
	./badbuf <file ||:
