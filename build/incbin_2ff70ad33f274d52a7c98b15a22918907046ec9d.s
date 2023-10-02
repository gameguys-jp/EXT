.section .data._00cobble, "aw"
.balign 4

.global _00cobble
.type _00cobble, @object
.size _00cobble, (_00cobble_end - _00cobble)
_00cobble:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/00cobble.tim"

.local _00cobble_end
_00cobble_end:

.balign 4

.section .data._00cobble_size, "aw"
.balign 4

.global _00cobble_size
.type _00cobble_size, @object
.size _00cobble_size, 4
_00cobble_size:
	.int (_00cobble_end - _00cobble)
