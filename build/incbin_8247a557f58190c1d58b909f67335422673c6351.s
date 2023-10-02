.section .data._00fountain_texture, "aw"
.balign 4

.global _00fountain_texture
.type _00fountain_texture, @object
.size _00fountain_texture, (_00fountain_texture_end - _00fountain_texture)
_00fountain_texture:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/00fountain_texture.tim"

.local _00fountain_texture_end
_00fountain_texture_end:

.balign 4

.section .data._00fountain_texture_size, "aw"
.balign 4

.global _00fountain_texture_size
.type _00fountain_texture_size, @object
.size _00fountain_texture_size, 4
_00fountain_texture_size:
	.int (_00fountain_texture_end - _00fountain_texture)
