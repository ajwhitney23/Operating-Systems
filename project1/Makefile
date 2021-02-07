all: prolific generation explorer slugs

prolific: prolific.c
	gcc prolific.c -o prolific

generation: generation.c
	gcc generation.c -o generation

explorer: explorer.c
	gcc explorer.c -o explorer

slugs: slug.c slugrace.c
	gcc slug.c -o slug
	gcc slugrace.c -o slugrace

clean:
	rm prolific generation slug slugrace