all:
	clang -fsanitize=fuzzer target.c -o binaryFuzzer

gencov:
	clang -fprofile-instr-generate -fcoverage-mapping target.c -fsanitize=fuzzer -o binaryCoverage

gencovAsan:
	clang -fprofile-instr-generate -fcoverage-mapping target.c -fsanitize=fuzzer,address -o binaryCoverage

run:
	./binaryFuzzer corpus

coverage:
	./binaryCoverage corpus/* 
	llvm-profdata merge -sparse *.profraw -o default.profdata && llvm-cov show ./binaryCoverage -instr-profile=default.profdata

clean:
	rm binaryCoverage *.profdata *.profraw corpus -r crash-* 2>/dev/null binaryFuzzer binaryCoverage
