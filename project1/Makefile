all: prolific generation explorer slug slugrace

prolific: prolific.c
	gcc prolific.c -o prolific

generation: generation.c
	gcc generation.c -o generation

explorer: explorer.c
	gcc explorer.c -o explorer

slug: slug.c
	gcc slug.c -o slug

slugrace: slugrace.c slug
	gcc slugrace.c -o slugrace

clean:
	rm prolific generation explorer slug slugrace