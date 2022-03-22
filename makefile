reg = `pkg-config regex --cflags --libs`

%.t:%.exe
	./$^

%.exe:%.c
	gcc $^ -o $@  $(reg)
