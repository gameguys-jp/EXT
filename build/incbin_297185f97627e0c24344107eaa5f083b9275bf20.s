.section .data.test, "aw"
.balign 4

.global test
.type test, @object
.size test, (test_end - test)
test:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/test.tim"

.local test_end
test_end:

.balign 4

.section .data.test_size, "aw"
.balign 4

.global test_size
.type test_size, @object
.size test_size, 4
test_size:
	.int (test_end - test)
