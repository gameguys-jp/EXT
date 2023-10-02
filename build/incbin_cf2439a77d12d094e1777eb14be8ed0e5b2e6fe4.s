.section .data._0, "aw"
.balign 4

.global _0
.type _0, @object
.size _0, (_0_end - _0)
_0:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/0.tim"

.local _0_end
_0_end:

.balign 4

.section .data._0_size, "aw"
.balign 4

.global _0_size
.type _0_size, @object
.size _0_size, 4
_0_size:
	.int (_0_end - _0)
